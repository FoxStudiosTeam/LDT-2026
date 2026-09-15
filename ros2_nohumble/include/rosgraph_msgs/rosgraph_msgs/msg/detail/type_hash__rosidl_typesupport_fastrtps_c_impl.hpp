// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosgraph_msgs:msg\TypeHash.idl
// generated code does not contain a copyright notice

#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosgraph_msgs/msg/detail/type_hash__struct.h"
#include "rosgraph_msgs/msg/detail/type_hash__functions.h"
#include "rosgraph_msgs/msg/detail/type_hash__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"


// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _TypeHash__ros_msg_type = rosgraph_msgs__msg__TypeHash;


inline
bool impl_cdr_serialize_rosgraph_msgs__msg__TypeHash(
  const rosgraph_msgs__msg__TypeHash * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: value
  {
    size_t size = 32;
    auto array_ptr = ros_message->value;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosgraph_msgs__msg__TypeHash(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs__msg__TypeHash * ros_message)
{
  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: value
  {
    size_t size = 32;
    auto array_ptr = ros_message->value;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosgraph_msgs__msg__TypeHash(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TypeHash__ros_msg_type * ros_message = static_cast<const _TypeHash__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: value
  {
    size_t array_size = 32;
    auto array_ptr = ros_message->value;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosgraph_msgs__msg__TypeHash(
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

  // Field name: version
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: value
  {
    size_t array_size = 32;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosgraph_msgs__msg__TypeHash;
    is_plain =
      (
      offsetof(DataType, value) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosgraph_msgs__msg__TypeHash(
  const rosgraph_msgs__msg__TypeHash * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: value
  {
    size_t size = 32;
    auto array_ptr = ros_message->value;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosgraph_msgs__msg__TypeHash(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TypeHash__ros_msg_type * ros_message = static_cast<const _TypeHash__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: value
  {
    size_t array_size = 32;
    auto array_ptr = ros_message->value;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosgraph_msgs__msg__TypeHash(
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
  // Field name: version
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: value
  {
    size_t array_size = 32;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosgraph_msgs__msg__TypeHash;
    is_plain =
      (
      offsetof(DataType, value) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__TypeHash(
  const rosgraph_msgs__msg__TypeHash * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: value
  {
    size_t size = 32;
    auto array_ptr = ros_message->value;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__TypeHash(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs__msg__TypeHash * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: value
  {
    size_t size = 32;
    auto array_ptr = ros_message->value;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
