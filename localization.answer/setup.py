from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'localization'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # [수정 1] config 폴더 안의 모든 yaml 파일을 설치하도록 변경
        ('share/' + package_name + '/config', glob('config/*.yaml')),
        # [수정 2] launch 폴더 안의 모든 launch 파일을 설치하도록 변경 (선택사항)
        ('share/' + package_name + '/launch', glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jinju',
    maintainer_email='wnwlswn23@gmail.com',
    description='ERP42 wheel odometry + EKF sensor fusion (robot_localization)',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'wheel_odometry = localization.wheel_odometry:main',
            'imu_time_sync = localization.imu_time_sync:main',
            # 추가: utm.py 파일을 'utm_node'라는 명령어로 실행하도록 등록
            'utm_node = localization.utm:main', 
        ],
    },
)