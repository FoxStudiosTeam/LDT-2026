// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:srv\GetMapROI.idl
// generated code does not contain a copyright notice
#include "map_msgs/srv/detail/get_map_roi__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
map_msgs__srv__GetMapROI_Request__init(map_msgs__srv__GetMapROI_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // l_x
  // l_y
  return true;
}

void
map_msgs__srv__GetMapROI_Request__fini(map_msgs__srv__GetMapROI_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // l_x
  // l_y
}

bool
map_msgs__srv__GetMapROI_Request__are_equal(const map_msgs__srv__GetMapROI_Request * lhs, const map_msgs__srv__GetMapROI_Request * rhs)
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
  // l_x
  if (lhs->l_x != rhs->l_x) {
    return false;
  }
  // l_y
  if (lhs->l_y != rhs->l_y) {
    return false;
  }
  return true;
}

bool
map_msgs__srv__GetMapROI_Request__copy(
  const map_msgs__srv__GetMapROI_Request * input,
  map_msgs__srv__GetMapROI_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // l_x
  output->l_x = input->l_x;
  // l_y
  output->l_y = input->l_y;
  return true;
}

map_msgs__srv__GetMapROI_Request *
map_msgs__srv__GetMapROI_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Request * msg = (map_msgs__srv__GetMapROI_Request *)allocator.allocate(sizeof(map_msgs__srv__GetMapROI_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__GetMapROI_Request));
  bool success = map_msgs__srv__GetMapROI_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__GetMapROI_Request__destroy(map_msgs__srv__GetMapROI_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__GetMapROI_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__GetMapROI_Request__Sequence__init(map_msgs__srv__GetMapROI_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__srv__GetMapROI_Request)) {
      return false;
    }
    data = (map_msgs__srv__GetMapROI_Request *)allocator.zero_allocate(size, sizeof(map_msgs__srv__GetMapROI_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__GetMapROI_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__GetMapROI_Request__fini(&data[i - 1]);
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
map_msgs__srv__GetMapROI_Request__Sequence__fini(map_msgs__srv__GetMapROI_Request__Sequence * array)
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
      map_msgs__srv__GetMapROI_Request__fini(&array->data[i]);
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

map_msgs__srv__GetMapROI_Request__Sequence *
map_msgs__srv__GetMapROI_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Request__Sequence * array = (map_msgs__srv__GetMapROI_Request__Sequence *)allocator.allocate(sizeof(map_msgs__srv__GetMapROI_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__GetMapROI_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__GetMapROI_Request__Sequence__destroy(map_msgs__srv__GetMapROI_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__GetMapROI_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__GetMapROI_Request__Sequence__are_equal(const map_msgs__srv__GetMapROI_Request__Sequence * lhs, const map_msgs__srv__GetMapROI_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__GetMapROI_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__GetMapROI_Request__Sequence__copy(
  const map_msgs__srv__GetMapROI_Request__Sequence * input,
  map_msgs__srv__GetMapROI_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__srv__GetMapROI_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__GetMapROI_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__GetMapROI_Request * data =
      (map_msgs__srv__GetMapROI_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__GetMapROI_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__GetMapROI_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__GetMapROI_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `sub_map`
#include "nav_msgs/msg/detail/occupancy_grid__functions.h"

bool
map_msgs__srv__GetMapROI_Response__init(map_msgs__srv__GetMapROI_Response * msg)
{
  if (!msg) {
    return false;
  }
  // sub_map
  if (!nav_msgs__msg__OccupancyGrid__init(&msg->sub_map)) {
    map_msgs__srv__GetMapROI_Response__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__srv__GetMapROI_Response__fini(map_msgs__srv__GetMapROI_Response * msg)
{
  if (!msg) {
    return;
  }
  // sub_map
  nav_msgs__msg__OccupancyGrid__fini(&msg->sub_map);
}

bool
map_msgs__srv__GetMapROI_Response__are_equal(const map_msgs__srv__GetMapROI_Response * lhs, const map_msgs__srv__GetMapROI_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sub_map
  if (!nav_msgs__msg__OccupancyGrid__are_equal(
      &(lhs->sub_map), &(rhs->sub_map)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__srv__GetMapROI_Response__copy(
  const map_msgs__srv__GetMapROI_Response * input,
  map_msgs__srv__GetMapROI_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // sub_map
  if (!nav_msgs__msg__OccupancyGrid__copy(
      &(input->sub_map), &(output->sub_map)))
  {
    return false;
  }
  return true;
}

map_msgs__srv__GetMapROI_Response *
map_msgs__srv__GetMapROI_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Response * msg = (map_msgs__srv__GetMapROI_Response *)allocator.allocate(sizeof(map_msgs__srv__GetMapROI_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__GetMapROI_Response));
  bool success = map_msgs__srv__GetMapROI_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__GetMapROI_Response__destroy(map_msgs__srv__GetMapROI_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__GetMapROI_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__GetMapROI_Response__Sequence__init(map_msgs__srv__GetMapROI_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__srv__GetMapROI_Response)) {
      return false;
    }
    data = (map_msgs__srv__GetMapROI_Response *)allocator.zero_allocate(size, sizeof(map_msgs__srv__GetMapROI_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__GetMapROI_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__GetMapROI_Response__fini(&data[i - 1]);
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
map_msgs__srv__GetMapROI_Response__Sequence__fini(map_msgs__srv__GetMapROI_Response__Sequence * array)
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
      map_msgs__srv__GetMapROI_Response__fini(&array->data[i]);
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

map_msgs__srv__GetMapROI_Response__Sequence *
map_msgs__srv__GetMapROI_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Response__Sequence * array = (map_msgs__srv__GetMapROI_Response__Sequence *)allocator.allocate(sizeof(map_msgs__srv__GetMapROI_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__GetMapROI_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__GetMapROI_Response__Sequence__destroy(map_msgs__srv__GetMapROI_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__GetMapROI_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__GetMapROI_Response__Sequence__are_equal(const map_msgs__srv__GetMapROI_Response__Sequence * lhs, const map_msgs__srv__GetMapROI_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__GetMapROI_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__GetMapROI_Response__Sequence__copy(
  const map_msgs__srv__GetMapROI_Response__Sequence * input,
  map_msgs__srv__GetMapROI_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__srv__GetMapROI_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__GetMapROI_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__GetMapROI_Response * data =
      (map_msgs__srv__GetMapROI_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__GetMapROI_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__GetMapROI_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__GetMapROI_Response__copy(
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
// #include "map_msgs/srv/detail/get_map_roi__functions.h"

bool
map_msgs__srv__GetMapROI_Event__init(map_msgs__srv__GetMapROI_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    map_msgs__srv__GetMapROI_Event__fini(msg);
    return false;
  }
  // request
  if (!map_msgs__srv__GetMapROI_Request__Sequence__init(&msg->request, 0)) {
    map_msgs__srv__GetMapROI_Event__fini(msg);
    return false;
  }
  // response
  if (!map_msgs__srv__GetMapROI_Response__Sequence__init(&msg->response, 0)) {
    map_msgs__srv__GetMapROI_Event__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__srv__GetMapROI_Event__fini(map_msgs__srv__GetMapROI_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  map_msgs__srv__GetMapROI_Request__Sequence__fini(&msg->request);
  // response
  map_msgs__srv__GetMapROI_Response__Sequence__fini(&msg->response);
}

bool
map_msgs__srv__GetMapROI_Event__are_equal(const map_msgs__srv__GetMapROI_Event * lhs, const map_msgs__srv__GetMapROI_Event * rhs)
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
  if (!map_msgs__srv__GetMapROI_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!map_msgs__srv__GetMapROI_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__srv__GetMapROI_Event__copy(
  const map_msgs__srv__GetMapROI_Event * input,
  map_msgs__srv__GetMapROI_Event * output)
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
  if (!map_msgs__srv__GetMapROI_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!map_msgs__srv__GetMapROI_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

map_msgs__srv__GetMapROI_Event *
map_msgs__srv__GetMapROI_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Event * msg = (map_msgs__srv__GetMapROI_Event *)allocator.allocate(sizeof(map_msgs__srv__GetMapROI_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__GetMapROI_Event));
  bool success = map_msgs__srv__GetMapROI_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__GetMapROI_Event__destroy(map_msgs__srv__GetMapROI_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__GetMapROI_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__GetMapROI_Event__Sequence__init(map_msgs__srv__GetMapROI_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__srv__GetMapROI_Event)) {
      return false;
    }
    data = (map_msgs__srv__GetMapROI_Event *)allocator.zero_allocate(size, sizeof(map_msgs__srv__GetMapROI_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__GetMapROI_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__GetMapROI_Event__fini(&data[i - 1]);
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
map_msgs__srv__GetMapROI_Event__Sequence__fini(map_msgs__srv__GetMapROI_Event__Sequence * array)
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
      map_msgs__srv__GetMapROI_Event__fini(&array->data[i]);
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

map_msgs__srv__GetMapROI_Event__Sequence *
map_msgs__srv__GetMapROI_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__GetMapROI_Event__Sequence * array = (map_msgs__srv__GetMapROI_Event__Sequence *)allocator.allocate(sizeof(map_msgs__srv__GetMapROI_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__GetMapROI_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__GetMapROI_Event__Sequence__destroy(map_msgs__srv__GetMapROI_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__GetMapROI_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__GetMapROI_Event__Sequence__are_equal(const map_msgs__srv__GetMapROI_Event__Sequence * lhs, const map_msgs__srv__GetMapROI_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__GetMapROI_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__GetMapROI_Event__Sequence__copy(
  const map_msgs__srv__GetMapROI_Event__Sequence * input,
  map_msgs__srv__GetMapROI_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__srv__GetMapROI_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__GetMapROI_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__GetMapROI_Event * data =
      (map_msgs__srv__GetMapROI_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__GetMapROI_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__GetMapROI_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__GetMapROI_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
