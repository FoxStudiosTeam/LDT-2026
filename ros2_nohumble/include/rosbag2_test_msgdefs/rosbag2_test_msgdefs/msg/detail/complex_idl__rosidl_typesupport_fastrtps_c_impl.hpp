// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosbag2_test_msgdefs:msg\ComplexIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_idl__struct.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_idl__functions.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_idl__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosbag2_test_msgdefs/msg/detail/basic_idl__functions.h"  // a

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rosbag2_test_msgdefs/msg/detail/basic_idl__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ComplexIdl__ros_msg_type = rosbag2_test_msgdefs__msg__ComplexIdl;


inline
bool impl_cdr_serialize_rosbag2_test_msgdefs__msg__ComplexIdl(
  const rosbag2_test_msgdefs__msg__ComplexIdl * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: a
  {
    impl_cdr_serialize_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->a, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosbag2_test_msgdefs__msg__ComplexIdl(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__msg__ComplexIdl * ros_message)
{
  // Field name: a
  {
    impl_cdr_deserialize_rosbag2_test_msgdefs__msg__BasicIdl(cdr, &ros_message->a);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosbag2_test_msgdefs__msg__ComplexIdl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexIdl__ros_msg_type * ros_message = static_cast<const _ComplexIdl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: a
  current_alignment += impl_get_serialized_size_rosbag2_test_msgdefs__msg__BasicIdl(
    &(ros_message->a), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosbag2_test_msgdefs__msg__ComplexIdl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: a
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosbag2_test_msgdefs__msg__BasicIdl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__msg__ComplexIdl;
    is_plain =
      (
      offsetof(DataType, a) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosbag2_test_msgdefs__msg__ComplexIdl(
  const rosbag2_test_msgdefs__msg__ComplexIdl * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: a
  {
    impl_cdr_serialize_key_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->a, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosbag2_test_msgdefs__msg__ComplexIdl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexIdl__ros_msg_type * ros_message = static_cast<const _ComplexIdl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: a
  current_alignment += impl_get_serialized_size_key_rosbag2_test_msgdefs__msg__BasicIdl(
    &(ros_message->a), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosbag2_test_msgdefs__msg__ComplexIdl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: a
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosbag2_test_msgdefs__msg__BasicIdl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__msg__ComplexIdl;
    is_plain =
      (
      offsetof(DataType, a) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__msg__ComplexIdl(
  const rosbag2_test_msgdefs__msg__ComplexIdl * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: a
  {
    impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->a, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__msg__ComplexIdl(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__msg__ComplexIdl * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: a
  {
    impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__msg__BasicIdl(cdr, &ros_message->a, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
