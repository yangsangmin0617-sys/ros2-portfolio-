// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from erp42_msgs:msg/SerialFeedBack.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__BUILDER_HPP_
#define ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "erp42_msgs/msg/detail/serial_feed_back__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace erp42_msgs
{

namespace msg
{

namespace builder
{

class Init_SerialFeedBack_alive
{
public:
  explicit Init_SerialFeedBack_alive(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  ::erp42_msgs::msg::SerialFeedBack alive(::erp42_msgs::msg::SerialFeedBack::_alive_type arg)
  {
    msg_.alive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_encoder
{
public:
  explicit Init_SerialFeedBack_encoder(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  Init_SerialFeedBack_alive encoder(::erp42_msgs::msg::SerialFeedBack::_encoder_type arg)
  {
    msg_.encoder = std::move(arg);
    return Init_SerialFeedBack_alive(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_brake
{
public:
  explicit Init_SerialFeedBack_brake(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  Init_SerialFeedBack_encoder brake(::erp42_msgs::msg::SerialFeedBack::_brake_type arg)
  {
    msg_.brake = std::move(arg);
    return Init_SerialFeedBack_encoder(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_steer
{
public:
  explicit Init_SerialFeedBack_steer(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  Init_SerialFeedBack_brake steer(::erp42_msgs::msg::SerialFeedBack::_steer_type arg)
  {
    msg_.steer = std::move(arg);
    return Init_SerialFeedBack_brake(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_speed
{
public:
  explicit Init_SerialFeedBack_speed(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  Init_SerialFeedBack_steer speed(::erp42_msgs::msg::SerialFeedBack::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_SerialFeedBack_steer(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_gear
{
public:
  explicit Init_SerialFeedBack_gear(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  Init_SerialFeedBack_speed gear(::erp42_msgs::msg::SerialFeedBack::_gear_type arg)
  {
    msg_.gear = std::move(arg);
    return Init_SerialFeedBack_speed(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_estop
{
public:
  explicit Init_SerialFeedBack_estop(::erp42_msgs::msg::SerialFeedBack & msg)
  : msg_(msg)
  {}
  Init_SerialFeedBack_gear estop(::erp42_msgs::msg::SerialFeedBack::_estop_type arg)
  {
    msg_.estop = std::move(arg);
    return Init_SerialFeedBack_gear(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

class Init_SerialFeedBack_mora
{
public:
  Init_SerialFeedBack_mora()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SerialFeedBack_estop mora(::erp42_msgs::msg::SerialFeedBack::_mora_type arg)
  {
    msg_.mora = std::move(arg);
    return Init_SerialFeedBack_estop(msg_);
  }

private:
  ::erp42_msgs::msg::SerialFeedBack msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::erp42_msgs::msg::SerialFeedBack>()
{
  return erp42_msgs::msg::builder::Init_SerialFeedBack_mora();
}

}  // namespace erp42_msgs

#endif  // ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__BUILDER_HPP_
