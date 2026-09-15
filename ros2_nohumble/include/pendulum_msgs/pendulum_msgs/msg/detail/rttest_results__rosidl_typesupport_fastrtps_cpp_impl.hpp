// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "pendulum_msgs/msg/detail/rttest_results__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "pendulum_msgs/msg/detail/joint_command__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "pendulum_msgs/msg/detail/joint_state__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace pendulum_msgs
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
  const pendulum_msgs::msg::RttestResults & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.stamp,
    cdr);

  // Member: command
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.command,
    cdr);

  // Member: state
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.state,
    cdr);

  // Member: cur_latency
  cdr << ros_message.cur_latency;

  // Member: mean_latency
  cdr << ros_message.mean_latency;

  // Member: min_latency
  cdr << ros_message.min_latency;

  // Member: max_latency
  cdr << ros_message.max_latency;

  // Member: minor_pagefaults
  cdr << ros_message.minor_pagefaults;

  // Member: major_pagefaults
  cdr << ros_message.major_pagefaults;

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pendulum_msgs::msg::RttestResults & ros_message)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.stamp);

  // Member: command
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.command);

  // Member: state
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.state);

  // Member: cur_latency
  cdr >> ros_message.cur_latency;

  // Member: mean_latency
  cdr >> ros_message.mean_latency;

  // Member: min_latency
  cdr >> ros_message.min_latency;

  // Member: max_latency
  cdr >> ros_message.max_latency;

  // Member: minor_pagefaults
  cdr >> ros_message.minor_pagefaults;

  // Member: major_pagefaults
  cdr >> ros_message.major_pagefaults;

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const pendulum_msgs::msg::RttestResults & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: stamp
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.stamp,
      cdr, endpoint_info, serialization_context);
    // Member: command
    pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.command,
      cdr, endpoint_info, serialization_context);
    // Member: state
    pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.state,
      cdr, endpoint_info, serialization_context);
    // Member: cur_latency
    cdr << ros_message.cur_latency;
    // Member: mean_latency
    cdr << ros_message.mean_latency;
    // Member: min_latency
    cdr << ros_message.min_latency;
    // Member: max_latency
    cdr << ros_message.max_latency;
    // Member: minor_pagefaults
    cdr << ros_message.minor_pagefaults;
    // Member: major_pagefaults
    cdr << ros_message.major_pagefaults;
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "pendulum_msgs.typesupport_fastrtps_cpp",
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
  pendulum_msgs::msg::RttestResults & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.stamp,
    endpoint_info,
    serialization_context);

  // Member: command
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.command,
    endpoint_info,
    serialization_context);

  // Member: state
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.state,
    endpoint_info,
    serialization_context);

  // Member: cur_latency
  cdr >> ros_message.cur_latency;

  // Member: mean_latency
  cdr >> ros_message.mean_latency;

  // Member: min_latency
  cdr >> ros_message.min_latency;

  // Member: max_latency
  cdr >> ros_message.max_latency;

  // Member: minor_pagefaults
  cdr >> ros_message.minor_pagefaults;

  // Member: major_pagefaults
  cdr >> ros_message.major_pagefaults;

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const pendulum_msgs::msg::RttestResults & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: stamp
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.stamp, current_alignment);

  // Member: command
  current_alignment +=
    pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.command, current_alignment);

  // Member: state
  current_alignment +=
    pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.state, current_alignment);

  // Member: cur_latency
  {
    size_t item_size = sizeof(ros_message.cur_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mean_latency
  {
    size_t item_size = sizeof(ros_message.mean_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: min_latency
  {
    size_t item_size = sizeof(ros_message.min_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: max_latency
  {
    size_t item_size = sizeof(ros_message.max_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: minor_pagefaults
  {
    size_t item_size = sizeof(ros_message.minor_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: major_pagefaults
  {
    size_t item_size = sizeof(ros_message.major_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_RttestResults(
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

  // Member: stamp
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
  // Member: command
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_JointCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: cur_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mean_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: min_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: max_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: minor_pagefaults
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: major_pagefaults
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pendulum_msgs::msg::RttestResults;
    is_plain =
      (
      offsetof(DataType, major_pagefaults) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const pendulum_msgs::msg::RttestResults & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.stamp,
    cdr);

  // Member: command
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.command,
    cdr);

  // Member: state
  pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.state,
    cdr);

  // Member: cur_latency
  cdr << ros_message.cur_latency;

  // Member: mean_latency
  cdr << ros_message.mean_latency;

  // Member: min_latency
  cdr << ros_message.min_latency;

  // Member: max_latency
  cdr << ros_message.max_latency;

  // Member: minor_pagefaults
  cdr << ros_message.minor_pagefaults;

  // Member: major_pagefaults
  cdr << ros_message.major_pagefaults;

  return true;
}

inline
size_t
get_serialized_size_key(
  const pendulum_msgs::msg::RttestResults & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: stamp
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.stamp, current_alignment);

  // Member: command
  current_alignment +=
    pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.command, current_alignment);

  // Member: state
  current_alignment +=
    pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.state, current_alignment);

  // Member: cur_latency
  {
    size_t item_size = sizeof(ros_message.cur_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mean_latency
  {
    size_t item_size = sizeof(ros_message.mean_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: min_latency
  {
    size_t item_size = sizeof(ros_message.min_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: max_latency
  {
    size_t item_size = sizeof(ros_message.max_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: minor_pagefaults
  {
    size_t item_size = sizeof(ros_message.minor_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: major_pagefaults
  {
    size_t item_size = sizeof(ros_message.major_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_RttestResults(
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

  // Member: stamp
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

  // Member: command
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_JointCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        pendulum_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: cur_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mean_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: min_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: minor_pagefaults
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: major_pagefaults
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pendulum_msgs::msg::RttestResults;
    is_plain =
      (
      offsetof(DataType, major_pagefaults) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pendulum_msgs

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
