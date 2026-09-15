// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_test_msgdefs:action\BasicAction.idl
// generated code does not contain a copyright notice
#include "rosbag2_test_msgdefs/action/detail/basic_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `goal`
#include "rosidl_runtime_c/string_functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_Goal__init(rosbag2_test_msgdefs__action__BasicAction_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // goal
  if (!rosidl_runtime_c__String__init(&msg->goal)) {
    rosbag2_test_msgdefs__action__BasicAction_Goal__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_Goal__fini(rosbag2_test_msgdefs__action__BasicAction_Goal * msg)
{
  if (!msg) {
    return;
  }
  // goal
  rosidl_runtime_c__String__fini(&msg->goal);
}

bool
rosbag2_test_msgdefs__action__BasicAction_Goal__are_equal(const rosbag2_test_msgdefs__action__BasicAction_Goal * lhs, const rosbag2_test_msgdefs__action__BasicAction_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_Goal__copy(
  const rosbag2_test_msgdefs__action__BasicAction_Goal * input,
  rosbag2_test_msgdefs__action__BasicAction_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // goal
  if (!rosidl_runtime_c__String__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_Goal *
rosbag2_test_msgdefs__action__BasicAction_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Goal * msg = (rosbag2_test_msgdefs__action__BasicAction_Goal *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal));
  bool success = rosbag2_test_msgdefs__action__BasicAction_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_Goal__destroy(rosbag2_test_msgdefs__action__BasicAction_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Goal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_Goal *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_Goal__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_Goal__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence *
rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_Goal * data =
      (rosbag2_test_msgdefs__action__BasicAction_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_Result__init(rosbag2_test_msgdefs__action__BasicAction_Result * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    rosbag2_test_msgdefs__action__BasicAction_Result__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_Result__fini(rosbag2_test_msgdefs__action__BasicAction_Result * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
rosbag2_test_msgdefs__action__BasicAction_Result__are_equal(const rosbag2_test_msgdefs__action__BasicAction_Result * lhs, const rosbag2_test_msgdefs__action__BasicAction_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_Result__copy(
  const rosbag2_test_msgdefs__action__BasicAction_Result * input,
  rosbag2_test_msgdefs__action__BasicAction_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_Result *
rosbag2_test_msgdefs__action__BasicAction_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Result * msg = (rosbag2_test_msgdefs__action__BasicAction_Result *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_Result));
  bool success = rosbag2_test_msgdefs__action__BasicAction_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_Result__destroy(rosbag2_test_msgdefs__action__BasicAction_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Result * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_Result)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_Result *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_Result__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_Result__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_Result__Sequence *
rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_Result__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_Result__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_Result)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_Result * data =
      (rosbag2_test_msgdefs__action__BasicAction_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `feedback`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_Feedback__init(rosbag2_test_msgdefs__action__BasicAction_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__init(&msg->feedback)) {
    rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(rosbag2_test_msgdefs__action__BasicAction_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // feedback
  rosidl_runtime_c__String__fini(&msg->feedback);
}

bool
rosbag2_test_msgdefs__action__BasicAction_Feedback__are_equal(const rosbag2_test_msgdefs__action__BasicAction_Feedback * lhs, const rosbag2_test_msgdefs__action__BasicAction_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_Feedback__copy(
  const rosbag2_test_msgdefs__action__BasicAction_Feedback * input,
  rosbag2_test_msgdefs__action__BasicAction_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_Feedback *
rosbag2_test_msgdefs__action__BasicAction_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Feedback * msg = (rosbag2_test_msgdefs__action__BasicAction_Feedback *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback));
  bool success = rosbag2_test_msgdefs__action__BasicAction_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_Feedback__destroy(rosbag2_test_msgdefs__action__BasicAction_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Feedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_Feedback *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence *
rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_Feedback * data =
      (rosbag2_test_msgdefs__action__BasicAction_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_action__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!rosbag2_test_msgdefs__action__BasicAction_Goal__init(&msg->goal)) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  rosbag2_test_msgdefs__action__BasicAction_Goal__fini(&msg->goal);
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__are_equal(const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * lhs, const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!rosbag2_test_msgdefs__action__BasicAction_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__copy(
  const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * input,
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!rosbag2_test_msgdefs__action__BasicAction_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request *
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * msg = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request));
  bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__destroy(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence *
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request * data =
      (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__fini(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__are_equal(const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * lhs, const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__copy(
  const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * input,
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response *
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * msg = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response));
  bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__destroy(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence *
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response * data =
      (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_action__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__init(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__are_equal(const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * lhs, const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__copy(
  const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * input,
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event *
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * msg = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event));
  bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__destroy(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence *
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event * data =
      (rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__fini(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__are_equal(const rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * lhs, const rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__copy(
  const rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * input,
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_GetResult_Request *
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * msg = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Request *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request));
  bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__destroy(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Request *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence *
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Request * data =
      (rosbag2_test_msgdefs__action__BasicAction_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_action__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!rosbag2_test_msgdefs__action__BasicAction_Result__init(&msg->result)) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__fini(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  rosbag2_test_msgdefs__action__BasicAction_Result__fini(&msg->result);
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__are_equal(const rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * lhs, const rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!rosbag2_test_msgdefs__action__BasicAction_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__copy(
  const rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * input,
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!rosbag2_test_msgdefs__action__BasicAction_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_GetResult_Response *
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * msg = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Response *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response));
  bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__destroy(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Response *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence *
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Response * data =
      (rosbag2_test_msgdefs__action__BasicAction_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_action__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__init(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__init(&msg->request, 0)) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__init(&msg->response, 0)) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__fini(&msg->request);
  // response
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__fini(&msg->response);
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__are_equal(const rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * lhs, const rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__copy(
  const rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * input,
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_GetResult_Event *
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * msg = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Event *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event));
  bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__destroy(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Event *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence *
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_GetResult_Event * data =
      (rosbag2_test_msgdefs__action__BasicAction_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_action__functions.h"

bool
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!rosbag2_test_msgdefs__action__BasicAction_Feedback__init(&msg->feedback)) {
    rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  rosbag2_test_msgdefs__action__BasicAction_Feedback__fini(&msg->feedback);
}

bool
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__are_equal(const rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * lhs, const rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!rosbag2_test_msgdefs__action__BasicAction_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__copy(
  const rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * input,
  rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!rosbag2_test_msgdefs__action__BasicAction_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage *
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * msg = (rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage));
  bool success = rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__destroy(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__init(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage)) {
      return false;
    }
    data = (rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage *)allocator.zero_allocate(size, sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(&data[i - 1]);
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
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__fini(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * array)
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
      rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(&array->data[i]);
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

rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence *
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * array = (rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence *)allocator.allocate(sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__destroy(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__are_equal(const rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * lhs, const rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence__copy(
  const rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * input,
  rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage * data =
      (rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
