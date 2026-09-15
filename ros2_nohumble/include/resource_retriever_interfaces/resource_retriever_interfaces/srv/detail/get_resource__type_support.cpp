// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from resource_retriever_interfaces:srv\GetResource.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
#include "resource_retriever_interfaces/srv/detail/get_resource__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace resource_retriever_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetResource_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) resource_retriever_interfaces::srv::GetResource_Request(_init);
}

void GetResource_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<resource_retriever_interfaces::srv::GetResource_Request *>(message_memory);
  typed_message->~GetResource_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetResource_Request_message_member_array[2] = {
  {
    "path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Request, path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "etag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Request, etag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetResource_Request_message_members = {
  "resource_retriever_interfaces::srv",  // message namespace
  "GetResource_Request",  // message name
  2,  // number of fields
  sizeof(resource_retriever_interfaces::srv::GetResource_Request),
  false,  // has_any_key_member_
  GetResource_Request_message_member_array,  // message members
  GetResource_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetResource_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetResource_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetResource_Request_message_members,
  get_message_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Request__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource_Request__get_type_description,
  &resource_retriever_interfaces__srv__GetResource_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace resource_retriever_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Request>()
{
  return &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, resource_retriever_interfaces, srv, GetResource_Request)() {
  return &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
#include "rosidl_buffer/buffer.hpp"

namespace resource_retriever_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetResource_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) resource_retriever_interfaces::srv::GetResource_Response(_init);
}

void GetResource_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<resource_retriever_interfaces::srv::GetResource_Response *>(message_memory);
  typed_message->~GetResource_Response();
}

size_t size_function__GetResource_Response__body(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const rosidl::Buffer<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetResource_Response__body(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const rosidl::Buffer<uint8_t> *>(untyped_member);
  member.throw_if_not_cpu_backend();
  return &member[index];
}

void * get_function__GetResource_Response__body(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<rosidl::Buffer<uint8_t> *>(untyped_member);
  member.throw_if_not_cpu_backend();
  return &member[index];
}

void fetch_function__GetResource_Response__body(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__GetResource_Response__body(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__GetResource_Response__body(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__GetResource_Response__body(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__GetResource_Response__body(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<rosidl::Buffer<uint8_t> *>(untyped_member);
  member->throw_if_not_cpu_backend();
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetResource_Response_message_member_array[5] = {
  {
    "status_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Response, status_code),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "error_reason",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Response, error_reason),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "expanded_path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Response, expanded_path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "etag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Response, etag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "body",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Response, body),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetResource_Response__body,  // size() function pointer
    get_const_function__GetResource_Response__body,  // get_const(index) function pointer
    get_function__GetResource_Response__body,  // get(index) function pointer
    fetch_function__GetResource_Response__body,  // fetch(index, &value) function pointer
    assign_function__GetResource_Response__body,  // assign(index, value) function pointer
    resize_function__GetResource_Response__body,  // resize(index) function pointer
    true  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetResource_Response_message_members = {
  "resource_retriever_interfaces::srv",  // message namespace
  "GetResource_Response",  // message name
  5,  // number of fields
  sizeof(resource_retriever_interfaces::srv::GetResource_Response),
  false,  // has_any_key_member_
  GetResource_Response_message_member_array,  // message members
  GetResource_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetResource_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetResource_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetResource_Response_message_members,
  get_message_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Response__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource_Response__get_type_description,
  &resource_retriever_interfaces__srv__GetResource_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace resource_retriever_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Response>()
{
  return &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, resource_retriever_interfaces, srv, GetResource_Response)() {
  return &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace resource_retriever_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetResource_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) resource_retriever_interfaces::srv::GetResource_Event(_init);
}

void GetResource_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<resource_retriever_interfaces::srv::GetResource_Event *>(message_memory);
  typed_message->~GetResource_Event();
}

size_t size_function__GetResource_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<resource_retriever_interfaces::srv::GetResource_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetResource_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<resource_retriever_interfaces::srv::GetResource_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__GetResource_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<resource_retriever_interfaces::srv::GetResource_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetResource_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const resource_retriever_interfaces::srv::GetResource_Request *>(
    get_const_function__GetResource_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<resource_retriever_interfaces::srv::GetResource_Request *>(untyped_value);
  value = item;
}

void assign_function__GetResource_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<resource_retriever_interfaces::srv::GetResource_Request *>(
    get_function__GetResource_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const resource_retriever_interfaces::srv::GetResource_Request *>(untyped_value);
  item = value;
}

void resize_function__GetResource_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<resource_retriever_interfaces::srv::GetResource_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetResource_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<resource_retriever_interfaces::srv::GetResource_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetResource_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<resource_retriever_interfaces::srv::GetResource_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__GetResource_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<resource_retriever_interfaces::srv::GetResource_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetResource_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const resource_retriever_interfaces::srv::GetResource_Response *>(
    get_const_function__GetResource_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<resource_retriever_interfaces::srv::GetResource_Response *>(untyped_value);
  value = item;
}

void assign_function__GetResource_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<resource_retriever_interfaces::srv::GetResource_Response *>(
    get_function__GetResource_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const resource_retriever_interfaces::srv::GetResource_Response *>(untyped_value);
  item = value;
}

void resize_function__GetResource_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<resource_retriever_interfaces::srv::GetResource_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetResource_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetResource_Event__request,  // size() function pointer
    get_const_function__GetResource_Event__request,  // get_const(index) function pointer
    get_function__GetResource_Event__request,  // get(index) function pointer
    fetch_function__GetResource_Event__request,  // fetch(index, &value) function pointer
    assign_function__GetResource_Event__request,  // assign(index, value) function pointer
    resize_function__GetResource_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(resource_retriever_interfaces::srv::GetResource_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetResource_Event__response,  // size() function pointer
    get_const_function__GetResource_Event__response,  // get_const(index) function pointer
    get_function__GetResource_Event__response,  // get(index) function pointer
    fetch_function__GetResource_Event__response,  // fetch(index, &value) function pointer
    assign_function__GetResource_Event__response,  // assign(index, value) function pointer
    resize_function__GetResource_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetResource_Event_message_members = {
  "resource_retriever_interfaces::srv",  // message namespace
  "GetResource_Event",  // message name
  3,  // number of fields
  sizeof(resource_retriever_interfaces::srv::GetResource_Event),
  false,  // has_any_key_member_
  GetResource_Event_message_member_array,  // message members
  GetResource_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  GetResource_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetResource_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetResource_Event_message_members,
  get_message_typesupport_handle_function,
  &resource_retriever_interfaces__srv__GetResource_Event__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource_Event__get_type_description,
  &resource_retriever_interfaces__srv__GetResource_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace resource_retriever_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Event>()
{
  return &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, resource_retriever_interfaces, srv, GetResource_Event)() {
  return &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__functions.h"
// already included above
// #include "resource_retriever_interfaces/srv/detail/get_resource__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace resource_retriever_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetResource_service_members = {
  "resource_retriever_interfaces::srv",  // service namespace
  "GetResource",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<resource_retriever_interfaces::srv::GetResource>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t GetResource_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetResource_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<resource_retriever_interfaces::srv::GetResource_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<resource_retriever_interfaces::srv::GetResource>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<resource_retriever_interfaces::srv::GetResource>,
  &resource_retriever_interfaces__srv__GetResource__get_type_hash,
  &resource_retriever_interfaces__srv__GetResource__get_type_description,
  &resource_retriever_interfaces__srv__GetResource__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace resource_retriever_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<resource_retriever_interfaces::srv::GetResource>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::resource_retriever_interfaces::srv::rosidl_typesupport_introspection_cpp::GetResource_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::resource_retriever_interfaces::srv::GetResource_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::resource_retriever_interfaces::srv::GetResource_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::resource_retriever_interfaces::srv::GetResource_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, resource_retriever_interfaces, srv, GetResource)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<resource_retriever_interfaces::srv::GetResource>();
}

#ifdef __cplusplus
}
#endif
