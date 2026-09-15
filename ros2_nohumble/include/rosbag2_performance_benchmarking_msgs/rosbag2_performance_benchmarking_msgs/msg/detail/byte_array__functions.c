// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice
#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(rosbag2_performance_benchmarking_msgs__msg__ByteArray * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__octet__Sequence__init(&msg->data, 0)) {
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(rosbag2_performance_benchmarking_msgs__msg__ByteArray * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__octet__Sequence__fini(&msg->data);
}

bool
rosbag2_performance_benchmarking_msgs__msg__ByteArray__are_equal(const rosbag2_performance_benchmarking_msgs__msg__ByteArray * lhs, const rosbag2_performance_benchmarking_msgs__msg__ByteArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__octet__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_performance_benchmarking_msgs__msg__ByteArray__copy(
  const rosbag2_performance_benchmarking_msgs__msg__ByteArray * input,
  rosbag2_performance_benchmarking_msgs__msg__ByteArray * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__octet__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

rosbag2_performance_benchmarking_msgs__msg__ByteArray *
rosbag2_performance_benchmarking_msgs__msg__ByteArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_performance_benchmarking_msgs__msg__ByteArray * msg = (rosbag2_performance_benchmarking_msgs__msg__ByteArray *)allocator.allocate(sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray));
  bool success = rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_performance_benchmarking_msgs__msg__ByteArray__destroy(rosbag2_performance_benchmarking_msgs__msg__ByteArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__init(rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_performance_benchmarking_msgs__msg__ByteArray * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray)) {
      return false;
    }
    data = (rosbag2_performance_benchmarking_msgs__msg__ByteArray *)allocator.zero_allocate(size, sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(&data[i - 1]);
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
rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__fini(rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * array)
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
      rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(&array->data[i]);
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

rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence *
rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * array = (rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence *)allocator.allocate(sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__destroy(rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__are_equal(const rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * lhs, const rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_performance_benchmarking_msgs__msg__ByteArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence__copy(
  const rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * input,
  rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_performance_benchmarking_msgs__msg__ByteArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_performance_benchmarking_msgs__msg__ByteArray * data =
      (rosbag2_performance_benchmarking_msgs__msg__ByteArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_performance_benchmarking_msgs__msg__ByteArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_performance_benchmarking_msgs__msg__ByteArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_performance_benchmarking_msgs__msg__ByteArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
