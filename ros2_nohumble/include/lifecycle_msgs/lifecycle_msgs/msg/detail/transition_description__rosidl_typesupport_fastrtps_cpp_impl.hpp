// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from lifecycle_msgs:msg\TransitionDescription.idl
// generated code does not contain a copyright notice

#ifndef LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "lifecycle_msgs/msg/detail/transition_description__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "lifecycle_msgs/msg/detail/transition__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "lifecycle_msgs/msg/detail/state__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "lifecycle_msgs/msg/detail/state__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace lifecycle_msgs
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
  const lifecycle_msgs::msg::TransitionDescription & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: transition
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.transition,
    cdr);

  // Member: start_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.start_state,
    cdr);

  // Member: goal_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.goal_state,
    cdr);

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lifecycle_msgs::msg::TransitionDescription & ros_message)
{
  // Member: transition
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.transition);

  // Member: start_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.start_state);

  // Member: goal_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.goal_state);

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const lifecycle_msgs::msg::TransitionDescription & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: transition
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.transition,
      cdr, endpoint_info, serialization_context);
    // Member: start_state
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.start_state,
      cdr, endpoint_info, serialization_context);
    // Member: goal_state
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.goal_state,
      cdr, endpoint_info, serialization_context);
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "lifecycle_msgs.typesupport_fastrtps_cpp",
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
  lifecycle_msgs::msg::TransitionDescription & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: transition
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.transition,
    endpoint_info,
    serialization_context);

  // Member: start_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.start_state,
    endpoint_info,
    serialization_context);

  // Member: goal_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.goal_state,
    endpoint_info,
    serialization_context);

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const lifecycle_msgs::msg::TransitionDescription & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: transition
  current_alignment +=
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.transition, current_alignment);

  // Member: start_state
  current_alignment +=
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.start_state, current_alignment);

  // Member: goal_state
  current_alignment +=
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.goal_state, current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_TransitionDescription(
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

  // Member: transition
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Transition(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: start_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: goal_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_State(
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
    using DataType = lifecycle_msgs::msg::TransitionDescription;
    is_plain =
      (
      offsetof(DataType, goal_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const lifecycle_msgs::msg::TransitionDescription & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: transition
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.transition,
    cdr);

  // Member: start_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.start_state,
    cdr);

  // Member: goal_state
  lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.goal_state,
    cdr);

  return true;
}

inline
size_t
get_serialized_size_key(
  const lifecycle_msgs::msg::TransitionDescription & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: transition
  current_alignment +=
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.transition, current_alignment);

  // Member: start_state
  current_alignment +=
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.start_state, current_alignment);

  // Member: goal_state
  current_alignment +=
    lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.goal_state, current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_TransitionDescription(
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

  // Member: transition
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Transition(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: start_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: goal_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        lifecycle_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_State(
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
    using DataType = lifecycle_msgs::msg::TransitionDescription;
    is_plain =
      (
      offsetof(DataType, goal_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace lifecycle_msgs

#endif  // LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
