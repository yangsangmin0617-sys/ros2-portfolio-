import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from nav_msgs.msg import Odometry
from pyproj import Transformer
import numpy as np
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
# TF 관련 라이브러리 추가
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped

class GpsToOdomNode(Node):
    def __init__(self):
        super().__init__('gps_odom_publisher_node')
        
        # [QoS 수정] 대부분의 GPS 센서와 백파일(Best Effort) 데이터에 대응하기 위한 설정
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        )

        # 구독 설정 (QoS 적용)
        self.subscription = self.create_subscription(
            NavSatFix, 
            '/ublox_gps_node/fix', 
            self.listener_callback, 
            qos_profile)
            
        self.odom_publisher = self.create_publisher(Odometry, '/gps_odom', 10)
        
        # TF Broadcaster 초기화 (RViz 시각화 필수)
        self.tf_broadcaster = TransformBroadcaster(self)

        # UTM 변환기 및 기준점 설정
        self.transformer = Transformer.from_crs("epsg:4326", "epsg:32652")
        self.anchor_lat = 37.239
        self.anchor_lon = 126.773
        self.anchor_x, self.anchor_y = self.transformer.transform(self.anchor_lat, self.anchor_lon)
        
        self.get_logger().info('GPS Odom Node(BEST_EFFORT)가 시작되었습니다.')
        self.get_logger().info('/ublox_gps_node/fix 토픽으로부터 데이터를 기다리는 중...')

    def listener_callback(self, msg):
        # 데이터가 들어오면 무조건 로그를 출력하여 통신 여부 확인
        self.get_logger().info(f'--- 데이터 수신됨! (Lat: {msg.latitude:.6f}, Lon: {msg.longitude:.6f}) ---')

        if np.isnan(msg.latitude) or np.isnan(msg.longitude):
            self.get_logger().warn('수신된 GPS 값이 NaN입니다. 데이터를 건너뜁니다.')
            return

        # UTM 변환
        current_x, current_y = self.transformer.transform(msg.latitude, msg.longitude)

        # 상대 좌표 계산
        relative_x = current_x - self.anchor_x
        relative_y = current_y - self.anchor_y

        # 1. Odometry 메시지 발행
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

        # 2. TF 데이터 발행 (RViz2에서 로봇의 위치를 물리적으로 이동시킴)
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
