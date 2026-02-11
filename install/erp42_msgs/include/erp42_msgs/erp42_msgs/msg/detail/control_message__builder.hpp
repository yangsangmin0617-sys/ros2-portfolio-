// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from erp42_msgs:msg/ControlMessage.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__BUILDER_HPP_
#define ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "erp42_msgs/msg/detail/control_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace erp42_msgs
{

namespace msg
{

namespace builder
{

class Init_ControlMessage_alive
{
public:
  explicit Init_ControlMessage_alive(::erp42_msgs::msg::ControlMessage & msg)
  : msg_(msg)
  {}
  ::erp42_msgs::msg::ControlMessage alive(::erp42_msgs::msg::ControlMessage::_alive_type arg)
  {
    msg_.alive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

class Init_ControlMessage_brake
{
public:
  explicit Init_ControlMessage_brake(::erp42_msgs::msg::ControlMessage & msg)
  : msg_(msg)
  {}
  Init_ControlMessage_alive brake(::erp42_msgs::msg::ControlMessage::_brake_type arg)
  {
    msg_.brake = std::move(arg);
    return Init_ControlMessage_alive(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

class Init_ControlMessage_steer
{
public:
  explicit Init_ControlMessage_steer(::erp42_msgs::msg::ControlMessage & msg)
  : msg_(msg)
  {}
  Init_ControlMessage_brake steer(::erp42_msgs::msg::ControlMessage::_steer_type arg)
  {
    msg_.steer = std::move(arg);
    return Init_ControlMessage_brake(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

class Init_ControlMessage_speed
{
public:
  explicit Init_ControlMessage_speed(::erp42_msgs::msg::ControlMessage & msg)
  : msg_(msg)
  {}
  Init_ControlMessage_steer speed(::erp42_msgs::msg::ControlMessage::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_ControlMessage_steer(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

class Init_ControlMessage_gear
{
public:
  explicit Init_ControlMessage_gear(::erp42_msgs::msg::ControlMessage & msg)
  : msg_(msg)
  {}
  Init_ControlMessage_speed gear(::erp42_msgs::msg::ControlMessage::_gear_type arg)
  {
    msg_.gear = std::move(arg);
    return Init_ControlMessage_speed(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

class Init_ControlMessage_estop
{
public:
  explicit Init_ControlMessage_estop(::erp42_msgs::msg::ControlMessage & msg)
  : msg_(msg)
  {}
  Init_ControlMessage_gear estop(::erp42_msgs::msg::ControlMessage::_estop_type arg)
  {
    msg_.estop = std::move(arg);
    return Init_ControlMessage_gear(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

class Init_ControlMessage_mora
{
public:
  Init_ControlMessage_mora()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlMessage_estop mora(::erp42_msgs::msg::ControlMessage::_mora_type arg)
  {
    msg_.mora = std::move(arg);
    return Init_ControlMessage_estop(msg_);
  }

private:
  ::erp42_msgs::msg::ControlMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::erp42_msgs::msg::ControlMessage>()
{
  return erp42_msgs::msg::builder::Init_ControlMessage_mora();
}

}  // namespace erp42_msgs

#endif  // ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__BUILDER_HPP_
