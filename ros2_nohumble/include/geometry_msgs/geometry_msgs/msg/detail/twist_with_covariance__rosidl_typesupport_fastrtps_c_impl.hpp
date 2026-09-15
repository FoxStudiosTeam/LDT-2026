// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from geometry_msgs:msg\TwistWithCovariance.idl
// generated code does not contain a copyright notice

#ifndef GEOMETRY_MSGS__MSG__DETAIL__TWIST_WITH_COVARIANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__TWIST_WITH_COVARIANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "geometry_msgs/msg/detail/twist_with_covariance__struct.h"
#include "geometry_msgs/msg/detail/twist_with_covariance__functions.h"
#include "geometry_msgs/msg/detail/twist_with_covariance__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "geometry_msgs/msg/detail/twist__functions.h"  // twist

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _TwistWithCovariance__ros_msg_type = geometry_msgs__msg__TwistWithCovariance;


inline
bool impl_cdr_serialize_geometry_msgs__msg__TwistWithCovariance(
  const geometry_msgs__msg__TwistWithCovariance * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: twist
  {
    impl_cdr_serialize_geometry_msgs__msg__Twist(
      &ros_message->twist, cdr);
  }

  // Field name: covariance
  {
    size_t size = 36;
    auto array_ptr = ros_message->covariance;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_geometry_msgs__msg__TwistWithCovariance(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__TwistWithCovariance * ros_message)
{
  // Field name: twist
  {
    impl_cdr_deserialize_geometry_msgs__msg__Twist(cdr, &ros_message->twist);
  }

  // Field name: covariance
  {
    size_t size = 36;
    auto array_ptr = ros_message->covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_geometry_msgs__msg__TwistWithCovariance(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TwistWithCovariance__ros_msg_type * ros_message = static_cast<const _TwistWithCovariance__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: twist
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Twist(
    &(ros_message->twist), current_alignment);

  // Field name: covariance
  {
    size_t array_size = 36;
    auto array_ptr = ros_message->covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_geometry_msgs__msg__TwistWithCovariance(
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

  // Field name: twist
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: covariance
  {
    size_t array_size = 36;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = geometry_msgs__msg__TwistWithCovariance;
    is_plain =
      (
      offsetof(DataType, covariance) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_geometry_msgs__msg__TwistWithCovariance(
  const geometry_msgs__msg__TwistWithCovariance * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: twist
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Twist(
      &ros_message->twist, cdr);
  }

  // Field name: covariance
  {
    size_t size = 36;
    auto array_ptr = ros_message->covariance;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_geometry_msgs__msg__TwistWithCovariance(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TwistWithCovariance__ros_msg_type * ros_message = static_cast<const _TwistWithCovariance__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: twist
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Twist(
    &(ros_message->twist), current_alignment);

  // Field name: covariance
  {
    size_t array_size = 36;
    auto array_ptr = ros_message->covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_geometry_msgs__msg__TwistWithCovariance(
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
  // Field name: twist
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: covariance
  {
    size_t array_size = 36;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = geometry_msgs__msg__TwistWithCovariance;
    is_plain =
      (
      offsetof(DataType, covariance) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_geometry_msgs__msg__TwistWithCovariance(
  const geometry_msgs__msg__TwistWithCovariance * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: twist
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Twist(
      &ros_message->twist, cdr, endpoint_info, serialization_context);
  }

  // Field name: covariance
  {
    size_t size = 36;
    auto array_ptr = ros_message->covariance;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__TwistWithCovariance(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__TwistWithCovariance * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: twist
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Twist(cdr, &ros_message->twist, endpoint_info, serialization_context);
  }

  // Field name: covariance
  {
    size_t size = 36;
    auto array_ptr = ros_message->covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // GEOMETRY_MSGS__MSG__DETAIL__TWIST_WITH_COVARIANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
