// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_test_msgdefs:msg\ComplexWithRelativeDep.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/complex_with_relative_dep.h"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__STRUCT_H_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'a'
#include "rosbag2_test_msgdefs/msg/detail/basic_idl__struct.h"

/// Struct defined in msg/ComplexWithRelativeDep in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__msg__ComplexWithRelativeDep
{
  rosbag2_test_msgdefs__msg__BasicIdl a;
} rosbag2_test_msgdefs__msg__ComplexWithRelativeDep;

// Struct for a sequence of rosbag2_test_msgdefs__msg__ComplexWithRelativeDep.
typedef struct rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence
{
  rosbag2_test_msgdefs__msg__ComplexWithRelativeDep * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__msg__ComplexWithRelativeDep__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__STRUCT_H_
