// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from rosgraph_msgs:msg\Action.idl
// generated code does not contain a copyright notice

#ifndef ROSGRAPH_MSGS__MSG__DETAIL__ACTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__ACTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosgraph_msgs/msg/detail/action__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "rosgraph_msgs/msg/detail/topic__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "rosgraph_msgs/msg/detail/topic__rosidl_typesupport_fastrtps_cpp_impl.hpp"


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
  const rosgraph_msgs::msg::Action & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;

  // Member: send_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.send_goal,
    cdr);

  // Member: get_result
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.get_result,
    cdr);

  // Member: cancel_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.cancel_goal,
    cdr);

  // Member: feedback
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.feedback,
    cdr);

  // Member: status
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.status,
    cdr);

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs::msg::Action & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: send_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.send_goal);

  // Member: get_result
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.get_result);

  // Member: cancel_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.cancel_goal);

  // Member: feedback
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.feedback);

  // Member: status
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.status);

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const rosgraph_msgs::msg::Action & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: name
    cdr << ros_message.name;
    // Member: send_goal
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.send_goal,
      cdr, endpoint_info, serialization_context);
    // Member: get_result
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.get_result,
      cdr, endpoint_info, serialization_context);
    // Member: cancel_goal
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.cancel_goal,
      cdr, endpoint_info, serialization_context);
    // Member: feedback
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.feedback,
      cdr, endpoint_info, serialization_context);
    // Member: status
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.status,
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
  rosgraph_msgs::msg::Action & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: name
  cdr >> ros_message.name;

  // Member: send_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.send_goal,
    endpoint_info,
    serialization_context);

  // Member: get_result
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.get_result,
    endpoint_info,
    serialization_context);

  // Member: cancel_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.cancel_goal,
    endpoint_info,
    serialization_context);

  // Member: feedback
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.feedback,
    endpoint_info,
    serialization_context);

  // Member: status
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.status,
    endpoint_info,
    serialization_context);

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const rosgraph_msgs::msg::Action & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);

  // Member: send_goal
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.send_goal, current_alignment);

  // Member: get_result
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.get_result, current_alignment);

  // Member: cancel_goal
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.cancel_goal, current_alignment);

  // Member: feedback
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.feedback, current_alignment);

  // Member: status
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.status, current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_Action(
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

  // Member: name
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
  // Member: send_goal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: get_result
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: cancel_goal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: feedback
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: status
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Topic(
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
    using DataType = rosgraph_msgs::msg::Action;
    is_plain =
      (
      offsetof(DataType, status) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const rosgraph_msgs::msg::Action & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;

  // Member: send_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.send_goal,
    cdr);

  // Member: get_result
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.get_result,
    cdr);

  // Member: cancel_goal
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.cancel_goal,
    cdr);

  // Member: feedback
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.feedback,
    cdr);

  // Member: status
  rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.status,
    cdr);

  return true;
}

inline
size_t
get_serialized_size_key(
  const rosgraph_msgs::msg::Action & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);

  // Member: send_goal
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.send_goal, current_alignment);

  // Member: get_result
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.get_result, current_alignment);

  // Member: cancel_goal
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.cancel_goal, current_alignment);

  // Member: feedback
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.feedback, current_alignment);

  // Member: status
  current_alignment +=
    rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.status, current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_Action(
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

  // Member: name
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

  // Member: send_goal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: get_result
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: cancel_goal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: feedback
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: status
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Topic(
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
    using DataType = rosgraph_msgs::msg::Action;
    is_plain =
      (
      offsetof(DataType, status) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__ACTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
