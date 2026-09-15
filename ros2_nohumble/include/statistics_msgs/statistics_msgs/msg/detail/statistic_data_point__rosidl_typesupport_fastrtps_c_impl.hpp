// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from statistics_msgs:msg\StatisticDataPoint.idl
// generated code does not contain a copyright notice

#ifndef STATISTICS_MSGS__MSG__DETAIL__STATISTIC_DATA_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define STATISTICS_MSGS__MSG__DETAIL__STATISTIC_DATA_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "statistics_msgs/msg/detail/statistic_data_point__struct.h"
#include "statistics_msgs/msg/detail/statistic_data_point__functions.h"
#include "statistics_msgs/msg/detail/statistic_data_point__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"


// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _StatisticDataPoint__ros_msg_type = statistics_msgs__msg__StatisticDataPoint;


inline
bool impl_cdr_serialize_statistics_msgs__msg__StatisticDataPoint(
  const statistics_msgs__msg__StatisticDataPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: data_type
  {
    cdr << ros_message->data_type;
  }

  // Field name: data
  {
    cdr << ros_message->data;
  }

  return true;
}

inline
bool impl_cdr_deserialize_statistics_msgs__msg__StatisticDataPoint(
  eprosima::fastcdr::Cdr & cdr,
  statistics_msgs__msg__StatisticDataPoint * ros_message)
{
  // Field name: data_type
  {
    cdr >> ros_message->data_type;
  }

  // Field name: data
  {
    cdr >> ros_message->data;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_statistics_msgs__msg__StatisticDataPoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StatisticDataPoint__ros_msg_type * ros_message = static_cast<const _StatisticDataPoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: data_type
  {
    size_t item_size = sizeof(ros_message->data_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data
  {
    size_t item_size = sizeof(ros_message->data);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_statistics_msgs__msg__StatisticDataPoint(
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

  // Field name: data_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: data
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
    using DataType = statistics_msgs__msg__StatisticDataPoint;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_statistics_msgs__msg__StatisticDataPoint(
  const statistics_msgs__msg__StatisticDataPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: data_type
  {
    cdr << ros_message->data_type;
  }

  // Field name: data
  {
    cdr << ros_message->data;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_statistics_msgs__msg__StatisticDataPoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StatisticDataPoint__ros_msg_type * ros_message = static_cast<const _StatisticDataPoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: data_type
  {
    size_t item_size = sizeof(ros_message->data_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data
  {
    size_t item_size = sizeof(ros_message->data);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_statistics_msgs__msg__StatisticDataPoint(
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
  // Field name: data_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: data
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
    using DataType = statistics_msgs__msg__StatisticDataPoint;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_statistics_msgs__msg__StatisticDataPoint(
  const statistics_msgs__msg__StatisticDataPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: data_type
  {
    cdr << ros_message->data_type;
  }

  // Field name: data
  {
    cdr << ros_message->data;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_statistics_msgs__msg__StatisticDataPoint(
  eprosima::fastcdr::Cdr & cdr,
  statistics_msgs__msg__StatisticDataPoint * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: data_type
  {
    cdr >> ros_message->data_type;
  }

  // Field name: data
  {
    cdr >> ros_message->data;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // STATISTICS_MSGS__MSG__DETAIL__STATISTIC_DATA_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
