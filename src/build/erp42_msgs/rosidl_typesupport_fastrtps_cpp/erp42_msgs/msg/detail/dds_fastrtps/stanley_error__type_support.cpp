// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice
#include "erp42_msgs/msg/detail/stanley_error__rosidl_typesupport_fastrtps_cpp.hpp"
#include "erp42_msgs/msg/detail/stanley_error__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace erp42_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
cdr_serialize(
  const erp42_msgs::msg::StanleyError & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ctr
  cdr << ros_message.ctr;
  // Member: hdr
  cdr << ros_message.hdr;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  erp42_msgs::msg::StanleyError & ros_message)
{
  // Member: ctr
  cdr >> ros_message.ctr;

  // Member: hdr
  cdr >> ros_message.hdr;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
get_serialized_size(
  const erp42_msgs::msg::StanleyError & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ctr
  {
    size_t item_size = sizeof(ros_message.ctr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hdr
  {
    size_t item_size = sizeof(ros_message.hdr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
max_serialized_size_StanleyError(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: ctr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hdr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = erp42_msgs::msg::StanleyError;
    is_plain =
      (
      offsetof(DataType, hdr) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _StanleyError__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const erp42_msgs::msg::StanleyError *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StanleyError__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<erp42_msgs::msg::StanleyError *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StanleyError__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const erp42_msgs::msg::StanleyError *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StanleyError__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_StanleyError(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _StanleyError__callbacks = {
  "erp42_msgs::msg",
  "StanleyError",
  _StanleyError__cdr_serialize,
  _StanleyError__cdr_deserialize,
  _StanleyError__get_serialized_size,
  _StanleyError__max_serialized_size
};

static rosidl_message_type_support_t _StanleyError__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StanleyError__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace erp42_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_erp42_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<erp42_msgs::msg::StanleyError>()
{
  return &erp42_msgs::msg::typesupport_fastrtps_cpp::_StanleyError__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, erp42_msgs, msg, StanleyError)() {
  return &erp42_msgs::msg::typesupport_fastrtps_cpp::_StanleyError__handle;
}

#ifdef __cplusplus
}
#endif
