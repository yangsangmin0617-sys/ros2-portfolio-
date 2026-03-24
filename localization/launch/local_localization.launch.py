"""
[Launch File: Local Odometry Localization]

1. 역할: 
   - GPS 없이 Encoder와 IMU만을 활용하여 로봇의 연속적인 상대 위치(Odometry)를 추정함.
   - odom -> base_link 사이의 Dynamic TF를 발행함.

2. 노드 구성 및 데이터 흐름:
   A. wheel_odometry: 
      - Input: /erp42_feedback, /imu/data
      - Logic: Bicycle Kinematic Model 기반 기초 오도메트리 계산
      - Output: /odometry/wheel
   B. local_ekf_node (robot_localization):
      - Input: /odometry/wheel, /imu/data (또는 /imu/data/synced)
      - Logic: Extended Kalman Filter를 이용한 센서 퓨전
      - Output: /odometry/local, TF (odom -> base_link)
   C. imu_time_sync (Optional):
      - Input: /imu/data
      - Logic: Bag 재생 시 과거 IMU 타임스탬프를 현재 Wall-clock으로 재발행
      - Output: /imu/data/synced

3. Arguments:
   - use_sim_time: 시뮬레이션 환경 또는 bag 재생 시 true 설정
   - sync_imu: Bag 파일 재생 시 IMU 데이터의 타임스탬프 동기화 여부
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def _launch_setup(context):
    # 패키지 경로 및 설정 파일 로드
    pkg_share = get_package_share_directory('localization')
    ekf_config = os.path.join(pkg_share, 'config', 'ekf_local.yaml')

    # 실행 인자 값 파싱
    use_sim_time = LaunchConfiguration('use_sim_time').perform(context).lower() == 'true'
    sync_imu = LaunchConfiguration('sync_imu').perform(context).lower() == 'true'

    # 동기화 여부에 따른 IMU 구독 토픽 결정
    imu_topic = '/imu/data/synced' if sync_imu else '/imu/data'

    nodes = [
        # [Node 1] Wheel Odometry: 차량 피드백을 기반으로 기초 이동량 계산
        Node(
            package='localization',
            executable='wheel_odometry',
            name='wheel_odometry',
            output='screen',
            parameters=[{'pub_tf': False, 'use_sim_time': use_sim_time}],
        ),

        # [Node 2] Local EKF: 바퀴 속도와 IMU 방향 데이터를 융합하여 odom 프레임 생성
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='local_ekf_node',
            output='screen',
            # ekf_local.yaml 설정을 바탕으로 world_frame := odom 실행
            parameters=[ekf_config, {'use_sim_time': use_sim_time, 'imu0': imu_topic}],
            remappings=[('/odometry/filtered', '/odometry/local')]
        ),

        # [Node 3] Static TF: 로봇 중심(base_link)과 IMU 센서 사이의 고정 좌표 정의
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_imu',
            arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'imu_link'],
            parameters=[{'use_sim_time': use_sim_time}],
        ),
    ]

    # Bag 재생 모드일 경우 타임스탬프 동기화 노드 추가 실행
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
        DeclareLaunchArgument('use_sim_time', default_value='false', 
                              description='Use simulation (Gazebo) clock if true'),
        DeclareLaunchArgument('sync_imu', default_value='false',
                              description='Re-stamp IMU to wall clock for bag playback'),
        OpaqueFunction(function=_launch_setup),
    ])