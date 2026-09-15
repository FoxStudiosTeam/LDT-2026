// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:srv\GetPointMap.idl
// generated code does not contain a copyright notice
#include "map_msgs/srv/detail/get_point_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
map_msgs__srv__GetPointMap_Request__init(map_msgs__srv__GetPointMap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
map_msgs__srv__GetPointMap_Request__fini(map_msgs__srv__GetPointMap_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
map_msgs__srv__GetPointMap_Request__are_equal(const map_msgs__srv__GetPointMap_Request * lhs, const map_msgs__srv__GetPointMap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
map_msgs__srv__GetPointMap_Request__copy(
  const map_msgs__srv__GetPointMap_Request * input,
  map_msgs__srv__GetPointMap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

map_msgs__srv__GetPointMap_Request *
map_msgs__srv__GetPointMap_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Request * msg = (map_msgs__srv__GetPointMap_Request *)allocator.allocate(sizeof(map_msgs__srv__GetPointMap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__GetPointMap_Request));
  bool success = map_msgs__srv__GetPointMap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__GetPointMap_Request__destroy(map_msgs__srv__GetPointMap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__GetPointMap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__GetPointMap_Request__Sequence__init(map_msgs__srv__GetPointMap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__srv__GetPointMap_Request)) {
      return false;
    }
    data = (map_msgs__srv__GetPointMap_Request *)allocator.zero_allocate(size, sizeof(map_msgs__srv__GetPointMap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__GetPointMap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__GetPointMap_Request__fini(&data[i - 1]);
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
map_msgs__srv__GetPointMap_Request__Sequence__fini(map_msgs__srv__GetPointMap_Request__Sequence * array)
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
      map_msgs__srv__GetPointMap_Request__fini(&array->data[i]);
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

map_msgs__srv__GetPointMap_Request__Sequence *
map_msgs__srv__GetPointMap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Request__Sequence * array = (map_msgs__srv__GetPointMap_Request__Sequence *)allocator.allocate(sizeof(map_msgs__srv__GetPointMap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__GetPointMap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__GetPointMap_Request__Sequence__destroy(map_msgs__srv__GetPointMap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__GetPointMap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__GetPointMap_Request__Sequence__are_equal(const map_msgs__srv__GetPointMap_Request__Sequence * lhs, const map_msgs__srv__GetPointMap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__GetPointMap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__GetPointMap_Request__Sequence__copy(
  const map_msgs__srv__GetPointMap_Request__Sequence * input,
  map_msgs__srv__GetPointMap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__srv__GetPointMap_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__GetPointMap_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__GetPointMap_Request * data =
      (map_msgs__srv__GetPointMap_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__GetPointMap_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__GetPointMap_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__GetPointMap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `map`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"

bool
map_msgs__srv__GetPointMap_Response__init(map_msgs__srv__GetPointMap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // map
  if (!sensor_msgs__msg__PointCloud2__init(&msg->map)) {
    map_msgs__srv__GetPointMap_Response__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__srv__GetPointMap_Response__fini(map_msgs__srv__GetPointMap_Response * msg)
{
  if (!msg) {
    return;
  }
  // map
  sensor_msgs__msg__PointCloud2__fini(&msg->map);
}

bool
map_msgs__srv__GetPointMap_Response__are_equal(const map_msgs__srv__GetPointMap_Response * lhs, const map_msgs__srv__GetPointMap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // map
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->map), &(rhs->map)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__srv__GetPointMap_Response__copy(
  const map_msgs__srv__GetPointMap_Response * input,
  map_msgs__srv__GetPointMap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // map
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->map), &(output->map)))
  {
    return false;
  }
  return true;
}

map_msgs__srv__GetPointMap_Response *
map_msgs__srv__GetPointMap_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Response * msg = (map_msgs__srv__GetPointMap_Response *)allocator.allocate(sizeof(map_msgs__srv__GetPointMap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__GetPointMap_Response));
  bool success = map_msgs__srv__GetPointMap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__GetPointMap_Response__destroy(map_msgs__srv__GetPointMap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__GetPointMap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__GetPointMap_Response__Sequence__init(map_msgs__srv__GetPointMap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__srv__GetPointMap_Response)) {
      return false;
    }
    data = (map_msgs__srv__GetPointMap_Response *)allocator.zero_allocate(size, sizeof(map_msgs__srv__GetPointMap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__GetPointMap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__GetPointMap_Response__fini(&data[i - 1]);
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
map_msgs__srv__GetPointMap_Response__Sequence__fini(map_msgs__srv__GetPointMap_Response__Sequence * array)
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
      map_msgs__srv__GetPointMap_Response__fini(&array->data[i]);
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

map_msgs__srv__GetPointMap_Response__Sequence *
map_msgs__srv__GetPointMap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Response__Sequence * array = (map_msgs__srv__GetPointMap_Response__Sequence *)allocator.allocate(sizeof(map_msgs__srv__GetPointMap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__GetPointMap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__GetPointMap_Response__Sequence__destroy(map_msgs__srv__GetPointMap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__GetPointMap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__GetPointMap_Response__Sequence__are_equal(const map_msgs__srv__GetPointMap_Response__Sequence * lhs, const map_msgs__srv__GetPointMap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__GetPointMap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__GetPointMap_Response__Sequence__copy(
  const map_msgs__srv__GetPointMap_Response__Sequence * input,
  map_msgs__srv__GetPointMap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__srv__GetPointMap_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__GetPointMap_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__GetPointMap_Response * data =
      (map_msgs__srv__GetPointMap_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__GetPointMap_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__GetPointMap_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__GetPointMap_Response__copy(
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
// #include "map_msgs/srv/detail/get_point_map__functions.h"

bool
map_msgs__srv__GetPointMap_Event__init(map_msgs__srv__GetPointMap_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    map_msgs__srv__GetPointMap_Event__fini(msg);
    return false;
  }
  // request
  if (!map_msgs__srv__GetPointMap_Request__Sequence__init(&msg->request, 0)) {
    map_msgs__srv__GetPointMap_Event__fini(msg);
    return false;
  }
  // response
  if (!map_msgs__srv__GetPointMap_Response__Sequence__init(&msg->response, 0)) {
    map_msgs__srv__GetPointMap_Event__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__srv__GetPointMap_Event__fini(map_msgs__srv__GetPointMap_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  map_msgs__srv__GetPointMap_Request__Sequence__fini(&msg->request);
  // response
  map_msgs__srv__GetPointMap_Response__Sequence__fini(&msg->response);
}

bool
map_msgs__srv__GetPointMap_Event__are_equal(const map_msgs__srv__GetPointMap_Event * lhs, const map_msgs__srv__GetPointMap_Event * rhs)
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
  if (!map_msgs__srv__GetPointMap_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!map_msgs__srv__GetPointMap_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__srv__GetPointMap_Event__copy(
  const map_msgs__srv__GetPointMap_Event * input,
  map_msgs__srv__GetPointMap_Event * output)
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
  if (!map_msgs__srv__GetPointMap_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!map_msgs__srv__GetPointMap_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

map_msgs__srv__GetPointMap_Event *
map_msgs__srv__GetPointMap_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Event * msg = (map_msgs__srv__GetPointMap_Event *)allocator.allocate(sizeof(map_msgs__srv__GetPointMap_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__GetPointMap_Event));
  bool success = map_msgs__srv__GetPointMap_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__GetPointMap_Event__destroy(map_msgs__srv__GetPointMap_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__GetPointMap_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__GetPointMap_Event__Sequence__init(map_msgs__srv__GetPointMap_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__srv__GetPointMap_Event)) {
      return false;
    }
    data = (map_msgs__srv__GetPointMap_Event *)allocator.zero_allocate(size, sizeof(map_msgs__srv__GetPointMap_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__GetPointMap_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__GetPointMap_Event__fini(&data[i - 1]);
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
map_msgs__srv__GetPointMap_Event__Sequence__fini(map_msgs__srv__GetPointMap_Event__Sequence * array)
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
      map_msgs__srv__GetPointMap_Event__fini(&array->data[i]);
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

map_msgs__srv__GetPointMap_Event__Sequence *
map_msgs__srv__GetPointMap_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetPointMap_Event__Sequence * array = (map_msgs__srv__GetPointMap_Event__Sequence *)allocator.allocate(sizeof(map_msgs__srv__GetPointMap_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__GetPointMap_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__GetPointMap_Event__Sequence__destroy(map_msgs__srv__GetPointMap_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__GetPointMap_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__GetPointMap_Event__Sequence__are_equal(const map_msgs__srv__GetPointMap_Event__Sequence * lhs, const map_msgs__srv__GetPointMap_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__GetPointMap_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__GetPointMap_Event__Sequence__copy(
  const map_msgs__srv__GetPointMap_Event__Sequence * input,
  map_msgs__srv__GetPointMap_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__srv__GetPointMap_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__GetPointMap_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__GetPointMap_Event * data =
      (map_msgs__srv__GetPointMap_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__GetPointMap_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__GetPointMap_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__GetPointMap_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
