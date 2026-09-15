// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rosbag2_test_msgdefs:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rosbag2_test_msgdefs/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
#include "rosbag2_test_msgdefs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosbag2_test_msgdefs/srv/detail/basic_srv__functions.h"
#include "rosbag2_test_msgdefs/srv/detail/basic_srv__struct.h"


// Include directives for member types
// Member `req`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_test_msgdefs__srv__BasicSrv_Request__init(message_memory);
}

void rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_fini_function(void * message_memory)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_member_array[1] = {
  {
    "req",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_test_msgdefs__srv__BasicSrv_Request, req),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_members = {
  "rosbag2_test_msgdefs__srv",  // message namespace
  "BasicSrv_Request",  // message name
  1,  // number of fields
  sizeof(rosbag2_test_msgdefs__srv__BasicSrv_Request),
  false,  // has_any_key_member_
  rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_member_array,  // message members
  rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle = {
  0,
  &rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_hash,
  &rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_description,
  &rosbag2_test_msgdefs__srv__BasicSrv_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Request)() {
  if (!rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle.typesupport_identifier) {
    rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__functions.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__struct.h"


// Include directives for member types
// Member `resp`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_test_msgdefs__srv__BasicSrv_Response__init(message_memory);
}

void rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_fini_function(void * message_memory)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_member_array[1] = {
  {
    "resp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_test_msgdefs__srv__BasicSrv_Response, resp),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_members = {
  "rosbag2_test_msgdefs__srv",  // message namespace
  "BasicSrv_Response",  // message name
  1,  // number of fields
  sizeof(rosbag2_test_msgdefs__srv__BasicSrv_Response),
  false,  // has_any_key_member_
  rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_member_array,  // message members
  rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle = {
  0,
  &rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_hash,
  &rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_description,
  &rosbag2_test_msgdefs__srv__BasicSrv_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Response)() {
  if (!rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle.typesupport_identifier) {
    rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__functions.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "rosbag2_test_msgdefs/srv/basic_srv.h"
// Member `request`
// Member `response`
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_test_msgdefs__srv__BasicSrv_Event__init(message_memory);
}

void rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_fini_function(void * message_memory)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Event__fini(message_memory);
}

size_t rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__size_function__BasicSrv_Event__request(
  const void * untyped_member)
{
  const rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence * member =
    (const rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_const_function__BasicSrv_Event__request(
  const void * untyped_member, size_t index)
{
  const rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence * member =
    (const rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_function__BasicSrv_Event__request(
  void * untyped_member, size_t index)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence * member =
    (rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__fetch_function__BasicSrv_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosbag2_test_msgdefs__srv__BasicSrv_Request * item =
    ((const rosbag2_test_msgdefs__srv__BasicSrv_Request *)
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_const_function__BasicSrv_Event__request(untyped_member, index));
  rosbag2_test_msgdefs__srv__BasicSrv_Request * value =
    (rosbag2_test_msgdefs__srv__BasicSrv_Request *)(untyped_value);
  *value = *item;
}

void rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__assign_function__BasicSrv_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Request * item =
    ((rosbag2_test_msgdefs__srv__BasicSrv_Request *)
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_function__BasicSrv_Event__request(untyped_member, index));
  const rosbag2_test_msgdefs__srv__BasicSrv_Request * value =
    (const rosbag2_test_msgdefs__srv__BasicSrv_Request *)(untyped_value);
  *item = *value;
}

bool rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__resize_function__BasicSrv_Event__request(
  void * untyped_member, size_t size)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence * member =
    (rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence *)(untyped_member);
  rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__fini(member);
  return rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence__init(member, size);
}

size_t rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__size_function__BasicSrv_Event__response(
  const void * untyped_member)
{
  const rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence * member =
    (const rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_const_function__BasicSrv_Event__response(
  const void * untyped_member, size_t index)
{
  const rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence * member =
    (const rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_function__BasicSrv_Event__response(
  void * untyped_member, size_t index)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence * member =
    (rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__fetch_function__BasicSrv_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosbag2_test_msgdefs__srv__BasicSrv_Response * item =
    ((const rosbag2_test_msgdefs__srv__BasicSrv_Response *)
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_const_function__BasicSrv_Event__response(untyped_member, index));
  rosbag2_test_msgdefs__srv__BasicSrv_Response * value =
    (rosbag2_test_msgdefs__srv__BasicSrv_Response *)(untyped_value);
  *value = *item;
}

void rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__assign_function__BasicSrv_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Response * item =
    ((rosbag2_test_msgdefs__srv__BasicSrv_Response *)
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_function__BasicSrv_Event__response(untyped_member, index));
  const rosbag2_test_msgdefs__srv__BasicSrv_Response * value =
    (const rosbag2_test_msgdefs__srv__BasicSrv_Response *)(untyped_value);
  *item = *value;
}

bool rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__resize_function__BasicSrv_Event__response(
  void * untyped_member, size_t size)
{
  rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence * member =
    (rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence *)(untyped_member);
  rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__fini(member);
  return rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_test_msgdefs__srv__BasicSrv_Event, info),  // bytes offset in struct
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
    offsetof(rosbag2_test_msgdefs__srv__BasicSrv_Event, request),  // bytes offset in struct
    NULL,  // default value
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__size_function__BasicSrv_Event__request,  // size() function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_const_function__BasicSrv_Event__request,  // get_const(index) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_function__BasicSrv_Event__request,  // get(index) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__fetch_function__BasicSrv_Event__request,  // fetch(index, &value) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__assign_function__BasicSrv_Event__request,  // assign(index, value) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__resize_function__BasicSrv_Event__request,  // resize(index) function pointer
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
    offsetof(rosbag2_test_msgdefs__srv__BasicSrv_Event, response),  // bytes offset in struct
    NULL,  // default value
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__size_function__BasicSrv_Event__response,  // size() function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_const_function__BasicSrv_Event__response,  // get_const(index) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__get_function__BasicSrv_Event__response,  // get(index) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__fetch_function__BasicSrv_Event__response,  // fetch(index, &value) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__assign_function__BasicSrv_Event__response,  // assign(index, value) function pointer
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__resize_function__BasicSrv_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_members = {
  "rosbag2_test_msgdefs__srv",  // message namespace
  "BasicSrv_Event",  // message name
  3,  // number of fields
  sizeof(rosbag2_test_msgdefs__srv__BasicSrv_Event),
  false,  // has_any_key_member_
  rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_member_array,  // message members
  rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_type_support_handle = {
  0,
  &rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_hash,
  &rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_description,
  &rosbag2_test_msgdefs__srv__BasicSrv_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Event)() {
  rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Request)();
  rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Response)();
  if (!rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_type_support_handle.typesupport_identifier) {
    rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_members = {
  "rosbag2_test_msgdefs__srv",  // service namespace
  "BasicSrv",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle,
  NULL,  // response message
  // rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle
  NULL  // event_message
  // rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle
};


static rosidl_service_type_support_t rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle = {
  0,
  &rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_members,
  get_service_typesupport_handle_function,
  &rosbag2_test_msgdefs__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle,
  &rosbag2_test_msgdefs__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle,
  &rosbag2_test_msgdefs__srv__BasicSrv_Event__rosidl_typesupport_introspection_c__BasicSrv_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rosbag2_test_msgdefs,
    srv,
    BasicSrv
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rosbag2_test_msgdefs,
    srv,
    BasicSrv
  ),
  &rosbag2_test_msgdefs__srv__BasicSrv__get_type_hash,
  &rosbag2_test_msgdefs__srv__BasicSrv__get_type_description,
  &rosbag2_test_msgdefs__srv__BasicSrv__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_test_msgdefs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv)(void) {
  if (!rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle.typesupport_identifier) {
    rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_test_msgdefs, srv, BasicSrv_Event)()->data;
  }

  return &rosbag2_test_msgdefs__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle;
}
