// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rosgraph_msgs:msg\Node.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rosgraph_msgs/msg/detail/node__functions.h"
#include "rosgraph_msgs/msg/detail/node__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rosgraph_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Node_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosgraph_msgs::msg::Node(_init);
}

void Node_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosgraph_msgs::msg::Node *>(message_memory);
  typed_message->~Node();
}

size_t size_function__Node__parameters(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rcl_interfaces::msg::ParameterDescriptor> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__parameters(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rcl_interfaces::msg::ParameterDescriptor> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__parameters(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rcl_interfaces::msg::ParameterDescriptor> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__parameters(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rcl_interfaces::msg::ParameterDescriptor *>(
    get_const_function__Node__parameters(untyped_member, index));
  auto & value = *reinterpret_cast<rcl_interfaces::msg::ParameterDescriptor *>(untyped_value);
  value = item;
}

void assign_function__Node__parameters(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rcl_interfaces::msg::ParameterDescriptor *>(
    get_function__Node__parameters(untyped_member, index));
  const auto & value = *reinterpret_cast<const rcl_interfaces::msg::ParameterDescriptor *>(untyped_value);
  item = value;
}

void resize_function__Node__parameters(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rcl_interfaces::msg::ParameterDescriptor> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__parameter_values(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rcl_interfaces::msg::ParameterValue> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__parameter_values(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rcl_interfaces::msg::ParameterValue> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__parameter_values(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rcl_interfaces::msg::ParameterValue> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__parameter_values(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rcl_interfaces::msg::ParameterValue *>(
    get_const_function__Node__parameter_values(untyped_member, index));
  auto & value = *reinterpret_cast<rcl_interfaces::msg::ParameterValue *>(untyped_value);
  value = item;
}

void assign_function__Node__parameter_values(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rcl_interfaces::msg::ParameterValue *>(
    get_function__Node__parameter_values(untyped_member, index));
  const auto & value = *reinterpret_cast<const rcl_interfaces::msg::ParameterValue *>(untyped_value);
  item = value;
}

void resize_function__Node__parameter_values(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rcl_interfaces::msg::ParameterValue> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__publishers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__publishers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__publishers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__publishers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosgraph_msgs::msg::Topic *>(
    get_const_function__Node__publishers(untyped_member, index));
  auto & value = *reinterpret_cast<rosgraph_msgs::msg::Topic *>(untyped_value);
  value = item;
}

void assign_function__Node__publishers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosgraph_msgs::msg::Topic *>(
    get_function__Node__publishers(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosgraph_msgs::msg::Topic *>(untyped_value);
  item = value;
}

void resize_function__Node__publishers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__subscriptions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__subscriptions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__subscriptions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__subscriptions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosgraph_msgs::msg::Topic *>(
    get_const_function__Node__subscriptions(untyped_member, index));
  auto & value = *reinterpret_cast<rosgraph_msgs::msg::Topic *>(untyped_value);
  value = item;
}

void assign_function__Node__subscriptions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosgraph_msgs::msg::Topic *>(
    get_function__Node__subscriptions(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosgraph_msgs::msg::Topic *>(untyped_value);
  item = value;
}

void resize_function__Node__subscriptions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosgraph_msgs::msg::Topic> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__service_clients(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__service_clients(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__service_clients(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__service_clients(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosgraph_msgs::msg::Service *>(
    get_const_function__Node__service_clients(untyped_member, index));
  auto & value = *reinterpret_cast<rosgraph_msgs::msg::Service *>(untyped_value);
  value = item;
}

void assign_function__Node__service_clients(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosgraph_msgs::msg::Service *>(
    get_function__Node__service_clients(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosgraph_msgs::msg::Service *>(untyped_value);
  item = value;
}

void resize_function__Node__service_clients(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__service_servers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__service_servers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__service_servers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__service_servers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosgraph_msgs::msg::Service *>(
    get_const_function__Node__service_servers(untyped_member, index));
  auto & value = *reinterpret_cast<rosgraph_msgs::msg::Service *>(untyped_value);
  value = item;
}

void assign_function__Node__service_servers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosgraph_msgs::msg::Service *>(
    get_function__Node__service_servers(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosgraph_msgs::msg::Service *>(untyped_value);
  item = value;
}

void resize_function__Node__service_servers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosgraph_msgs::msg::Service> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__action_clients(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__action_clients(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__action_clients(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__action_clients(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosgraph_msgs::msg::Action *>(
    get_const_function__Node__action_clients(untyped_member, index));
  auto & value = *reinterpret_cast<rosgraph_msgs::msg::Action *>(untyped_value);
  value = item;
}

void assign_function__Node__action_clients(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosgraph_msgs::msg::Action *>(
    get_function__Node__action_clients(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosgraph_msgs::msg::Action *>(untyped_value);
  item = value;
}

void resize_function__Node__action_clients(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Node__action_servers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Node__action_servers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  return &member[index];
}

void * get_function__Node__action_servers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  return &member[index];
}

void fetch_function__Node__action_servers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rosgraph_msgs::msg::Action *>(
    get_const_function__Node__action_servers(untyped_member, index));
  auto & value = *reinterpret_cast<rosgraph_msgs::msg::Action *>(untyped_value);
  value = item;
}

void assign_function__Node__action_servers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rosgraph_msgs::msg::Action *>(
    get_function__Node__action_servers(untyped_member, index));
  const auto & value = *reinterpret_cast<const rosgraph_msgs::msg::Action *>(untyped_value);
  item = value;
}

void resize_function__Node__action_servers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rosgraph_msgs::msg::Action> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Node_message_member_array[9] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, name),  // bytes offset in struct
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
    "parameters",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rcl_interfaces::msg::ParameterDescriptor>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, parameters),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__parameters,  // size() function pointer
    get_const_function__Node__parameters,  // get_const(index) function pointer
    get_function__Node__parameters,  // get(index) function pointer
    fetch_function__Node__parameters,  // fetch(index, &value) function pointer
    assign_function__Node__parameters,  // assign(index, value) function pointer
    resize_function__Node__parameters,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "parameter_values",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rcl_interfaces::msg::ParameterValue>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, parameter_values),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__parameter_values,  // size() function pointer
    get_const_function__Node__parameter_values,  // get_const(index) function pointer
    get_function__Node__parameter_values,  // get(index) function pointer
    fetch_function__Node__parameter_values,  // fetch(index, &value) function pointer
    assign_function__Node__parameter_values,  // assign(index, value) function pointer
    resize_function__Node__parameter_values,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "publishers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosgraph_msgs::msg::Topic>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, publishers),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__publishers,  // size() function pointer
    get_const_function__Node__publishers,  // get_const(index) function pointer
    get_function__Node__publishers,  // get(index) function pointer
    fetch_function__Node__publishers,  // fetch(index, &value) function pointer
    assign_function__Node__publishers,  // assign(index, value) function pointer
    resize_function__Node__publishers,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "subscriptions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosgraph_msgs::msg::Topic>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, subscriptions),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__subscriptions,  // size() function pointer
    get_const_function__Node__subscriptions,  // get_const(index) function pointer
    get_function__Node__subscriptions,  // get(index) function pointer
    fetch_function__Node__subscriptions,  // fetch(index, &value) function pointer
    assign_function__Node__subscriptions,  // assign(index, value) function pointer
    resize_function__Node__subscriptions,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "service_clients",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosgraph_msgs::msg::Service>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, service_clients),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__service_clients,  // size() function pointer
    get_const_function__Node__service_clients,  // get_const(index) function pointer
    get_function__Node__service_clients,  // get(index) function pointer
    fetch_function__Node__service_clients,  // fetch(index, &value) function pointer
    assign_function__Node__service_clients,  // assign(index, value) function pointer
    resize_function__Node__service_clients,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "service_servers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosgraph_msgs::msg::Service>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, service_servers),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__service_servers,  // size() function pointer
    get_const_function__Node__service_servers,  // get_const(index) function pointer
    get_function__Node__service_servers,  // get(index) function pointer
    fetch_function__Node__service_servers,  // fetch(index, &value) function pointer
    assign_function__Node__service_servers,  // assign(index, value) function pointer
    resize_function__Node__service_servers,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "action_clients",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosgraph_msgs::msg::Action>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, action_clients),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__action_clients,  // size() function pointer
    get_const_function__Node__action_clients,  // get_const(index) function pointer
    get_function__Node__action_clients,  // get(index) function pointer
    fetch_function__Node__action_clients,  // fetch(index, &value) function pointer
    assign_function__Node__action_clients,  // assign(index, value) function pointer
    resize_function__Node__action_clients,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "action_servers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosgraph_msgs::msg::Action>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::Node, action_servers),  // bytes offset in struct
    nullptr,  // default value
    size_function__Node__action_servers,  // size() function pointer
    get_const_function__Node__action_servers,  // get_const(index) function pointer
    get_function__Node__action_servers,  // get(index) function pointer
    fetch_function__Node__action_servers,  // fetch(index, &value) function pointer
    assign_function__Node__action_servers,  // assign(index, value) function pointer
    resize_function__Node__action_servers,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Node_message_members = {
  "rosgraph_msgs::msg",  // message namespace
  "Node",  // message name
  9,  // number of fields
  sizeof(rosgraph_msgs::msg::Node),
  false,  // has_any_key_member_
  Node_message_member_array,  // message members
  Node_init_function,  // function to initialize message memory (memory has to be allocated)
  Node_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Node_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Node_message_members,
  get_message_typesupport_handle_function,
  &rosgraph_msgs__msg__Node__get_type_hash,
  &rosgraph_msgs__msg__Node__get_type_description,
  &rosgraph_msgs__msg__Node__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rosgraph_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosgraph_msgs::msg::Node>()
{
  return &::rosgraph_msgs::msg::rosidl_typesupport_introspection_cpp::Node_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosgraph_msgs, msg, Node)() {
  return &::rosgraph_msgs::msg::rosidl_typesupport_introspection_cpp::Node_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
