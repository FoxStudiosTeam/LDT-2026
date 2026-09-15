// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pendulum_msgs/msg/detail/rttest_results__rosidl_typesupport_introspection_c.h"
#include "pendulum_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pendulum_msgs/msg/detail/rttest_results__functions.h"
#include "pendulum_msgs/msg/detail/rttest_results__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `command`
#include "pendulum_msgs/msg/joint_command.h"
// Member `command`
#include "pendulum_msgs/msg/detail/joint_command__rosidl_typesupport_introspection_c.h"
// Member `state`
#include "pendulum_msgs/msg/joint_state.h"
// Member `state`
#include "pendulum_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pendulum_msgs__msg__RttestResults__init(message_memory);
}

void pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_fini_function(void * message_memory)
{
  pendulum_msgs__msg__RttestResults__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_member_array[9] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "cur_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, cur_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "mean_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, mean_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "min_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, min_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "max_latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, max_latency),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "minor_pagefaults",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, minor_pagefaults),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "major_pagefaults",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pendulum_msgs__msg__RttestResults, major_pagefaults),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_members = {
  "pendulum_msgs__msg",  // message namespace
  "RttestResults",  // message name
  9,  // number of fields
  sizeof(pendulum_msgs__msg__RttestResults),
  false,  // has_any_key_member_
  pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_member_array,  // message members
  pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_init_function,  // function to initialize message memory (memory has to be allocated)
  pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_type_support_handle = {
  0,
  &pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_members,
  get_message_typesupport_handle_function,
  &pendulum_msgs__msg__RttestResults__get_type_hash,
  &pendulum_msgs__msg__RttestResults__get_type_description,
  &pendulum_msgs__msg__RttestResults__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pendulum_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pendulum_msgs, msg, RttestResults)() {
  pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pendulum_msgs, msg, JointCommand)();
  pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pendulum_msgs, msg, JointState)();
  if (!pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_type_support_handle.typesupport_identifier) {
    pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pendulum_msgs__msg__RttestResults__rosidl_typesupport_introspection_c__RttestResults_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
