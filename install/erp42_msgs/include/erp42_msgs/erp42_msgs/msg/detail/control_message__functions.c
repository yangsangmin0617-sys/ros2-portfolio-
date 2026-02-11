// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from erp42_msgs:msg/ControlMessage.idl
// generated code does not contain a copyright notice
#include "erp42_msgs/msg/detail/control_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
erp42_msgs__msg__ControlMessage__init(erp42_msgs__msg__ControlMessage * msg)
{
  if (!msg) {
    return false;
  }
  // mora
  // estop
  // gear
  // speed
  // steer
  // brake
  // alive
  return true;
}

void
erp42_msgs__msg__ControlMessage__fini(erp42_msgs__msg__ControlMessage * msg)
{
  if (!msg) {
    return;
  }
  // mora
  // estop
  // gear
  // speed
  // steer
  // brake
  // alive
}

bool
erp42_msgs__msg__ControlMessage__are_equal(const erp42_msgs__msg__ControlMessage * lhs, const erp42_msgs__msg__ControlMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mora
  if (lhs->mora != rhs->mora) {
    return false;
  }
  // estop
  if (lhs->estop != rhs->estop) {
    return false;
  }
  // gear
  if (lhs->gear != rhs->gear) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // steer
  if (lhs->steer != rhs->steer) {
    return false;
  }
  // brake
  if (lhs->brake != rhs->brake) {
    return false;
  }
  // alive
  if (lhs->alive != rhs->alive) {
    return false;
  }
  return true;
}

bool
erp42_msgs__msg__ControlMessage__copy(
  const erp42_msgs__msg__ControlMessage * input,
  erp42_msgs__msg__ControlMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // mora
  output->mora = input->mora;
  // estop
  output->estop = input->estop;
  // gear
  output->gear = input->gear;
  // speed
  output->speed = input->speed;
  // steer
  output->steer = input->steer;
  // brake
  output->brake = input->brake;
  // alive
  output->alive = input->alive;
  return true;
}

erp42_msgs__msg__ControlMessage *
erp42_msgs__msg__ControlMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  erp42_msgs__msg__ControlMessage * msg = (erp42_msgs__msg__ControlMessage *)allocator.allocate(sizeof(erp42_msgs__msg__ControlMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(erp42_msgs__msg__ControlMessage));
  bool success = erp42_msgs__msg__ControlMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
erp42_msgs__msg__ControlMessage__destroy(erp42_msgs__msg__ControlMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    erp42_msgs__msg__ControlMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
erp42_msgs__msg__ControlMessage__Sequence__init(erp42_msgs__msg__ControlMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  erp42_msgs__msg__ControlMessage * data = NULL;

  if (size) {
    data = (erp42_msgs__msg__ControlMessage *)allocator.zero_allocate(size, sizeof(erp42_msgs__msg__ControlMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = erp42_msgs__msg__ControlMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        erp42_msgs__msg__ControlMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
erp42_msgs__msg__ControlMessage__Sequence__fini(erp42_msgs__msg__ControlMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      erp42_msgs__msg__ControlMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

erp42_msgs__msg__ControlMessage__Sequence *
erp42_msgs__msg__ControlMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  erp42_msgs__msg__ControlMessage__Sequence * array = (erp42_msgs__msg__ControlMessage__Sequence *)allocator.allocate(sizeof(erp42_msgs__msg__ControlMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = erp42_msgs__msg__ControlMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
erp42_msgs__msg__ControlMessage__Sequence__destroy(erp42_msgs__msg__ControlMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    erp42_msgs__msg__ControlMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
erp42_msgs__msg__ControlMessage__Sequence__are_equal(const erp42_msgs__msg__ControlMessage__Sequence * lhs, const erp42_msgs__msg__ControlMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!erp42_msgs__msg__ControlMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
erp42_msgs__msg__ControlMessage__Sequence__copy(
  const erp42_msgs__msg__ControlMessage__Sequence * input,
  erp42_msgs__msg__ControlMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(erp42_msgs__msg__ControlMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    erp42_msgs__msg__ControlMessage * data =
      (erp42_msgs__msg__ControlMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!erp42_msgs__msg__ControlMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          erp42_msgs__msg__ControlMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!erp42_msgs__msg__ControlMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
