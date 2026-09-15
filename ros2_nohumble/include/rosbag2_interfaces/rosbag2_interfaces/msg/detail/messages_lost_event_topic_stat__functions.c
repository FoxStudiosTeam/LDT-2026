// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `topic_name`
#include "rosidl_runtime_c/string_functions.h"

bool
rosbag2_interfaces__msg__MessagesLostEventTopicStat__init(rosbag2_interfaces__msg__MessagesLostEventTopicStat * msg)
{
  if (!msg) {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__init(&msg->topic_name)) {
    rosbag2_interfaces__msg__MessagesLostEventTopicStat__fini(msg);
    return false;
  }
  // messages_lost_in_transport
  // messages_lost_in_recorder
  return true;
}

void
rosbag2_interfaces__msg__MessagesLostEventTopicStat__fini(rosbag2_interfaces__msg__MessagesLostEventTopicStat * msg)
{
  if (!msg) {
    return;
  }
  // topic_name
  rosidl_runtime_c__String__fini(&msg->topic_name);
  // messages_lost_in_transport
  // messages_lost_in_recorder
}

bool
rosbag2_interfaces__msg__MessagesLostEventTopicStat__are_equal(const rosbag2_interfaces__msg__MessagesLostEventTopicStat * lhs, const rosbag2_interfaces__msg__MessagesLostEventTopicStat * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->topic_name), &(rhs->topic_name)))
  {
    return false;
  }
  // messages_lost_in_transport
  if (lhs->messages_lost_in_transport != rhs->messages_lost_in_transport) {
    return false;
  }
  // messages_lost_in_recorder
  if (lhs->messages_lost_in_recorder != rhs->messages_lost_in_recorder) {
    return false;
  }
  return true;
}

bool
rosbag2_interfaces__msg__MessagesLostEventTopicStat__copy(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat * input,
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * output)
{
  if (!input || !output) {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__copy(
      &(input->topic_name), &(output->topic_name)))
  {
    return false;
  }
  // messages_lost_in_transport
  output->messages_lost_in_transport = input->messages_lost_in_transport;
  // messages_lost_in_recorder
  output->messages_lost_in_recorder = input->messages_lost_in_recorder;
  return true;
}

rosbag2_interfaces__msg__MessagesLostEventTopicStat *
rosbag2_interfaces__msg__MessagesLostEventTopicStat__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * msg = (rosbag2_interfaces__msg__MessagesLostEventTopicStat *)allocator.allocate(sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat));
  bool success = rosbag2_interfaces__msg__MessagesLostEventTopicStat__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_interfaces__msg__MessagesLostEventTopicStat__destroy(rosbag2_interfaces__msg__MessagesLostEventTopicStat * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_interfaces__msg__MessagesLostEventTopicStat__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__init(rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat)) {
      return false;
    }
    data = (rosbag2_interfaces__msg__MessagesLostEventTopicStat *)allocator.zero_allocate(size, sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_interfaces__msg__MessagesLostEventTopicStat__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_interfaces__msg__MessagesLostEventTopicStat__fini(&data[i - 1]);
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
rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__fini(rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * array)
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
      rosbag2_interfaces__msg__MessagesLostEventTopicStat__fini(&array->data[i]);
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

rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence *
rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * array = (rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence *)allocator.allocate(sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__destroy(rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__are_equal(const rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * lhs, const rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__copy(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * input,
  rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_interfaces__msg__MessagesLostEventTopicStat);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_interfaces__msg__MessagesLostEventTopicStat * data =
      (rosbag2_interfaces__msg__MessagesLostEventTopicStat *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_interfaces__msg__MessagesLostEventTopicStat__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
