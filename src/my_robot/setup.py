from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'my_robot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # [수정 부분] 시스템이 config 폴더 안의 yaml 파일을 찾을 수 있게 등록합니다.
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yangsangmin',
    maintainer_email='yangsangmin@todo.todo',
    description='ERP42 EKF Localization Package',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # [수정 부분] 터미널에서 odom_predictor라고 치면 실행되도록 등록합니다.
            'odom_predictor = my_robot.odom_predictor:main',
        ],
    },
)