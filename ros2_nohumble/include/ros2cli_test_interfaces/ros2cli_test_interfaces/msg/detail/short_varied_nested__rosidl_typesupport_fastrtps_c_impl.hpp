// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from ros2cli_test_interfaces:msg\ShortVariedNested.idl
// generated code does not contain a copyright notice

#ifndef ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2cli_test_interfaces/msg/detail/short_varied_nested__struct.h"
#include "ros2cli_test_interfaces/msg/detail/short_varied_nested__functions.h"
#include "ros2cli_test_interfaces/msg/detail/short_varied_nested__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "ros2cli_test_interfaces/msg/detail/short_varied__functions.h"  // short_varied

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "ros2cli_test_interfaces/msg/detail/short_varied__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ShortVariedNested__ros_msg_type = ros2cli_test_interfaces__msg__ShortVariedNested;


inline
bool impl_cdr_serialize_ros2cli_test_interfaces__msg__ShortVariedNested(
  const ros2cli_test_interfaces__msg__ShortVariedNested * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: short_varied
  {
    impl_cdr_serialize_ros2cli_test_interfaces__msg__ShortVaried(
      &ros_message->short_varied, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_ros2cli_test_interfaces__msg__ShortVariedNested(
  eprosima::fastcdr::Cdr & cdr,
  ros2cli_test_interfaces__msg__ShortVariedNested * ros_message)
{
  // Field name: short_varied
  {
    impl_cdr_deserialize_ros2cli_test_interfaces__msg__ShortVaried(cdr, &ros_message->short_varied);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_ros2cli_test_interfaces__msg__ShortVariedNested(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ShortVariedNested__ros_msg_type * ros_message = static_cast<const _ShortVariedNested__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: short_varied
  current_alignment += impl_get_serialized_size_ros2cli_test_interfaces__msg__ShortVaried(
    &(ros_message->short_varied), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_ros2cli_test_interfaces__msg__ShortVariedNested(
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

  // Field name: short_varied
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_ros2cli_test_interfaces__msg__ShortVaried(
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
    using DataType = ros2cli_test_interfaces__msg__ShortVariedNested;
    is_plain =
      (
      offsetof(DataType, short_varied) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_ros2cli_test_interfaces__msg__ShortVariedNested(
  const ros2cli_test_interfaces__msg__ShortVariedNested * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: short_varied
  {
    impl_cdr_serialize_key_ros2cli_test_interfaces__msg__ShortVaried(
      &ros_message->short_varied, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_ros2cli_test_interfaces__msg__ShortVariedNested(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ShortVariedNested__ros_msg_type * ros_message = static_cast<const _ShortVariedNested__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: short_varied
  current_alignment += impl_get_serialized_size_key_ros2cli_test_interfaces__msg__ShortVaried(
    &(ros_message->short_varied), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_ros2cli_test_interfaces__msg__ShortVariedNested(
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
  // Field name: short_varied
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_ros2cli_test_interfaces__msg__ShortVaried(
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
    using DataType = ros2cli_test_interfaces__msg__ShortVariedNested;
    is_plain =
      (
      offsetof(DataType, short_varied) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_ros2cli_test_interfaces__msg__ShortVariedNested(
  const ros2cli_test_interfaces__msg__ShortVariedNested * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: short_varied
  {
    impl_cdr_serialize_with_endpoint_ros2cli_test_interfaces__msg__ShortVaried(
      &ros_message->short_varied, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_ros2cli_test_interfaces__msg__ShortVariedNested(
  eprosima::fastcdr::Cdr & cdr,
  ros2cli_test_interfaces__msg__ShortVariedNested * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: short_varied
  {
    impl_cdr_deserialize_with_endpoint_ros2cli_test_interfaces__msg__ShortVaried(cdr, &ros_message->short_varied, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROS2CLI_TEST_INTERFACES__MSG__DETAIL__SHORT_VARIED_NESTED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
