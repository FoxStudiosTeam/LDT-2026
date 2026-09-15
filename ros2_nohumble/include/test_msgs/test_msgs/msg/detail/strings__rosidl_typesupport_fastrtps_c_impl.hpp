// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_msgs:msg\Strings.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_msgs/msg/detail/strings__struct.h"
#include "test_msgs/msg/detail/strings__functions.h"
#include "test_msgs/msg/detail/strings__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/string.h"  // bounded_string_value, bounded_string_value_default1, bounded_string_value_default2, bounded_string_value_default3, bounded_string_value_default4, bounded_string_value_default5, string_value, string_value_default1, string_value_default2, string_value_default3, string_value_default4, string_value_default5
#include "rosidl_runtime_c/string_functions.h"  // bounded_string_value, bounded_string_value_default1, bounded_string_value_default2, bounded_string_value_default3, bounded_string_value_default4, bounded_string_value_default5, string_value, string_value_default1, string_value_default2, string_value_default3, string_value_default4, string_value_default5

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _Strings__ros_msg_type = test_msgs__msg__Strings;


inline
bool impl_cdr_serialize_test_msgs__msg__Strings(
  const test_msgs__msg__Strings * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: string_value
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default1
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default2
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default3
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default4
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default5
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default5;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default1
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default2
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default3
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default4
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default5
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default5;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_msgs__msg__Strings(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__Strings * ros_message)
{
  // Field name: string_value
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value'\n");
      return false;
    }
  }

  // Field name: string_value_default1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default1.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default1'\n");
      return false;
    }
  }

  // Field name: string_value_default2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default2.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default2'\n");
      return false;
    }
  }

  // Field name: string_value_default3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default3.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default3'\n");
      return false;
    }
  }

  // Field name: string_value_default4
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default4.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default4);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default4,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default4'\n");
      return false;
    }
  }

  // Field name: string_value_default5
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default5.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default5);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default5,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default5'\n");
      return false;
    }
  }

  // Field name: bounded_string_value
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default1.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default1'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default2.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default2'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default3.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default3'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default4
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default4.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default4);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default4,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default4'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default5
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default5.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default5);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default5,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default5'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__msg__Strings(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Strings__ros_msg_type * ros_message = static_cast<const _Strings__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value.size + 1);

  // Field name: string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default1.size + 1);

  // Field name: string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default2.size + 1);

  // Field name: string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default3.size + 1);

  // Field name: string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default4.size + 1);

  // Field name: string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default5.size + 1);

  // Field name: bounded_string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value.size + 1);

  // Field name: bounded_string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default1.size + 1);

  // Field name: bounded_string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default2.size + 1);

  // Field name: bounded_string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default3.size + 1);

  // Field name: bounded_string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default4.size + 1);

  // Field name: bounded_string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default5.size + 1);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__msg__Strings(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: string_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default5
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: bounded_string_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default5
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs__msg__Strings;
    is_plain =
      (
      offsetof(DataType, bounded_string_value_default5) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__msg__Strings(
  const test_msgs__msg__Strings * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: string_value
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default1
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default2
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default3
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default4
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default5
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default5;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default1
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default2
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default3
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default4
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default5
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default5;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_msgs__msg__Strings(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Strings__ros_msg_type * ros_message = static_cast<const _Strings__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value.size + 1);

  // Field name: string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default1.size + 1);

  // Field name: string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default2.size + 1);

  // Field name: string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default3.size + 1);

  // Field name: string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default4.size + 1);

  // Field name: string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string_value_default5.size + 1);

  // Field name: bounded_string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value.size + 1);

  // Field name: bounded_string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default1.size + 1);

  // Field name: bounded_string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default2.size + 1);

  // Field name: bounded_string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default3.size + 1);

  // Field name: bounded_string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default4.size + 1);

  // Field name: bounded_string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->bounded_string_value_default5.size + 1);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__msg__Strings(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: string_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: string_value_default5
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: bounded_string_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default4
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  // Field name: bounded_string_value_default5
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        22 +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs__msg__Strings;
    is_plain =
      (
      offsetof(DataType, bounded_string_value_default5) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__msg__Strings(
  const test_msgs__msg__Strings * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: string_value
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default1
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default2
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default3
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default4
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: string_value_default5
  {
    const rosidl_runtime_c__String * str = &ros_message->string_value_default5;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default1
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default1;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default2
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default2;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default3
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default3;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default4
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default4;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: bounded_string_value_default5
  {
    const rosidl_runtime_c__String * str = &ros_message->bounded_string_value_default5;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_msgs__msg__Strings(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__Strings * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: string_value
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value'\n");
      return false;
    }
  }

  // Field name: string_value_default1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default1.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default1'\n");
      return false;
    }
  }

  // Field name: string_value_default2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default2.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default2'\n");
      return false;
    }
  }

  // Field name: string_value_default3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default3.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default3'\n");
      return false;
    }
  }

  // Field name: string_value_default4
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default4.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default4);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default4,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default4'\n");
      return false;
    }
  }

  // Field name: string_value_default5
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string_value_default5.data) {
      rosidl_runtime_c__String__init(&ros_message->string_value_default5);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string_value_default5,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string_value_default5'\n");
      return false;
    }
  }

  // Field name: bounded_string_value
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default1
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default1.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default1);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default1,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default1'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default2
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default2.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default2);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default2,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default2'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default3
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default3.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default3);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default3,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default3'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default4
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default4.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default4);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default4,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default4'\n");
      return false;
    }
  }

  // Field name: bounded_string_value_default5
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->bounded_string_value_default5.data) {
      rosidl_runtime_c__String__init(&ros_message->bounded_string_value_default5);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->bounded_string_value_default5,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'bounded_string_value_default5'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
