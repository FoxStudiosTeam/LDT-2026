// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_msgs:msg\ProjectedMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map.h"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__STRUCT_H_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'map'
#include "nav_msgs/msg/detail/occupancy_grid__struct.h"

/// Struct defined in msg/ProjectedMap in the package map_msgs.
typedef struct map_msgs__msg__ProjectedMap
{
  nav_msgs__msg__OccupancyGrid map;
  double min_z;
  double max_z;
} map_msgs__msg__ProjectedMap;

// Struct for a sequence of map_msgs__msg__ProjectedMap.
typedef struct map_msgs__msg__ProjectedMap__Sequence
{
  map_msgs__msg__ProjectedMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__msg__ProjectedMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__STRUCT_H_
