// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from test_msgs:msg\Strings.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define TEST_MSGS__MSG__DETAIL__STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "test_msgs/msg/detail/strings__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.


namespace test_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

// Inline implementations of the (de)serialization family of functions.
// Kept separate from the public, exported wrappers (see the generated
// `..._type_support.cpp`) so that nested-message call sites elsewhere can
// `#include` this header and let the compiler fully inline the recursive
// (de)serialization logic instead of making an opaque cross-library call.
namespace detail
{


inline
bool
cdr_serialize(
  const test_msgs::msg::Strings & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: string_value
  cdr << ros_message.string_value;

  // Member: string_value_default1
  cdr << ros_message.string_value_default1;

  // Member: string_value_default2
  cdr << ros_message.string_value_default2;

  // Member: string_value_default3
  cdr << ros_message.string_value_default3;

  // Member: string_value_default4
  cdr << ros_message.string_value_default4;

  // Member: string_value_default5
  cdr << ros_message.string_value_default5;

  // Member: bounded_string_value
  cdr << ros_message.bounded_string_value;

  // Member: bounded_string_value_default1
  cdr << ros_message.bounded_string_value_default1;

  // Member: bounded_string_value_default2
  cdr << ros_message.bounded_string_value_default2;

  // Member: bounded_string_value_default3
  cdr << ros_message.bounded_string_value_default3;

  // Member: bounded_string_value_default4
  cdr << ros_message.bounded_string_value_default4;

  // Member: bounded_string_value_default5
  cdr << ros_message.bounded_string_value_default5;

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs::msg::Strings & ros_message)
{
  // Member: string_value
  cdr >> ros_message.string_value;

  // Member: string_value_default1
  cdr >> ros_message.string_value_default1;

  // Member: string_value_default2
  cdr >> ros_message.string_value_default2;

  // Member: string_value_default3
  cdr >> ros_message.string_value_default3;

  // Member: string_value_default4
  cdr >> ros_message.string_value_default4;

  // Member: string_value_default5
  cdr >> ros_message.string_value_default5;

  // Member: bounded_string_value
  cdr >> ros_message.bounded_string_value;

  // Member: bounded_string_value_default1
  cdr >> ros_message.bounded_string_value_default1;

  // Member: bounded_string_value_default2
  cdr >> ros_message.bounded_string_value_default2;

  // Member: bounded_string_value_default3
  cdr >> ros_message.bounded_string_value_default3;

  // Member: bounded_string_value_default4
  cdr >> ros_message.bounded_string_value_default4;

  // Member: bounded_string_value_default5
  cdr >> ros_message.bounded_string_value_default5;

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const test_msgs::msg::Strings & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: string_value
    cdr << ros_message.string_value;
    // Member: string_value_default1
    cdr << ros_message.string_value_default1;
    // Member: string_value_default2
    cdr << ros_message.string_value_default2;
    // Member: string_value_default3
    cdr << ros_message.string_value_default3;
    // Member: string_value_default4
    cdr << ros_message.string_value_default4;
    // Member: string_value_default5
    cdr << ros_message.string_value_default5;
    // Member: bounded_string_value
    cdr << ros_message.bounded_string_value;
    // Member: bounded_string_value_default1
    cdr << ros_message.bounded_string_value_default1;
    // Member: bounded_string_value_default2
    cdr << ros_message.bounded_string_value_default2;
    // Member: bounded_string_value_default3
    cdr << ros_message.bounded_string_value_default3;
    // Member: bounded_string_value_default4
    cdr << ros_message.bounded_string_value_default4;
    // Member: bounded_string_value_default5
    cdr << ros_message.bounded_string_value_default5;
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "test_msgs.typesupport_fastrtps_cpp",
      "cdr_serialize_with_endpoint failed: %s", e.what());
    return false;
  }
  return true;
}

// Endpoint-aware deserialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_deserialize_with_endpoint(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs::msg::Strings & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: string_value
  cdr >> ros_message.string_value;

  // Member: string_value_default1
  cdr >> ros_message.string_value_default1;

  // Member: string_value_default2
  cdr >> ros_message.string_value_default2;

  // Member: string_value_default3
  cdr >> ros_message.string_value_default3;

  // Member: string_value_default4
  cdr >> ros_message.string_value_default4;

  // Member: string_value_default5
  cdr >> ros_message.string_value_default5;

  // Member: bounded_string_value
  cdr >> ros_message.bounded_string_value;

  // Member: bounded_string_value_default1
  cdr >> ros_message.bounded_string_value_default1;

  // Member: bounded_string_value_default2
  cdr >> ros_message.bounded_string_value_default2;

  // Member: bounded_string_value_default3
  cdr >> ros_message.bounded_string_value_default3;

  // Member: bounded_string_value_default4
  cdr >> ros_message.bounded_string_value_default4;

  // Member: bounded_string_value_default5
  cdr >> ros_message.bounded_string_value_default5;

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const test_msgs::msg::Strings & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value.size() + 1);

  // Member: string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default1.size() + 1);

  // Member: string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default2.size() + 1);

  // Member: string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default3.size() + 1);

  // Member: string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default4.size() + 1);

  // Member: string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default5.size() + 1);

  // Member: bounded_string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value.size() + 1);

  // Member: bounded_string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default1.size() + 1);

  // Member: bounded_string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default2.size() + 1);

  // Member: bounded_string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default3.size() + 1);

  // Member: bounded_string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default4.size() + 1);

  // Member: bounded_string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default5.size() + 1);

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_Strings(
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

  // Member: string_value
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
  // Member: string_value_default1
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
  // Member: string_value_default2
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
  // Member: string_value_default3
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
  // Member: string_value_default4
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
  // Member: string_value_default5
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
  // Member: bounded_string_value
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
  // Member: bounded_string_value_default1
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
  // Member: bounded_string_value_default2
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
  // Member: bounded_string_value_default3
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
  // Member: bounded_string_value_default4
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
  // Member: bounded_string_value_default5
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
    using DataType = test_msgs::msg::Strings;
    is_plain =
      (
      offsetof(DataType, bounded_string_value_default5) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const test_msgs::msg::Strings & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: string_value
  cdr << ros_message.string_value;

  // Member: string_value_default1
  cdr << ros_message.string_value_default1;

  // Member: string_value_default2
  cdr << ros_message.string_value_default2;

  // Member: string_value_default3
  cdr << ros_message.string_value_default3;

  // Member: string_value_default4
  cdr << ros_message.string_value_default4;

  // Member: string_value_default5
  cdr << ros_message.string_value_default5;

  // Member: bounded_string_value
  cdr << ros_message.bounded_string_value;

  // Member: bounded_string_value_default1
  cdr << ros_message.bounded_string_value_default1;

  // Member: bounded_string_value_default2
  cdr << ros_message.bounded_string_value_default2;

  // Member: bounded_string_value_default3
  cdr << ros_message.bounded_string_value_default3;

  // Member: bounded_string_value_default4
  cdr << ros_message.bounded_string_value_default4;

  // Member: bounded_string_value_default5
  cdr << ros_message.bounded_string_value_default5;

  return true;
}

inline
size_t
get_serialized_size_key(
  const test_msgs::msg::Strings & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value.size() + 1);

  // Member: string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default1.size() + 1);

  // Member: string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default2.size() + 1);

  // Member: string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default3.size() + 1);

  // Member: string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default4.size() + 1);

  // Member: string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.string_value_default5.size() + 1);

  // Member: bounded_string_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value.size() + 1);

  // Member: bounded_string_value_default1
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default1.size() + 1);

  // Member: bounded_string_value_default2
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default2.size() + 1);

  // Member: bounded_string_value_default3
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default3.size() + 1);

  // Member: bounded_string_value_default4
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default4.size() + 1);

  // Member: bounded_string_value_default5
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.bounded_string_value_default5.size() + 1);

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_Strings(
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

  // Member: string_value
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

  // Member: string_value_default1
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

  // Member: string_value_default2
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

  // Member: string_value_default3
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

  // Member: string_value_default4
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

  // Member: string_value_default5
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

  // Member: bounded_string_value
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

  // Member: bounded_string_value_default1
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

  // Member: bounded_string_value_default2
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

  // Member: bounded_string_value_default3
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

  // Member: bounded_string_value_default4
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

  // Member: bounded_string_value_default5
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
    using DataType = test_msgs::msg::Strings;
    is_plain =
      (
      offsetof(DataType, bounded_string_value_default5) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__STRINGS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
