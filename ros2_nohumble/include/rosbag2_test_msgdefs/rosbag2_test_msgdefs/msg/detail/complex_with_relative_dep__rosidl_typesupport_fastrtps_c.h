// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from rosbag2_test_msgdefs:msg\ComplexWithRelativeDep.idl
// generated code does not contain a copyright notice
#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_with_relative_dep__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool cdr_serialize_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  const rosbag2_test_msgdefs__msg__ComplexWithRelativeDep * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool cdr_deserialize_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  eprosima::fastcdr::Cdr &,
  rosbag2_test_msgdefs__msg__ComplexWithRelativeDep * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t get_serialized_size_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t max_serialized_size_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool cdr_serialize_key_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  const rosbag2_test_msgdefs__msg__ComplexWithRelativeDep * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t get_serialized_size_key_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t max_serialized_size_key_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool has_buffer_fields_rosbag2_test_msgdefs__msg__ComplexWithRelativeDep();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosbag2_test_msgdefs, msg, ComplexWithRelativeDep)();

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
