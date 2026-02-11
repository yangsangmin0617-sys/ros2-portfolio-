import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import PoseStamped # PoseStamped 임포트 추가

class GpsToPosePublisher(Node):
    def __init__(self):
        super().__init__('gps_to_pose_node')
        
        # 1. 발행자 설정: PoseStamped 타입으로 'robot_pose' 토픽 발행
        self.publisher_ = self.create_publisher(PoseStamped, 'robot_pose', 10)
        
        # 2. 타이머 설정
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        msg = PoseStamped()

        # 1. Header 설정
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map' # 보통 Pose는 map 프레임을 기준으로 합니다.

        # 2. Position 설정 (위도/경도를 x, y로 매핑)
        # 실제로는 UTM 변환이 필요하지만, 테스트를 위해 값을 직접 넣습니다.
        msg.pose.position.x = 37.4967109 # 임시로 위도 값을 x에 대입
        msg.pose.position.y = 126.9573456 # 임시로 경도 값을 y에 대입
        msg.pose.position.z = 109.972    # 고도 값을 z에 대입

        # 3. Orientation 설정 (회전 정보 - 필수)
        # Pose에는 방향 정보가 꼭 있어야 합니다. '회전 없음' 상태로 설정합니다.
        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0
        msg.pose.orientation.w = 1.0

        # 발행
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing Pose: x={msg.pose.position.x}, y={msg.pose.position.y}, z={msg.pose.position.z}')

def main(args=None):
    rclpy.init(args=args)
    node = GpsToPosePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()