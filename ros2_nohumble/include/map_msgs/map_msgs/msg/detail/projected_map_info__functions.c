// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:msg\ProjectedMapInfo.idl
// generated code does not contain a copyright notice
#include "map_msgs/msg/detail/projected_map_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"

bool
map_msgs__msg__ProjectedMapInfo__init(map_msgs__msg__ProjectedMapInfo * msg)
{
  if (!msg) {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    map_msgs__msg__ProjectedMapInfo__fini(msg);
    return false;
  }
  // x
  // y
  // width
  // height
  // min_z
  // max_z
  return true;
}

void
map_msgs__msg__ProjectedMapInfo__fini(map_msgs__msg__ProjectedMapInfo * msg)
{
  if (!msg) {
    return;
  }
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
  // x
  // y
  // width
  // height
  // min_z
  // max_z
}

bool
map_msgs__msg__ProjectedMapInfo__are_equal(const map_msgs__msg__ProjectedMapInfo * lhs, const map_msgs__msg__ProjectedMapInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_id), &(rhs->frame_id)))
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
map_msgs__msg__ProjectedMapInfo__copy(
  const map_msgs__msg__ProjectedMapInfo * input,
  map_msgs__msg__ProjectedMapInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_id), &(output->frame_id)))
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
  // min_z
  output->min_z = input->min_z;
  // max_z
  output->max_z = input->max_z;
  return true;
}

map_msgs__msg__ProjectedMapInfo *
map_msgs__msg__ProjectedMapInfo__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__ProjectedMapInfo * msg = (map_msgs__msg__ProjectedMapInfo *)allocator.allocate(sizeof(map_msgs__msg__ProjectedMapInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__msg__ProjectedMapInfo));
  bool success = map_msgs__msg__ProjectedMapInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__msg__ProjectedMapInfo__destroy(map_msgs__msg__ProjectedMapInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__msg__ProjectedMapInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__msg__ProjectedMapInfo__Sequence__init(map_msgs__msg__ProjectedMapInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__ProjectedMapInfo * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__msg__ProjectedMapInfo)) {
      return false;
    }
    data = (map_msgs__msg__ProjectedMapInfo *)allocator.zero_allocate(size, sizeof(map_msgs__msg__ProjectedMapInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__msg__ProjectedMapInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__msg__ProjectedMapInfo__fini(&data[i - 1]);
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
map_msgs__msg__ProjectedMapInfo__Sequence__fini(map_msgs__msg__ProjectedMapInfo__Sequence * array)
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
      map_msgs__msg__ProjectedMapInfo__fini(&array->data[i]);
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

map_msgs__msg__ProjectedMapInfo__Sequence *
map_msgs__msg__ProjectedMapInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__ProjectedMapInfo__Sequence * array = (map_msgs__msg__ProjectedMapInfo__Sequence *)allocator.allocate(sizeof(map_msgs__msg__ProjectedMapInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__msg__ProjectedMapInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__msg__ProjectedMapInfo__Sequence__destroy(map_msgs__msg__ProjectedMapInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__msg__ProjectedMapInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__msg__ProjectedMapInfo__Sequence__are_equal(const map_msgs__msg__ProjectedMapInfo__Sequence * lhs, const map_msgs__msg__ProjectedMapInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__msg__ProjectedMapInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__msg__ProjectedMapInfo__Sequence__copy(
  const map_msgs__msg__ProjectedMapInfo__Sequence * input,
  map_msgs__msg__ProjectedMapInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__msg__ProjectedMapInfo)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__msg__ProjectedMapInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__msg__ProjectedMapInfo * data =
      (map_msgs__msg__ProjectedMapInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__msg__ProjectedMapInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__msg__ProjectedMapInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__msg__ProjectedMapInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
