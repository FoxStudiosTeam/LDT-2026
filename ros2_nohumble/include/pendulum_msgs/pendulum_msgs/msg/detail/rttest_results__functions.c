// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice
#include "pendulum_msgs/msg/detail/rttest_results__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `command`
#include "pendulum_msgs/msg/detail/joint_command__functions.h"
// Member `state`
#include "pendulum_msgs/msg/detail/joint_state__functions.h"

bool
pendulum_msgs__msg__RttestResults__init(pendulum_msgs__msg__RttestResults * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    pendulum_msgs__msg__RttestResults__fini(msg);
    return false;
  }
  // command
  if (!pendulum_msgs__msg__JointCommand__init(&msg->command)) {
    pendulum_msgs__msg__RttestResults__fini(msg);
    return false;
  }
  // state
  if (!pendulum_msgs__msg__JointState__init(&msg->state)) {
    pendulum_msgs__msg__RttestResults__fini(msg);
    return false;
  }
  // cur_latency
  // mean_latency
  // min_latency
  // max_latency
  // minor_pagefaults
  // major_pagefaults
  return true;
}

void
pendulum_msgs__msg__RttestResults__fini(pendulum_msgs__msg__RttestResults * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // command
  pendulum_msgs__msg__JointCommand__fini(&msg->command);
  // state
  pendulum_msgs__msg__JointState__fini(&msg->state);
  // cur_latency
  // mean_latency
  // min_latency
  // max_latency
  // minor_pagefaults
  // major_pagefaults
}

bool
pendulum_msgs__msg__RttestResults__are_equal(const pendulum_msgs__msg__RttestResults * lhs, const pendulum_msgs__msg__RttestResults * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // command
  if (!pendulum_msgs__msg__JointCommand__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // state
  if (!pendulum_msgs__msg__JointState__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // cur_latency
  if (lhs->cur_latency != rhs->cur_latency) {
    return false;
  }
  // mean_latency
  if (lhs->mean_latency != rhs->mean_latency) {
    return false;
  }
  // min_latency
  if (lhs->min_latency != rhs->min_latency) {
    return false;
  }
  // max_latency
  if (lhs->max_latency != rhs->max_latency) {
    return false;
  }
  // minor_pagefaults
  if (lhs->minor_pagefaults != rhs->minor_pagefaults) {
    return false;
  }
  // major_pagefaults
  if (lhs->major_pagefaults != rhs->major_pagefaults) {
    return false;
  }
  return true;
}

bool
pendulum_msgs__msg__RttestResults__copy(
  const pendulum_msgs__msg__RttestResults * input,
  pendulum_msgs__msg__RttestResults * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // command
  if (!pendulum_msgs__msg__JointCommand__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // state
  if (!pendulum_msgs__msg__JointState__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // cur_latency
  output->cur_latency = input->cur_latency;
  // mean_latency
  output->mean_latency = input->mean_latency;
  // min_latency
  output->min_latency = input->min_latency;
  // max_latency
  output->max_latency = input->max_latency;
  // minor_pagefaults
  output->minor_pagefaults = input->minor_pagefaults;
  // major_pagefaults
  output->major_pagefaults = input->major_pagefaults;
  return true;
}

pendulum_msgs__msg__RttestResults *
pendulum_msgs__msg__RttestResults__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pendulum_msgs__msg__RttestResults * msg = (pendulum_msgs__msg__RttestResults *)allocator.allocate(sizeof(pendulum_msgs__msg__RttestResults), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pendulum_msgs__msg__RttestResults));
  bool success = pendulum_msgs__msg__RttestResults__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pendulum_msgs__msg__RttestResults__destroy(pendulum_msgs__msg__RttestResults * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pendulum_msgs__msg__RttestResults__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pendulum_msgs__msg__RttestResults__Sequence__init(pendulum_msgs__msg__RttestResults__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pendulum_msgs__msg__RttestResults * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(pendulum_msgs__msg__RttestResults)) {
      return false;
    }
    data = (pendulum_msgs__msg__RttestResults *)allocator.zero_allocate(size, sizeof(pendulum_msgs__msg__RttestResults), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pendulum_msgs__msg__RttestResults__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pendulum_msgs__msg__RttestResults__fini(&data[i - 1]);
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
pendulum_msgs__msg__RttestResults__Sequence__fini(pendulum_msgs__msg__RttestResults__Sequence * array)
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
      pendulum_msgs__msg__RttestResults__fini(&array->data[i]);
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

pendulum_msgs__msg__RttestResults__Sequence *
pendulum_msgs__msg__RttestResults__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pendulum_msgs__msg__RttestResults__Sequence * array = (pendulum_msgs__msg__RttestResults__Sequence *)allocator.allocate(sizeof(pendulum_msgs__msg__RttestResults__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pendulum_msgs__msg__RttestResults__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pendulum_msgs__msg__RttestResults__Sequence__destroy(pendulum_msgs__msg__RttestResults__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pendulum_msgs__msg__RttestResults__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pendulum_msgs__msg__RttestResults__Sequence__are_equal(const pendulum_msgs__msg__RttestResults__Sequence * lhs, const pendulum_msgs__msg__RttestResults__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pendulum_msgs__msg__RttestResults__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pendulum_msgs__msg__RttestResults__Sequence__copy(
  const pendulum_msgs__msg__RttestResults__Sequence * input,
  pendulum_msgs__msg__RttestResults__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(pendulum_msgs__msg__RttestResults)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(pendulum_msgs__msg__RttestResults);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pendulum_msgs__msg__RttestResults * data =
      (pendulum_msgs__msg__RttestResults *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pendulum_msgs__msg__RttestResults__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pendulum_msgs__msg__RttestResults__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pendulum_msgs__msg__RttestResults__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
