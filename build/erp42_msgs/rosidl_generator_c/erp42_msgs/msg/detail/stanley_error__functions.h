// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice

#ifndef ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__FUNCTIONS_H_
#define ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "erp42_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "erp42_msgs/msg/detail/stanley_error__struct.h"

/// Initialize msg/StanleyError message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * erp42_msgs__msg__StanleyError
 * )) before or use
 * erp42_msgs__msg__StanleyError__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
bool
erp42_msgs__msg__StanleyError__init(erp42_msgs__msg__StanleyError * msg);

/// Finalize msg/StanleyError message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
void
erp42_msgs__msg__StanleyError__fini(erp42_msgs__msg__StanleyError * msg);

/// Create msg/StanleyError message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * erp42_msgs__msg__StanleyError__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
erp42_msgs__msg__StanleyError *
erp42_msgs__msg__StanleyError__create();

/// Destroy msg/StanleyError message.
/**
 * It calls
 * erp42_msgs__msg__StanleyError__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
void
erp42_msgs__msg__StanleyError__destroy(erp42_msgs__msg__StanleyError * msg);

/// Check for msg/StanleyError message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
bool
erp42_msgs__msg__StanleyError__are_equal(const erp42_msgs__msg__StanleyError * lhs, const erp42_msgs__msg__StanleyError * rhs);

/// Copy a msg/StanleyError message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
bool
erp42_msgs__msg__StanleyError__copy(
  const erp42_msgs__msg__StanleyError * input,
  erp42_msgs__msg__StanleyError * output);

/// Initialize array of msg/StanleyError messages.
/**
 * It allocates the memory for the number of elements and calls
 * erp42_msgs__msg__StanleyError__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
bool
erp42_msgs__msg__StanleyError__Sequence__init(erp42_msgs__msg__StanleyError__Sequence * array, size_t size);

/// Finalize array of msg/StanleyError messages.
/**
 * It calls
 * erp42_msgs__msg__StanleyError__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
void
erp42_msgs__msg__StanleyError__Sequence__fini(erp42_msgs__msg__StanleyError__Sequence * array);

/// Create array of msg/StanleyError messages.
/**
 * It allocates the memory for the array and calls
 * erp42_msgs__msg__StanleyError__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
erp42_msgs__msg__StanleyError__Sequence *
erp42_msgs__msg__StanleyError__Sequence__create(size_t size);

/// Destroy array of msg/StanleyError messages.
/**
 * It calls
 * erp42_msgs__msg__StanleyError__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
void
erp42_msgs__msg__StanleyError__Sequence__destroy(erp42_msgs__msg__StanleyError__Sequence * array);

/// Check for msg/StanleyError message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
bool
erp42_msgs__msg__StanleyError__Sequence__are_equal(const erp42_msgs__msg__StanleyError__Sequence * lhs, const erp42_msgs__msg__StanleyError__Sequence * rhs);

/// Copy an array of msg/StanleyError messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_erp42_msgs
bool
erp42_msgs__msg__StanleyError__Sequence__copy(
  const erp42_msgs__msg__StanleyError__Sequence * input,
  erp42_msgs__msg__StanleyError__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ERP42_MSGS__MSG__DETAIL__STANLEY_ERROR__FUNCTIONS_H_
