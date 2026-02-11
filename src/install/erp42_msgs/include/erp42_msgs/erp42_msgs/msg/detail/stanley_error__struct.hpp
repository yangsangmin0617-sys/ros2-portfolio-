// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__STRUCT_HPP_
#define ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__erp42_msgs__msg__StanleyError __attribute__((deprecated))
#else
# define DEPRECATED__erp42_msgs__msg__StanleyError __declspec(deprecated)
#endif

namespace erp42_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StanleyError_
{
  using Type = StanleyError_<ContainerAllocator>;

  explicit StanleyError_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ctr = 0.0f;
      this->hdr = 0.0f;
    }
  }

  explicit StanleyError_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ctr = 0.0f;
      this->hdr = 0.0f;
    }
  }

  // field types and members
  using _ctr_type =
    float;
  _ctr_type ctr;
  using _hdr_type =
    float;
  _hdr_type hdr;

  // setters for named parameter idiom
  Type & set__ctr(
    const float & _arg)
  {
    this->ctr = _arg;
    return *this;
  }
  Type & set__hdr(
    const float & _arg)
  {
    this->hdr = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    erp42_msgs::msg::StanleyError_<ContainerAllocator> *;
  using ConstRawPtr =
    const erp42_msgs::msg::StanleyError_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      erp42_msgs::msg::StanleyError_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      erp42_msgs::msg::StanleyError_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__erp42_msgs__msg__StanleyError
    std::shared_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__erp42_msgs__msg__StanleyError
    std::shared_ptr<erp42_msgs::msg::StanleyError_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StanleyError_ & other) const
  {
    if (this->ctr != other.ctr) {
      return false;
    }
    if (this->hdr != other.hdr) {
      return false;
    }
    return true;
  }
  bool operator!=(const StanleyError_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StanleyError_

// alias to use template instance with default allocator
using StanleyError =
  erp42_msgs::msg::StanleyError_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace erp42_msgs

#endif  // ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__STRUCT_HPP_
