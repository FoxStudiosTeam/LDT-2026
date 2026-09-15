// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tf2_msgs:srv\FrameGraph.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tf2_msgs/srv/detail/frame_graph__rosidl_typesupport_introspection_c.h"
#include "tf2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tf2_msgs/srv/detail/frame_graph__functions.h"
#include "tf2_msgs/srv/detail/frame_graph__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_msgs__srv__FrameGraph_Request__init(message_memory);
}

void tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_fini_function(void * message_memory)
{
  tf2_msgs__srv__FrameGraph_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_msgs__srv__FrameGraph_Request, structure_needs_at_least_one_member),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_members = {
  "tf2_msgs__srv",  // message namespace
  "FrameGraph_Request",  // message name
  1,  // number of fields
  sizeof(tf2_msgs__srv__FrameGraph_Request),
  false,  // has_any_key_member_
  tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_member_array,  // message members
  tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_type_support_handle = {
  0,
  &tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_members,
  get_message_typesupport_handle_function,
  &tf2_msgs__srv__FrameGraph_Request__get_type_hash,
  &tf2_msgs__srv__FrameGraph_Request__get_type_description,
  &tf2_msgs__srv__FrameGraph_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Request)() {
  if (!tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_type_support_handle.typesupport_identifier) {
    tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__functions.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__struct.h"


// Include directives for member types
// Member `frame_yaml`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_msgs__srv__FrameGraph_Response__init(message_memory);
}

void tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_fini_function(void * message_memory)
{
  tf2_msgs__srv__FrameGraph_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_member_array[1] = {
  {
    "frame_yaml",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_msgs__srv__FrameGraph_Response, frame_yaml),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_members = {
  "tf2_msgs__srv",  // message namespace
  "FrameGraph_Response",  // message name
  1,  // number of fields
  sizeof(tf2_msgs__srv__FrameGraph_Response),
  false,  // has_any_key_member_
  tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_member_array,  // message members
  tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle = {
  0,
  &tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_members,
  get_message_typesupport_handle_function,
  &tf2_msgs__srv__FrameGraph_Response__get_type_hash,
  &tf2_msgs__srv__FrameGraph_Response__get_type_description,
  &tf2_msgs__srv__FrameGraph_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Response)() {
  if (!tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle.typesupport_identifier) {
    tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__functions.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "tf2_msgs/srv/frame_graph.h"
// Member `request`
// Member `response`
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tf2_msgs__srv__FrameGraph_Event__init(message_memory);
}

void tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_fini_function(void * message_memory)
{
  tf2_msgs__srv__FrameGraph_Event__fini(message_memory);
}

size_t tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__size_function__FrameGraph_Event__request(
  const void * untyped_member)
{
  const tf2_msgs__srv__FrameGraph_Request__Sequence * member =
    (const tf2_msgs__srv__FrameGraph_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_const_function__FrameGraph_Event__request(
  const void * untyped_member, size_t index)
{
  const tf2_msgs__srv__FrameGraph_Request__Sequence * member =
    (const tf2_msgs__srv__FrameGraph_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_function__FrameGraph_Event__request(
  void * untyped_member, size_t index)
{
  tf2_msgs__srv__FrameGraph_Request__Sequence * member =
    (tf2_msgs__srv__FrameGraph_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__fetch_function__FrameGraph_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tf2_msgs__srv__FrameGraph_Request * item =
    ((const tf2_msgs__srv__FrameGraph_Request *)
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_const_function__FrameGraph_Event__request(untyped_member, index));
  tf2_msgs__srv__FrameGraph_Request * value =
    (tf2_msgs__srv__FrameGraph_Request *)(untyped_value);
  *value = *item;
}

void tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__assign_function__FrameGraph_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tf2_msgs__srv__FrameGraph_Request * item =
    ((tf2_msgs__srv__FrameGraph_Request *)
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_function__FrameGraph_Event__request(untyped_member, index));
  const tf2_msgs__srv__FrameGraph_Request * value =
    (const tf2_msgs__srv__FrameGraph_Request *)(untyped_value);
  *item = *value;
}

bool tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__resize_function__FrameGraph_Event__request(
  void * untyped_member, size_t size)
{
  tf2_msgs__srv__FrameGraph_Request__Sequence * member =
    (tf2_msgs__srv__FrameGraph_Request__Sequence *)(untyped_member);
  tf2_msgs__srv__FrameGraph_Request__Sequence__fini(member);
  return tf2_msgs__srv__FrameGraph_Request__Sequence__init(member, size);
}

size_t tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__size_function__FrameGraph_Event__response(
  const void * untyped_member)
{
  const tf2_msgs__srv__FrameGraph_Response__Sequence * member =
    (const tf2_msgs__srv__FrameGraph_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_const_function__FrameGraph_Event__response(
  const void * untyped_member, size_t index)
{
  const tf2_msgs__srv__FrameGraph_Response__Sequence * member =
    (const tf2_msgs__srv__FrameGraph_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_function__FrameGraph_Event__response(
  void * untyped_member, size_t index)
{
  tf2_msgs__srv__FrameGraph_Response__Sequence * member =
    (tf2_msgs__srv__FrameGraph_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__fetch_function__FrameGraph_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tf2_msgs__srv__FrameGraph_Response * item =
    ((const tf2_msgs__srv__FrameGraph_Response *)
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_const_function__FrameGraph_Event__response(untyped_member, index));
  tf2_msgs__srv__FrameGraph_Response * value =
    (tf2_msgs__srv__FrameGraph_Response *)(untyped_value);
  *value = *item;
}

void tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__assign_function__FrameGraph_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tf2_msgs__srv__FrameGraph_Response * item =
    ((tf2_msgs__srv__FrameGraph_Response *)
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_function__FrameGraph_Event__response(untyped_member, index));
  const tf2_msgs__srv__FrameGraph_Response * value =
    (const tf2_msgs__srv__FrameGraph_Response *)(untyped_value);
  *item = *value;
}

bool tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__resize_function__FrameGraph_Event__response(
  void * untyped_member, size_t size)
{
  tf2_msgs__srv__FrameGraph_Response__Sequence * member =
    (tf2_msgs__srv__FrameGraph_Response__Sequence *)(untyped_member);
  tf2_msgs__srv__FrameGraph_Response__Sequence__fini(member);
  return tf2_msgs__srv__FrameGraph_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tf2_msgs__srv__FrameGraph_Event, info),  // bytes offset in struct
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
    offsetof(tf2_msgs__srv__FrameGraph_Event, request),  // bytes offset in struct
    NULL,  // default value
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__size_function__FrameGraph_Event__request,  // size() function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_const_function__FrameGraph_Event__request,  // get_const(index) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_function__FrameGraph_Event__request,  // get(index) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__fetch_function__FrameGraph_Event__request,  // fetch(index, &value) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__assign_function__FrameGraph_Event__request,  // assign(index, value) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__resize_function__FrameGraph_Event__request,  // resize(index) function pointer
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
    offsetof(tf2_msgs__srv__FrameGraph_Event, response),  // bytes offset in struct
    NULL,  // default value
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__size_function__FrameGraph_Event__response,  // size() function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_const_function__FrameGraph_Event__response,  // get_const(index) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__get_function__FrameGraph_Event__response,  // get(index) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__fetch_function__FrameGraph_Event__response,  // fetch(index, &value) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__assign_function__FrameGraph_Event__response,  // assign(index, value) function pointer
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__resize_function__FrameGraph_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_members = {
  "tf2_msgs__srv",  // message namespace
  "FrameGraph_Event",  // message name
  3,  // number of fields
  sizeof(tf2_msgs__srv__FrameGraph_Event),
  false,  // has_any_key_member_
  tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_member_array,  // message members
  tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_type_support_handle = {
  0,
  &tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_members,
  get_message_typesupport_handle_function,
  &tf2_msgs__srv__FrameGraph_Event__get_type_hash,
  &tf2_msgs__srv__FrameGraph_Event__get_type_description,
  &tf2_msgs__srv__FrameGraph_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Event)() {
  tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Request)();
  tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Response)();
  if (!tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_type_support_handle.typesupport_identifier) {
    tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_members = {
  "tf2_msgs__srv",  // service namespace
  "FrameGraph",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_Request_message_type_support_handle,
  NULL,  // response message
  // tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle
  NULL  // event_message
  // tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle
};


static rosidl_service_type_support_t tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_type_support_handle = {
  0,
  &tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_members,
  get_service_typesupport_handle_function,
  &tf2_msgs__srv__FrameGraph_Request__rosidl_typesupport_introspection_c__FrameGraph_Request_message_type_support_handle,
  &tf2_msgs__srv__FrameGraph_Response__rosidl_typesupport_introspection_c__FrameGraph_Response_message_type_support_handle,
  &tf2_msgs__srv__FrameGraph_Event__rosidl_typesupport_introspection_c__FrameGraph_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tf2_msgs,
    srv,
    FrameGraph
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tf2_msgs,
    srv,
    FrameGraph
  ),
  &tf2_msgs__srv__FrameGraph__get_type_hash,
  &tf2_msgs__srv__FrameGraph__get_type_description,
  &tf2_msgs__srv__FrameGraph__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tf2_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph)(void) {
  if (!tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_type_support_handle.typesupport_identifier) {
    tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tf2_msgs, srv, FrameGraph_Event)()->data;
  }

  return &tf2_msgs__srv__detail__frame_graph__rosidl_typesupport_introspection_c__FrameGraph_service_type_support_handle;
}
