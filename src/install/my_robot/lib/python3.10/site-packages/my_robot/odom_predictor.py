import rclpy
from rclpy.node import Node
from erp42_msgs.msg import SerialFeedBack
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion
import math

class ERP42OdomPublisher(Node):
    def __init__(self):
        super().__init__('erp42_odom_publisher')
        
        # 1. 구독자 설정: 피드백 메시지 수신
        self.subscription = self.create_subscription(
            SerialFeedBack,
            '/erp42_feedback',
            self.feedback_callback,
            10)
            
        # 2. 발행자 설정: Odometry 메시지 송신
        self.odom_pub = self.create_publisher(Odometry, '/odom', 10)
        
        # 상태 변수
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0
        self.wheelbase = 1.04 # ERP42 축거
        self.last_time = self.get_clock().now()

    def euler_to_quaternion(self, yaw):
        """방향각(Yaw)을 Odometry에 필요한 Quaternion 형식으로 변환"""
        q = Quaternion()
        q.x = 0.0
        q.y = 0.0
        q.z = math.sin(yaw / 2.0)
        q.w = math.cos(yaw / 2.0)
        return q

    def feedback_callback(self, msg):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9
        
        if dt <= 0: return

        # ERP42 데이터 (단위 변환 필요 시 여기서 수행)
        v = msg.speed 
        delta = msg.steer 

        # 위치 업데이트 (Dead Reckoning)
        self.x += v * math.cos(self.theta) * dt
        self.y += v * math.sin(self.theta) * dt
        self.theta += (v * math.tan(delta) / self.wheelbase) * dt

        # Odometry 메시지 생성
        odom = Odometry()
        odom.header.stamp = current_time.to_msg()
        odom.header.frame_id = "odom"       # 기준 좌표계
        odom.child_frame_id = "base_link"  # 로봇 좌표계

        # 위치 정보 채우기
        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.orientation = self.euler_to_quaternion(self.theta)

        # 속도 정보 채우기
        odom.twist.twist.linear.x = float(v)
        odom.twist.twist.angular.z = float(v * math.tan(delta) / self.wheelbase)

        # 발행!
        self.odom_pub.publish(odom)
        
        self.last_time = current_time

def main(args=None):
    rclpy.init(args=args)
    node = ERP42OdomPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()