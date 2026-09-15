// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pendulum_msgs:msg\JointCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/joint_command.h"


#ifndef PENDULUM_MSGS__MSG__DETAIL__JOINT_COMMAND__STRUCT_H_
#define PENDULUM_MSGS__MSG__DETAIL__JOINT_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/JointCommand in the package pendulum_msgs.
typedef struct pendulum_msgs__msg__JointCommand
{
  double position;
} pendulum_msgs__msg__JointCommand;

// Struct for a sequence of pendulum_msgs__msg__JointCommand.
typedef struct pendulum_msgs__msg__JointCommand__Sequence
{
  pendulum_msgs__msg__JointCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pendulum_msgs__msg__JointCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PENDULUM_MSGS__MSG__DETAIL__JOINT_COMMAND__STRUCT_H_
