# 🏎️ ERP42 Autonomous Localization Project

본 프로젝트는 **ROS 2** 환경에서 자율주행 플랫폼(ERP42)의 정밀한 위치 추정을 위해 개발되었습니다. **Encoder, IMU, GPS** 데이터를 수학적으로 융합(EKF)하여 실외 주행 시 발생하는 누적 오차(Drift)를 최소화하고 안정적인 좌표계를 유지합니다.

---

## 📡 Sensor & Topic Specifications

### 1. Input Sensor Data (Raw)
| 센서 | 토픽 이름 | 메시지 타입 | 주요 활용 데이터 | 비고 |
| :--- | :--- | :--- | :--- | :--- |
| **ENCODER** | `/erp42_feedback` | `erp42_msgs/SerialFeedBack` | speed, steer, gear | Bicycle Model 기반 위치 추정 |
| **IMU** | `/imu/data` | `sensor_msgs/Imu` | orientation(Yaw), angular_velocity | 초기 Heading 정렬 및 회전 보정 |
| **GPS** | `/ublox_gps_node/fix` | `sensor_msgs/NavSatFix` | latitude, longitude | map 프레임 기준 절대 위치 보정 |

### 2. Processed & Output Topics
| 토픽 이름 | 메시지 타입 | 발행 노드 | 설명 |
| :--- | :--- | :--- | :--- |
| `/odom` | `nav_msgs/Odometry` | `wheel_odometry` | 바퀴 속도와 IMU 방향을 조합한 기초 오도메트리 |
| `/gps_odom` | `nav_msgs/Odometry` | `gps_odometry` | GPS 위경도를 미터(m) 단위 XY 좌표로 변환 |
| `/odometry/local` | `nav_msgs/Odometry` | **Local EKF** | 바퀴+IMU 융합, 부드러운 주행 경로 (odom 기준) |
| `/odometry/global` | `nav_msgs/Odometry` | **Global EKF** | GPS+바퀴+IMU 융합, 지도상 절대 위치 (map 기준) |

---

## 📐 System Architecture & TF Tree

### 1. TF(Transform) 구성
본 시스템은 정밀한 위치 추정을 위해 다음과 같은 TF 체계를 구축하였습니다.

* **Dynamic TF (동적 변환)**
    * **`map` → `odom`**: **Global EKF**가 발행하며, GPS를 이용해 누적 오차를 보정함.
    * **`odom` → `base_link`**: **Local EKF**가 발행하며, 로봇의 연속적인 이동량을 나타냄.
* **Static TF (정적 변환)**
    * **`base_link` → `imu_link` / `gps` / `velodyne`**: 센서의 물리적 설치 위치 정보를 정의함.



### 2. Timestamp 동기화 분석 (Engineering Report)
* **Q: Raw Sensor와 Odometry의 타임스탬프는 왜 같아야 하는가?**
* **A:** EKF는 여러 센서 데이터를 시간순으로 정렬하여 처리합니다. 타임스탬프가 일치하지 않으면 과거의 상태에 현재 측정값을 적용하게 되어 계산 오차가 발생합니다. 본 프로젝트는 `sync_imu:=true` 옵션과 `imu_time_sync` 노드를 통해 데이터 간의 **시간적 동기화(Temporal Synchronization)**를 보장합니다.

---

 🛠️ Installation & Usage
 
 1. Build
'''bash
# 워크스페이스 빌드
colcon build --symlink-install --packages-select localization
source install/setup.bash


## 🛰️ Sensor & Data Specifications

| 센서 | 토픽 이름 | 메시지 타입 | 주요 활용 데이터 | 비고 |
| :--- | :--- | :--- | :--- | :--- |
| **ENCODER** | `/erp42_feedback` | `erp42_msgs/SerialFeedBack` | speed, steer, gear | Bicycle Model 기반 위치 추정 |
| **IMU** | `/imu/data` | `sensor_msgs/Imu` | orientation(Yaw), angular_velocity | 초기 Heading 정렬 및 회전 보정 |
| **GPS** | `/ublox_gps_node/fix` | `sensor_msgs/NavSatFix` | latitude, longitude | map 프레임 기준 절대 위치 보정 |


실행 명령어 

colcon build

ros2 bag play ros2 bag play /home/yangsangmin/bagfile/rosbag2_2026_01_19-15_04_28 --topics /erp42_feedback /imu/data /ublox_gps_node/fix
(topic을 따로 적는 이유 tf를 백파일이 발행하고 있기 떄문에 지정해서 함)

ros2 launch localization dual_ekf_localization.launch.py sync_imu:=true

global ekf 실행결과



<img width="586" height="547" alt="스크린샷 2026-03-20 19-32-36" src="https://github.com/user-attachments/assets/2d91fd7e-76e9-4a66-9019-023edae2eb85" />



local ekf 실행결과(gps를 제외한 IMU, ENCODER를 사용한 코드)





<img width="586" height="547" alt="스크린샷 2026-03-20 20-16-54" src="https://github.com/user-attachments/assets/0d752753-5ed5-4627-ae92-dc77fa215a52" />





물론 당시 백파일 상황이 imu를 고정못했을 때이긴 하지만 오차와 흔들림이 감지된다는걸 확일 할 수 있음











