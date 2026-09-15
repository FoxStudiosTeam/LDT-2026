// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtlesim_msgs:srv\Spawn.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtlesim_msgs/srv/detail/spawn__rosidl_typesupport_introspection_c.h"
#include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtlesim_msgs/srv/detail/spawn__functions.h"
#include "turtlesim_msgs/srv/detail/spawn__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__srv__Spawn_Request__init(message_memory);
}

void turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_fini_function(void * message_memory)
{
  turtlesim_msgs__srv__Spawn_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_member_array[4] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__srv__Spawn_Request, x),  // bytes offset in struct
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
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__srv__Spawn_Request, y),  // bytes offset in struct
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
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__srv__Spawn_Request, theta),  // bytes offset in struct
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
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__srv__Spawn_Request, name),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_members = {
  "turtlesim_msgs__srv",  // message namespace
  "Spawn_Request",  // message name
  4,  // number of fields
  sizeof(turtlesim_msgs__srv__Spawn_Request),
  false,  // has_any_key_member_
  turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_member_array,  // message members
  turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_type_support_handle = {
  0,
  &turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__srv__Spawn_Request__get_type_hash,
  &turtlesim_msgs__srv__Spawn_Request__get_type_description,
  &turtlesim_msgs__srv__Spawn_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Request)() {
  if (!turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__functions.h"
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__struct.h"


// Include directives for member types
// Member `name`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__srv__Spawn_Response__init(message_memory);
}

void turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_fini_function(void * message_memory)
{
  turtlesim_msgs__srv__Spawn_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_member_array[1] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__srv__Spawn_Response, name),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_members = {
  "turtlesim_msgs__srv",  // message namespace
  "Spawn_Response",  // message name
  1,  // number of fields
  sizeof(turtlesim_msgs__srv__Spawn_Response),
  false,  // has_any_key_member_
  turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_member_array,  // message members
  turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle = {
  0,
  &turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__srv__Spawn_Response__get_type_hash,
  &turtlesim_msgs__srv__Spawn_Response__get_type_description,
  &turtlesim_msgs__srv__Spawn_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Response)() {
  if (!turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__rosidl_typesupport_introspection_c.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__functions.h"
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "turtlesim_msgs/srv/spawn.h"
// Member `request`
// Member `response`
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtlesim_msgs__srv__Spawn_Event__init(message_memory);
}

void turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_fini_function(void * message_memory)
{
  turtlesim_msgs__srv__Spawn_Event__fini(message_memory);
}

size_t turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__size_function__Spawn_Event__request(
  const void * untyped_member)
{
  const turtlesim_msgs__srv__Spawn_Request__Sequence * member =
    (const turtlesim_msgs__srv__Spawn_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_const_function__Spawn_Event__request(
  const void * untyped_member, size_t index)
{
  const turtlesim_msgs__srv__Spawn_Request__Sequence * member =
    (const turtlesim_msgs__srv__Spawn_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_function__Spawn_Event__request(
  void * untyped_member, size_t index)
{
  turtlesim_msgs__srv__Spawn_Request__Sequence * member =
    (turtlesim_msgs__srv__Spawn_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__fetch_function__Spawn_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtlesim_msgs__srv__Spawn_Request * item =
    ((const turtlesim_msgs__srv__Spawn_Request *)
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_const_function__Spawn_Event__request(untyped_member, index));
  turtlesim_msgs__srv__Spawn_Request * value =
    (turtlesim_msgs__srv__Spawn_Request *)(untyped_value);
  *value = *item;
}

void turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__assign_function__Spawn_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtlesim_msgs__srv__Spawn_Request * item =
    ((turtlesim_msgs__srv__Spawn_Request *)
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_function__Spawn_Event__request(untyped_member, index));
  const turtlesim_msgs__srv__Spawn_Request * value =
    (const turtlesim_msgs__srv__Spawn_Request *)(untyped_value);
  *item = *value;
}

bool turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__resize_function__Spawn_Event__request(
  void * untyped_member, size_t size)
{
  turtlesim_msgs__srv__Spawn_Request__Sequence * member =
    (turtlesim_msgs__srv__Spawn_Request__Sequence *)(untyped_member);
  turtlesim_msgs__srv__Spawn_Request__Sequence__fini(member);
  return turtlesim_msgs__srv__Spawn_Request__Sequence__init(member, size);
}

size_t turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__size_function__Spawn_Event__response(
  const void * untyped_member)
{
  const turtlesim_msgs__srv__Spawn_Response__Sequence * member =
    (const turtlesim_msgs__srv__Spawn_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_const_function__Spawn_Event__response(
  const void * untyped_member, size_t index)
{
  const turtlesim_msgs__srv__Spawn_Response__Sequence * member =
    (const turtlesim_msgs__srv__Spawn_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_function__Spawn_Event__response(
  void * untyped_member, size_t index)
{
  turtlesim_msgs__srv__Spawn_Response__Sequence * member =
    (turtlesim_msgs__srv__Spawn_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__fetch_function__Spawn_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtlesim_msgs__srv__Spawn_Response * item =
    ((const turtlesim_msgs__srv__Spawn_Response *)
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_const_function__Spawn_Event__response(untyped_member, index));
  turtlesim_msgs__srv__Spawn_Response * value =
    (turtlesim_msgs__srv__Spawn_Response *)(untyped_value);
  *value = *item;
}

void turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__assign_function__Spawn_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtlesim_msgs__srv__Spawn_Response * item =
    ((turtlesim_msgs__srv__Spawn_Response *)
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_function__Spawn_Event__response(untyped_member, index));
  const turtlesim_msgs__srv__Spawn_Response * value =
    (const turtlesim_msgs__srv__Spawn_Response *)(untyped_value);
  *item = *value;
}

bool turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__resize_function__Spawn_Event__response(
  void * untyped_member, size_t size)
{
  turtlesim_msgs__srv__Spawn_Response__Sequence * member =
    (turtlesim_msgs__srv__Spawn_Response__Sequence *)(untyped_member);
  turtlesim_msgs__srv__Spawn_Response__Sequence__fini(member);
  return turtlesim_msgs__srv__Spawn_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtlesim_msgs__srv__Spawn_Event, info),  // bytes offset in struct
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
    offsetof(turtlesim_msgs__srv__Spawn_Event, request),  // bytes offset in struct
    NULL,  // default value
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__size_function__Spawn_Event__request,  // size() function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_const_function__Spawn_Event__request,  // get_const(index) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_function__Spawn_Event__request,  // get(index) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__fetch_function__Spawn_Event__request,  // fetch(index, &value) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__assign_function__Spawn_Event__request,  // assign(index, value) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__resize_function__Spawn_Event__request,  // resize(index) function pointer
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
    offsetof(turtlesim_msgs__srv__Spawn_Event, response),  // bytes offset in struct
    NULL,  // default value
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__size_function__Spawn_Event__response,  // size() function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_const_function__Spawn_Event__response,  // get_const(index) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__get_function__Spawn_Event__response,  // get(index) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__fetch_function__Spawn_Event__response,  // fetch(index, &value) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__assign_function__Spawn_Event__response,  // assign(index, value) function pointer
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__resize_function__Spawn_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_members = {
  "turtlesim_msgs__srv",  // message namespace
  "Spawn_Event",  // message name
  3,  // number of fields
  sizeof(turtlesim_msgs__srv__Spawn_Event),
  false,  // has_any_key_member_
  turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_member_array,  // message members
  turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_type_support_handle = {
  0,
  &turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_members,
  get_message_typesupport_handle_function,
  &turtlesim_msgs__srv__Spawn_Event__get_type_hash,
  &turtlesim_msgs__srv__Spawn_Event__get_type_description,
  &turtlesim_msgs__srv__Spawn_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Event)() {
  turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Request)();
  turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Response)();
  if (!turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "turtlesim_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "turtlesim_msgs/srv/detail/spawn__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_members = {
  "turtlesim_msgs__srv",  // service namespace
  "Spawn",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_Request_message_type_support_handle,
  NULL,  // response message
  // turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle
  NULL  // event_message
  // turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle
};


static rosidl_service_type_support_t turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_type_support_handle = {
  0,
  &turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_members,
  get_service_typesupport_handle_function,
  &turtlesim_msgs__srv__Spawn_Request__rosidl_typesupport_introspection_c__Spawn_Request_message_type_support_handle,
  &turtlesim_msgs__srv__Spawn_Response__rosidl_typesupport_introspection_c__Spawn_Response_message_type_support_handle,
  &turtlesim_msgs__srv__Spawn_Event__rosidl_typesupport_introspection_c__Spawn_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtlesim_msgs,
    srv,
    Spawn
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    turtlesim_msgs,
    srv,
    Spawn
  ),
  &turtlesim_msgs__srv__Spawn__get_type_hash,
  &turtlesim_msgs__srv__Spawn__get_type_description,
  &turtlesim_msgs__srv__Spawn__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtlesim_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn)(void) {
  if (!turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_type_support_handle.typesupport_identifier) {
    turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim_msgs, srv, Spawn_Event)()->data;
  }

  return &turtlesim_msgs__srv__detail__spawn__rosidl_typesupport_introspection_c__Spawn_service_type_support_handle;
}
