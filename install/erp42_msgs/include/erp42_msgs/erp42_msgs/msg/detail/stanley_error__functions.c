// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice
#include "erp42_msgs/msg/detail/stanley_error__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
erp42_msgs__msg__StanleyError__init(erp42_msgs__msg__StanleyError * msg)
{
  if (!msg) {
    return false;
  }
  // ctr
  // hdr
  return true;
}

void
erp42_msgs__msg__StanleyError__fini(erp42_msgs__msg__StanleyError * msg)
{
  if (!msg) {
    return;
  }
  // ctr
  // hdr
}

bool
erp42_msgs__msg__StanleyError__are_equal(const erp42_msgs__msg__StanleyError * lhs, const erp42_msgs__msg__StanleyError * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ctr
  if (lhs->ctr != rhs->ctr) {
    return false;
  }
  // hdr
  if (lhs->hdr != rhs->hdr) {
    return false;
  }
  return true;
}

bool
erp42_msgs__msg__StanleyError__copy(
  const erp42_msgs__msg__StanleyError * input,
  erp42_msgs__msg__StanleyError * output)
{
  if (!input || !output) {
    return false;
  }
  // ctr
  output->ctr = input->ctr;
  // hdr
  output->hdr = input->hdr;
  return true;
}

erp42_msgs__msg__StanleyError *
erp42_msgs__msg__StanleyError__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  erp42_msgs__msg__StanleyError * msg = (erp42_msgs__msg__StanleyError *)allocator.allocate(sizeof(erp42_msgs__msg__StanleyError), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(erp42_msgs__msg__StanleyError));
  bool success = erp42_msgs__msg__StanleyError__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
erp42_msgs__msg__StanleyError__destroy(erp42_msgs__msg__StanleyError * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    erp42_msgs__msg__StanleyError__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
erp42_msgs__msg__StanleyError__Sequence__init(erp42_msgs__msg__StanleyError__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  erp42_msgs__msg__StanleyError * data = NULL;

  if (size) {
    data = (erp42_msgs__msg__StanleyError *)allocator.zero_allocate(size, sizeof(erp42_msgs__msg__StanleyError), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = erp42_msgs__msg__StanleyError__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        erp42_msgs__msg__StanleyError__fini(&data[i - 1]);
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
erp42_msgs__msg__StanleyError__Sequence__fini(erp42_msgs__msg__StanleyError__Sequence * array)
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
      erp42_msgs__msg__StanleyError__fini(&array->data[i]);
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

erp42_msgs__msg__StanleyError__Sequence *
erp42_msgs__msg__StanleyError__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  erp42_msgs__msg__StanleyError__Sequence * array = (erp42_msgs__msg__StanleyError__Sequence *)allocator.allocate(sizeof(erp42_msgs__msg__StanleyError__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = erp42_msgs__msg__StanleyError__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
erp42_msgs__msg__StanleyError__Sequence__destroy(erp42_msgs__msg__StanleyError__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    erp42_msgs__msg__StanleyError__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
erp42_msgs__msg__StanleyError__Sequence__are_equal(const erp42_msgs__msg__StanleyError__Sequence * lhs, const erp42_msgs__msg__StanleyError__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!erp42_msgs__msg__StanleyError__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
erp42_msgs__msg__StanleyError__Sequence__copy(
  const erp42_msgs__msg__StanleyError__Sequence * input,
  erp42_msgs__msg__StanleyError__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(erp42_msgs__msg__StanleyError);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    erp42_msgs__msg__StanleyError * data =
      (erp42_msgs__msg__StanleyError *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!erp42_msgs__msg__StanleyError__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          erp42_msgs__msg__StanleyError__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!erp42_msgs__msg__StanleyError__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
