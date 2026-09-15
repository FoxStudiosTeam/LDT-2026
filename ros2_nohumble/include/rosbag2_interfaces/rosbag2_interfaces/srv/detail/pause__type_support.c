// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rosbag2_interfaces:srv\Pause.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rosbag2_interfaces/srv/detail/pause__rosidl_typesupport_introspection_c.h"
#include "rosbag2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosbag2_interfaces/srv/detail/pause__functions.h"
#include "rosbag2_interfaces/srv/detail/pause__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_interfaces__srv__Pause_Request__init(message_memory);
}

void rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_fini_function(void * message_memory)
{
  rosbag2_interfaces__srv__Pause_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces__srv__Pause_Request, structure_needs_at_least_one_member),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_members = {
  "rosbag2_interfaces__srv",  // message namespace
  "Pause_Request",  // message name
  1,  // number of fields
  sizeof(rosbag2_interfaces__srv__Pause_Request),
  false,  // has_any_key_member_
  rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_member_array,  // message members
  rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_type_support_handle = {
  0,
  &rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_interfaces__srv__Pause_Request__get_type_hash,
  &rosbag2_interfaces__srv__Pause_Request__get_type_description,
  &rosbag2_interfaces__srv__Pause_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Request)() {
  if (!rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_type_support_handle.typesupport_identifier) {
    rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosbag2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__functions.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_interfaces__srv__Pause_Response__init(message_memory);
}

void rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_fini_function(void * message_memory)
{
  rosbag2_interfaces__srv__Pause_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces__srv__Pause_Response, structure_needs_at_least_one_member),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_members = {
  "rosbag2_interfaces__srv",  // message namespace
  "Pause_Response",  // message name
  1,  // number of fields
  sizeof(rosbag2_interfaces__srv__Pause_Response),
  false,  // has_any_key_member_
  rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_member_array,  // message members
  rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle = {
  0,
  &rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_interfaces__srv__Pause_Response__get_type_hash,
  &rosbag2_interfaces__srv__Pause_Response__get_type_description,
  &rosbag2_interfaces__srv__Pause_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Response)() {
  if (!rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle.typesupport_identifier) {
    rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosbag2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__functions.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "rosbag2_interfaces/srv/pause.h"
// Member `request`
// Member `response`
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_interfaces__srv__Pause_Event__init(message_memory);
}

void rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_fini_function(void * message_memory)
{
  rosbag2_interfaces__srv__Pause_Event__fini(message_memory);
}

size_t rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__size_function__Pause_Event__request(
  const void * untyped_member)
{
  const rosbag2_interfaces__srv__Pause_Request__Sequence * member =
    (const rosbag2_interfaces__srv__Pause_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_const_function__Pause_Event__request(
  const void * untyped_member, size_t index)
{
  const rosbag2_interfaces__srv__Pause_Request__Sequence * member =
    (const rosbag2_interfaces__srv__Pause_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_function__Pause_Event__request(
  void * untyped_member, size_t index)
{
  rosbag2_interfaces__srv__Pause_Request__Sequence * member =
    (rosbag2_interfaces__srv__Pause_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__fetch_function__Pause_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosbag2_interfaces__srv__Pause_Request * item =
    ((const rosbag2_interfaces__srv__Pause_Request *)
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_const_function__Pause_Event__request(untyped_member, index));
  rosbag2_interfaces__srv__Pause_Request * value =
    (rosbag2_interfaces__srv__Pause_Request *)(untyped_value);
  *value = *item;
}

void rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__assign_function__Pause_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosbag2_interfaces__srv__Pause_Request * item =
    ((rosbag2_interfaces__srv__Pause_Request *)
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_function__Pause_Event__request(untyped_member, index));
  const rosbag2_interfaces__srv__Pause_Request * value =
    (const rosbag2_interfaces__srv__Pause_Request *)(untyped_value);
  *item = *value;
}

bool rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__resize_function__Pause_Event__request(
  void * untyped_member, size_t size)
{
  rosbag2_interfaces__srv__Pause_Request__Sequence * member =
    (rosbag2_interfaces__srv__Pause_Request__Sequence *)(untyped_member);
  rosbag2_interfaces__srv__Pause_Request__Sequence__fini(member);
  return rosbag2_interfaces__srv__Pause_Request__Sequence__init(member, size);
}

size_t rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__size_function__Pause_Event__response(
  const void * untyped_member)
{
  const rosbag2_interfaces__srv__Pause_Response__Sequence * member =
    (const rosbag2_interfaces__srv__Pause_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_const_function__Pause_Event__response(
  const void * untyped_member, size_t index)
{
  const rosbag2_interfaces__srv__Pause_Response__Sequence * member =
    (const rosbag2_interfaces__srv__Pause_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_function__Pause_Event__response(
  void * untyped_member, size_t index)
{
  rosbag2_interfaces__srv__Pause_Response__Sequence * member =
    (rosbag2_interfaces__srv__Pause_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__fetch_function__Pause_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosbag2_interfaces__srv__Pause_Response * item =
    ((const rosbag2_interfaces__srv__Pause_Response *)
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_const_function__Pause_Event__response(untyped_member, index));
  rosbag2_interfaces__srv__Pause_Response * value =
    (rosbag2_interfaces__srv__Pause_Response *)(untyped_value);
  *value = *item;
}

void rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__assign_function__Pause_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosbag2_interfaces__srv__Pause_Response * item =
    ((rosbag2_interfaces__srv__Pause_Response *)
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_function__Pause_Event__response(untyped_member, index));
  const rosbag2_interfaces__srv__Pause_Response * value =
    (const rosbag2_interfaces__srv__Pause_Response *)(untyped_value);
  *item = *value;
}

bool rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__resize_function__Pause_Event__response(
  void * untyped_member, size_t size)
{
  rosbag2_interfaces__srv__Pause_Response__Sequence * member =
    (rosbag2_interfaces__srv__Pause_Response__Sequence *)(untyped_member);
  rosbag2_interfaces__srv__Pause_Response__Sequence__fini(member);
  return rosbag2_interfaces__srv__Pause_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces__srv__Pause_Event, info),  // bytes offset in struct
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
    offsetof(rosbag2_interfaces__srv__Pause_Event, request),  // bytes offset in struct
    NULL,  // default value
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__size_function__Pause_Event__request,  // size() function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_const_function__Pause_Event__request,  // get_const(index) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_function__Pause_Event__request,  // get(index) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__fetch_function__Pause_Event__request,  // fetch(index, &value) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__assign_function__Pause_Event__request,  // assign(index, value) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__resize_function__Pause_Event__request,  // resize(index) function pointer
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
    offsetof(rosbag2_interfaces__srv__Pause_Event, response),  // bytes offset in struct
    NULL,  // default value
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__size_function__Pause_Event__response,  // size() function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_const_function__Pause_Event__response,  // get_const(index) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__get_function__Pause_Event__response,  // get(index) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__fetch_function__Pause_Event__response,  // fetch(index, &value) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__assign_function__Pause_Event__response,  // assign(index, value) function pointer
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__resize_function__Pause_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_members = {
  "rosbag2_interfaces__srv",  // message namespace
  "Pause_Event",  // message name
  3,  // number of fields
  sizeof(rosbag2_interfaces__srv__Pause_Event),
  false,  // has_any_key_member_
  rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_member_array,  // message members
  rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_type_support_handle = {
  0,
  &rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_interfaces__srv__Pause_Event__get_type_hash,
  &rosbag2_interfaces__srv__Pause_Event__get_type_description,
  &rosbag2_interfaces__srv__Pause_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Event)() {
  rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Request)();
  rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Response)();
  if (!rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_type_support_handle.typesupport_identifier) {
    rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosbag2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/pause__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_members = {
  "rosbag2_interfaces__srv",  // service namespace
  "Pause",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_Request_message_type_support_handle,
  NULL,  // response message
  // rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle
  NULL  // event_message
  // rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle
};


static rosidl_service_type_support_t rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_type_support_handle = {
  0,
  &rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_members,
  get_service_typesupport_handle_function,
  &rosbag2_interfaces__srv__Pause_Request__rosidl_typesupport_introspection_c__Pause_Request_message_type_support_handle,
  &rosbag2_interfaces__srv__Pause_Response__rosidl_typesupport_introspection_c__Pause_Response_message_type_support_handle,
  &rosbag2_interfaces__srv__Pause_Event__rosidl_typesupport_introspection_c__Pause_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rosbag2_interfaces,
    srv,
    Pause
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rosbag2_interfaces,
    srv,
    Pause
  ),
  &rosbag2_interfaces__srv__Pause__get_type_hash,
  &rosbag2_interfaces__srv__Pause__get_type_description,
  &rosbag2_interfaces__srv__Pause__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause)(void) {
  if (!rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_type_support_handle.typesupport_identifier) {
    rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_interfaces, srv, Pause_Event)()->data;
  }

  return &rosbag2_interfaces__srv__detail__pause__rosidl_typesupport_introspection_c__Pause_service_type_support_handle;
}
