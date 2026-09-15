// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_msgs:msg\BasicTypes.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__BASIC_TYPES__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__BASIC_TYPES__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_msgs/msg/detail/basic_types__struct.h"
#include "test_msgs/msg/detail/basic_types__functions.h"
#include "test_msgs/msg/detail/basic_types__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"


// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _BasicTypes__ros_msg_type = test_msgs__msg__BasicTypes;


inline
bool impl_cdr_serialize_test_msgs__msg__BasicTypes(
  const test_msgs__msg__BasicTypes * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_value
  {
    cdr << (ros_message->bool_value ? true : false);
  }

  // Field name: byte_value
  {
    cdr << ros_message->byte_value;
  }

  // Field name: char_value
  {
    cdr << ros_message->char_value;
  }

  // Field name: float32_value
  {
    cdr << ros_message->float32_value;
  }

  // Field name: float64_value
  {
    cdr << ros_message->float64_value;
  }

  // Field name: int8_value
  {
    cdr << ros_message->int8_value;
  }

  // Field name: uint8_value
  {
    cdr << ros_message->uint8_value;
  }

  // Field name: int16_value
  {
    cdr << ros_message->int16_value;
  }

  // Field name: uint16_value
  {
    cdr << ros_message->uint16_value;
  }

  // Field name: int32_value
  {
    cdr << ros_message->int32_value;
  }

  // Field name: uint32_value
  {
    cdr << ros_message->uint32_value;
  }

  // Field name: int64_value
  {
    cdr << ros_message->int64_value;
  }

  // Field name: uint64_value
  {
    cdr << ros_message->uint64_value;
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_msgs__msg__BasicTypes(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__BasicTypes * ros_message)
{
  // Field name: bool_value
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->bool_value = tmp ? true : false;
  }

  // Field name: byte_value
  {
    cdr >> ros_message->byte_value;
  }

  // Field name: char_value
  {
    cdr >> ros_message->char_value;
  }

  // Field name: float32_value
  {
    cdr >> ros_message->float32_value;
  }

  // Field name: float64_value
  {
    cdr >> ros_message->float64_value;
  }

  // Field name: int8_value
  {
    cdr >> ros_message->int8_value;
  }

  // Field name: uint8_value
  {
    cdr >> ros_message->uint8_value;
  }

  // Field name: int16_value
  {
    cdr >> ros_message->int16_value;
  }

  // Field name: uint16_value
  {
    cdr >> ros_message->uint16_value;
  }

  // Field name: int32_value
  {
    cdr >> ros_message->int32_value;
  }

  // Field name: uint32_value
  {
    cdr >> ros_message->uint32_value;
  }

  // Field name: int64_value
  {
    cdr >> ros_message->int64_value;
  }

  // Field name: uint64_value
  {
    cdr >> ros_message->uint64_value;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__msg__BasicTypes(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BasicTypes__ros_msg_type * ros_message = static_cast<const _BasicTypes__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_value
  {
    size_t item_size = sizeof(ros_message->bool_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_value
  {
    size_t item_size = sizeof(ros_message->byte_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_value
  {
    size_t item_size = sizeof(ros_message->char_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_value
  {
    size_t item_size = sizeof(ros_message->float32_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_value
  {
    size_t item_size = sizeof(ros_message->float64_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_value
  {
    size_t item_size = sizeof(ros_message->int8_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_value
  {
    size_t item_size = sizeof(ros_message->uint8_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_value
  {
    size_t item_size = sizeof(ros_message->int16_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_value
  {
    size_t item_size = sizeof(ros_message->uint16_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_value
  {
    size_t item_size = sizeof(ros_message->int32_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_value
  {
    size_t item_size = sizeof(ros_message->uint32_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_value
  {
    size_t item_size = sizeof(ros_message->int64_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_value
  {
    size_t item_size = sizeof(ros_message->uint64_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__msg__BasicTypes(
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

  // Field name: bool_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs__msg__BasicTypes;
    is_plain =
      (
      offsetof(DataType, uint64_value) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__msg__BasicTypes(
  const test_msgs__msg__BasicTypes * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_value
  {
    cdr << (ros_message->bool_value ? true : false);
  }

  // Field name: byte_value
  {
    cdr << ros_message->byte_value;
  }

  // Field name: char_value
  {
    cdr << ros_message->char_value;
  }

  // Field name: float32_value
  {
    cdr << ros_message->float32_value;
  }

  // Field name: float64_value
  {
    cdr << ros_message->float64_value;
  }

  // Field name: int8_value
  {
    cdr << ros_message->int8_value;
  }

  // Field name: uint8_value
  {
    cdr << ros_message->uint8_value;
  }

  // Field name: int16_value
  {
    cdr << ros_message->int16_value;
  }

  // Field name: uint16_value
  {
    cdr << ros_message->uint16_value;
  }

  // Field name: int32_value
  {
    cdr << ros_message->int32_value;
  }

  // Field name: uint32_value
  {
    cdr << ros_message->uint32_value;
  }

  // Field name: int64_value
  {
    cdr << ros_message->int64_value;
  }

  // Field name: uint64_value
  {
    cdr << ros_message->uint64_value;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_msgs__msg__BasicTypes(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BasicTypes__ros_msg_type * ros_message = static_cast<const _BasicTypes__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_value
  {
    size_t item_size = sizeof(ros_message->bool_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_value
  {
    size_t item_size = sizeof(ros_message->byte_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_value
  {
    size_t item_size = sizeof(ros_message->char_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_value
  {
    size_t item_size = sizeof(ros_message->float32_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_value
  {
    size_t item_size = sizeof(ros_message->float64_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_value
  {
    size_t item_size = sizeof(ros_message->int8_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_value
  {
    size_t item_size = sizeof(ros_message->uint8_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_value
  {
    size_t item_size = sizeof(ros_message->int16_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_value
  {
    size_t item_size = sizeof(ros_message->uint16_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_value
  {
    size_t item_size = sizeof(ros_message->int32_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_value
  {
    size_t item_size = sizeof(ros_message->uint32_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_value
  {
    size_t item_size = sizeof(ros_message->int64_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_value
  {
    size_t item_size = sizeof(ros_message->uint64_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__msg__BasicTypes(
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
  // Field name: bool_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_value
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs__msg__BasicTypes;
    is_plain =
      (
      offsetof(DataType, uint64_value) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__msg__BasicTypes(
  const test_msgs__msg__BasicTypes * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_value
  {
    cdr << (ros_message->bool_value ? true : false);
  }

  // Field name: byte_value
  {
    cdr << ros_message->byte_value;
  }

  // Field name: char_value
  {
    cdr << ros_message->char_value;
  }

  // Field name: float32_value
  {
    cdr << ros_message->float32_value;
  }

  // Field name: float64_value
  {
    cdr << ros_message->float64_value;
  }

  // Field name: int8_value
  {
    cdr << ros_message->int8_value;
  }

  // Field name: uint8_value
  {
    cdr << ros_message->uint8_value;
  }

  // Field name: int16_value
  {
    cdr << ros_message->int16_value;
  }

  // Field name: uint16_value
  {
    cdr << ros_message->uint16_value;
  }

  // Field name: int32_value
  {
    cdr << ros_message->int32_value;
  }

  // Field name: uint32_value
  {
    cdr << ros_message->uint32_value;
  }

  // Field name: int64_value
  {
    cdr << ros_message->int64_value;
  }

  // Field name: uint64_value
  {
    cdr << ros_message->uint64_value;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_msgs__msg__BasicTypes(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__BasicTypes * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_value
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->bool_value = tmp ? true : false;
  }

  // Field name: byte_value
  {
    cdr >> ros_message->byte_value;
  }

  // Field name: char_value
  {
    cdr >> ros_message->char_value;
  }

  // Field name: float32_value
  {
    cdr >> ros_message->float32_value;
  }

  // Field name: float64_value
  {
    cdr >> ros_message->float64_value;
  }

  // Field name: int8_value
  {
    cdr >> ros_message->int8_value;
  }

  // Field name: uint8_value
  {
    cdr >> ros_message->uint8_value;
  }

  // Field name: int16_value
  {
    cdr >> ros_message->int16_value;
  }

  // Field name: uint16_value
  {
    cdr >> ros_message->uint16_value;
  }

  // Field name: int32_value
  {
    cdr >> ros_message->int32_value;
  }

  // Field name: uint32_value
  {
    cdr >> ros_message->uint32_value;
  }

  // Field name: int64_value
  {
    cdr >> ros_message->int64_value;
  }

  // Field name: uint64_value
  {
    cdr >> ros_message->uint64_value;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__BASIC_TYPES__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
