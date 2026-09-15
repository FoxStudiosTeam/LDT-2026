// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from logging_demo:srv\ConfigLogger.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "logging_demo/srv/detail/config_logger__rosidl_typesupport_introspection_c.h"
#include "logging_demo/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "logging_demo/srv/detail/config_logger__functions.h"
#include "logging_demo/srv/detail/config_logger__struct.h"


// Include directives for member types
// Member `logger_name`
// Member `level`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  logging_demo__srv__ConfigLogger_Request__init(message_memory);
}

void logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_fini_function(void * message_memory)
{
  logging_demo__srv__ConfigLogger_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_member_array[2] = {
  {
    "logger_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(logging_demo__srv__ConfigLogger_Request, logger_name),  // bytes offset in struct
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
    "level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(logging_demo__srv__ConfigLogger_Request, level),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_members = {
  "logging_demo__srv",  // message namespace
  "ConfigLogger_Request",  // message name
  2,  // number of fields
  sizeof(logging_demo__srv__ConfigLogger_Request),
  false,  // has_any_key_member_
  logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_member_array,  // message members
  logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_type_support_handle = {
  0,
  &logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_members,
  get_message_typesupport_handle_function,
  &logging_demo__srv__ConfigLogger_Request__get_type_hash,
  &logging_demo__srv__ConfigLogger_Request__get_type_description,
  &logging_demo__srv__ConfigLogger_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_logging_demo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Request)() {
  if (!logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_type_support_handle.typesupport_identifier) {
    logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "logging_demo/srv/detail/config_logger__rosidl_typesupport_introspection_c.h"
// already included above
// #include "logging_demo/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "logging_demo/srv/detail/config_logger__functions.h"
// already included above
// #include "logging_demo/srv/detail/config_logger__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  logging_demo__srv__ConfigLogger_Response__init(message_memory);
}

void logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_fini_function(void * message_memory)
{
  logging_demo__srv__ConfigLogger_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(logging_demo__srv__ConfigLogger_Response, success),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_members = {
  "logging_demo__srv",  // message namespace
  "ConfigLogger_Response",  // message name
  1,  // number of fields
  sizeof(logging_demo__srv__ConfigLogger_Response),
  false,  // has_any_key_member_
  logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_member_array,  // message members
  logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle = {
  0,
  &logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_members,
  get_message_typesupport_handle_function,
  &logging_demo__srv__ConfigLogger_Response__get_type_hash,
  &logging_demo__srv__ConfigLogger_Response__get_type_description,
  &logging_demo__srv__ConfigLogger_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_logging_demo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Response)() {
  if (!logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle.typesupport_identifier) {
    logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "logging_demo/srv/detail/config_logger__rosidl_typesupport_introspection_c.h"
// already included above
// #include "logging_demo/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "logging_demo/srv/detail/config_logger__functions.h"
// already included above
// #include "logging_demo/srv/detail/config_logger__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "logging_demo/srv/config_logger.h"
// Member `request`
// Member `response`
// already included above
// #include "logging_demo/srv/detail/config_logger__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  logging_demo__srv__ConfigLogger_Event__init(message_memory);
}

void logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_fini_function(void * message_memory)
{
  logging_demo__srv__ConfigLogger_Event__fini(message_memory);
}

size_t logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__size_function__ConfigLogger_Event__request(
  const void * untyped_member)
{
  const logging_demo__srv__ConfigLogger_Request__Sequence * member =
    (const logging_demo__srv__ConfigLogger_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_const_function__ConfigLogger_Event__request(
  const void * untyped_member, size_t index)
{
  const logging_demo__srv__ConfigLogger_Request__Sequence * member =
    (const logging_demo__srv__ConfigLogger_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_function__ConfigLogger_Event__request(
  void * untyped_member, size_t index)
{
  logging_demo__srv__ConfigLogger_Request__Sequence * member =
    (logging_demo__srv__ConfigLogger_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__fetch_function__ConfigLogger_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const logging_demo__srv__ConfigLogger_Request * item =
    ((const logging_demo__srv__ConfigLogger_Request *)
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_const_function__ConfigLogger_Event__request(untyped_member, index));
  logging_demo__srv__ConfigLogger_Request * value =
    (logging_demo__srv__ConfigLogger_Request *)(untyped_value);
  *value = *item;
}

void logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__assign_function__ConfigLogger_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  logging_demo__srv__ConfigLogger_Request * item =
    ((logging_demo__srv__ConfigLogger_Request *)
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_function__ConfigLogger_Event__request(untyped_member, index));
  const logging_demo__srv__ConfigLogger_Request * value =
    (const logging_demo__srv__ConfigLogger_Request *)(untyped_value);
  *item = *value;
}

bool logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__resize_function__ConfigLogger_Event__request(
  void * untyped_member, size_t size)
{
  logging_demo__srv__ConfigLogger_Request__Sequence * member =
    (logging_demo__srv__ConfigLogger_Request__Sequence *)(untyped_member);
  logging_demo__srv__ConfigLogger_Request__Sequence__fini(member);
  return logging_demo__srv__ConfigLogger_Request__Sequence__init(member, size);
}

size_t logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__size_function__ConfigLogger_Event__response(
  const void * untyped_member)
{
  const logging_demo__srv__ConfigLogger_Response__Sequence * member =
    (const logging_demo__srv__ConfigLogger_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_const_function__ConfigLogger_Event__response(
  const void * untyped_member, size_t index)
{
  const logging_demo__srv__ConfigLogger_Response__Sequence * member =
    (const logging_demo__srv__ConfigLogger_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_function__ConfigLogger_Event__response(
  void * untyped_member, size_t index)
{
  logging_demo__srv__ConfigLogger_Response__Sequence * member =
    (logging_demo__srv__ConfigLogger_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__fetch_function__ConfigLogger_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const logging_demo__srv__ConfigLogger_Response * item =
    ((const logging_demo__srv__ConfigLogger_Response *)
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_const_function__ConfigLogger_Event__response(untyped_member, index));
  logging_demo__srv__ConfigLogger_Response * value =
    (logging_demo__srv__ConfigLogger_Response *)(untyped_value);
  *value = *item;
}

void logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__assign_function__ConfigLogger_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  logging_demo__srv__ConfigLogger_Response * item =
    ((logging_demo__srv__ConfigLogger_Response *)
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_function__ConfigLogger_Event__response(untyped_member, index));
  const logging_demo__srv__ConfigLogger_Response * value =
    (const logging_demo__srv__ConfigLogger_Response *)(untyped_value);
  *item = *value;
}

bool logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__resize_function__ConfigLogger_Event__response(
  void * untyped_member, size_t size)
{
  logging_demo__srv__ConfigLogger_Response__Sequence * member =
    (logging_demo__srv__ConfigLogger_Response__Sequence *)(untyped_member);
  logging_demo__srv__ConfigLogger_Response__Sequence__fini(member);
  return logging_demo__srv__ConfigLogger_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(logging_demo__srv__ConfigLogger_Event, info),  // bytes offset in struct
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
    offsetof(logging_demo__srv__ConfigLogger_Event, request),  // bytes offset in struct
    NULL,  // default value
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__size_function__ConfigLogger_Event__request,  // size() function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_const_function__ConfigLogger_Event__request,  // get_const(index) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_function__ConfigLogger_Event__request,  // get(index) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__fetch_function__ConfigLogger_Event__request,  // fetch(index, &value) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__assign_function__ConfigLogger_Event__request,  // assign(index, value) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__resize_function__ConfigLogger_Event__request,  // resize(index) function pointer
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
    offsetof(logging_demo__srv__ConfigLogger_Event, response),  // bytes offset in struct
    NULL,  // default value
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__size_function__ConfigLogger_Event__response,  // size() function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_const_function__ConfigLogger_Event__response,  // get_const(index) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__get_function__ConfigLogger_Event__response,  // get(index) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__fetch_function__ConfigLogger_Event__response,  // fetch(index, &value) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__assign_function__ConfigLogger_Event__response,  // assign(index, value) function pointer
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__resize_function__ConfigLogger_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_members = {
  "logging_demo__srv",  // message namespace
  "ConfigLogger_Event",  // message name
  3,  // number of fields
  sizeof(logging_demo__srv__ConfigLogger_Event),
  false,  // has_any_key_member_
  logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_member_array,  // message members
  logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_type_support_handle = {
  0,
  &logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_members,
  get_message_typesupport_handle_function,
  &logging_demo__srv__ConfigLogger_Event__get_type_hash,
  &logging_demo__srv__ConfigLogger_Event__get_type_description,
  &logging_demo__srv__ConfigLogger_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_logging_demo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Event)() {
  logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Request)();
  logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Response)();
  if (!logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_type_support_handle.typesupport_identifier) {
    logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "logging_demo/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "logging_demo/srv/detail/config_logger__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_members = {
  "logging_demo__srv",  // service namespace
  "ConfigLogger",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_type_support_handle,
  NULL,  // response message
  // logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle
  NULL  // event_message
  // logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle
};


static rosidl_service_type_support_t logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_type_support_handle = {
  0,
  &logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_members,
  get_service_typesupport_handle_function,
  &logging_demo__srv__ConfigLogger_Request__rosidl_typesupport_introspection_c__ConfigLogger_Request_message_type_support_handle,
  &logging_demo__srv__ConfigLogger_Response__rosidl_typesupport_introspection_c__ConfigLogger_Response_message_type_support_handle,
  &logging_demo__srv__ConfigLogger_Event__rosidl_typesupport_introspection_c__ConfigLogger_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    logging_demo,
    srv,
    ConfigLogger
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    logging_demo,
    srv,
    ConfigLogger
  ),
  &logging_demo__srv__ConfigLogger__get_type_hash,
  &logging_demo__srv__ConfigLogger__get_type_description,
  &logging_demo__srv__ConfigLogger__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_logging_demo
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger)(void) {
  if (!logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_type_support_handle.typesupport_identifier) {
    logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, logging_demo, srv, ConfigLogger_Event)()->data;
  }

  return &logging_demo__srv__detail__config_logger__rosidl_typesupport_introspection_c__ConfigLogger_service_type_support_handle;
}
