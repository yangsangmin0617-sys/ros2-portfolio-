// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__STRUCT_H_
#define ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/StanleyError in the package erp42_msgs.
/**
  * Messages
 */
typedef struct erp42_msgs__msg__StanleyError
{
  float ctr;
  float hdr;
} erp42_msgs__msg__StanleyError;

// Struct for a sequence of erp42_msgs__msg__StanleyError.
typedef struct erp42_msgs__msg__StanleyError__Sequence
{
  erp42_msgs__msg__StanleyError * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} erp42_msgs__msg__StanleyError__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__STRUCT_H_
