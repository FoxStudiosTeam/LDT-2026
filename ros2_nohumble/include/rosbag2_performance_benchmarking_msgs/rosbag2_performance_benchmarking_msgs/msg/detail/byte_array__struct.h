// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_performance_benchmarking_msgs/msg/byte_array.h"


#ifndef ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__STRUCT_H_
#define ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ByteArray in the package rosbag2_performance_benchmarking_msgs.
typedef struct rosbag2_performance_benchmarking_msgs__msg__ByteArray
{
  /// array of data
  rosidl_runtime_c__octet__Sequence data;
} rosbag2_performance_benchmarking_msgs__msg__ByteArray;

// Struct for a sequence of rosbag2_performance_benchmarking_msgs__msg__ByteArray.
typedef struct rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence
{
  rosbag2_performance_benchmarking_msgs__msg__ByteArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_performance_benchmarking_msgs__msg__ByteArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__STRUCT_H_
