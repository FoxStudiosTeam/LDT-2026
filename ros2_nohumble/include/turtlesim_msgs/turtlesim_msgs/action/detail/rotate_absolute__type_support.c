// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlesim_msgs:action\RotateAbsolute.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
#include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
#include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_Goal__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_member_array[1] = {
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_Goal, theta),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_Goal",  // message name
  1,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_Goal),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_Goal__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_Goal__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_Goal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_Goal)() {
  if (!turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_Goal__rosidl_typesupport_introspection_c__RotateAbsolute_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_Result__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_member_array[1] = {
  {
    "delta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_Result, delta),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_Result",  // message name
  1,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_Result),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_Result__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_Result__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_Result__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_Result)() {
  if (!turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_Result__rosidl_typesupport_introspection_c__RotateAbsolute_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_Feedback__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_member_array[1] = {
  {
    "remaining",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_Feedback, remaining),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_Feedback",  // message name
  1,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_Feedback),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_Feedback__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_Feedback__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_Feedback__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_Feedback)() {
  if (!turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_Feedback__rosidl_typesupport_introspection_c__RotateAbsolute_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "turtlesim_msgs/action/rotate_absolute.h"
// Member `goal`
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Request, goal_id),  // bytes offset in struct
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
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Request, goal),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Request),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Request)() {
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_Goal)();
  if (!turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Response, accepted),  // bytes offset in struct
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
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Response, stamp),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Response),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Response)() {
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "turtlesim_msgs/action/rotate_absolute.h"
// Member `request`
// Member `response`
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__fini(message_memory);
}

size_t turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_SendGoal_Event__request(
  const void * untyped_member)
{
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_SendGoal_Event__request(
  const void * untyped_member, size_t index)
{
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_SendGoal_Event__request(
  void * untyped_member, size_t index)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request * item =
    ((const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request *)
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_SendGoal_Event__request(untyped_member, index));
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request * value =
    (turtlesim_msgs__action__RotateAbsolute_SendGoal_Request *)(untyped_value);
  *value = *item;
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request * item =
    ((turtlesim_msgs__action__RotateAbsolute_SendGoal_Request *)
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_SendGoal_Event__request(untyped_member, index));
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request * value =
    (const turtlesim_msgs__action__RotateAbsolute_SendGoal_Request *)(untyped_value);
  *item = *value;
}

bool turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_SendGoal_Event__request(
  void * untyped_member, size_t size)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence *)(untyped_member);
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence__fini(member);
  return turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__Sequence__init(member, size);
}

size_t turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_SendGoal_Event__response(
  const void * untyped_member)
{
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_SendGoal_Event__response(
  const void * untyped_member, size_t index)
{
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_SendGoal_Event__response(
  void * untyped_member, size_t index)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response * item =
    ((const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response *)
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_SendGoal_Event__response(untyped_member, index));
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response * value =
    (turtlesim_msgs__action__RotateAbsolute_SendGoal_Response *)(untyped_value);
  *value = *item;
}

void turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response * item =
    ((turtlesim_msgs__action__RotateAbsolute_SendGoal_Response *)
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_SendGoal_Event__response(untyped_member, index));
  const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response * value =
    (const turtlesim_msgs__action__RotateAbsolute_SendGoal_Response *)(untyped_value);
  *item = *value;
}

bool turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_SendGoal_Event__response(
  void * untyped_member, size_t size)
{
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence *)(untyped_member);
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence__fini(member);
  return turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Event, info),  // bytes offset in struct
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
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Event, request),  // bytes offset in struct
    NULL,  // default value
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_SendGoal_Event__request,  // size() function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_SendGoal_Event__request,  // get_const(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_SendGoal_Event__request,  // get(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_SendGoal_Event__request,  // fetch(index, &value) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_SendGoal_Event__request,  // assign(index, value) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_SendGoal_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Event, response),  // bytes offset in struct
    NULL,  // default value
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_SendGoal_Event__response,  // size() function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_SendGoal_Event__response,  // get_const(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_SendGoal_Event__response,  // get(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_SendGoal_Event__response,  // fetch(index, &value) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_SendGoal_Event__response,  // assign(index, value) function pointer
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_SendGoal_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_SendGoal_Event),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Event)() {
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Request)();
  turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Response)();
  if (!turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_members = {
  "turtlesim_msgs__action",  // service namespace
  "RotateAbsolute_SendGoal",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_type_support_handle,
  NULL,  // response message
  // turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle
  NULL  // event_message
  // turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle
};


static rosidl_service_type_support_t turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_type_support_handle = {
  0,
  &turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_members,
  get_service_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Request__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Request_message_type_support_handle,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Response__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Response_message_type_support_handle,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal_Event__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtlesim_msgs,
    action,
    RotateAbsolute_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtlesim_msgs,
    action,
    RotateAbsolute_SendGoal
  ),
  &turtlesim_msgs__action__RotateAbsolute_SendGoal__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_SendGoal__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal)(void) {
  if (!turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_SendGoal_Event)()->data;
  }

  return &turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_GetResult_Request, goal_id),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_GetResult_Request),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Request__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Request__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Request)() {
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "turtlesim_msgs/action/rotate_absolute.h"
// Member `result`
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_GetResult_Response, status),  // bytes offset in struct
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
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_GetResult_Response, result),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_GetResult_Response),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Response__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Response__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Response)() {
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_Result)();
  if (!turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/service_event_info.h"
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "turtlesim_msgs/action/rotate_absolute.h"
// Member `request`
// Member `response`
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__fini(message_memory);
}

size_t turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_GetResult_Event__request(
  const void * untyped_member)
{
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_GetResult_Event__request(
  const void * untyped_member, size_t index)
{
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_GetResult_Event__request(
  void * untyped_member, size_t index)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Request * item =
    ((const turtlesim_msgs__action__RotateAbsolute_GetResult_Request *)
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_GetResult_Event__request(untyped_member, index));
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request * value =
    (turtlesim_msgs__action__RotateAbsolute_GetResult_Request *)(untyped_value);
  *value = *item;
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request * item =
    ((turtlesim_msgs__action__RotateAbsolute_GetResult_Request *)
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_GetResult_Event__request(untyped_member, index));
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Request * value =
    (const turtlesim_msgs__action__RotateAbsolute_GetResult_Request *)(untyped_value);
  *item = *value;
}

bool turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_GetResult_Event__request(
  void * untyped_member, size_t size)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence *)(untyped_member);
  turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence__fini(member);
  return turtlesim_msgs__action__RotateAbsolute_GetResult_Request__Sequence__init(member, size);
}

size_t turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_GetResult_Event__response(
  const void * untyped_member)
{
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_GetResult_Event__response(
  const void * untyped_member, size_t index)
{
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence * member =
    (const turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_GetResult_Event__response(
  void * untyped_member, size_t index)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Response * item =
    ((const turtlesim_msgs__action__RotateAbsolute_GetResult_Response *)
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_GetResult_Event__response(untyped_member, index));
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response * value =
    (turtlesim_msgs__action__RotateAbsolute_GetResult_Response *)(untyped_value);
  *value = *item;
}

void turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response * item =
    ((turtlesim_msgs__action__RotateAbsolute_GetResult_Response *)
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_GetResult_Event__response(untyped_member, index));
  const turtlesim_msgs__action__RotateAbsolute_GetResult_Response * value =
    (const turtlesim_msgs__action__RotateAbsolute_GetResult_Response *)(untyped_value);
  *item = *value;
}

bool turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_GetResult_Event__response(
  void * untyped_member, size_t size)
{
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence * member =
    (turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence *)(untyped_member);
  turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence__fini(member);
  return turtlesim_msgs__action__RotateAbsolute_GetResult_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_GetResult_Event, info),  // bytes offset in struct
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
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_GetResult_Event, request),  // bytes offset in struct
    NULL,  // default value
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_GetResult_Event__request,  // size() function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_GetResult_Event__request,  // get_const(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_GetResult_Event__request,  // get(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_GetResult_Event__request,  // fetch(index, &value) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_GetResult_Event__request,  // assign(index, value) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_GetResult_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_GetResult_Event, response),  // bytes offset in struct
    NULL,  // default value
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__size_function__RotateAbsolute_GetResult_Event__response,  // size() function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__RotateAbsolute_GetResult_Event__response,  // get_const(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__get_function__RotateAbsolute_GetResult_Event__response,  // get(index) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__RotateAbsolute_GetResult_Event__response,  // fetch(index, &value) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__RotateAbsolute_GetResult_Event__response,  // assign(index, value) function pointer
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__RotateAbsolute_GetResult_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_GetResult_Event),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Event__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Event__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Event)() {
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Request)();
  turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Response)();
  if (!turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_members = {
  "turtlesim_msgs__action",  // service namespace
  "RotateAbsolute_GetResult",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_type_support_handle,
  NULL,  // response message
  // turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle
  NULL  // event_message
  // turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle
};


static rosidl_service_type_support_t turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_type_support_handle = {
  0,
  &turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_members,
  get_service_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Request__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Request_message_type_support_handle,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Response__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Response_message_type_support_handle,
  &turtlesim_msgs__action__RotateAbsolute_GetResult_Event__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtlesim_msgs,
    action,
    RotateAbsolute_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtlesim_msgs,
    action,
    RotateAbsolute_GetResult
  ),
  &turtlesim_msgs__action__RotateAbsolute_GetResult__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_GetResult__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_GetResult__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult)(void) {
  if (!turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_GetResult_Event)()->data;
  }

  return &turtlesim_msgs__action__detail__rotate_absolute__rosidl_typesupport_introspection_c__RotateAbsolute_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__functions.h"
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "turtlesim_msgs/action/rotate_absolute.h"
// Member `feedback`
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__init(message_memory);
}

void turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_fini_function(void * message_memory)
{
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_FeedbackMessage, goal_id),  // bytes offset in struct
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
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__action__RotateAbsolute_FeedbackMessage, feedback),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_members = {
  "turtlesim_msgs__action",  // message namespace
  "RotateAbsolute_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(turtlesim_msgs__action__RotateAbsolute_FeedbackMessage),
  false,  // has_any_key_member_
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_member_array,  // message members
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_type_support_handle = {
  0,
  &turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__get_type_hash,
  &turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__get_type_description,
  &turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_FeedbackMessage)() {
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, action, RotateAbsolute_Feedback)();
  if (!turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__action__RotateAbsolute_FeedbackMessage__rosidl_typesupport_introspection_c__RotateAbsolute_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
