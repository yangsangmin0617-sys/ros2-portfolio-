"""
[Node: gps_odometry]

1. 역할: 
   - GPS의 위도/경도(WGS84) 데이터를 UTM(Universal Transverse Mercator) 좌표계로 변환함.
   - 변환된 UTM 좌표에서 미리 정의된 'Map Anchor(Datum)' 값을 차감하여, 
     지도 원점(0,0) 기준의 로컬 미터(m) 단위 좌표를 생성함.

2. 데이터 흐름 (Input/Output):
   - 입력(Input): 
     * /ublox_gps_node/fix (sensor_msgs/NavSatFix): GPS 위도, 경도 및 공분산 데이터
     * config/map_anchor.yaml: 지도의 원점이 될 위도/경도 기준점
   - 출력(Output): 
     * /odometry/gps (nav_msgs/Odometry): 'map' 프레임 기준의 x, y 좌표

3. 주요 특징:
   - 전 지구적 좌표인 UTM을 그대로 쓰지 않고, Anchor 기반의 상대 좌표를 계산하여 EKF 연산 시 수치적 정밀도를 확보함.
   - GPS 수신기의 상태(msg.status.status)를 확인하여 유효한 데이터만 처리함.
   - GPS 센서 자체의 위치 공분산(Position Covariance)을 Odometry 메시지에 반영하여 EKF의 가중치 조절에 기여함.
"""

import os
import utm
import yaml
import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory
from nav_msgs.msg import Odometry
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Quaternion

class GpsOdometryNode(Node):

    def __init__(self):
        super().__init__('gps_odometry')

        # 1. 외부 설정 파일(map_anchor.yaml)로부터 지도의 원점 좌표(Datum) 로드
        # 이를 통해 코드 수정 없이 테스트 장소에 맞춰 원점을 변경할 수 있음 (유지보수성 향상)
        pkg_share = get_package_share_directory('localization')
        anchor_path = os.path.join(pkg_share, 'config', 'map_anchor.yaml')
        
        try:
            with open(anchor_path, 'r') as f:
                anchor = yaml.safe_load(f)
            datum_lat = anchor['latitude']
            datum_lon = anchor['longitude']
        except Exception as e:
            self.get_logger().error(f'Failed to load map_anchor.yaml: {e}')
            return

        # 2. 로드된 Datum 위경도를 UTM 직교 좌표계(미터 단위)의 원점으로 변환
        self._datum_e, self._datum_n, self._zone_number, self._zone_letter = \
            utm.from_latlon(datum_lat, datum_lon)

        self.get_logger().info(
            f'Map Origin Fixed (Datum): lat={datum_lat:.6f}, lon={datum_lon:.6f} '
            f'→ UTM Zone {self._zone_number}{self._zone_letter} '
            f'Reference E={self._datum_e:.2f}, N={self._datum_n:.2f}'
        )

        # 3. ROS 2 통신 설정
        # GPS 원시 데이터를 구독하고, 변환된 로컬 오도메트리를 발행함
        self.create_subscription(NavSatFix, '/ublox_gps_node/fix', self._on_fix, 10)
        self._odom_pub = self.create_publisher(Odometry, '/odometry/gps', 10)

    def _on_fix(self, msg: NavSatFix):
        # GPS 신호가 유효하지 않으면(No Fix) 처리를 중단함
        if msg.status.status < 0:
            return

        # 4. 현재 GPS 위치를 UTM 좌표로 변환
        # force_zone 설정을 통해 Datum과 동일한 UTM Zone 내에서 계산되도록 보장함
        e, n, _, _ = utm.from_latlon(msg.latitude, msg.longitude,
                                     force_zone_number=self._zone_number,
                                     force_zone_letter=self._zone_letter)
        
        # 5. Datum 기준 상대 좌표 계산 (최종 x, y)
        # x: 동쪽(Easting) 방향 이동량, y: 북쪽(Northing) 방향 이동량
        x = e - self._datum_e
        y = n - self._datum_n

        # 6. Odometry 메시지 구성 및 발행
        odom = Odometry()
        odom.header.stamp = msg.header.stamp
        odom.header.frame_id = 'map'        # 절대 좌표계 기준
        odom.child_frame_id = 'base_link'

        odom.pose.pose.position.x = x
        odom.pose.pose.position.y = y
        odom.pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)

        # 7. 공분산(Covariance) 설정: GPS 센서의 정밀도 정보를 EKF에 전달
        # GPS 데이터가 튈 경우(높은 공분산) EKF가 이를 인지하여 반영 비중을 낮춤
        cov36 = [0.0] * 36
        if len(msg.position_covariance) == 9:
            # NavSatFix의 ENU 좌표계 공분산을 Odometry 6x6 행렬에 매핑
            cov36[0] = msg.position_covariance[0]   # East 오차
            cov36[7] = msg.position_covariance[4]   # North 오차
        else:
            # 공분산 정보가 없을 경우 기본값으로 큰 불확실성 부여
            cov36[0] = 10.0
            cov36[7] = 10.0
            
        # 2D 주행이므로 무관한 축(Z, Roll, Pitch, Yaw)에는 매우 큰 오차값을 부여하여 무시하도록 함
        cov36[14] = 1e6
        cov36[21] = 1e6
        cov36[28] = 1e6
        cov36[35] = 1e6
        odom.pose.covariance = cov36

        self._odom_pub.publish(odom)

def main(args=None):
    rclpy.init(args=args)
    node = GpsOdometryNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()