// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_msgs:msg\PointCloud2Update.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/point_cloud2_update.h"


#ifndef MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__STRUCT_H_
#define MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'ADD'.
enum
{
  map_msgs__msg__PointCloud2Update__ADD = 0ul
};

/// Constant 'DELETE'.
enum
{
  map_msgs__msg__PointCloud2Update__DELETE = 1ul
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'points'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

/// Struct defined in msg/PointCloud2Update in the package map_msgs.
typedef struct map_msgs__msg__PointCloud2Update
{
  std_msgs__msg__Header header;
  /// type of update, one of ADD or DELETE
  uint32_t type;
  sensor_msgs__msg__PointCloud2 points;
} map_msgs__msg__PointCloud2Update;

// Struct for a sequence of map_msgs__msg__PointCloud2Update.
typedef struct map_msgs__msg__PointCloud2Update__Sequence
{
  map_msgs__msg__PointCloud2Update * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_msgs__msg__PointCloud2Update__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__STRUCT_H_
