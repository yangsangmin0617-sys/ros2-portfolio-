"""
[Node: gps_to_odom_node]

1. 역할:
   - GPS 위도/경도(WGS84) 데이터를 UTM(Universal Transverse Mercator) 평면 좌표로 변환함.
   - 변환된 좌표에 기준점(Anchor)을 적용하여 'map' 프레임 기준의 상대 좌표를 생성함.
   - Odometry 메시지 발행과 동시에 TF(map -> base_link)를 직접 브로드캐스팅하여 RViz2 시각화를 지원함.

2. 데이터 흐름 (Input/Output):
   - 입력(Input): 
     * /ublox_gps_node/fix (sensor_msgs/NavSatFix): GPS 원시 데이터 (QoS: BEST_EFFORT 대응)
   - 출력(Output): 
     * /gps_odom (nav_msgs/Odometry): 상대 좌표가 적용된 오도메트리 데이터
     * TF (map -> base_link): RViz2에서 로봇 모델의 물리적 위치 이동을 담당

3. 주요 특징 (핵심 엔지니어링 근거):
   - QoS(BEST_EFFORT): 데이터 손실이 있더라도 최신성을 우선시해야 하는 GPS 센서 및 백파일(bag) 환경에 최적화된 통신 설정임.
   - pyproj Transformer: EPSG:4326(WGS84)에서 EPSG:32652(UTM Zone 52N)로의 고정밀 좌표계 변환 수행.
   - TF Broadcaster: EKF 노드 없이 단독 실행 시에도 로봇의 위치를 지도상에 고정시켜 시각적 확인을 용이하게 함.
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from nav_msgs.msg import Odometry
from pyproj import Transformer
import numpy as np
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped

class GpsToOdomNode(Node):
    def __init__(self):
        super().__init__('gps_odom_publisher_node')
        
        # 1. QoS 설정: 통신 신뢰도 정책 정의
        # BEST_EFFORT는 네트워크 부하가 있거나 불안정한 환경에서 최신 데이터를 우선적으로 수신하기 위한 설정임.
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        )

        # 2. 구독 및 발행 설정
        self.subscription = self.create_subscription(
            NavSatFix, 
            '/ublox_gps_node/fix', 
            self.listener_callback, 
            qos_profile)
            
        self.odom_publisher = self.create_publisher(Odometry, '/gps_odom', 10)
        
        # 3. TF Broadcaster 초기화: map 좌표계와 로봇(base_link) 좌표계 실시간 연결
        self.tf_broadcaster = TransformBroadcaster(self)

        # 4. 좌표계 변환기 및 기준점(Anchor) 설정
        # EPSG:32652 (WGS 84 / UTM zone 52N) 좌표계 활용
        self.transformer = Transformer.from_crs("epsg:4326", "epsg:32652")
        self.anchor_lat = 37.239
        self.anchor_lon = 126.773
        self.anchor_x, self.anchor_y = self.transformer.transform(self.anchor_lat, self.anchor_lon)
        
        self.get_logger().info(f'GPS Odom Node Started (Origin: {self.anchor_lat}, {self.anchor_lon})')

    def listener_callback(self, msg):
        # 수신된 데이터 유효성 검사 (NaN 값 수신 시 처리 중단)
        if np.isnan(msg.latitude) or np.isnan(msg.longitude):
            self.get_logger().warn('Received NaN GPS coordinates. Skipping...')
            return

        # 5. UTM 변환 및 상대 좌표(Relative Coordinates) 계산
        current_x, current_y = self.transformer.transform(msg.latitude, msg.longitude)
        relative_x = current_x - self.anchor_x
        relative_y = current_y - self.anchor_y

        # 6. Odometry 메시지 발행 (EKF 입력 및 기록용)
        odom = Odometry()
        odom.header.stamp = msg.header.stamp
        odom.header.frame_id = 'map'
        odom.child_frame_id = 'base_link'
        
        odom.pose.pose.position.x = relative_x
        odom.pose.pose.position.y = relative_y
        odom.pose.pose.position.z = 0.0 
        odom.pose.pose.orientation.w = 1.0

        # 공분산(Covariance) 설정: 위치 추정의 불확실성(0.1) 정의
        pose_covariance = np.zeros(36)
        pose_covariance[0] = 0.1  # x축 오차
        pose_covariance[7] = 0.1  # y축 오차
        pose_covariance[14] = 0.1 # z축 오차
        odom.pose.covariance = pose_covariance.tolist()

        self.odom_publisher.publish(odom)

        # 7. TF Dynamic Transform 발행 (RViz2 시각화 필수 로직)
        # Fixed Frame이 'map'일 때 로봇 모델이 실제 경로를 따라 이동하도록 함.
        t = TransformStamped()
        t.header.stamp = msg.header.stamp
        t.header.frame_id = 'map'
        t.child_frame_id = 'base_link'
        t.transform.translation.x = relative_x
        t.transform.translation.y = relative_y
        t.transform.translation.z = 0.0
        t.transform.rotation.w = 1.0 

        self.tf_broadcaster.sendTransform(t)

def main(args=None):
    rclpy.init(args=args)
    node = GpsToOdomNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()