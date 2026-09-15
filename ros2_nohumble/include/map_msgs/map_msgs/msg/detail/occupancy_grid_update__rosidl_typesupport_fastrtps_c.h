// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from map_msgs:msg\OccupancyGridUpdate.idl
// generated code does not contain a copyright notice
#ifndef MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "map_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "map_msgs/msg/detail/occupancy_grid_update__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
bool cdr_serialize_map_msgs__msg__OccupancyGridUpdate(
  const map_msgs__msg__OccupancyGridUpdate * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
bool cdr_deserialize_map_msgs__msg__OccupancyGridUpdate(
  eprosima::fastcdr::Cdr &,
  map_msgs__msg__OccupancyGridUpdate * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
size_t get_serialized_size_map_msgs__msg__OccupancyGridUpdate(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
size_t max_serialized_size_map_msgs__msg__OccupancyGridUpdate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
bool cdr_serialize_key_map_msgs__msg__OccupancyGridUpdate(
  const map_msgs__msg__OccupancyGridUpdate * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
size_t get_serialized_size_key_map_msgs__msg__OccupancyGridUpdate(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
size_t max_serialized_size_key_map_msgs__msg__OccupancyGridUpdate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
bool has_buffer_fields_map_msgs__msg__OccupancyGridUpdate();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, map_msgs, msg, OccupancyGridUpdate)();

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
