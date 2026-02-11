// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from erp42_msgs:msg/SerialFeedBack.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__STRUCT_H_
#define ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SerialFeedBack in the package erp42_msgs.
/**
  * Messages
 */
typedef struct erp42_msgs__msg__SerialFeedBack
{
  uint8_t mora;
  uint8_t estop;
  uint8_t gear;
  double speed;
  double steer;
  int16_t brake;
  int32_t encoder;
  uint8_t alive;
} erp42_msgs__msg__SerialFeedBack;

// Struct for a sequence of erp42_msgs__msg__SerialFeedBack.
typedef struct erp42_msgs__msg__SerialFeedBack__Sequence
{
  erp42_msgs__msg__SerialFeedBack * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} erp42_msgs__msg__SerialFeedBack__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ERP42_MSGS__MSG__DETAIL__SERIAL_FEED_BACK__STRUCT_H_
