import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def _launch_setup(context):
    pkg_share = get_package_share_directory('localization')
    
    # 1. 두 개의 YAML 파일 경로 설정
    local_config = os.path.join(pkg_share, 'config', 'ekf_local.yaml')
    global_config = os.path.join(pkg_share, 'config', 'ekf_global.yaml')

    use_sim_time = LaunchConfiguration('use_sim_time').perform(context).lower() == 'true'
    sync_imu = LaunchConfiguration('sync_imu').perform(context).lower() == 'true'
    imu_topic = '/imu/data/synced' if sync_imu else '/imu/data'

    nodes = [
        # [노드 1] 바퀴 오도메트리 파이썬 노드
        Node(
            package='localization',
            executable='wheel_odometry',
            name='wheel_odometry',
            output='screen',
            parameters=[{'pub_tf': False, 'use_sim_time': use_sim_time}],
        ),
        
        # [노드 2] Local EKF (odom 프레임 생성)
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_local_node', # 이름 구분
            output='screen',
            parameters=[local_config, {'use_sim_time': use_sim_time, 'imu0': imu_topic}],
            remappings=[('odometry/filtered', 'odometry/local')] # 토픽 이름 구분
        ),

        # [노드 3] Global EKF (map 프레임 생성 + GPS 퓨전)
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_global_node', # 이름 구분
            output='screen',
            parameters=[global_config, {'use_sim_time': use_sim_time, 'imu0': imu_topic}],
            remappings=[('odometry/filtered', 'odometry/global')] # 토픽 이름 구분
        ),

        # [노드 4] UTM 변환 노드 (상민님이 아까 수정한 파이썬 코드)
        Node(
            package='localization',
            executable='utm_node', # 상민님의 GPS 변환 실행파일 이름
            name='utm_node',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time}],
        ),

        # [노드 5] Static TF (base_link와 imu 위치 맞춤)
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_imu',
            arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'imu_link'],
            parameters=[{'use_sim_time': use_sim_time}],
        ),
    ]

    if sync_imu:
        nodes.append(
            Node(package='localization', executable='imu_time_sync', name='imu_time_sync',
                 output='screen', parameters=[{'use_sim_time': use_sim_time}])
        )

    return nodes

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='false'),
        DeclareLaunchArgument('sync_imu', default_value='true'),
        OpaqueFunction(function=_launch_setup),
    ])