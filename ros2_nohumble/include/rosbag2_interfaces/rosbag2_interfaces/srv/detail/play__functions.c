// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_interfaces:srv\Play.idl
// generated code does not contain a copyright notice
#include "rosbag2_interfaces/srv/detail/play__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `start_offset`
// Member `playback_until_timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `playback_duration`
#include "builtin_interfaces/msg/detail/duration__functions.h"

bool
rosbag2_interfaces__srv__Play_Request__init(rosbag2_interfaces__srv__Play_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start_offset
  if (!builtin_interfaces__msg__Time__init(&msg->start_offset)) {
    rosbag2_interfaces__srv__Play_Request__fini(msg);
    return false;
  }
  // playback_duration
  if (!builtin_interfaces__msg__Duration__init(&msg->playback_duration)) {
    rosbag2_interfaces__srv__Play_Request__fini(msg);
    return false;
  }
  // playback_until_timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->playback_until_timestamp)) {
    rosbag2_interfaces__srv__Play_Request__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_interfaces__srv__Play_Request__fini(rosbag2_interfaces__srv__Play_Request * msg)
{
  if (!msg) {
    return;
  }
  // start_offset
  builtin_interfaces__msg__Time__fini(&msg->start_offset);
  // playback_duration
  builtin_interfaces__msg__Duration__fini(&msg->playback_duration);
  // playback_until_timestamp
  builtin_interfaces__msg__Time__fini(&msg->playback_until_timestamp);
}

bool
rosbag2_interfaces__srv__Play_Request__are_equal(const rosbag2_interfaces__srv__Play_Request * lhs, const rosbag2_interfaces__srv__Play_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_offset
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->start_offset), &(rhs->start_offset)))
  {
    return false;
  }
  // playback_duration
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->playback_duration), &(rhs->playback_duration)))
  {
    return false;
  }
  // playback_until_timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->playback_until_timestamp), &(rhs->playback_until_timestamp)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_interfaces__srv__Play_Request__copy(
  const rosbag2_interfaces__srv__Play_Request * input,
  rosbag2_interfaces__srv__Play_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start_offset
  if (!builtin_interfaces__msg__Time__copy(
      &(input->start_offset), &(output->start_offset)))
  {
    return false;
  }
  // playback_duration
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->playback_duration), &(output->playback_duration)))
  {
    return false;
  }
  // playback_until_timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->playback_until_timestamp), &(output->playback_until_timestamp)))
  {
    return false;
  }
  return true;
}

rosbag2_interfaces__srv__Play_Request *
rosbag2_interfaces__srv__Play_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Request * msg = (rosbag2_interfaces__srv__Play_Request *)allocator.allocate(sizeof(rosbag2_interfaces__srv__Play_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_interfaces__srv__Play_Request));
  bool success = rosbag2_interfaces__srv__Play_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_interfaces__srv__Play_Request__destroy(rosbag2_interfaces__srv__Play_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_interfaces__srv__Play_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_interfaces__srv__Play_Request__Sequence__init(rosbag2_interfaces__srv__Play_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_interfaces__srv__Play_Request)) {
      return false;
    }
    data = (rosbag2_interfaces__srv__Play_Request *)allocator.zero_allocate(size, sizeof(rosbag2_interfaces__srv__Play_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_interfaces__srv__Play_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_interfaces__srv__Play_Request__fini(&data[i - 1]);
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
rosbag2_interfaces__srv__Play_Request__Sequence__fini(rosbag2_interfaces__srv__Play_Request__Sequence * array)
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
      rosbag2_interfaces__srv__Play_Request__fini(&array->data[i]);
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

rosbag2_interfaces__srv__Play_Request__Sequence *
rosbag2_interfaces__srv__Play_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Request__Sequence * array = (rosbag2_interfaces__srv__Play_Request__Sequence *)allocator.allocate(sizeof(rosbag2_interfaces__srv__Play_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_interfaces__srv__Play_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_interfaces__srv__Play_Request__Sequence__destroy(rosbag2_interfaces__srv__Play_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_interfaces__srv__Play_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_interfaces__srv__Play_Request__Sequence__are_equal(const rosbag2_interfaces__srv__Play_Request__Sequence * lhs, const rosbag2_interfaces__srv__Play_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_interfaces__srv__Play_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_interfaces__srv__Play_Request__Sequence__copy(
  const rosbag2_interfaces__srv__Play_Request__Sequence * input,
  rosbag2_interfaces__srv__Play_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_interfaces__srv__Play_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_interfaces__srv__Play_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_interfaces__srv__Play_Request * data =
      (rosbag2_interfaces__srv__Play_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_interfaces__srv__Play_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_interfaces__srv__Play_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_interfaces__srv__Play_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
rosbag2_interfaces__srv__Play_Response__init(rosbag2_interfaces__srv__Play_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
rosbag2_interfaces__srv__Play_Response__fini(rosbag2_interfaces__srv__Play_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
rosbag2_interfaces__srv__Play_Response__are_equal(const rosbag2_interfaces__srv__Play_Response * lhs, const rosbag2_interfaces__srv__Play_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
rosbag2_interfaces__srv__Play_Response__copy(
  const rosbag2_interfaces__srv__Play_Response * input,
  rosbag2_interfaces__srv__Play_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

rosbag2_interfaces__srv__Play_Response *
rosbag2_interfaces__srv__Play_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Response * msg = (rosbag2_interfaces__srv__Play_Response *)allocator.allocate(sizeof(rosbag2_interfaces__srv__Play_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_interfaces__srv__Play_Response));
  bool success = rosbag2_interfaces__srv__Play_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_interfaces__srv__Play_Response__destroy(rosbag2_interfaces__srv__Play_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_interfaces__srv__Play_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_interfaces__srv__Play_Response__Sequence__init(rosbag2_interfaces__srv__Play_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_interfaces__srv__Play_Response)) {
      return false;
    }
    data = (rosbag2_interfaces__srv__Play_Response *)allocator.zero_allocate(size, sizeof(rosbag2_interfaces__srv__Play_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_interfaces__srv__Play_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_interfaces__srv__Play_Response__fini(&data[i - 1]);
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
rosbag2_interfaces__srv__Play_Response__Sequence__fini(rosbag2_interfaces__srv__Play_Response__Sequence * array)
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
      rosbag2_interfaces__srv__Play_Response__fini(&array->data[i]);
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

rosbag2_interfaces__srv__Play_Response__Sequence *
rosbag2_interfaces__srv__Play_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Response__Sequence * array = (rosbag2_interfaces__srv__Play_Response__Sequence *)allocator.allocate(sizeof(rosbag2_interfaces__srv__Play_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_interfaces__srv__Play_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_interfaces__srv__Play_Response__Sequence__destroy(rosbag2_interfaces__srv__Play_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_interfaces__srv__Play_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_interfaces__srv__Play_Response__Sequence__are_equal(const rosbag2_interfaces__srv__Play_Response__Sequence * lhs, const rosbag2_interfaces__srv__Play_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_interfaces__srv__Play_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_interfaces__srv__Play_Response__Sequence__copy(
  const rosbag2_interfaces__srv__Play_Response__Sequence * input,
  rosbag2_interfaces__srv__Play_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_interfaces__srv__Play_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_interfaces__srv__Play_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_interfaces__srv__Play_Response * data =
      (rosbag2_interfaces__srv__Play_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_interfaces__srv__Play_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_interfaces__srv__Play_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_interfaces__srv__Play_Response__copy(
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
// #include "rosbag2_interfaces/srv/detail/play__functions.h"

bool
rosbag2_interfaces__srv__Play_Event__init(rosbag2_interfaces__srv__Play_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    rosbag2_interfaces__srv__Play_Event__fini(msg);
    return false;
  }
  // request
  if (!rosbag2_interfaces__srv__Play_Request__Sequence__init(&msg->request, 0)) {
    rosbag2_interfaces__srv__Play_Event__fini(msg);
    return false;
  }
  // response
  if (!rosbag2_interfaces__srv__Play_Response__Sequence__init(&msg->response, 0)) {
    rosbag2_interfaces__srv__Play_Event__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_interfaces__srv__Play_Event__fini(rosbag2_interfaces__srv__Play_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  rosbag2_interfaces__srv__Play_Request__Sequence__fini(&msg->request);
  // response
  rosbag2_interfaces__srv__Play_Response__Sequence__fini(&msg->response);
}

bool
rosbag2_interfaces__srv__Play_Event__are_equal(const rosbag2_interfaces__srv__Play_Event * lhs, const rosbag2_interfaces__srv__Play_Event * rhs)
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
  if (!rosbag2_interfaces__srv__Play_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!rosbag2_interfaces__srv__Play_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_interfaces__srv__Play_Event__copy(
  const rosbag2_interfaces__srv__Play_Event * input,
  rosbag2_interfaces__srv__Play_Event * output)
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
  if (!rosbag2_interfaces__srv__Play_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!rosbag2_interfaces__srv__Play_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

rosbag2_interfaces__srv__Play_Event *
rosbag2_interfaces__srv__Play_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Event * msg = (rosbag2_interfaces__srv__Play_Event *)allocator.allocate(sizeof(rosbag2_interfaces__srv__Play_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_interfaces__srv__Play_Event));
  bool success = rosbag2_interfaces__srv__Play_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_interfaces__srv__Play_Event__destroy(rosbag2_interfaces__srv__Play_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_interfaces__srv__Play_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_interfaces__srv__Play_Event__Sequence__init(rosbag2_interfaces__srv__Play_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(rosbag2_interfaces__srv__Play_Event)) {
      return false;
    }
    data = (rosbag2_interfaces__srv__Play_Event *)allocator.zero_allocate(size, sizeof(rosbag2_interfaces__srv__Play_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_interfaces__srv__Play_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_interfaces__srv__Play_Event__fini(&data[i - 1]);
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
rosbag2_interfaces__srv__Play_Event__Sequence__fini(rosbag2_interfaces__srv__Play_Event__Sequence * array)
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
      rosbag2_interfaces__srv__Play_Event__fini(&array->data[i]);
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

rosbag2_interfaces__srv__Play_Event__Sequence *
rosbag2_interfaces__srv__Play_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_interfaces__srv__Play_Event__Sequence * array = (rosbag2_interfaces__srv__Play_Event__Sequence *)allocator.allocate(sizeof(rosbag2_interfaces__srv__Play_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_interfaces__srv__Play_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_interfaces__srv__Play_Event__Sequence__destroy(rosbag2_interfaces__srv__Play_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_interfaces__srv__Play_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_interfaces__srv__Play_Event__Sequence__are_equal(const rosbag2_interfaces__srv__Play_Event__Sequence * lhs, const rosbag2_interfaces__srv__Play_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_interfaces__srv__Play_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_interfaces__srv__Play_Event__Sequence__copy(
  const rosbag2_interfaces__srv__Play_Event__Sequence * input,
  rosbag2_interfaces__srv__Play_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(rosbag2_interfaces__srv__Play_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(rosbag2_interfaces__srv__Play_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_interfaces__srv__Play_Event * data =
      (rosbag2_interfaces__srv__Play_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_interfaces__srv__Play_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_interfaces__srv__Play_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_interfaces__srv__Play_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
