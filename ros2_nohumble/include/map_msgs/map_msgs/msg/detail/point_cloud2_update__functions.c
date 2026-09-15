// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:msg\PointCloud2Update.idl
// generated code does not contain a copyright notice
#include "map_msgs/msg/detail/point_cloud2_update__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `points`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"

bool
map_msgs__msg__PointCloud2Update__init(map_msgs__msg__PointCloud2Update * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    map_msgs__msg__PointCloud2Update__fini(msg);
    return false;
  }
  // type
  // points
  if (!sensor_msgs__msg__PointCloud2__init(&msg->points)) {
    map_msgs__msg__PointCloud2Update__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__msg__PointCloud2Update__fini(map_msgs__msg__PointCloud2Update * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // type
  // points
  sensor_msgs__msg__PointCloud2__fini(&msg->points);
}

bool
map_msgs__msg__PointCloud2Update__are_equal(const map_msgs__msg__PointCloud2Update * lhs, const map_msgs__msg__PointCloud2Update * rhs)
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
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__msg__PointCloud2Update__copy(
  const map_msgs__msg__PointCloud2Update * input,
  map_msgs__msg__PointCloud2Update * output)
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
  // type
  output->type = input->type;
  // points
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

map_msgs__msg__PointCloud2Update *
map_msgs__msg__PointCloud2Update__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__PointCloud2Update * msg = (map_msgs__msg__PointCloud2Update *)allocator.allocate(sizeof(map_msgs__msg__PointCloud2Update), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__msg__PointCloud2Update));
  bool success = map_msgs__msg__PointCloud2Update__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__msg__PointCloud2Update__destroy(map_msgs__msg__PointCloud2Update * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__msg__PointCloud2Update__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__msg__PointCloud2Update__Sequence__init(map_msgs__msg__PointCloud2Update__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__PointCloud2Update * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(map_msgs__msg__PointCloud2Update)) {
      return false;
    }
    data = (map_msgs__msg__PointCloud2Update *)allocator.zero_allocate(size, sizeof(map_msgs__msg__PointCloud2Update), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__msg__PointCloud2Update__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__msg__PointCloud2Update__fini(&data[i - 1]);
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
map_msgs__msg__PointCloud2Update__Sequence__fini(map_msgs__msg__PointCloud2Update__Sequence * array)
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
      map_msgs__msg__PointCloud2Update__fini(&array->data[i]);
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

map_msgs__msg__PointCloud2Update__Sequence *
map_msgs__msg__PointCloud2Update__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__msg__PointCloud2Update__Sequence * array = (map_msgs__msg__PointCloud2Update__Sequence *)allocator.allocate(sizeof(map_msgs__msg__PointCloud2Update__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__msg__PointCloud2Update__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__msg__PointCloud2Update__Sequence__destroy(map_msgs__msg__PointCloud2Update__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__msg__PointCloud2Update__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__msg__PointCloud2Update__Sequence__are_equal(const map_msgs__msg__PointCloud2Update__Sequence * lhs, const map_msgs__msg__PointCloud2Update__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__msg__PointCloud2Update__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__msg__PointCloud2Update__Sequence__copy(
  const map_msgs__msg__PointCloud2Update__Sequence * input,
  map_msgs__msg__PointCloud2Update__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(map_msgs__msg__PointCloud2Update)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(map_msgs__msg__PointCloud2Update);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__msg__PointCloud2Update * data =
      (map_msgs__msg__PointCloud2Update *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__msg__PointCloud2Update__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__msg__PointCloud2Update__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__msg__PointCloud2Update__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
