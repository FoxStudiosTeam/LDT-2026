// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from shape_msgs:msg\SolidPrimitive.idl
// generated code does not contain a copyright notice
#ifndef SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "shape_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "shape_msgs/msg/detail/solid_primitive__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
bool cdr_serialize_shape_msgs__msg__SolidPrimitive(
  const shape_msgs__msg__SolidPrimitive * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
bool cdr_deserialize_shape_msgs__msg__SolidPrimitive(
  eprosima::fastcdr::Cdr &,
  shape_msgs__msg__SolidPrimitive * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
size_t get_serialized_size_shape_msgs__msg__SolidPrimitive(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
size_t max_serialized_size_shape_msgs__msg__SolidPrimitive(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
bool cdr_serialize_key_shape_msgs__msg__SolidPrimitive(
  const shape_msgs__msg__SolidPrimitive * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
size_t get_serialized_size_key_shape_msgs__msg__SolidPrimitive(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
size_t max_serialized_size_key_shape_msgs__msg__SolidPrimitive(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
bool has_buffer_fields_shape_msgs__msg__SolidPrimitive();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_shape_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shape_msgs, msg, SolidPrimitive)();

#ifdef __cplusplus
}
#endif

#endif  // SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
