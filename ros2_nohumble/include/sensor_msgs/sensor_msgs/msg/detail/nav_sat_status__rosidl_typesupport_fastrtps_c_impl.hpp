// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from sensor_msgs:msg\NavSatStatus.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_MSGS__MSG__DETAIL__NAV_SAT_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define SENSOR_MSGS__MSG__DETAIL__NAV_SAT_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "sensor_msgs/msg/detail/nav_sat_status__struct.h"
#include "sensor_msgs/msg/detail/nav_sat_status__functions.h"
#include "sensor_msgs/msg/detail/nav_sat_status__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"


// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _NavSatStatus__ros_msg_type = sensor_msgs__msg__NavSatStatus;


inline
bool impl_cdr_serialize_sensor_msgs__msg__NavSatStatus(
  const sensor_msgs__msg__NavSatStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: service
  {
    cdr << ros_message->service;
  }

  return true;
}

inline
bool impl_cdr_deserialize_sensor_msgs__msg__NavSatStatus(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__NavSatStatus * ros_message)
{
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: service
  {
    cdr >> ros_message->service;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_sensor_msgs__msg__NavSatStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavSatStatus__ros_msg_type * ros_message = static_cast<const _NavSatStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: service
  {
    size_t item_size = sizeof(ros_message->service);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_sensor_msgs__msg__NavSatStatus(
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

  // Field name: status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: service
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = sensor_msgs__msg__NavSatStatus;
    is_plain =
      (
      offsetof(DataType, service) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_sensor_msgs__msg__NavSatStatus(
  const sensor_msgs__msg__NavSatStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: service
  {
    cdr << ros_message->service;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_sensor_msgs__msg__NavSatStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavSatStatus__ros_msg_type * ros_message = static_cast<const _NavSatStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: service
  {
    size_t item_size = sizeof(ros_message->service);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_sensor_msgs__msg__NavSatStatus(
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
  // Field name: status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: service
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = sensor_msgs__msg__NavSatStatus;
    is_plain =
      (
      offsetof(DataType, service) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_sensor_msgs__msg__NavSatStatus(
  const sensor_msgs__msg__NavSatStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: service
  {
    cdr << ros_message->service;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_sensor_msgs__msg__NavSatStatus(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__NavSatStatus * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: service
  {
    cdr >> ros_message->service;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // SENSOR_MSGS__MSG__DETAIL__NAV_SAT_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
