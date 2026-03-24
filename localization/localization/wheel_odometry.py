"""
[Node: wheel_odometry]

1. 역할: 
   - ERP42 플랫폼의 인코더 피드백(/erp42_feedback)을 기반으로 로봇의 이동 거리와 속도를 계산함.
   - 자전거 모델(Bicycle Kinematic Model)을 사용하여 2D 평면상의 x, y, theta(Yaw) 좌표를 추정함.

2. 데이터 흐름 (Input/Output):
   - 입력(Input): 
     * /erp42_feedback (erp42_msgs/SerialFeedBack): 속도(speed), 조향각(steer), 기어(gear)
     * /imu/data (sensor_msgs/Imu): 초기 주행 방향(Heading) 설정을 위한 절대 각도 수신
   - 출력(Output): 
     * /odometry/wheel (nav_msgs/Odometry): 필터링되지 않은 순수 휠 오도메트리 데이터
     * TF (odom -> base_link): 선택적(pub_tf)으로 로컬 좌표계 변환 발행

3. 주요 특징 (핵심 엔지니어링 근거):
   - IMU Initial Alignment: 휠 엔코더는 상대적인 변화량만 알 수 있으므로, 시작 시 IMU의 Yaw 값을 받아 로봇의 초기 방향을 실제 방위와 일치시킴.
   - Bicycle Model: 차량의 휠베이스(1.04m)와 조향각을 이용하여 단순 직선 운동이 아닌 실제 차량의 회전 궤적을 반영함.
   - Covariance Mapping: EKF 노드가 이 데이터를 신뢰할 수 있도록 위치(Position)와 속도(Twist)에 대한 오차 범위를 공분산 행렬로 정의함.
"""

import math
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped, Quaternion
from sensor_msgs.msg import Imu
from erp42_msgs.msg import SerialFeedBack
from tf2_ros import TransformBroadcaster

# ── 상수 정의 (Sensor & Vehicle Specs) ──────────────────────────────────────
WHEELBASE = 1.04          # ERP42 축거 [m]
MAX_DT    = 1.0           # 비정상적인 시간 간격 무시 [s]

# 공분산 설정 (EKF 가중치 결정 파라미터)
COV_POSE_XY   = 0.01      # 위치 추정 불확실성 (±10cm 수준)
COV_POSE_YAW  = 0.05      # 방향 추정 불확실성
COV_TWIST_VX  = 0.01      # 선속도 오차
COV_TWIST_VY  = 0.001     # 측면 미끄러짐 오차 (No-slip 가정으로 낮게 설정)
COV_TWIST_YAW = 0.05      # 회전 속도 오차
COV_FILL      = 1e-6      # 수치적 안정성을 위한 최소값


class WheelOdometryNode(Node):

    def __init__(self):
        super().__init__('wheel_odometry')

        # 1. 파라미터 설정 (TF 발행 여부 결정)
        self.declare_parameter('pub_tf', True)
        self._pub_tf = self.get_parameter('pub_tf').get_parameter_value().bool_value

        # 2. 로봇 상태 변수 초기화
        self._x = 0.0
        self._y = 0.0
        self._theta = 0.0
        self._last_time = self.get_clock().now()
        self._orientation_ready = False  # IMU 방향 수신 전까지 연산 대기

        # 3. 구독/발행자 설정
        self.create_subscription(SerialFeedBack, '/erp42_feedback', self._on_feedback, 10)
        self.create_subscription(Imu, '/imu/data', self._on_imu, 10)
        self._odom_pub = self.create_publisher(Odometry, '/odometry/wheel', 10)
        self._tf_broadcaster = TransformBroadcaster(self)

        self.get_logger().info(f'WheelOdometry initialized (L={WHEELBASE}m, pub_tf={self._pub_tf})')

    def _on_imu(self, msg: Imu):
        """
        초기 1회 IMU 데이터를 받아 로봇의 절대 방향(Yaw)을 초기화함.
        이후 오도메트리 계산 시 기준점이 됨.
        """
        if not self._orientation_ready:
            _, _, yaw = euler_from_quaternion(msg.orientation)
            self._theta = yaw
            self._orientation_ready = True
            self.get_logger().info(f'IMU heading aligned: {math.degrees(yaw):.1f}°')
            self._publish(0.0, 0.0)

    def _on_feedback(self, msg: SerialFeedBack):
        """
        ERP42 피드백 데이터를 주기로 위치를 업데이트함 (Bicycle Model).
        """
        now = self.get_clock().now()
        dt = (now - self._last_time).nanoseconds * 1e-9
        self._last_time = now

        # 방향 초기화가 안 되었거나 시간 간격이 비정상적이면 무시
        if not self._orientation_ready or dt <= 0 or dt > MAX_DT:
            return

        # 기어 상태에 따른 전/후진 속도 결정
        v = msg.speed if msg.gear != 0 else -msg.speed
        steer = msg.steer

        # [핵심 로직] Bicycle Kinematic Model 적용
        # dt 동안의 직선 이동량과 회전량을 계산하여 누적
        self._x += v * math.cos(self._theta) * dt
        self._y += v * math.sin(self._theta) * dt
        self._theta += (v / WHEELBASE) * math.tan(steer) * dt
        
        # 각도 정규화 (-pi ~ pi)
        self._theta = math.atan2(math.sin(self._theta), math.cos(self._theta))

        self._publish(v, steer)

    def _publish(self, v: float, steer: float):
        """
        계산된 오도메트리 결과를 ROS 2 메시지 형식으로 발행함.
        """
        stamp = self.get_clock().now().to_msg()
        q = yaw_to_quaternion(self._theta)

        odom = Odometry()
        odom.header.stamp = stamp
        odom.header.frame_id = 'odom'
        odom.child_frame_id = 'base_link'

        # 1. Pose (위치 및 방향) 설정
        odom.pose.pose.position.x = self._x
        odom.pose.pose.position.y = self._y
        odom.pose.pose.orientation = q
        # x, y, yaw에 대한 공분산 주입
        odom.pose.covariance = _make_cov_36(COV_POSE_XY, COV_POSE_XY, COV_POSE_YAW)

        # 2. Twist (선속도 및 각속도) 설정
        odom.twist.twist.linear.x = float(v)
        # 조향각과 속도를 이용한 각속도(Yaw-rate) 계산
        odom.twist.twist.angular.z = (v / WHEELBASE) * math.tan(steer) if steer else 0.0
        odom.twist.covariance = _make_cov_36(COV_TWIST_VX, COV_TWIST_VY, COV_TWIST_YAW)

        self._odom_pub.publish(odom)

        # 3. 필요 시 TF 발행 (odom -> base_link)
        if self._pub_tf:
            t = TransformStamped()
            t.header.stamp = stamp
            t.header.frame_id = 'odom'
            t.child_frame_id = 'base_link'
            t.transform.translation.x = self._x
            t.transform.translation.y = self._y
            t.transform.rotation = q
            self._tf_broadcaster.sendTransform(t)

# ── 유틸리티 함수 (좌표 변환 및 행렬 생성) ───────────────────────────────────

def yaw_to_quaternion(yaw: float) -> Quaternion:
    """Yaw 각도를 Quaternion 메시지 형식으로 변환"""
    half = yaw / 2.0
    return Quaternion(x=0.0, y=0.0, z=math.sin(half), w=math.cos(half))

def euler_from_quaternion(q) -> tuple:
    """Quaternion을 Euler 각도로 변환 (IMU Yaw 추출용)"""
    siny = 2.0 * (q.w * q.z + q.x * q.y)
    cosy = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
    yaw = math.atan2(siny, cosy)
    return 0.0, 0.0, yaw  # roll, pitch 생략

def _make_cov_36(d0: float, d1: float, d5: float) -> list:
    """6x6 공분산 행렬의 주요 대각 성분 채우기"""
    cov = [COV_FILL] * 36
    cov[0] = d0   # x
    cov[7] = d1   # y
    cov[35] = d5  # yaw
    return cov

def main(args=None):
    rclpy.init(args=args)
    node = WheelOdometryNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()