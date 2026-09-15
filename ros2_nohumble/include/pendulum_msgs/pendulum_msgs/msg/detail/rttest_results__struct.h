// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/rttest_results.h"


#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__STRUCT_H_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'command'
#include "pendulum_msgs/msg/detail/joint_command__struct.h"
// Member 'state'
#include "pendulum_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in msg/RttestResults in the package pendulum_msgs.
typedef struct pendulum_msgs__msg__RttestResults
{
  builtin_interfaces__msg__Time stamp;
  pendulum_msgs__msg__JointCommand command;
  pendulum_msgs__msg__JointState state;
  uint64_t cur_latency;
  double mean_latency;
  uint64_t min_latency;
  uint64_t max_latency;
  uint64_t minor_pagefaults;
  uint64_t major_pagefaults;
} pendulum_msgs__msg__RttestResults;

// Struct for a sequence of pendulum_msgs__msg__RttestResults.
typedef struct pendulum_msgs__msg__RttestResults__Sequence
{
  pendulum_msgs__msg__RttestResults * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pendulum_msgs__msg__RttestResults__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__STRUCT_H_
