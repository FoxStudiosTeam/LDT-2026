// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice
#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pendulum_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pendulum_msgs/msg/detail/rttest_results__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
bool cdr_serialize_pendulum_msgs__msg__RttestResults(
  const pendulum_msgs__msg__RttestResults * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
bool cdr_deserialize_pendulum_msgs__msg__RttestResults(
  eprosima::fastcdr::Cdr &,
  pendulum_msgs__msg__RttestResults * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
size_t get_serialized_size_pendulum_msgs__msg__RttestResults(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
size_t max_serialized_size_pendulum_msgs__msg__RttestResults(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
bool cdr_serialize_key_pendulum_msgs__msg__RttestResults(
  const pendulum_msgs__msg__RttestResults * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
size_t get_serialized_size_key_pendulum_msgs__msg__RttestResults(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
size_t max_serialized_size_key_pendulum_msgs__msg__RttestResults(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
bool has_buffer_fields_pendulum_msgs__msg__RttestResults();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pendulum_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pendulum_msgs, msg, RttestResults)();

#ifdef __cplusplus
}
#endif

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
