import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix # GPS 메시지 타입 임포트

class GpsReceiver(Node):
    def __init__(self):
        super().__init__('gps_receiver_node')
        
        # 구독자(Subscriber) 설정
        # (타입, 토픽명, 콜백함수, 큐 사이즈)
        self.subscription = self.create_subscription(
            NavSatFix,
            '/ublox_gps_node/fix',  # 재생 중인 토픽명과 정확히 일치해야 함
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        # 데이터가 들어오면 실행되는 함수
        lat = msg.latitude
        lon = msg.longitude
        self.get_logger().info(f'데이터 수신 성공! 위도: {lat}, 경도: {lon}')

def main(args=None):
    rclpy.init(args=args)
    node = GpsReceiver()
    try:
        rclpy.spin(node) # 노드가 계속 실행되도록 유지
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()