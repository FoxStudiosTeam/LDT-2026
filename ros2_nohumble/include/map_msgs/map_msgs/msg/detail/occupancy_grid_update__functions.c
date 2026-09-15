// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:msg\OccupancyGridUpdate.idl
// generated code does not contain a copyright notice
#include "map_msgs/msg/detail/occupancy_grid_update__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
map_msgs__msg__OccupancyGridUpdate__init(map_msgs__msg__OccupancyGridUpdate * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    map_msgs__msg__OccupancyGridUpdate__fini(msg);
    return false;
  }
  // x
  // y
  // width
  // height
  // data
  if (!rosidl_runtime_c__int8__Sequence__init(&msg->data, 0)) {
    map_msgs__msg__OccupancyGridUpdate__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__msg__OccupancyGridUpdate__fini(map_msgs__msg__OccupancyGridUpdate * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x
  // y
  // width
  // height
  // data
  rosidl_runtime_c__int8__Sequence__fini(&msg->data);
}

bool
map_msgs__msg__OccupancyGridUpdate__are_equal(const map_msgs__msg__OccupancyGridUpdate * lhs, const map_msgs__msg__OccupancyGridUpdate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
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
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__int8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__msg__OccupancyGridUpdate__copy(
  const map_msgs__msg__OccupancyGridUpdate * input,
  map_msgs__msg__OccupancyGridUpdate * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // data
  if (!rosidl_runtime_c__int8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

map_msgs__msg__OccupancyGridUpdate *
map_msgs__msg__OccupancyGridUpdate__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__OccupancyGridUpdate * msg = (map_msgs__msg__OccupancyGridUpdate *)allocator.allocate(sizeof(map_msgs__msg__OccupancyGridUpdate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__msg__OccupancyGridUpdate));
  bool success = map_msgs__msg__OccupancyGridUpdate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__msg__OccupancyGridUpdate__destroy(map_msgs__msg__OccupancyGridUpdate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__msg__OccupancyGridUpdate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__msg__OccupancyGridUpdate__Sequence__init(map_msgs__msg__OccupancyGridUpdate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__OccupancyGridUpdate * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__msg__OccupancyGridUpdate)) {
      return false;
    }
    data = (map_msgs__msg__OccupancyGridUpdate *)allocator.zero_allocate(size, sizeof(map_msgs__msg__OccupancyGridUpdate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__msg__OccupancyGridUpdate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__msg__OccupancyGridUpdate__fini(&data[i - 1]);
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
map_msgs__msg__OccupancyGridUpdate__Sequence__fini(map_msgs__msg__OccupancyGridUpdate__Sequence * array)
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
      map_msgs__msg__OccupancyGridUpdate__fini(&array->data[i]);
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

map_msgs__msg__OccupancyGridUpdate__Sequence *
map_msgs__msg__OccupancyGridUpdate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__OccupancyGridUpdate__Sequence * array = (map_msgs__msg__OccupancyGridUpdate__Sequence *)allocator.allocate(sizeof(map_msgs__msg__OccupancyGridUpdate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__msg__OccupancyGridUpdate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__msg__OccupancyGridUpdate__Sequence__destroy(map_msgs__msg__OccupancyGridUpdate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__msg__OccupancyGridUpdate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__msg__OccupancyGridUpdate__Sequence__are_equal(const map_msgs__msg__OccupancyGridUpdate__Sequence * lhs, const map_msgs__msg__OccupancyGridUpdate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__msg__OccupancyGridUpdate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__msg__OccupancyGridUpdate__Sequence__copy(
  const map_msgs__msg__OccupancyGridUpdate__Sequence * input,
  map_msgs__msg__OccupancyGridUpdate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__msg__OccupancyGridUpdate)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__msg__OccupancyGridUpdate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__msg__OccupancyGridUpdate * data =
      (map_msgs__msg__OccupancyGridUpdate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__msg__OccupancyGridUpdate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__msg__OccupancyGridUpdate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__msg__OccupancyGridUpdate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
