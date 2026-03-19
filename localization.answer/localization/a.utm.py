import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from nav_msgs.msg import Odometry
from pyproj import Transformer
import numpy as np
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

class GpsToOdomNode(Node):
    def __init__(self):
        super().__init__('gps_odom_publisher_node')
        
        # [QoS 설정]
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        )

        # 구독 설정
        self.subscription = self.create_subscription(
            NavSatFix, 
            '/ublox_gps_node/fix', 
            self.listener_callback, 
            qos_profile)
            
        self.odom_publisher = self.create_publisher(Odometry, '/gps_odom', 10)

        # UTM 변환기 설정
        self.transformer = Transformer.from_crs("epsg:4326", "epsg:32652")
        
        # [수정됨] 고정된 좌표 대신, 첫 데이터를 원점(0,0)으로 삼기 위한 변수
        self.is_first_gps = True
        self.anchor_x = 0.0
        self.anchor_y = 0.0
        
        self.get_logger().info('GPS Odom Node가 시작되었습니다.')

    def listener_callback(self, msg):
        if np.isnan(msg.latitude) or np.isnan(msg.longitude):
            self.get_logger().warn('수신된 GPS 값이 NaN입니다. 건너뜁니다.')
            return

        # 1. UTM 변환
        current_x, current_y = self.transformer.transform(msg.latitude, msg.longitude)

        # 2. [수정됨] 첫 GPS 데이터 수신 시, 그 위치를 영점(Anchor)으로 셋팅
        if self.is_first_gps:
            self.anchor_x = current_x
            self.anchor_y = current_y
            self.is_first_gps = False
            self.get_logger().info(f'--- [성공] 첫 GPS 위치를 시작점(0,0)으로 고정합니다! (X:{self.anchor_x:.2f}, Y:{self.anchor_y:.2f}) ---')

        # 3. 영점으로부터의 상대 거리 계산
        relative_x = current_x - self.anchor_x
        relative_y = current_y - self.anchor_y

        # 4. Odometry 메시지 발행 (TF는 EKF가 하므로 여기서는 제외)
        odom = Odometry()
        odom.header.stamp = msg.header.stamp
        odom.header.frame_id = 'map'
        odom.child_frame_id = 'base_link'
        
        odom.pose.pose.position.x = relative_x
        odom.pose.pose.position.y = relative_y
        odom.pose.pose.position.z = 0.0 
        odom.pose.pose.orientation.w = 1.0

        pose_covariance = np.zeros(36)
        pose_covariance[0] = 0.1
        pose_covariance[7] = 0.1
        pose_covariance[14] = 0.1
        odom.pose.covariance = pose_covariance.tolist()

        self.odom_publisher.publish(odom)

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