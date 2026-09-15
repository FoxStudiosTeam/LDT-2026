// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_msgs:msg\WStrings.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__W_STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__W_STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_msgs/msg/detail/w_strings__struct.h"
#include "test_msgs/msg/detail/w_strings__functions.h"
#include "test_msgs/msg/detail/w_strings__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/u16string.h"  // array_of_wstrings, bounded_sequence_of_wstrings, unbounded_sequence_of_wstrings, wstring_value, wstring_value_default1, wstring_value_default2, wstring_value_default3
#include "rosidl_runtime_c/u16string_functions.h"  // array_of_wstrings, bounded_sequence_of_wstrings, unbounded_sequence_of_wstrings, wstring_value, wstring_value_default1, wstring_value_default2, wstring_value_default3

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _WStrings__ros_msg_type = test_msgs__msg__WStrings;


inline
bool impl_cdr_serialize_test_msgs__msg__WStrings(
  const test_msgs__msg__WStrings * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: wstring_value
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value);
  }

  // Field name: wstring_value_default1
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default1);
  }

  // Field name: wstring_value_default2
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default2);
  }

  // Field name: wstring_value_default3
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default3);
  }

  // Field name: array_of_wstrings
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t size = ros_message->bounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t size = ros_message->unbounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_msgs__msg__WStrings(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__WStrings * ros_message)
{
  // Field name: wstring_value
  {
    if (!ros_message->wstring_value.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value);
      return false;
    }
  }

  // Field name: wstring_value_default1
  {
    if (!ros_message->wstring_value_default1.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value_default1);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value_default1);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value_default1);
      return false;
    }
  }

  // Field name: wstring_value_default2
  {
    if (!ros_message->wstring_value_default2.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value_default2);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value_default2);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value_default2);
      return false;
    }
  }

  // Field name: wstring_value_default3
  {
    if (!ros_message->wstring_value_default3.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value_default3);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value_default3);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value_default3);
      return false;
    }
  }

  // Field name: array_of_wstrings
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    std::wstring wstr;
    for (size_t i = 0; i < size; ++i) {
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__U16String__init(&ros_i);
      }
      bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_i);
      if (!succeeded) {
        fprintf(stderr, "failed to create wstring from u16string\n");
        rosidl_runtime_c__U16String__fini(&ros_i);
        return false;
      }
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->bounded_sequence_of_wstrings.data) {
      rosidl_runtime_c__U16String__Sequence__fini(&ros_message->bounded_sequence_of_wstrings);
    }
    if (!rosidl_runtime_c__U16String__Sequence__init(&ros_message->bounded_sequence_of_wstrings, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_wstrings'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    std::wstring wstr;
    for (size_t i = 0; i < size; ++i) {
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__U16String__init(&ros_i);
      }
      bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_i);
      if (!succeeded) {
        fprintf(stderr, "failed to create wstring from u16string\n");
        rosidl_runtime_c__U16String__fini(&ros_i);
        return false;
      }
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->unbounded_sequence_of_wstrings.data) {
      rosidl_runtime_c__U16String__Sequence__fini(&ros_message->unbounded_sequence_of_wstrings);
    }
    if (!rosidl_runtime_c__U16String__Sequence__init(&ros_message->unbounded_sequence_of_wstrings, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_wstrings'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    std::wstring wstr;
    for (size_t i = 0; i < size; ++i) {
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__U16String__init(&ros_i);
      }
      bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_i);
      if (!succeeded) {
        fprintf(stderr, "failed to create wstring from u16string\n");
        rosidl_runtime_c__U16String__fini(&ros_i);
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__msg__WStrings(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WStrings__ros_msg_type * ros_message = static_cast<const _WStrings__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: wstring_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value.size + 1);

  // Field name: wstring_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value_default1.size + 1);

  // Field name: wstring_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value_default2.size + 1);

  // Field name: wstring_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value_default3.size + 1);

  // Field name: array_of_wstrings
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (array_ptr[index].size + 1);
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t array_size = ros_message->bounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (array_ptr[index].size + 1);
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t array_size = ros_message->unbounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__msg__WStrings(
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

  // Field name: wstring_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: wstring_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: wstring_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: wstring_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: array_of_wstrings
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs__msg__WStrings;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_wstrings) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__msg__WStrings(
  const test_msgs__msg__WStrings * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: wstring_value
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value);
  }

  // Field name: wstring_value_default1
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default1);
  }

  // Field name: wstring_value_default2
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default2);
  }

  // Field name: wstring_value_default3
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default3);
  }

  // Field name: array_of_wstrings
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t size = ros_message->bounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t size = ros_message->unbounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_msgs__msg__WStrings(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WStrings__ros_msg_type * ros_message = static_cast<const _WStrings__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: wstring_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value.size + 1);

  // Field name: wstring_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value_default1.size + 1);

  // Field name: wstring_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value_default2.size + 1);

  // Field name: wstring_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    wchar_size *
    (ros_message->wstring_value_default3.size + 1);

  // Field name: array_of_wstrings
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (array_ptr[index].size + 1);
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t array_size = ros_message->bounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (array_ptr[index].size + 1);
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t array_size = ros_message->unbounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__msg__WStrings(
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
  // Field name: wstring_value
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: wstring_value_default1
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: wstring_value_default2
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: wstring_value_default3
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: array_of_wstrings
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        wchar_size *
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_msgs__msg__WStrings;
    is_plain =
      (
      offsetof(DataType, unbounded_sequence_of_wstrings) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__msg__WStrings(
  const test_msgs__msg__WStrings * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: wstring_value
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value);
  }

  // Field name: wstring_value_default1
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default1);
  }

  // Field name: wstring_value_default2
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default2);
  }

  // Field name: wstring_value_default3
  {
    rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, ros_message->wstring_value_default3);
  }

  // Field name: array_of_wstrings
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    size_t size = ros_message->bounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    size_t size = ros_message->unbounded_sequence_of_wstrings.size;
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__U16String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      rosidl_typesupport_fastrtps_c::cdr_serialize(cdr, *str);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_msgs__msg__WStrings(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__msg__WStrings * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: wstring_value
  {
    if (!ros_message->wstring_value.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value);
      return false;
    }
  }

  // Field name: wstring_value_default1
  {
    if (!ros_message->wstring_value_default1.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value_default1);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value_default1);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value_default1);
      return false;
    }
  }

  // Field name: wstring_value_default2
  {
    if (!ros_message->wstring_value_default2.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value_default2);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value_default2);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value_default2);
      return false;
    }
  }

  // Field name: wstring_value_default3
  {
    if (!ros_message->wstring_value_default3.data) {
      rosidl_runtime_c__U16String__init(&ros_message->wstring_value_default3);
    }
    bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_message->wstring_value_default3);
    if (!succeeded) {
      fprintf(stderr, "failed to create wstring from u16string\n");
      rosidl_runtime_c__U16String__fini(&ros_message->wstring_value_default3);
      return false;
    }
  }

  // Field name: array_of_wstrings
  {
    size_t size = 3;
    auto array_ptr = ros_message->array_of_wstrings;
    std::wstring wstr;
    for (size_t i = 0; i < size; ++i) {
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__U16String__init(&ros_i);
      }
      bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_i);
      if (!succeeded) {
        fprintf(stderr, "failed to create wstring from u16string\n");
        rosidl_runtime_c__U16String__fini(&ros_i);
        return false;
      }
    }
  }

  // Field name: bounded_sequence_of_wstrings
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->bounded_sequence_of_wstrings.data) {
      rosidl_runtime_c__U16String__Sequence__fini(&ros_message->bounded_sequence_of_wstrings);
    }
    if (!rosidl_runtime_c__U16String__Sequence__init(&ros_message->bounded_sequence_of_wstrings, size)) {
      fprintf(stderr, "failed to create array for field 'bounded_sequence_of_wstrings'");
      return false;
    }
    auto array_ptr = ros_message->bounded_sequence_of_wstrings.data;
    std::wstring wstr;
    for (size_t i = 0; i < size; ++i) {
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__U16String__init(&ros_i);
      }
      bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_i);
      if (!succeeded) {
        fprintf(stderr, "failed to create wstring from u16string\n");
        rosidl_runtime_c__U16String__fini(&ros_i);
        return false;
      }
    }
  }

  // Field name: unbounded_sequence_of_wstrings
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->unbounded_sequence_of_wstrings.data) {
      rosidl_runtime_c__U16String__Sequence__fini(&ros_message->unbounded_sequence_of_wstrings);
    }
    if (!rosidl_runtime_c__U16String__Sequence__init(&ros_message->unbounded_sequence_of_wstrings, size)) {
      fprintf(stderr, "failed to create array for field 'unbounded_sequence_of_wstrings'");
      return false;
    }
    auto array_ptr = ros_message->unbounded_sequence_of_wstrings.data;
    std::wstring wstr;
    for (size_t i = 0; i < size; ++i) {
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__U16String__init(&ros_i);
      }
      bool succeeded = rosidl_typesupport_fastrtps_c::cdr_deserialize(cdr, ros_i);
      if (!succeeded) {
        fprintf(stderr, "failed to create wstring from u16string\n");
        rosidl_runtime_c__U16String__fini(&ros_i);
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__W_STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
