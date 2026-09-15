// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from test_msgs:msg\KeyedString.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "test_msgs/msg/detail/keyed_string__functions.h"
#include "test_msgs/msg/detail/keyed_string__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace test_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void KeyedString_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) test_msgs::msg::KeyedString(_init);
}

void KeyedString_fini_function(void * message_memory)
{
  auto typed_message = static_cast<test_msgs::msg::KeyedString *>(message_memory);
  typed_message->~KeyedString();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember KeyedString_message_member_array[2] = {
  {
    "key",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs::msg::KeyedString, key),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs::msg::KeyedString, value),  // bytes offset in struct
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

static const ::rosidl_typesupport_introspection_cpp::MessageMembers KeyedString_message_members = {
  "test_msgs::msg",  // message namespace
  "KeyedString",  // message name
  2,  // number of fields
  sizeof(test_msgs::msg::KeyedString),
  true,  // has_any_key_member_
  KeyedString_message_member_array,  // message members
  KeyedString_init_function,  // function to initialize message memory (memory has to be allocated)
  KeyedString_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t KeyedString_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &KeyedString_message_members,
  get_message_typesupport_handle_function,
  &test_msgs__msg__KeyedString__get_type_hash,
  &test_msgs__msg__KeyedString__get_type_description,
  &test_msgs__msg__KeyedString__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace test_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<test_msgs::msg::KeyedString>()
{
  return &::test_msgs::msg::rosidl_typesupport_introspection_cpp::KeyedString_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, test_msgs, msg, KeyedString)() {
  return &::test_msgs::msg::rosidl_typesupport_introspection_cpp::KeyedString_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
