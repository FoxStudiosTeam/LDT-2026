// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from map_msgs:srv\GetPointMap.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "map_msgs/srv/detail/get_point_map__functions.h"
#include "map_msgs/srv/detail/get_point_map__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace map_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetPointMap_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) map_msgs::srv::GetPointMap_Request(_init);
}

void GetPointMap_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<map_msgs::srv::GetPointMap_Request *>(message_memory);
  typed_message->~GetPointMap_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetPointMap_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_msgs::srv::GetPointMap_Request, structure_needs_at_least_one_member),  // bytes offset in struct
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

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetPointMap_Request_message_members = {
  "map_msgs::srv",  // message namespace
  "GetPointMap_Request",  // message name
  1,  // number of fields
  sizeof(map_msgs::srv::GetPointMap_Request),
  false,  // has_any_key_member_
  GetPointMap_Request_message_member_array,  // message members
  GetPointMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetPointMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetPointMap_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetPointMap_Request_message_members,
  get_message_typesupport_handle_function,
  &map_msgs__srv__GetPointMap_Request__get_type_hash,
  &map_msgs__srv__GetPointMap_Request__get_type_description,
  &map_msgs__srv__GetPointMap_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace map_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<map_msgs::srv::GetPointMap_Request>()
{
  return &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, map_msgs, srv, GetPointMap_Request)() {
  return &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_Request_message_type_support_handle;
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
// #include "map_msgs/srv/detail/get_point_map__functions.h"
// already included above
// #include "map_msgs/srv/detail/get_point_map__struct.hpp"
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

namespace map_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetPointMap_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) map_msgs::srv::GetPointMap_Response(_init);
}

void GetPointMap_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<map_msgs::srv::GetPointMap_Response *>(message_memory);
  typed_message->~GetPointMap_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetPointMap_Response_message_member_array[1] = {
  {
    "map",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::PointCloud2>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_msgs::srv::GetPointMap_Response, map),  // bytes offset in struct
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

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetPointMap_Response_message_members = {
  "map_msgs::srv",  // message namespace
  "GetPointMap_Response",  // message name
  1,  // number of fields
  sizeof(map_msgs::srv::GetPointMap_Response),
  false,  // has_any_key_member_
  GetPointMap_Response_message_member_array,  // message members
  GetPointMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetPointMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetPointMap_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetPointMap_Response_message_members,
  get_message_typesupport_handle_function,
  &map_msgs__srv__GetPointMap_Response__get_type_hash,
  &map_msgs__srv__GetPointMap_Response__get_type_description,
  &map_msgs__srv__GetPointMap_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace map_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<map_msgs::srv::GetPointMap_Response>()
{
  return &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, map_msgs, srv, GetPointMap_Response)() {
  return &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_Response_message_type_support_handle;
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
// #include "map_msgs/srv/detail/get_point_map__functions.h"
// already included above
// #include "map_msgs/srv/detail/get_point_map__struct.hpp"
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

namespace map_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetPointMap_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) map_msgs::srv::GetPointMap_Event(_init);
}

void GetPointMap_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<map_msgs::srv::GetPointMap_Event *>(message_memory);
  typed_message->~GetPointMap_Event();
}

size_t size_function__GetPointMap_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<map_msgs::srv::GetPointMap_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetPointMap_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<map_msgs::srv::GetPointMap_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__GetPointMap_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<map_msgs::srv::GetPointMap_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetPointMap_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const map_msgs::srv::GetPointMap_Request *>(
    get_const_function__GetPointMap_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<map_msgs::srv::GetPointMap_Request *>(untyped_value);
  value = item;
}

void assign_function__GetPointMap_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<map_msgs::srv::GetPointMap_Request *>(
    get_function__GetPointMap_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const map_msgs::srv::GetPointMap_Request *>(untyped_value);
  item = value;
}

void resize_function__GetPointMap_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<map_msgs::srv::GetPointMap_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetPointMap_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<map_msgs::srv::GetPointMap_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetPointMap_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<map_msgs::srv::GetPointMap_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__GetPointMap_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<map_msgs::srv::GetPointMap_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetPointMap_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const map_msgs::srv::GetPointMap_Response *>(
    get_const_function__GetPointMap_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<map_msgs::srv::GetPointMap_Response *>(untyped_value);
  value = item;
}

void assign_function__GetPointMap_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<map_msgs::srv::GetPointMap_Response *>(
    get_function__GetPointMap_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const map_msgs::srv::GetPointMap_Response *>(untyped_value);
  item = value;
}

void resize_function__GetPointMap_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<map_msgs::srv::GetPointMap_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetPointMap_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_msgs::srv::GetPointMap_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<map_msgs::srv::GetPointMap_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(map_msgs::srv::GetPointMap_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetPointMap_Event__request,  // size() function pointer
    get_const_function__GetPointMap_Event__request,  // get_const(index) function pointer
    get_function__GetPointMap_Event__request,  // get(index) function pointer
    fetch_function__GetPointMap_Event__request,  // fetch(index, &value) function pointer
    assign_function__GetPointMap_Event__request,  // assign(index, value) function pointer
    resize_function__GetPointMap_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<map_msgs::srv::GetPointMap_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(map_msgs::srv::GetPointMap_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetPointMap_Event__response,  // size() function pointer
    get_const_function__GetPointMap_Event__response,  // get_const(index) function pointer
    get_function__GetPointMap_Event__response,  // get(index) function pointer
    fetch_function__GetPointMap_Event__response,  // fetch(index, &value) function pointer
    assign_function__GetPointMap_Event__response,  // assign(index, value) function pointer
    resize_function__GetPointMap_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetPointMap_Event_message_members = {
  "map_msgs::srv",  // message namespace
  "GetPointMap_Event",  // message name
  3,  // number of fields
  sizeof(map_msgs::srv::GetPointMap_Event),
  false,  // has_any_key_member_
  GetPointMap_Event_message_member_array,  // message members
  GetPointMap_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  GetPointMap_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetPointMap_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetPointMap_Event_message_members,
  get_message_typesupport_handle_function,
  &map_msgs__srv__GetPointMap_Event__get_type_hash,
  &map_msgs__srv__GetPointMap_Event__get_type_description,
  &map_msgs__srv__GetPointMap_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace map_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<map_msgs::srv::GetPointMap_Event>()
{
  return &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, map_msgs, srv, GetPointMap_Event)() {
  return &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_Event_message_type_support_handle;
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
// #include "map_msgs/srv/detail/get_point_map__functions.h"
// already included above
// #include "map_msgs/srv/detail/get_point_map__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace map_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetPointMap_service_members = {
  "map_msgs::srv",  // service namespace
  "GetPointMap",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<map_msgs::srv::GetPointMap>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t GetPointMap_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetPointMap_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<map_msgs::srv::GetPointMap_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<map_msgs::srv::GetPointMap_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<map_msgs::srv::GetPointMap_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<map_msgs::srv::GetPointMap>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<map_msgs::srv::GetPointMap>,
  &map_msgs__srv__GetPointMap__get_type_hash,
  &map_msgs__srv__GetPointMap__get_type_description,
  &map_msgs__srv__GetPointMap__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace map_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<map_msgs::srv::GetPointMap>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::map_msgs::srv::rosidl_typesupport_introspection_cpp::GetPointMap_service_type_support_handle;
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
        ::map_msgs::srv::GetPointMap_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::map_msgs::srv::GetPointMap_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::map_msgs::srv::GetPointMap_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, map_msgs, srv, GetPointMap)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<map_msgs::srv::GetPointMap>();
}

#ifdef __cplusplus
}
#endif
