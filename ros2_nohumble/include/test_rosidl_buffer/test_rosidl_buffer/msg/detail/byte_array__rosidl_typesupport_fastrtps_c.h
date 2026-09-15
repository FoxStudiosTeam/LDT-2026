// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from test_rosidl_buffer:msg\ByteArray.idl
// generated code does not contain a copyright notice
#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "test_rosidl_buffer/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "test_rosidl_buffer/msg/detail/byte_array__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
bool cdr_serialize_test_rosidl_buffer__msg__ByteArray(
  const test_rosidl_buffer__msg__ByteArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
bool cdr_deserialize_test_rosidl_buffer__msg__ByteArray(
  eprosima::fastcdr::Cdr &,
  test_rosidl_buffer__msg__ByteArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
size_t get_serialized_size_test_rosidl_buffer__msg__ByteArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
size_t max_serialized_size_test_rosidl_buffer__msg__ByteArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
bool cdr_serialize_key_test_rosidl_buffer__msg__ByteArray(
  const test_rosidl_buffer__msg__ByteArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
size_t get_serialized_size_key_test_rosidl_buffer__msg__ByteArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
size_t max_serialized_size_key_test_rosidl_buffer__msg__ByteArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
bool has_buffer_fields_test_rosidl_buffer__msg__ByteArray();

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, test_rosidl_buffer, msg, ByteArray)();

#ifdef __cplusplus
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
