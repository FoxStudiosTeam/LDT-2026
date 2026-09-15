// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from stereo_msgs:msg\DisparityImage.idl
// generated code does not contain a copyright notice
#ifndef STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "stereo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "stereo_msgs/msg/detail/disparity_image__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
bool cdr_serialize_stereo_msgs__msg__DisparityImage(
  const stereo_msgs__msg__DisparityImage * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
bool cdr_deserialize_stereo_msgs__msg__DisparityImage(
  eprosima::fastcdr::Cdr &,
  stereo_msgs__msg__DisparityImage * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
size_t get_serialized_size_stereo_msgs__msg__DisparityImage(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
size_t max_serialized_size_stereo_msgs__msg__DisparityImage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
bool cdr_serialize_key_stereo_msgs__msg__DisparityImage(
  const stereo_msgs__msg__DisparityImage * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
size_t get_serialized_size_key_stereo_msgs__msg__DisparityImage(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
size_t max_serialized_size_key_stereo_msgs__msg__DisparityImage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
bool has_buffer_fields_stereo_msgs__msg__DisparityImage();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stereo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, stereo_msgs, msg, DisparityImage)();

#ifdef __cplusplus
}
#endif

#endif  // STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
