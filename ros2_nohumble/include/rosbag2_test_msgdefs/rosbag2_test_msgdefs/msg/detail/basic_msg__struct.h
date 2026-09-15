// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_test_msgdefs:msg\BasicMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/basic_msg.h"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_MSG__STRUCT_H_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/BasicMsg in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__msg__BasicMsg
{
  float c;
} rosbag2_test_msgdefs__msg__BasicMsg;

// Struct for a sequence of rosbag2_test_msgdefs__msg__BasicMsg.
typedef struct rosbag2_test_msgdefs__msg__BasicMsg__Sequence
{
  rosbag2_test_msgdefs__msg__BasicMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__msg__BasicMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_MSG__STRUCT_H_
