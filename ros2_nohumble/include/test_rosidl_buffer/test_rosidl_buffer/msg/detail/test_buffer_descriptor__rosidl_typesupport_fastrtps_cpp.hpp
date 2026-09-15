// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from test_rosidl_buffer:msg\TestBufferDescriptor.idl
// generated code does not contain a copyright notice

#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "test_rosidl_buffer/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace test_rosidl_buffer
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
cdr_serialize(
  const test_rosidl_buffer::msg::TestBufferDescriptor & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  test_rosidl_buffer::msg::TestBufferDescriptor & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
get_serialized_size(
  const test_rosidl_buffer::msg::TestBufferDescriptor & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
max_serialized_size_TestBufferDescriptor(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
cdr_serialize_key(
  const test_rosidl_buffer::msg::TestBufferDescriptor & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
get_serialized_size_key(
  const test_rosidl_buffer::msg::TestBufferDescriptor & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
max_serialized_size_key_TestBufferDescriptor(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
has_buffer_fields_TestBufferDescriptor();

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace test_rosidl_buffer

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_test_rosidl_buffer
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, test_rosidl_buffer, msg, TestBufferDescriptor)();

#ifdef __cplusplus
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
