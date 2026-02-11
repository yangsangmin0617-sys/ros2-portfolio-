// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from erp42_msgs:msg/ControlMessage.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__TRAITS_HPP_
#define ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "erp42_msgs/msg/detail/control_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace erp42_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControlMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: mora
  {
    out << "mora: ";
    rosidl_generator_traits::value_to_yaml(msg.mora, out);
    out << ", ";
  }

  // member: estop
  {
    out << "estop: ";
    rosidl_generator_traits::value_to_yaml(msg.estop, out);
    out << ", ";
  }

  // member: gear
  {
    out << "gear: ";
    rosidl_generator_traits::value_to_yaml(msg.gear, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: steer
  {
    out << "steer: ";
    rosidl_generator_traits::value_to_yaml(msg.steer, out);
    out << ", ";
  }

  // member: brake
  {
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
    out << ", ";
  }

  // member: alive
  {
    out << "alive: ";
    rosidl_generator_traits::value_to_yaml(msg.alive, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControlMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mora
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mora: ";
    rosidl_generator_traits::value_to_yaml(msg.mora, out);
    out << "\n";
  }

  // member: estop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estop: ";
    rosidl_generator_traits::value_to_yaml(msg.estop, out);
    out << "\n";
  }

  // member: gear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gear: ";
    rosidl_generator_traits::value_to_yaml(msg.gear, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: steer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer: ";
    rosidl_generator_traits::value_to_yaml(msg.steer, out);
    out << "\n";
  }

  // member: brake
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
    out << "\n";
  }

  // member: alive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alive: ";
    rosidl_generator_traits::value_to_yaml(msg.alive, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControlMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace erp42_msgs

namespace rosidl_generator_traits
{

[[deprecated("use erp42_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const erp42_msgs::msg::ControlMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  erp42_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use erp42_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const erp42_msgs::msg::ControlMessage & msg)
{
  return erp42_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<erp42_msgs::msg::ControlMessage>()
{
  return "erp42_msgs::msg::ControlMessage";
}

template<>
inline const char * name<erp42_msgs::msg::ControlMessage>()
{
  return "erp42_msgs/msg/ControlMessage";
}

template<>
struct has_fixed_size<erp42_msgs::msg::ControlMessage>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<erp42_msgs::msg::ControlMessage>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<erp42_msgs::msg::ControlMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ERP42_MSGS__MSG__DETAIL__CONTROL_MESSAGE__TRAITS_HPP_
