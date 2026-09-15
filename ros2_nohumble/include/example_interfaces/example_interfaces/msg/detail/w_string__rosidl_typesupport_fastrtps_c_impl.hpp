// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from example_interfaces:msg\WString.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__MSG__DETAIL__W_STRING__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define EXAMPLE_INTERFACES__MSG__DETAIL__W_STRING__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "example_interfaces/msg/detail/w_string__struct.h"
#include "example_interfaces/msg/detail/w_string__functions.h"
#include "example_interfaces/msg/detail/w_string__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/u16string.h"  // data
#include "rosidl_runtime_c/u16string_functions.h"  // data

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _WString__ros_msg_type = example_interfaces__msg__WString;


inline
bool impl_cdr_serialize_example_interfaces__msg__WString(
  const example_interfaces__msg__WString * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: data
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->data);
  }

  return true;
}

inline
bool impl_cdr_deserialize_example_interfaces__msg__WString(
  eprosima::fastcdr::Cdr & cdr,
  example_interfaces__msg__WString * ros_message)
{
  // Field name: data
  {
    if (!ros_message->data.data) {
      rosidl_runtime_c__U16String__init(&ros_message->data);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->data);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->data);
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_example_interfaces__msg__WString(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WString__ros_msg_type * ros_message = static_cast<const _WString__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->data.size + 1);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_example_interfaces__msg__WString(
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

  // Field name: data
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = example_interfaces__msg__WString;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_example_interfaces__msg__WString(
  const example_interfaces__msg__WString * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: data
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->data);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_example_interfaces__msg__WString(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WString__ros_msg_type * ros_message = static_cast<const _WString__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->data.size + 1);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_example_interfaces__msg__WString(
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
  // Field name: data
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = example_interfaces__msg__WString;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_example_interfaces__msg__WString(
  const example_interfaces__msg__WString * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: data
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->data);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_example_interfaces__msg__WString(
  eprosima::fastcdr::Cdr & cdr,
  example_interfaces__msg__WString * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: data
  {
    if (!ros_message->data.data) {
      rosidl_runtime_c__U16String__init(&ros_message->data);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->data);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->data);
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // EXAMPLE_INTERFACES__MSG__DETAIL__W_STRING__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
