// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from rosgraph_msgs:msg\Clock.idl
// generated code does not contain a copyright notice

#ifndef ROSGRAPH_MSGS__MSG__DETAIL__CLOCK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__CLOCK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosgraph_msgs/msg/detail/clock__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace rosgraph_msgs
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
  const rosgraph_msgs::msg::Clock & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: clock
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.clock,
    cdr);

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs::msg::Clock & ros_message)
{
  // Member: clock
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.clock);

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const rosgraph_msgs::msg::Clock & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: clock
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.clock,
      cdr, endpoint_info, serialization_context);
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "rosgraph_msgs.typesupport_fastrtps_cpp",
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
  rosgraph_msgs::msg::Clock & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: clock
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.clock,
    endpoint_info,
    serialization_context);

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const rosgraph_msgs::msg::Clock & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: clock
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.clock, current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_Clock(
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

  // Member: clock
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosgraph_msgs::msg::Clock;
    is_plain =
      (
      offsetof(DataType, clock) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const rosgraph_msgs::msg::Clock & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: clock
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.clock,
    cdr);

  return true;
}

inline
size_t
get_serialized_size_key(
  const rosgraph_msgs::msg::Clock & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: clock
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.clock, current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_Clock(
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

  // Member: clock
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosgraph_msgs::msg::Clock;
    is_plain =
      (
      offsetof(DataType, clock) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__CLOCK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
