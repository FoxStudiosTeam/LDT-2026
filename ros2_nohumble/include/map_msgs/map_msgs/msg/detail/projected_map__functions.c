// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:msg\ProjectedMap.idl
// generated code does not contain a copyright notice
#include "map_msgs/msg/detail/projected_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `map`
#include "nav_msgs/msg/detail/occupancy_grid__functions.h"

bool
map_msgs__msg__ProjectedMap__init(map_msgs__msg__ProjectedMap * msg)
{
  if (!msg) {
    return false;
  }
  // map
  if (!nav_msgs__msg__OccupancyGrid__init(&msg->map)) {
    map_msgs__msg__ProjectedMap__fini(msg);
    return false;
  }
  // min_z
  // max_z
  return true;
}

void
map_msgs__msg__ProjectedMap__fini(map_msgs__msg__ProjectedMap * msg)
{
  if (!msg) {
    return;
  }
  // map
  nav_msgs__msg__OccupancyGrid__fini(&msg->map);
  // min_z
  // max_z
}

bool
map_msgs__msg__ProjectedMap__are_equal(const map_msgs__msg__ProjectedMap * lhs, const map_msgs__msg__ProjectedMap * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // map
  if (!nav_msgs__msg__OccupancyGrid__are_equal(
      &(lhs->map), &(rhs->map)))
  {
    return false;
  }
  // min_z
  if (lhs->min_z != rhs->min_z) {
    return false;
  }
  // max_z
  if (lhs->max_z != rhs->max_z) {
    return false;
  }
  return true;
}

bool
map_msgs__msg__ProjectedMap__copy(
  const map_msgs__msg__ProjectedMap * input,
  map_msgs__msg__ProjectedMap * output)
{
  if (!input || !output) {
    return false;
  }
  // map
  if (!nav_msgs__msg__OccupancyGrid__copy(
      &(input->map), &(output->map)))
  {
    return false;
  }
  // min_z
  output->min_z = input->min_z;
  // max_z
  output->max_z = input->max_z;
  return true;
}

map_msgs__msg__ProjectedMap *
map_msgs__msg__ProjectedMap__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__ProjectedMap * msg = (map_msgs__msg__ProjectedMap *)allocator.allocate(sizeof(map_msgs__msg__ProjectedMap), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__msg__ProjectedMap));
  bool success = map_msgs__msg__ProjectedMap__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__msg__ProjectedMap__destroy(map_msgs__msg__ProjectedMap * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__msg__ProjectedMap__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__msg__ProjectedMap__Sequence__init(map_msgs__msg__ProjectedMap__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__ProjectedMap * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__msg__ProjectedMap)) {
      return false;
    }
    data = (map_msgs__msg__ProjectedMap *)allocator.zero_allocate(size, sizeof(map_msgs__msg__ProjectedMap), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__msg__ProjectedMap__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__msg__ProjectedMap__fini(&data[i - 1]);
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
map_msgs__msg__ProjectedMap__Sequence__fini(map_msgs__msg__ProjectedMap__Sequence * array)
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
      map_msgs__msg__ProjectedMap__fini(&array->data[i]);
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

map_msgs__msg__ProjectedMap__Sequence *
map_msgs__msg__ProjectedMap__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__ProjectedMap__Sequence * array = (map_msgs__msg__ProjectedMap__Sequence *)allocator.allocate(sizeof(map_msgs__msg__ProjectedMap__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__msg__ProjectedMap__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__msg__ProjectedMap__Sequence__destroy(map_msgs__msg__ProjectedMap__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__msg__ProjectedMap__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__msg__ProjectedMap__Sequence__are_equal(const map_msgs__msg__ProjectedMap__Sequence * lhs, const map_msgs__msg__ProjectedMap__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__msg__ProjectedMap__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__msg__ProjectedMap__Sequence__copy(
  const map_msgs__msg__ProjectedMap__Sequence * input,
  map_msgs__msg__ProjectedMap__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__msg__ProjectedMap)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__msg__ProjectedMap);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__msg__ProjectedMap * data =
      (map_msgs__msg__ProjectedMap *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__msg__ProjectedMap__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__msg__ProjectedMap__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__msg__ProjectedMap__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
