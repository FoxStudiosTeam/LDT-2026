// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rosgraph_msgs:msg\TypeHash.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rosgraph_msgs/msg/detail/type_hash__functions.h"
#include "rosgraph_msgs/msg/detail/type_hash__struct.hpp"
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

void TypeHash_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosgraph_msgs::msg::TypeHash(_init);
}

void TypeHash_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosgraph_msgs::msg::TypeHash *>(message_memory);
  typed_message->~TypeHash();
}

size_t size_function__TypeHash__value(const void * untyped_member)
{
  (void)untyped_member;
  return 32;
}

const void * get_const_function__TypeHash__value(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 32> *>(untyped_member);
  return &member[index];
}

void * get_function__TypeHash__value(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 32> *>(untyped_member);
  return &member[index];
}

void fetch_function__TypeHash__value(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__TypeHash__value(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__TypeHash__value(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__TypeHash__value(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}


static const ::rosidl_typesupport_introspection_cpp::MessageMember TypeHash_message_member_array[2] = {
  {
    "version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::TypeHash, version),  // bytes offset in struct
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
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    32,  // array size
    false,  // is upper bound
    offsetof(rosgraph_msgs::msg::TypeHash, value),  // bytes offset in struct
    nullptr,  // default value
    size_function__TypeHash__value,  // size() function pointer
    get_const_function__TypeHash__value,  // get_const(index) function pointer
    get_function__TypeHash__value,  // get(index) function pointer
    fetch_function__TypeHash__value,  // fetch(index, &value) function pointer
    assign_function__TypeHash__value,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TypeHash_message_members = {
  "rosgraph_msgs::msg",  // message namespace
  "TypeHash",  // message name
  2,  // number of fields
  sizeof(rosgraph_msgs::msg::TypeHash),
  false,  // has_any_key_member_
  TypeHash_message_member_array,  // message members
  TypeHash_init_function,  // function to initialize message memory (memory has to be allocated)
  TypeHash_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TypeHash_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TypeHash_message_members,
  get_message_typesupport_handle_function,
  &rosgraph_msgs__msg__TypeHash__get_type_hash,
  &rosgraph_msgs__msg__TypeHash__get_type_description,
  &rosgraph_msgs__msg__TypeHash__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rosgraph_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosgraph_msgs::msg::TypeHash>()
{
  return &::rosgraph_msgs::msg::rosidl_typesupport_introspection_cpp::TypeHash_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosgraph_msgs, msg, TypeHash)() {
  return &::rosgraph_msgs::msg::rosidl_typesupport_introspection_cpp::TypeHash_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
