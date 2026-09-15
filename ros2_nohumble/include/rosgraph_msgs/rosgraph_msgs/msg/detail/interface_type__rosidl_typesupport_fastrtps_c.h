// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from rosgraph_msgs:msg\InterfaceType.idl
// generated code does not contain a copyright notice
#ifndef ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rosgraph_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rosgraph_msgs/msg/detail/interface_type__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
bool cdr_serialize_rosgraph_msgs__msg__InterfaceType(
  const rosgraph_msgs__msg__InterfaceType * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
bool cdr_deserialize_rosgraph_msgs__msg__InterfaceType(
  eprosima::fastcdr::Cdr &,
  rosgraph_msgs__msg__InterfaceType * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
size_t get_serialized_size_rosgraph_msgs__msg__InterfaceType(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
size_t max_serialized_size_rosgraph_msgs__msg__InterfaceType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
bool cdr_serialize_key_rosgraph_msgs__msg__InterfaceType(
  const rosgraph_msgs__msg__InterfaceType * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
size_t get_serialized_size_key_rosgraph_msgs__msg__InterfaceType(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
size_t max_serialized_size_key_rosgraph_msgs__msg__InterfaceType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
bool has_buffer_fields_rosgraph_msgs__msg__InterfaceType();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosgraph_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosgraph_msgs, msg, InterfaceType)();

#ifdef __cplusplus
}
#endif

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
