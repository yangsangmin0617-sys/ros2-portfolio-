// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__TRAITS_HPP_
#define ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "erp42_msgs/msg/detail/stanley_error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace erp42_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const StanleyError & msg,
  std::ostream & out)
{
  out << "{";
  // member: ctr
  {
    out << "ctr: ";
    rosidl_generator_traits::value_to_yaml(msg.ctr, out);
    out << ", ";
  }

  // member: hdr
  {
    out << "hdr: ";
    rosidl_generator_traits::value_to_yaml(msg.hdr, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StanleyError & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ctr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ctr: ";
    rosidl_generator_traits::value_to_yaml(msg.ctr, out);
    out << "\n";
  }

  // member: hdr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hdr: ";
    rosidl_generator_traits::value_to_yaml(msg.hdr, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StanleyError & msg, bool use_flow_style = false)
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
  const erp42_msgs::msg::StanleyError & msg,
  std::ostream & out, size_t indentation = 0)
{
  erp42_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use erp42_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const erp42_msgs::msg::StanleyError & msg)
{
  return erp42_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<erp42_msgs::msg::StanleyError>()
{
  return "erp42_msgs::msg::StanleyError";
}

template<>
inline const char * name<erp42_msgs::msg::StanleyError>()
{
  return "erp42_msgs/msg/StanleyError";
}

template<>
struct has_fixed_size<erp42_msgs::msg::StanleyError>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<erp42_msgs::msg::StanleyError>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<erp42_msgs::msg::StanleyError>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__TRAITS_HPP_
