// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "test_rosidl_buffer/msg/detail/byte_array_list__functions.h"
#include "test_rosidl_buffer/msg/detail/byte_array_list__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace test_rosidl_buffer
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ByteArrayList_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) test_rosidl_buffer::msg::ByteArrayList(_init);
}

void ByteArrayList_fini_function(void * message_memory)
{
  auto typed_message = static_cast<test_rosidl_buffer::msg::ByteArrayList *>(message_memory);
  typed_message->~ByteArrayList();
}

size_t size_function__ByteArrayList__items(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<test_rosidl_buffer::msg::ByteArray> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ByteArrayList__items(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<test_rosidl_buffer::msg::ByteArray> *>(untyped_member);
  return &member[index];
}

void * get_function__ByteArrayList__items(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<test_rosidl_buffer::msg::ByteArray> *>(untyped_member);
  return &member[index];
}

void fetch_function__ByteArrayList__items(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const test_rosidl_buffer::msg::ByteArray *>(
    get_const_function__ByteArrayList__items(untyped_member, index));
  auto & value = *reinterpret_cast<test_rosidl_buffer::msg::ByteArray *>(untyped_value);
  value = item;
}

void assign_function__ByteArrayList__items(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<test_rosidl_buffer::msg::ByteArray *>(
    get_function__ByteArrayList__items(untyped_member, index));
  const auto & value = *reinterpret_cast<const test_rosidl_buffer::msg::ByteArray *>(untyped_value);
  item = value;
}

void resize_function__ByteArrayList__items(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<test_rosidl_buffer::msg::ByteArray> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ByteArrayList_message_member_array[1] = {
  {
    "items",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<test_rosidl_buffer::msg::ByteArray>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_rosidl_buffer::msg::ByteArrayList, items),  // bytes offset in struct
    nullptr,  // default value
    size_function__ByteArrayList__items,  // size() function pointer
    get_const_function__ByteArrayList__items,  // get_const(index) function pointer
    get_function__ByteArrayList__items,  // get(index) function pointer
    fetch_function__ByteArrayList__items,  // fetch(index, &value) function pointer
    assign_function__ByteArrayList__items,  // assign(index, value) function pointer
    resize_function__ByteArrayList__items,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ByteArrayList_message_members = {
  "test_rosidl_buffer::msg",  // message namespace
  "ByteArrayList",  // message name
  1,  // number of fields
  sizeof(test_rosidl_buffer::msg::ByteArrayList),
  false,  // has_any_key_member_
  ByteArrayList_message_member_array,  // message members
  ByteArrayList_init_function,  // function to initialize message memory (memory has to be allocated)
  ByteArrayList_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ByteArrayList_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ByteArrayList_message_members,
  get_message_typesupport_handle_function,
  &test_rosidl_buffer__msg__ByteArrayList__get_type_hash,
  &test_rosidl_buffer__msg__ByteArrayList__get_type_description,
  &test_rosidl_buffer__msg__ByteArrayList__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace test_rosidl_buffer


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<test_rosidl_buffer::msg::ByteArrayList>()
{
  return &::test_rosidl_buffer::msg::rosidl_typesupport_introspection_cpp::ByteArrayList_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, test_rosidl_buffer, msg, ByteArrayList)() {
  return &::test_rosidl_buffer::msg::rosidl_typesupport_introspection_cpp::ByteArrayList_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
