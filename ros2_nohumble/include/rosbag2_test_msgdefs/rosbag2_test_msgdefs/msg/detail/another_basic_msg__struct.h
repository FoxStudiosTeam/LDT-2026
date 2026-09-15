// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_test_msgdefs:msg\AnotherBasicMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/another_basic_msg.h"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__STRUCT_H_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/AnotherBasicMsg in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__msg__AnotherBasicMsg
{
  float c;
} rosbag2_test_msgdefs__msg__AnotherBasicMsg;

// Struct for a sequence of rosbag2_test_msgdefs__msg__AnotherBasicMsg.
typedef struct rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence
{
  rosbag2_test_msgdefs__msg__AnotherBasicMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__msg__AnotherBasicMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__STRUCT_H_
