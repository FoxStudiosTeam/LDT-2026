// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtlesim_msgs:msg\Pose.idl
// generated code does not contain a copyright notice
#include "turtlesim_msgs/msg/detail/pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turtlesim_msgs__msg__Pose__init(turtlesim_msgs__msg__Pose * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // theta
  // linear_velocity
  // angular_velocity
  return true;
}

void
turtlesim_msgs__msg__Pose__fini(turtlesim_msgs__msg__Pose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
  // linear_velocity
  // angular_velocity
}

bool
turtlesim_msgs__msg__Pose__are_equal(const turtlesim_msgs__msg__Pose * lhs, const turtlesim_msgs__msg__Pose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  // linear_velocity
  if (lhs->linear_velocity != rhs->linear_velocity) {
    return false;
  }
  // angular_velocity
  if (lhs->angular_velocity != rhs->angular_velocity) {
    return false;
  }
  return true;
}

bool
turtlesim_msgs__msg__Pose__copy(
  const turtlesim_msgs__msg__Pose * input,
  turtlesim_msgs__msg__Pose * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  // linear_velocity
  output->linear_velocity = input->linear_velocity;
  // angular_velocity
  output->angular_velocity = input->angular_velocity;
  return true;
}

turtlesim_msgs__msg__Pose *
turtlesim_msgs__msg__Pose__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlesim_msgs__msg__Pose * msg = (turtlesim_msgs__msg__Pose *)allocator.allocate(sizeof(turtlesim_msgs__msg__Pose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtlesim_msgs__msg__Pose));
  bool success = turtlesim_msgs__msg__Pose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtlesim_msgs__msg__Pose__destroy(turtlesim_msgs__msg__Pose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtlesim_msgs__msg__Pose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtlesim_msgs__msg__Pose__Sequence__init(turtlesim_msgs__msg__Pose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlesim_msgs__msg__Pose * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(turtlesim_msgs__msg__Pose)) {
      return false;
    }
    data = (turtlesim_msgs__msg__Pose *)allocator.zero_allocate(size, sizeof(turtlesim_msgs__msg__Pose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtlesim_msgs__msg__Pose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtlesim_msgs__msg__Pose__fini(&data[i - 1]);
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
turtlesim_msgs__msg__Pose__Sequence__fini(turtlesim_msgs__msg__Pose__Sequence * array)
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
      turtlesim_msgs__msg__Pose__fini(&array->data[i]);
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

turtlesim_msgs__msg__Pose__Sequence *
turtlesim_msgs__msg__Pose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtlesim_msgs__msg__Pose__Sequence * array = (turtlesim_msgs__msg__Pose__Sequence *)allocator.allocate(sizeof(turtlesim_msgs__msg__Pose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtlesim_msgs__msg__Pose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtlesim_msgs__msg__Pose__Sequence__destroy(turtlesim_msgs__msg__Pose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtlesim_msgs__msg__Pose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtlesim_msgs__msg__Pose__Sequence__are_equal(const turtlesim_msgs__msg__Pose__Sequence * lhs, const turtlesim_msgs__msg__Pose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtlesim_msgs__msg__Pose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtlesim_msgs__msg__Pose__Sequence__copy(
  const turtlesim_msgs__msg__Pose__Sequence * input,
  turtlesim_msgs__msg__Pose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(turtlesim_msgs__msg__Pose)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(turtlesim_msgs__msg__Pose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtlesim_msgs__msg__Pose * data =
      (turtlesim_msgs__msg__Pose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtlesim_msgs__msg__Pose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtlesim_msgs__msg__Pose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtlesim_msgs__msg__Pose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
