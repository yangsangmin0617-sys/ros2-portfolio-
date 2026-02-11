// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from erp42_msgs:msg/SerialFeedBack.idl
// generated code does not contain a copyright notice
#include "erp42_msgs/msg/detail/serial_feed_back__rosidl_typesupport_fastrtps_cpp.hpp"
#include "erp42_msgs/msg/detail/serial_feed_back__struct.hpp"

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
  const erp42_msgs::msg::SerialFeedBack & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mora
  cdr << ros_message.mora;
  // Member: estop
  cdr << ros_message.estop;
  // Member: gear
  cdr << ros_message.gear;
  // Member: speed
  cdr << ros_message.speed;
  // Member: steer
  cdr << ros_message.steer;
  // Member: brake
  cdr << ros_message.brake;
  // Member: encoder
  cdr << ros_message.encoder;
  // Member: alive
  cdr << ros_message.alive;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  erp42_msgs::msg::SerialFeedBack & ros_message)
{
  // Member: mora
  cdr >> ros_message.mora;

  // Member: estop
  cdr >> ros_message.estop;

  // Member: gear
  cdr >> ros_message.gear;

  // Member: speed
  cdr >> ros_message.speed;

  // Member: steer
  cdr >> ros_message.steer;

  // Member: brake
  cdr >> ros_message.brake;

  // Member: encoder
  cdr >> ros_message.encoder;

  // Member: alive
  cdr >> ros_message.alive;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
get_serialized_size(
  const erp42_msgs::msg::SerialFeedBack & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mora
  {
    size_t item_size = sizeof(ros_message.mora);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: estop
  {
    size_t item_size = sizeof(ros_message.estop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gear
  {
    size_t item_size = sizeof(ros_message.gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed
  {
    size_t item_size = sizeof(ros_message.speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steer
  {
    size_t item_size = sizeof(ros_message.steer);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: brake
  {
    size_t item_size = sizeof(ros_message.brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: encoder
  {
    size_t item_size = sizeof(ros_message.encoder);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: alive
  {
    size_t item_size = sizeof(ros_message.alive);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_erp42_msgs
max_serialized_size_SerialFeedBack(
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


  // Member: mora
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: estop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: steer
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: brake
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: encoder
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alive
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = erp42_msgs::msg::SerialFeedBack;
    is_plain =
      (
      offsetof(DataType, alive) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SerialFeedBack__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const erp42_msgs::msg::SerialFeedBack *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SerialFeedBack__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<erp42_msgs::msg::SerialFeedBack *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SerialFeedBack__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const erp42_msgs::msg::SerialFeedBack *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SerialFeedBack__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SerialFeedBack(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SerialFeedBack__callbacks = {
  "erp42_msgs::msg",
  "SerialFeedBack",
  _SerialFeedBack__cdr_serialize,
  _SerialFeedBack__cdr_deserialize,
  _SerialFeedBack__get_serialized_size,
  _SerialFeedBack__max_serialized_size
};

static rosidl_message_type_support_t _SerialFeedBack__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SerialFeedBack__callbacks,
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
get_message_type_support_handle<erp42_msgs::msg::SerialFeedBack>()
{
  return &erp42_msgs::msg::typesupport_fastrtps_cpp::_SerialFeedBack__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, erp42_msgs, msg, SerialFeedBack)() {
  return &erp42_msgs::msg::typesupport_fastrtps_cpp::_SerialFeedBack__handle;
}

#ifdef __cplusplus
}
#endif
