// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice
#ifndef ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_performance_benchmarking_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
bool cdr_serialize_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  const rosbag2_performance_benchmarking_msgs__msg__ByteArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
bool cdr_deserialize_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  eprosima::fastcdr::Cdr &,
  rosbag2_performance_benchmarking_msgs__msg__ByteArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
size_t get_serialized_size_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
size_t max_serialized_size_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
bool cdr_serialize_key_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  const rosbag2_performance_benchmarking_msgs__msg__ByteArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
size_t get_serialized_size_key_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
size_t max_serialized_size_key_rosbag2_performance_benchmarking_msgs__msg__ByteArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
bool has_buffer_fields_rosbag2_performance_benchmarking_msgs__msg__ByteArray();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_performance_benchmarking_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosbag2_performance_benchmarking_msgs, msg, ByteArray)();

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
