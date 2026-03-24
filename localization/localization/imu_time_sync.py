"""
[Node: imu_time_sync]

1. 역할: 
   - IMU 센서 하드웨어에서 발생하는 고유 타임스탬프(Hardware Uptime)를 시스템 시간(Wall-clock Time)으로 재발행(Re-stamping)함.
   - Bag 파일 재생 시 또는 센서 하드웨어 클럭과 PC 클럭이 동기화되지 않았을 때 발생하는 EKF의 타임아웃 문제를 해결함.

2. 데이터 흐름 (Input/Output):
   - 입력(Input): 
     * /imu/data (sensor_msgs/Imu): 센서 하드웨어 기준 타임스탬프를 가진 원본 데이터
   - 출력(Output): 
     * /imu/data/synced (sensor_msgs/Imu): 현재 시스템 시간(now())으로 동기화된 데이터

3. 주요 특징 및 필요성 (핵심 엔지니어링 근거):
   - EKF(Extended Kalman Filter)는 여러 센서 데이터를 시간순으로 정렬하여 처리하는데, 
     센서의 타임스탬프가 시스템 시간보다 과거이거나 너무 앞서면 데이터가 무시(Discard)됨.
   - 본 노드는 센서 데이터 수신 즉시 현재 시스템 시간을 부여함으로써, 
     로컬 EKF 및 글로벌 EKF가 실시간으로 센서 데이터를 융합할 수 있는 '시간적 일관성'을 보장함.
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu

class ImuTimeSyncNode(Node):

    def __init__(self):
        super().__init__('imu_time_sync')
        
        # 1. 원본 IMU 데이터 구독
        self.create_subscription(Imu, '/imu/data', self._on_imu, 10)
        
        # 2. 시스템 시간으로 동기화된 IMU 데이터 발행
        self._pub = self.create_publisher(Imu, '/imu/data/synced', 10)
        
        self.get_logger().info('IMU Time Synchronization Node Started: /imu/data → /imu/data/synced')

    def _on_imu(self, msg: Imu):
        """
        IMU 데이터가 수신될 때마다 호출되는 콜백 함수.
        기존 msg.header.stamp를 현재 ROS 2 시스템 시간으로 교체하여 발행함.
        """
        # 3. Re-stamping: 현재 노드의 시스템 시간을 메시지 헤더에 주입
        msg.header.stamp = self.get_clock().now().to_msg()
        
        # 4. 동기화된 메시지 발행
        self._pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = ImuTimeSyncNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()