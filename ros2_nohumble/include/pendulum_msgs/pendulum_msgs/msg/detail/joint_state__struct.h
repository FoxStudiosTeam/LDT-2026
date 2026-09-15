// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pendulum_msgs:msg\JointState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/joint_state.h"


#ifndef PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_
#define PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/JointState in the package pendulum_msgs.
typedef struct pendulum_msgs__msg__JointState
{
  double position;
  double velocity;
  double effort;
} pendulum_msgs__msg__JointState;

// Struct for a sequence of pendulum_msgs__msg__JointState.
typedef struct pendulum_msgs__msg__JointState__Sequence
{
  pendulum_msgs__msg__JointState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pendulum_msgs__msg__JointState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PENDULUM_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_
