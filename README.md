1.localization
encoder, imu, gps를 활용해서 정밀한 위치추정을 위한 패키지입니다. 각 센서들을 융합하여 오차값을 최소화 합니다.

2.센서토픽
erp42_feedback: ERP42 플랫폼의 현재 속도, 조향각(Steer), 기어 상태 정보.
/imu/data: IMU 센서의 가속도, 각속도 및 절대 방향(Quaternion) 정보.
/ublox_gps_node/fix: GPS 수신기에서 들어오는 위도(Latitude), 경도(Longitude) 정보.
/odom: wheel_odometry 노드가 발행. 바퀴 속도와 IMU 방향을 조합한 기초 오도메트리.
/gps_odom: gps_odometry (또는 utm_node)가 발행. GPS 위경도를 미터(m) 단위의 XY 좌표로 변환한 데이터.
/odometry/local: Local EKF의 결과물. 바퀴+IMU를 융합하여 부드러운 주행 경로를 보여줍니다. (odom 프레임 기준)
/odometry/global: Global EKF의 결과물. GPS까지 합쳐져 지도상의 절대 위치를 나타냅니다. (map 프레임 기준)
