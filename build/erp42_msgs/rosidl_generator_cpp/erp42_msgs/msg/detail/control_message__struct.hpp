// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from erp42_msgs:msg/ControlMessage.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__STRUCT_HPP_
#define ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__erp42_msgs__msg__ControlMessage __attribute__((deprecated))
#else
# define DEPRECATED__erp42_msgs__msg__ControlMessage __declspec(deprecated)
#endif

namespace erp42_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControlMessage_
{
  using Type = ControlMessage_<ContainerAllocator>;

  explicit ControlMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mora = 0;
      this->estop = 0;
      this->gear = 0;
      this->speed = 0;
      this->steer = 0;
      this->brake = 0;
      this->alive = 0;
    }
  }

  explicit ControlMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mora = 0;
      this->estop = 0;
      this->gear = 0;
      this->speed = 0;
      this->steer = 0;
      this->brake = 0;
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
    uint16_t;
  _speed_type speed;
  using _steer_type =
    int16_t;
  _steer_type steer;
  using _brake_type =
    uint8_t;
  _brake_type brake;
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
    const uint16_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__steer(
    const int16_t & _arg)
  {
    this->steer = _arg;
    return *this;
  }
  Type & set__brake(
    const uint8_t & _arg)
  {
    this->brake = _arg;
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
    erp42_msgs::msg::ControlMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const erp42_msgs::msg::ControlMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      erp42_msgs::msg::ControlMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      erp42_msgs::msg::ControlMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__erp42_msgs__msg__ControlMessage
    std::shared_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__erp42_msgs__msg__ControlMessage
    std::shared_ptr<erp42_msgs::msg::ControlMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlMessage_ & other) const
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
    if (this->alive != other.alive) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlMessage_

// alias to use template instance with default allocator
using ControlMessage =
  erp42_msgs::msg::ControlMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace erp42_msgs

#endif  // ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__STRUCT_HPP_
