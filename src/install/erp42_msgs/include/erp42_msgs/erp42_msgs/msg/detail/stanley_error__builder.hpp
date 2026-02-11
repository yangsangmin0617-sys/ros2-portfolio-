// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__BUILDER_HPP_
#define ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "erp42_msgs/msg/detail/stanley_error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace erp42_msgs
{

namespace msg
{

namespace builder
{

class Init_StanleyError_hdr
{
public:
  explicit Init_StanleyError_hdr(::erp42_msgs::msg::StanleyError & msg)
  : msg_(msg)
  {}
  ::erp42_msgs::msg::StanleyError hdr(::erp42_msgs::msg::StanleyError::_hdr_type arg)
  {
    msg_.hdr = std::move(arg);
    return std::move(msg_);
  }

private:
  ::erp42_msgs::msg::StanleyError msg_;
};

class Init_StanleyError_ctr
{
public:
  Init_StanleyError_ctr()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StanleyError_hdr ctr(::erp42_msgs::msg::StanleyError::_ctr_type arg)
  {
    msg_.ctr = std::move(arg);
    return Init_StanleyError_hdr(msg_);
  }

private:
  ::erp42_msgs::msg::StanleyError msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::erp42_msgs::msg::StanleyError>()
{
  return erp42_msgs::msg::builder::Init_StanleyError_ctr();
}

}  // namespace erp42_msgs

#endif  // ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__BUILDER_HPP_
