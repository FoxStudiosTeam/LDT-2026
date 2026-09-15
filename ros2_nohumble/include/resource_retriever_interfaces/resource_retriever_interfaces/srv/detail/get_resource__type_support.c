// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from resource_retriever_interfaces:srv\GetResource.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "resource_retriever_interfaces/srv/detail/get_resource__rosidl_typesupport_introspection_c.h"
#include "resource_retriever_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
#include "resource_retriever_interfaces/srv/detail/get_resource__struct.h"


// Include directives for member types
// Member `path`
// Member `etag`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  resource_retriever_interfaces__srv__GetResource_Request__init(message_memory);
}

void resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_fini_function(void * message_memory)
{
  resource_retriever_interfaces__srv__GetResource_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_member_array[2] = {
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Request, path),  // bytes offset in struct
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
    "etag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Request, etag),  // bytes offset in struct
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

static const rosidl_typesupport_introspection_c__MessageMembers resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_members = {
  "resource_retriever_interfaces__srv",  // message namespace
  "GetResource_Request",  // message name
  2,  // number of fields
  sizeof(resource_retriever_interfaces__srv__GetResource_Request),
  false,  // has_any_key_member_
  resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_member_array,  // message members
  resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_type_support_handle = {
  0,
  &resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_members,
  get_message_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Request__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource_Request__get_type_description,
  &resource_retriever_interfaces__srv__GetResource_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_resource_retriever_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Request)() {
  if (!resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_type_support_handle.typesupport_identifier) {
    resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__rosidl_typesupport_introspection_c.h"
// already included above
// #include "resource_retriever_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__struct.h"
#include "rosidl_buffer/c_helpers.h"


// Include directives for member types
// Member `error_reason`
// Member `expanded_path`
// Member `etag`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `body`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  resource_retriever_interfaces__srv__GetResource_Response__init(message_memory);
}

void resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_fini_function(void * message_memory)
{
  resource_retriever_interfaces__srv__GetResource_Response__fini(message_memory);
}

size_t resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__size_function__GetResource_Response__body(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return member->size;
}

const void * resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__get_const_function__GetResource_Response__body(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void * resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__get_function__GetResource_Response__body(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__fetch_function__GetResource_Response__body(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__get_const_function__GetResource_Response__body(untyped_member, index));
  uint8_t * value = (uint8_t *)(untyped_value);
  *value = *item;
}

void resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__assign_function__GetResource_Response__body(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__get_function__GetResource_Response__body(untyped_member, index));
  const uint8_t * value = (const uint8_t *)(untyped_value);
  *item = *value;
}

bool resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__resize_function__GetResource_Response__body(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_member_array[5] = {
  {
    "status_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Response, status_code),  // bytes offset in struct
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
    "error_reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Response, error_reason),  // bytes offset in struct
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
    "expanded_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Response, expanded_path),  // bytes offset in struct
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
    "etag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Response, etag),  // bytes offset in struct
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
    "body",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Response, body),  // bytes offset in struct
    NULL,  // default value
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__size_function__GetResource_Response__body,  // size() function pointer
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__get_const_function__GetResource_Response__body,  // get_const(index) function pointer
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__get_function__GetResource_Response__body,  // get(index) function pointer
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__fetch_function__GetResource_Response__body,  // fetch(index, &value) function pointer
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__assign_function__GetResource_Response__body,  // assign(index, value) function pointer
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__resize_function__GetResource_Response__body,  // resize(index) function pointer
    true  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_members = {
  "resource_retriever_interfaces__srv",  // message namespace
  "GetResource_Response",  // message name
  5,  // number of fields
  sizeof(resource_retriever_interfaces__srv__GetResource_Response),
  false,  // has_any_key_member_
  resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_member_array,  // message members
  resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle = {
  0,
  &resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_members,
  get_message_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Response__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource_Response__get_type_description,
  &resource_retriever_interfaces__srv__GetResource_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_resource_retriever_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Response)() {
  if (!resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle.typesupport_identifier) {
    resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__rosidl_typesupport_introspection_c.h"
// already included above
// #include "resource_retriever_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "resource_retriever_interfaces/srv/get_resource.h"
// Member `request`
// Member `response`
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  resource_retriever_interfaces__srv__GetResource_Event__init(message_memory);
}

void resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_fini_function(void * message_memory)
{
  resource_retriever_interfaces__srv__GetResource_Event__fini(message_memory);
}

size_t resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__size_function__GetResource_Event__request(
  const void * untyped_member)
{
  const resource_retriever_interfaces__srv__GetResource_Request__Sequence * member =
    (const resource_retriever_interfaces__srv__GetResource_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_const_function__GetResource_Event__request(
  const void * untyped_member, size_t index)
{
  const resource_retriever_interfaces__srv__GetResource_Request__Sequence * member =
    (const resource_retriever_interfaces__srv__GetResource_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_function__GetResource_Event__request(
  void * untyped_member, size_t index)
{
  resource_retriever_interfaces__srv__GetResource_Request__Sequence * member =
    (resource_retriever_interfaces__srv__GetResource_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__fetch_function__GetResource_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const resource_retriever_interfaces__srv__GetResource_Request * item =
    ((const resource_retriever_interfaces__srv__GetResource_Request *)
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_const_function__GetResource_Event__request(untyped_member, index));
  resource_retriever_interfaces__srv__GetResource_Request * value =
    (resource_retriever_interfaces__srv__GetResource_Request *)(untyped_value);
  *value = *item;
}

void resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__assign_function__GetResource_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  resource_retriever_interfaces__srv__GetResource_Request * item =
    ((resource_retriever_interfaces__srv__GetResource_Request *)
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_function__GetResource_Event__request(untyped_member, index));
  const resource_retriever_interfaces__srv__GetResource_Request * value =
    (const resource_retriever_interfaces__srv__GetResource_Request *)(untyped_value);
  *item = *value;
}

bool resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__resize_function__GetResource_Event__request(
  void * untyped_member, size_t size)
{
  resource_retriever_interfaces__srv__GetResource_Request__Sequence * member =
    (resource_retriever_interfaces__srv__GetResource_Request__Sequence *)(untyped_member);
  resource_retriever_interfaces__srv__GetResource_Request__Sequence__fini(member);
  return resource_retriever_interfaces__srv__GetResource_Request__Sequence__init(member, size);
}

size_t resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__size_function__GetResource_Event__response(
  const void * untyped_member)
{
  const resource_retriever_interfaces__srv__GetResource_Response__Sequence * member =
    (const resource_retriever_interfaces__srv__GetResource_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_const_function__GetResource_Event__response(
  const void * untyped_member, size_t index)
{
  const resource_retriever_interfaces__srv__GetResource_Response__Sequence * member =
    (const resource_retriever_interfaces__srv__GetResource_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_function__GetResource_Event__response(
  void * untyped_member, size_t index)
{
  resource_retriever_interfaces__srv__GetResource_Response__Sequence * member =
    (resource_retriever_interfaces__srv__GetResource_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__fetch_function__GetResource_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const resource_retriever_interfaces__srv__GetResource_Response * item =
    ((const resource_retriever_interfaces__srv__GetResource_Response *)
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_const_function__GetResource_Event__response(untyped_member, index));
  resource_retriever_interfaces__srv__GetResource_Response * value =
    (resource_retriever_interfaces__srv__GetResource_Response *)(untyped_value);
  *value = *item;
}

void resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__assign_function__GetResource_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  resource_retriever_interfaces__srv__GetResource_Response * item =
    ((resource_retriever_interfaces__srv__GetResource_Response *)
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_function__GetResource_Event__response(untyped_member, index));
  const resource_retriever_interfaces__srv__GetResource_Response * value =
    (const resource_retriever_interfaces__srv__GetResource_Response *)(untyped_value);
  *item = *value;
}

bool resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__resize_function__GetResource_Event__response(
  void * untyped_member, size_t size)
{
  resource_retriever_interfaces__srv__GetResource_Response__Sequence * member =
    (resource_retriever_interfaces__srv__GetResource_Response__Sequence *)(untyped_member);
  resource_retriever_interfaces__srv__GetResource_Response__Sequence__fini(member);
  return resource_retriever_interfaces__srv__GetResource_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces__srv__GetResource_Event, info),  // bytes offset in struct
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
    offsetof(resource_retriever_interfaces__srv__GetResource_Event, request),  // bytes offset in struct
    NULL,  // default value
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__size_function__GetResource_Event__request,  // size() function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_const_function__GetResource_Event__request,  // get_const(index) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_function__GetResource_Event__request,  // get(index) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__fetch_function__GetResource_Event__request,  // fetch(index, &value) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__assign_function__GetResource_Event__request,  // assign(index, value) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__resize_function__GetResource_Event__request,  // resize(index) function pointer
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
    offsetof(resource_retriever_interfaces__srv__GetResource_Event, response),  // bytes offset in struct
    NULL,  // default value
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__size_function__GetResource_Event__response,  // size() function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_const_function__GetResource_Event__response,  // get_const(index) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__get_function__GetResource_Event__response,  // get(index) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__fetch_function__GetResource_Event__response,  // fetch(index, &value) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__assign_function__GetResource_Event__response,  // assign(index, value) function pointer
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__resize_function__GetResource_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_members = {
  "resource_retriever_interfaces__srv",  // message namespace
  "GetResource_Event",  // message name
  3,  // number of fields
  sizeof(resource_retriever_interfaces__srv__GetResource_Event),
  false,  // has_any_key_member_
  resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_member_array,  // message members
  resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_type_support_handle = {
  0,
  &resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_members,
  get_message_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Event__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource_Event__get_type_description,
  &resource_retriever_interfaces__srv__GetResource_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_resource_retriever_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Event)() {
  resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Request)();
  resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Response)();
  if (!resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_type_support_handle.typesupport_identifier) {
    resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "resource_retriever_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_members = {
  "resource_retriever_interfaces__srv",  // service namespace
  "GetResource",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_Request_message_type_support_handle,
  NULL,  // response message
  // resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle
  NULL  // event_message
  // resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle
};


static rosidl_service_type_support_t resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_type_support_handle = {
  0,
  &resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_members,
  get_service_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Request__rosidl_typesupport_introspection_c__GetResource_Request_message_type_support_handle,
  &resource_retriever_interfaces__srv__GetResource_Response__rosidl_typesupport_introspection_c__GetResource_Response_message_type_support_handle,
  &resource_retriever_interfaces__srv__GetResource_Event__rosidl_typesupport_introspection_c__GetResource_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    resource_retriever_interfaces,
    srv,
    GetResource
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    resource_retriever_interfaces,
    srv,
    GetResource
  ),
  &resource_retriever_interfaces__srv__GetResource__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource__get_type_description,
  &resource_retriever_interfaces__srv__GetResource__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_resource_retriever_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource)(void) {
  if (!resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_type_support_handle.typesupport_identifier) {
    resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, resource_retriever_interfaces, srv, GetResource_Event)()->data;
  }

  return &resource_retriever_interfaces__srv__detail__get_resource__rosidl_typesupport_introspection_c__GetResource_service_type_support_handle;
}
