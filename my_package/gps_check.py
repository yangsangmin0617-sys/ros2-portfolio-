import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix 

class GpsReceiver(Node):
    def __init__(self):
        super().__init__('gps_receiver_node')
        self.subscription = self.create_subscription(
            NavSatFix,
            '/ublox_gps_node/fix',  
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        lat = msg.latitude
        lon = msg.longitude
        self.get_logger().info(f'데이터 수신 성공! 위도: {lat}, 경도: {lon}')

def main(args=None):
    rclpy.init(args=args)
    node = GpsReceiver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()