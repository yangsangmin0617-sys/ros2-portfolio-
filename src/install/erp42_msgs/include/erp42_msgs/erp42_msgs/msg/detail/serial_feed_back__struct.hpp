// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from erp42_msgs:msg/SerialFeedBack.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__STRUCT_HPP_
#define ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__erp42_msgs__msg__SerialFeedBack __attribute__((deprecated))
#else
# define DEPRECATED__erp42_msgs__msg__SerialFeedBack __declspec(deprecated)
#endif

namespace erp42_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SerialFeedBack_
{
  using Type = SerialFeedBack_<ContainerAllocator>;

  explicit SerialFeedBack_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mora = 0;
      this->estop = 0;
      this->gear = 0;
      this->speed = 0.0;
      this->steer = 0.0;
      this->brake = 0;
      this->encoder = 0l;
      this->alive = 0;
    }
  }

  explicit SerialFeedBack_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mora = 0;
      this->estop = 0;
      this->gear = 0;
      this->speed = 0.0;
      this->steer = 0.0;
      this->brake = 0;
      this->encoder = 0l;
      this->alive = 0;
    }
  }

  // field types and members
  using _mora_type =
    uint8_t;
  _mora_type mora;
  using _estop_type =
    uint8_t;
  _estop_type estop;
  using _gear_type =
    uint8_t;
  _gear_type gear;
  using _speed_type =
    double;
  _speed_type speed;
  using _steer_type =
    double;
  _steer_type steer;
  using _brake_type =
    int16_t;
  _brake_type brake;
  using _encoder_type =
    int32_t;
  _encoder_type encoder;
  using _alive_type =
    uint8_t;
  _alive_type alive;

  // setters for named parameter idiom
  Type & set__mora(
    const uint8_t & _arg)
  {
    this->mora = _arg;
    return *this;
  }
  Type & set__estop(
    const uint8_t & _arg)
  {
    this->estop = _arg;
    return *this;
  }
  Type & set__gear(
    const uint8_t & _arg)
  {
    this->gear = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__steer(
    const double & _arg)
  {
    this->steer = _arg;
    return *this;
  }
  Type & set__brake(
    const int16_t & _arg)
  {
    this->brake = _arg;
    return *this;
  }
  Type & set__encoder(
    const int32_t & _arg)
  {
    this->encoder = _arg;
    return *this;
  }
  Type & set__alive(
    const uint8_t & _arg)
  {
    this->alive = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    erp42_msgs::msg::SerialFeedBack_<ContainerAllocator> *;
  using ConstRawPtr =
    const erp42_msgs::msg::SerialFeedBack_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      erp42_msgs::msg::SerialFeedBack_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      erp42_msgs::msg::SerialFeedBack_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__erp42_msgs__msg__SerialFeedBack
    std::shared_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__erp42_msgs__msg__SerialFeedBack
    std::shared_ptr<erp42_msgs::msg::SerialFeedBack_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SerialFeedBack_ & other) const
  {
    if (this->mora != other.mora) {
      return false;
    }
    if (this->estop != other.estop) {
      return false;
    }
    if (this->gear != other.gear) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->steer != other.steer) {
      return false;
    }
    if (this->brake != other.brake) {
      return false;
    }
    if (this->encoder != other.encoder) {
      return false;
    }
    if (this->alive != other.alive) {
      return false;
    }
    return true;
  }
  bool operator!=(const SerialFeedBack_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SerialFeedBack_

// alias to use template instance with default allocator
using SerialFeedBack =
  erp42_msgs::msg::SerialFeedBack_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace erp42_msgs

#endif  // ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__STRUCT_HPP_
