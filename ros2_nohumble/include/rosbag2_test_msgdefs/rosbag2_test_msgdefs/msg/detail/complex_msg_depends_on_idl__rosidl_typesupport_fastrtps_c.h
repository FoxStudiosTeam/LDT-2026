// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from rosbag2_test_msgdefs:msg\ComplexMsgDependsOnIdl.idl
// generated code does not contain a copyright notice
#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rosbag2_test_msgdefs/msg/detail/complex_msg_depends_on_idl__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool cdr_serialize_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  const rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool cdr_deserialize_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  eprosima::fastcdr::Cdr &,
  rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t get_serialized_size_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t max_serialized_size_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool cdr_serialize_key_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  const rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t get_serialized_size_key_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
size_t max_serialized_size_key_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
bool has_buffer_fields_rosbag2_test_msgdefs__msg__ComplexMsgDependsOnIdl();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosbag2_test_msgdefs, msg, ComplexMsgDependsOnIdl)();

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
