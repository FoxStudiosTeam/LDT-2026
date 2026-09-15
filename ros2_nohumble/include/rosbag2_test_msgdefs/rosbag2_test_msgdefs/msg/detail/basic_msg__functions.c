// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_test_msgdefs:msg\BasicMsg.idl
// generated code does not contain a copyright notice
#include "rosbag2_test_msgdefs/msg/detail/basic_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rosbag2_test_msgdefs__msg__BasicMsg__init(rosbag2_test_msgdefs__msg__BasicMsg * msg)
{
  if (!msg) {
    return false;
  }
  // c
  return true;
}

void
rosbag2_test_msgdefs__msg__BasicMsg__fini(rosbag2_test_msgdefs__msg__BasicMsg * msg)
{
  if (!msg) {
    return;
  }
  // c
}

bool
rosbag2_test_msgdefs__msg__BasicMsg__are_equal(const rosbag2_test_msgdefs__msg__BasicMsg * lhs, const rosbag2_test_msgdefs__msg__BasicMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // c
  if (lhs->c != rhs->c) {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__msg__BasicMsg__copy(
  const rosbag2_test_msgdefs__msg__BasicMsg * input,
  rosbag2_test_msgdefs__msg__BasicMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // c
  output->c = input->c;
  return true;
}

rosbag2_test_msgdefs__msg__BasicMsg *
rosbag2_test_msgdefs__msg__BasicMsg__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__msg__BasicMsg * msg = (rosbag2_test_msgdefs__msg__BasicMsg *)allocator.allocate(sizeof(rosbag2_test_msgdefs__msg__BasicMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__msg__BasicMsg));
  bool success = rosbag2_test_msgdefs__msg__BasicMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__msg__BasicMsg__destroy(rosbag2_test_msgdefs__msg__BasicMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__msg__BasicMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__msg__BasicMsg__Sequence__init(rosbag2_test_msgdefs__msg__BasicMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__msg__BasicMsg * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__msg__BasicMsg)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__msg__BasicMsg *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__msg__BasicMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__msg__BasicMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__msg__BasicMsg__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__msg__BasicMsg__Sequence__fini(rosbag2_test_msgdefs__msg__BasicMsg__Sequence * array)
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
      rosbag2_test_msgdefs__msg__BasicMsg__fini(&array->data[i]);
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

rosbag2_test_msgdefs__msg__BasicMsg__Sequence *
rosbag2_test_msgdefs__msg__BasicMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__msg__BasicMsg__Sequence * array = (rosbag2_test_msgdefs__msg__BasicMsg__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__msg__BasicMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__msg__BasicMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__msg__BasicMsg__Sequence__destroy(rosbag2_test_msgdefs__msg__BasicMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__msg__BasicMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__msg__BasicMsg__Sequence__are_equal(const rosbag2_test_msgdefs__msg__BasicMsg__Sequence * lhs, const rosbag2_test_msgdefs__msg__BasicMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__msg__BasicMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__msg__BasicMsg__Sequence__copy(
  const rosbag2_test_msgdefs__msg__BasicMsg__Sequence * input,
  rosbag2_test_msgdefs__msg__BasicMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__msg__BasicMsg)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__msg__BasicMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__msg__BasicMsg * data =
      (rosbag2_test_msgdefs__msg__BasicMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__msg__BasicMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__msg__BasicMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__msg__BasicMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
