// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice
#include "rosbag2_interfaces/msg/detail/messages_lost_event__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `node_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `messages_lost_statistics`
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__functions.h"

bool
rosbag2_interfaces__msg__MessagesLostEvent__init(rosbag2_interfaces__msg__MessagesLostEvent * msg)
{
  if (!msg) {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__init(&msg->node_name)) {
    rosbag2_interfaces__msg__MessagesLostEvent__fini(msg);
    return false;
  }
  // messages_lost_statistics
  if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__init(&msg->messages_lost_statistics, 0)) {
    rosbag2_interfaces__msg__MessagesLostEvent__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_interfaces__msg__MessagesLostEvent__fini(rosbag2_interfaces__msg__MessagesLostEvent * msg)
{
  if (!msg) {
    return;
  }
  // node_name
  rosidl_runtime_c__String__fini(&msg->node_name);
  // messages_lost_statistics
  rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__fini(&msg->messages_lost_statistics);
}

bool
rosbag2_interfaces__msg__MessagesLostEvent__are_equal(const rosbag2_interfaces__msg__MessagesLostEvent * lhs, const rosbag2_interfaces__msg__MessagesLostEvent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_name), &(rhs->node_name)))
  {
    return false;
  }
  // messages_lost_statistics
  if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__are_equal(
      &(lhs->messages_lost_statistics), &(rhs->messages_lost_statistics)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_interfaces__msg__MessagesLostEvent__copy(
  const rosbag2_interfaces__msg__MessagesLostEvent * input,
  rosbag2_interfaces__msg__MessagesLostEvent * output)
{
  if (!input || !output) {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__copy(
      &(input->node_name), &(output->node_name)))
  {
    return false;
  }
  // messages_lost_statistics
  if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__copy(
      &(input->messages_lost_statistics), &(output->messages_lost_statistics)))
  {
    return false;
  }
  return true;
}

rosbag2_interfaces__msg__MessagesLostEvent *
rosbag2_interfaces__msg__MessagesLostEvent__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__msg__MessagesLostEvent * msg = (rosbag2_interfaces__msg__MessagesLostEvent *)allocator.allocate(sizeof(rosbag2_interfaces__msg__MessagesLostEvent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_interfaces__msg__MessagesLostEvent));
  bool success = rosbag2_interfaces__msg__MessagesLostEvent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_interfaces__msg__MessagesLostEvent__destroy(rosbag2_interfaces__msg__MessagesLostEvent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_interfaces__msg__MessagesLostEvent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_interfaces__msg__MessagesLostEvent__Sequence__init(rosbag2_interfaces__msg__MessagesLostEvent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__msg__MessagesLostEvent * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_interfaces__msg__MessagesLostEvent)) {
      return false;
    }
    data = (rosbag2_interfaces__msg__MessagesLostEvent *)allocator.zero_allocate(size, sizeof(rosbag2_interfaces__msg__MessagesLostEvent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_interfaces__msg__MessagesLostEvent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_interfaces__msg__MessagesLostEvent__fini(&data[i - 1]);
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
rosbag2_interfaces__msg__MessagesLostEvent__Sequence__fini(rosbag2_interfaces__msg__MessagesLostEvent__Sequence * array)
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
      rosbag2_interfaces__msg__MessagesLostEvent__fini(&array->data[i]);
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

rosbag2_interfaces__msg__MessagesLostEvent__Sequence *
rosbag2_interfaces__msg__MessagesLostEvent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__msg__MessagesLostEvent__Sequence * array = (rosbag2_interfaces__msg__MessagesLostEvent__Sequence *)allocator.allocate(sizeof(rosbag2_interfaces__msg__MessagesLostEvent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_interfaces__msg__MessagesLostEvent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_interfaces__msg__MessagesLostEvent__Sequence__destroy(rosbag2_interfaces__msg__MessagesLostEvent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_interfaces__msg__MessagesLostEvent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_interfaces__msg__MessagesLostEvent__Sequence__are_equal(const rosbag2_interfaces__msg__MessagesLostEvent__Sequence * lhs, const rosbag2_interfaces__msg__MessagesLostEvent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_interfaces__msg__MessagesLostEvent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_interfaces__msg__MessagesLostEvent__Sequence__copy(
  const rosbag2_interfaces__msg__MessagesLostEvent__Sequence * input,
  rosbag2_interfaces__msg__MessagesLostEvent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_interfaces__msg__MessagesLostEvent)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_interfaces__msg__MessagesLostEvent);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_interfaces__msg__MessagesLostEvent * data =
      (rosbag2_interfaces__msg__MessagesLostEvent *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_interfaces__msg__MessagesLostEvent__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_interfaces__msg__MessagesLostEvent__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_interfaces__msg__MessagesLostEvent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
