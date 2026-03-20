ros2 환경에서 자율주행 플랫폼의 정밀한 위치 추정을 위해 개발되었습니다. ENCODER, IMU, GPS 데이터를 수학적으로 융합하여 실외 주행시 발생하는 오차를 최소화 하고 안정적인 좌표계를 유지합니다.

/erp42_feedback: ERP42 플랫폼의 현재 속도, 조향각(Steer), 기어 상태 정보.
/imu/data: IMU 센서의 가속도, 각속도 및 절대 방향(Quaternion) 정보.
/ublox_gps_node/fix: GPS 수신기에서 들어오는 위도(Latitude), 경도(Longitude) 정보.
/odom: wheel_odometry 노드가 발행. 바퀴 속도와 IMU 방향을 조합한 기초 오도메트리.
/gps_odom: gps_odometry (또는 utm_node)가 발행. GPS 위경도를 미터(m) 단위의 XY 좌표로 변환한 데이터
/odometry/local: Local EKF의 결과물. 바퀴+IMU를 융합하여 부드러운 주행 경로를 보여줍니다. (odom 프레임 기준)
/odometry/global: Global EKF의 결과물. GPS까지 합쳐져 지도상의 절대 위치를 나타냅니다. (map 프레임 기준)

좌표변환
map -> odom: Global EKF가 발행 (GPS 보정치).
odom -> base_link: Local EKF가 발행 (연속적인 이동량).
base_link -> imu_link / gps / velodyne: static_transform_publisher가 발행하는 센서 설치 위치 정보.

실행 명령어

colcon build

ros2 bag play 

