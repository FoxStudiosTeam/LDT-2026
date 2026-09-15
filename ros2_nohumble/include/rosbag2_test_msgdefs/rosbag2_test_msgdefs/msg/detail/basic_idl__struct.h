// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_test_msgdefs:msg\BasicIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/basic_idl.h"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__STRUCT_H_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/BasicIdl in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__msg__BasicIdl
{
  float x;
} rosbag2_test_msgdefs__msg__BasicIdl;

// Struct for a sequence of rosbag2_test_msgdefs__msg__BasicIdl.
typedef struct rosbag2_test_msgdefs__msg__BasicIdl__Sequence
{
  rosbag2_test_msgdefs__msg__BasicIdl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__msg__BasicIdl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__STRUCT_H_
