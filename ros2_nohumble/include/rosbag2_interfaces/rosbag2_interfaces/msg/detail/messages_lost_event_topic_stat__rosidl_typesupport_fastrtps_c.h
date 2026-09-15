// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice
#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
bool cdr_serialize_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
bool cdr_deserialize_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  eprosima::fastcdr::Cdr &,
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
size_t get_serialized_size_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
size_t max_serialized_size_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
bool cdr_serialize_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
size_t get_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
size_t max_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
bool has_buffer_fields_rosbag2_interfaces__msg__MessagesLostEventTopicStat();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosbag2_interfaces, msg, MessagesLostEventTopicStat)();

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
