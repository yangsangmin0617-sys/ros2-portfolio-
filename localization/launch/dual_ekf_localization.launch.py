"""
[Launch File: Dual EKF Localization with GPS]

1. 역할:
   - 두 개의 EKF 노드를 병렬로 실행하여 '연속성'과 '절대 위치'를 동시에 확보함.
   - TF Tree: map (절대좌표) -> odom (상대좌표) -> base_link (로봇)

2. 시스템 구성:
   A. local_ekf_node: 
      - 바퀴 오도메트리와 IMU를 융합하여 'odom -> base_link' 변환을 수행.
      - GPS 없이 연속적이고 부드러운 위치를 제공함 (Local Control용).
   B. global_ekf_node: 
      - GPS, 바퀴, IMU를 모두 융합하여 'map -> odom' 변환을 수행.
      - 누적 오차(Drift)를 GPS로 보정하여 지도상 절대 위치를 유지함.
   C. gps_odometry:
      - 위경도(NavSatFix)를 UTM 직교 좌표계(Odometry)로 변환함.

3. Static TF 정의 (센서 부착 위치):
   - IMU: 앞 1.0m, 위 0.5m
   - GPS: 앞 0.5m, 위 1.5m
   - LiDAR(Velodyne): 앞 1.0m, 위 1.0m
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def _launch_setup(context):
    pkg_share = get_package_share_directory('localization')
    ekf_local_config = os.path.join(pkg_share, 'config', 'ekf_local.yaml')
    ekf_global_config = os.path.join(pkg_share, 'config', 'ekf_global.yaml')

    use_sim_time = LaunchConfiguration('use_sim_time').perform(context).lower() == 'true'
    sync_imu = LaunchConfiguration('sync_imu').perform(context).lower() == 'true'

    # Bag 재생 시 타임스탬프 동기화를 위한 토픽 선택
    imu_topic = '/imu/data/synced' if sync_imu else '/imu/data'

    nodes = [
        # [Node 1] Wheel Odometry: ERP42 피드백 데이터를 이용한 기초 오도메트리 발행
        # Input: /erp42_feedback, Output: /odometry/wheel
        Node(
            package='localization',
            executable='wheel_odometry',
            name='wheel_odometry',
            output='screen',
            parameters=[{'pub_tf': False, 'use_sim_time': use_sim_time}],
        ),

        # [Node 2] EKF Local (Odom Frame): 끊김 없는 연속적 위치 추정
        # Input: /odometry/wheel, /imu/data, Output: /odometry/local, TF(odom->base_link)
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='local_ekf_node',
            output='screen',
            parameters=[ekf_local_config, {'use_sim_time': use_sim_time, 'imu0': imu_topic}],
            remappings=[
                ('odometry/filtered', '/odometry/local'),
                ('/set_pose', '/set_pose_local'),
                ('/diagnostics', '/diagnostics_local'),
            ],
        ),

        # [Node 3] EKF Global (Map Frame): GPS를 활용한 절대 좌표 보정
        # Input: /odometry/gps, /odometry/wheel, /imu/data, Output: /odometry/global, TF(map->odom)
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='global_ekf_node',
            output='screen',
            parameters=[ekf_global_config, {'use_sim_time': use_sim_time, 'imu0': imu_topic}],
            remappings=[
                ('odometry/filtered', '/odometry/global'),
                ('/set_pose', '/set_pose_global'),
                ('/diagnostics', '/diagnostics_global'),
            ],
        ),

        # [Node 4] GPS Odometry: 위경도 데이터를 EKF 입력용 XY 평면 좌표로 변환
        # Input: /ublox_gps_node/fix, Output: /odometry/gps
        Node(
            package='localization',
            executable='gps_odometry',
            name='gps_odometry',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
        ),

        # [Static TF Providers] 로봇 중심(base_link) 기준 각 센서의 물리적 오프셋 정의
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_imu',
            arguments=['1.0', '0', '0.5', '0', '0', '0', 'base_link', 'imu_link'],
            parameters=[{'use_sim_time': use_sim_time}],
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_gps',
            arguments=['0.5', '0', '1.5', '0', '0', '0', 'base_link', 'gps'],
            parameters=[{'use_sim_time': use_sim_time}],
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_velodyne',
            arguments=['1.0', '0', '1.0', '0', '0', '0', 'base_link', 'velodyne'],
            parameters=[{'use_sim_time': use_sim_time}],
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_encoder',
            arguments=['1.0', '-0.5', '0', '0', '0', '0', 'base_link', 'encoder_link'],
            parameters=[{'use_sim_time': use_sim_time}],
        ),
    ]

    # IMU 타임스탬프 동기화 노드 (Bag 재생 시 필수)
    if sync_imu:
        nodes.append(
            Node(
                package='localization',
                executable='imu_time_sync',
                name='imu_time_sync',
                output='screen',
                parameters=[{'use_sim_time': use_sim_time}],
            )
        )

    return nodes

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        DeclareLaunchArgument('sync_imu', default_value='false',
                              description='Re-stamp IMU to wall clock (for bag playback)'),
        OpaqueFunction(function=_launch_setup),
    ])