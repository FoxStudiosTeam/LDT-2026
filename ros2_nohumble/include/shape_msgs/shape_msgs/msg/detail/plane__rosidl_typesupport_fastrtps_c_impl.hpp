// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from shape_msgs:msg\Plane.idl
// generated code does not contain a copyright notice

#ifndef SHAPE_MSGS__MSG__DETAIL__PLANE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define SHAPE_MSGS__MSG__DETAIL__PLANE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "shape_msgs/msg/detail/plane__struct.h"
#include "shape_msgs/msg/detail/plane__functions.h"
#include "shape_msgs/msg/detail/plane__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"


// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _Plane__ros_msg_type = shape_msgs__msg__Plane;


inline
bool impl_cdr_serialize_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: coef
  {
    size_t size = 4;
    auto array_ptr = ros_message->coef;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_shape_msgs__msg__Plane(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__Plane * ros_message)
{
  // Field name: coef
  {
    size_t size = 4;
    auto array_ptr = ros_message->coef;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Plane__ros_msg_type * ros_message = static_cast<const _Plane__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: coef
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->coef;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_shape_msgs__msg__Plane(
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

  // Field name: coef
  {
    size_t array_size = 4;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = shape_msgs__msg__Plane;
    is_plain =
      (
      offsetof(DataType, coef) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: coef
  {
    size_t size = 4;
    auto array_ptr = ros_message->coef;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Plane__ros_msg_type * ros_message = static_cast<const _Plane__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: coef
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->coef;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_shape_msgs__msg__Plane(
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
  // Field name: coef
  {
    size_t array_size = 4;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = shape_msgs__msg__Plane;
    is_plain =
      (
      offsetof(DataType, coef) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: coef
  {
    size_t size = 4;
    auto array_ptr = ros_message->coef;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_shape_msgs__msg__Plane(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__Plane * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: coef
  {
    size_t size = 4;
    auto array_ptr = ros_message->coef;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // SHAPE_MSGS__MSG__DETAIL__PLANE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
