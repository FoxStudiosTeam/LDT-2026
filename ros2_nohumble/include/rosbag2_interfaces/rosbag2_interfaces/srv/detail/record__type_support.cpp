// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rosbag2_interfaces:srv\Record.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_interfaces/srv/detail/record__functions.h"
#include "rosbag2_interfaces/srv/detail/record__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rosbag2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Record_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosbag2_interfaces::srv::Record_Request(_init);
}

void Record_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosbag2_interfaces::srv::Record_Request *>(message_memory);
  typed_message->~Record_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Record_Request_message_member_array[2] = {
  {
    "uri",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Request, uri),  // bytes offset in struct
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
    "start_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Request, start_time),  // bytes offset in struct
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

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Record_Request_message_members = {
  "rosbag2_interfaces::srv",  // message namespace
  "Record_Request",  // message name
  2,  // number of fields
  sizeof(rosbag2_interfaces::srv::Record_Request),
  false,  // has_any_key_member_
  Record_Request_message_member_array,  // message members
  Record_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Record_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Record_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Record_Request_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_interfaces__srv__Record_Request__get_type_hash,
  &rosbag2_interfaces__srv__Record_Request__get_type_description,
  &rosbag2_interfaces__srv__Record_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbag2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosbag2_interfaces::srv::Record_Request>()
{
  return &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbag2_interfaces, srv, Record_Request)() {
  return &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_Request_message_type_support_handle;
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
// #include "rosbag2_interfaces/srv/detail/record__functions.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/record__struct.hpp"
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

namespace rosbag2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Record_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosbag2_interfaces::srv::Record_Response(_init);
}

void Record_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosbag2_interfaces::srv::Record_Response *>(message_memory);
  typed_message->~Record_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Record_Response_message_member_array[2] = {
  {
    "return_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Response, return_code),  // bytes offset in struct
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
    "error_string",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Response, error_string),  // bytes offset in struct
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

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Record_Response_message_members = {
  "rosbag2_interfaces::srv",  // message namespace
  "Record_Response",  // message name
  2,  // number of fields
  sizeof(rosbag2_interfaces::srv::Record_Response),
  false,  // has_any_key_member_
  Record_Response_message_member_array,  // message members
  Record_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Record_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Record_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Record_Response_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_interfaces__srv__Record_Response__get_type_hash,
  &rosbag2_interfaces__srv__Record_Response__get_type_description,
  &rosbag2_interfaces__srv__Record_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbag2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosbag2_interfaces::srv::Record_Response>()
{
  return &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbag2_interfaces, srv, Record_Response)() {
  return &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_Response_message_type_support_handle;
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
// #include "rosbag2_interfaces/srv/detail/record__functions.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/record__struct.hpp"
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

namespace rosbag2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Record_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosbag2_interfaces::srv::Record_Event(_init);
}

void Record_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosbag2_interfaces::srv::Record_Event *>(message_memory);
  typed_message->~Record_Event();
}

size_t size_function__Record_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosbag2_interfaces::srv::Record_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Record_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosbag2_interfaces::srv::Record_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__Record_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosbag2_interfaces::srv::Record_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__Record_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosbag2_interfaces::srv::Record_Request *>(
    get_const_function__Record_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<rosbag2_interfaces::srv::Record_Request *>(untyped_value);
  value = item;
}

void assign_function__Record_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosbag2_interfaces::srv::Record_Request *>(
    get_function__Record_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosbag2_interfaces::srv::Record_Request *>(untyped_value);
  item = value;
}

void resize_function__Record_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosbag2_interfaces::srv::Record_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Record_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosbag2_interfaces::srv::Record_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Record_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosbag2_interfaces::srv::Record_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__Record_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosbag2_interfaces::srv::Record_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__Record_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosbag2_interfaces::srv::Record_Response *>(
    get_const_function__Record_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<rosbag2_interfaces::srv::Record_Response *>(untyped_value);
  value = item;
}

void assign_function__Record_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosbag2_interfaces::srv::Record_Response *>(
    get_function__Record_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosbag2_interfaces::srv::Record_Response *>(untyped_value);
  item = value;
}

void resize_function__Record_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosbag2_interfaces::srv::Record_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Record_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosbag2_interfaces::srv::Record_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__Record_Event__request,  // size() function pointer
    get_const_function__Record_Event__request,  // get_const(index) function pointer
    get_function__Record_Event__request,  // get(index) function pointer
    fetch_function__Record_Event__request,  // fetch(index, &value) function pointer
    assign_function__Record_Event__request,  // assign(index, value) function pointer
    resize_function__Record_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosbag2_interfaces::srv::Record_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(rosbag2_interfaces::srv::Record_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__Record_Event__response,  // size() function pointer
    get_const_function__Record_Event__response,  // get_const(index) function pointer
    get_function__Record_Event__response,  // get(index) function pointer
    fetch_function__Record_Event__response,  // fetch(index, &value) function pointer
    assign_function__Record_Event__response,  // assign(index, value) function pointer
    resize_function__Record_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Record_Event_message_members = {
  "rosbag2_interfaces::srv",  // message namespace
  "Record_Event",  // message name
  3,  // number of fields
  sizeof(rosbag2_interfaces::srv::Record_Event),
  false,  // has_any_key_member_
  Record_Event_message_member_array,  // message members
  Record_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  Record_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Record_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Record_Event_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_interfaces__srv__Record_Event__get_type_hash,
  &rosbag2_interfaces__srv__Record_Event__get_type_description,
  &rosbag2_interfaces__srv__Record_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbag2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosbag2_interfaces::srv::Record_Event>()
{
  return &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbag2_interfaces, srv, Record_Event)() {
  return &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_Event_message_type_support_handle;
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
// #include "rosbag2_interfaces/srv/detail/record__functions.h"
// already included above
// #include "rosbag2_interfaces/srv/detail/record__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace rosbag2_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers Record_service_members = {
  "rosbag2_interfaces::srv",  // service namespace
  "Record",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<rosbag2_interfaces::srv::Record>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t Record_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Record_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosbag2_interfaces::srv::Record_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosbag2_interfaces::srv::Record_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosbag2_interfaces::srv::Record_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<rosbag2_interfaces::srv::Record>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<rosbag2_interfaces::srv::Record>,
  &rosbag2_interfaces__srv__Record__get_type_hash,
  &rosbag2_interfaces__srv__Record__get_type_description,
  &rosbag2_interfaces__srv__Record__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbag2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<rosbag2_interfaces::srv::Record>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::rosbag2_interfaces::srv::rosidl_typesupport_introspection_cpp::Record_service_type_support_handle;
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
        ::rosbag2_interfaces::srv::Record_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::rosbag2_interfaces::srv::Record_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::rosbag2_interfaces::srv::Record_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbag2_interfaces, srv, Record)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<rosbag2_interfaces::srv::Record>();
}

#ifdef __cplusplus
}
#endif
