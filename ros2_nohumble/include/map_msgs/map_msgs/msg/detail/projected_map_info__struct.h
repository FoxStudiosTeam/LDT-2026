// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_msgs:msg\ProjectedMapInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map_info.h"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__STRUCT_H_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ProjectedMapInfo in the package map_msgs.
typedef struct map_msgs__msg__ProjectedMapInfo
{
  rosidl_runtime_c__String frame_id;
  double x;
  double y;
  double width;
  double height;
  double min_z;
  double max_z;
} map_msgs__msg__ProjectedMapInfo;

// Struct for a sequence of map_msgs__msg__ProjectedMapInfo.
typedef struct map_msgs__msg__ProjectedMapInfo__Sequence
{
  map_msgs__msg__ProjectedMapInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__msg__ProjectedMapInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__STRUCT_H_
