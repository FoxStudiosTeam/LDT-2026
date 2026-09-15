// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_msgs:msg\OccupancyGridUpdate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/occupancy_grid_update.h"


#ifndef MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__STRUCT_H_
#define MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/OccupancyGridUpdate in the package map_msgs.
typedef struct map_msgs__msg__OccupancyGridUpdate
{
  std_msgs__msg__Header header;
  int32_t x;
  int32_t y;
  uint32_t width;
  uint32_t height;
  rosidl_runtime_c__int8__Sequence data;
} map_msgs__msg__OccupancyGridUpdate;

// Struct for a sequence of map_msgs__msg__OccupancyGridUpdate.
typedef struct map_msgs__msg__OccupancyGridUpdate__Sequence
{
  map_msgs__msg__OccupancyGridUpdate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__msg__OccupancyGridUpdate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__STRUCT_H_
