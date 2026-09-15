// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rosbag2_test_msgdefs:msg\ComplexMsgDependsOnIdl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_msg_depends_on_idl__functions.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_msg_depends_on_idl__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rosbag2_test_msgdefs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ComplexMsgDependsOnIdl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl(_init);
}

void ComplexMsgDependsOnIdl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl *>(message_memory);
  typed_message->~ComplexMsgDependsOnIdl();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ComplexMsgDependsOnIdl_message_member_array[1] = {
  {
    "a",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rosbag2_test_msgdefs::msg::BasicIdl>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl, a),  // bytes offset in struct
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

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ComplexMsgDependsOnIdl_message_members = {
  "rosbag2_test_msgdefs::msg",  // message namespace
  "ComplexMsgDependsOnIdl",  // message name
  1,  // number of fields
  sizeof(rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl),
  false,  // has_any_key_member_
  ComplexMsgDependsOnIdl_message_member_array,  // message members
  ComplexMsgDependsOnIdl_init_function,  // function to initialize message memory (memory has to be allocated)
  ComplexMsgDependsOnIdl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ComplexMsgDependsOnIdl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComplexMsgDependsOnIdl_message_members,
  get_message_typesupport_handle_function,
  &rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__get_type_hash,
  &rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__get_type_description,
  &rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rosbag2_test_msgdefs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosbag2_test_msgdefs::msg::ComplexMsgDependsOnIdl>()
{
  return &::rosbag2_test_msgdefs::msg::rosidl_typesupport_introspection_cpp::ComplexMsgDependsOnIdl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbag2_test_msgdefs, msg, ComplexMsgDependsOnIdl)() {
  return &::rosbag2_test_msgdefs::msg::rosidl_typesupport_introspection_cpp::ComplexMsgDependsOnIdl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
