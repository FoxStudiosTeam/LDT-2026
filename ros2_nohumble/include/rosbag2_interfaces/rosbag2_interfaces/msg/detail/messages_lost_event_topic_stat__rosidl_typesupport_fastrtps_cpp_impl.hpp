// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.


namespace rosbag2_interfaces
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
  const rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: topic_name
  cdr << ros_message.topic_name;

  // Member: messages_lost_in_transport
  cdr << ros_message.messages_lost_in_transport;

  // Member: messages_lost_in_recorder
  cdr << ros_message.messages_lost_in_recorder;

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message)
{
  // Member: topic_name
  cdr >> ros_message.topic_name;

  // Member: messages_lost_in_transport
  cdr >> ros_message.messages_lost_in_transport;

  // Member: messages_lost_in_recorder
  cdr >> ros_message.messages_lost_in_recorder;

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: topic_name
    cdr << ros_message.topic_name;
    // Member: messages_lost_in_transport
    cdr << ros_message.messages_lost_in_transport;
    // Member: messages_lost_in_recorder
    cdr << ros_message.messages_lost_in_recorder;
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "rosbag2_interfaces.typesupport_fastrtps_cpp",
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
  rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: topic_name
  cdr >> ros_message.topic_name;

  // Member: messages_lost_in_transport
  cdr >> ros_message.messages_lost_in_transport;

  // Member: messages_lost_in_recorder
  cdr >> ros_message.messages_lost_in_recorder;

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.topic_name.size() + 1);

  // Member: messages_lost_in_transport
  {
    size_t item_size = sizeof(ros_message.messages_lost_in_transport);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: messages_lost_in_recorder
  {
    size_t item_size = sizeof(ros_message.messages_lost_in_recorder);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_MessagesLostEventTopicStat(
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

  // Member: topic_name
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
  // Member: messages_lost_in_transport
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: messages_lost_in_recorder
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
    using DataType = rosbag2_interfaces::msg::MessagesLostEventTopicStat;
    is_plain =
      (
      offsetof(DataType, messages_lost_in_recorder) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: topic_name
  cdr << ros_message.topic_name;

  // Member: messages_lost_in_transport
  cdr << ros_message.messages_lost_in_transport;

  // Member: messages_lost_in_recorder
  cdr << ros_message.messages_lost_in_recorder;

  return true;
}

inline
size_t
get_serialized_size_key(
  const rosbag2_interfaces::msg::MessagesLostEventTopicStat & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.topic_name.size() + 1);

  // Member: messages_lost_in_transport
  {
    size_t item_size = sizeof(ros_message.messages_lost_in_transport);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: messages_lost_in_recorder
  {
    size_t item_size = sizeof(ros_message.messages_lost_in_recorder);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_MessagesLostEventTopicStat(
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

  // Member: topic_name
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

  // Member: messages_lost_in_transport
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: messages_lost_in_recorder
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
    using DataType = rosbag2_interfaces::msg::MessagesLostEventTopicStat;
    is_plain =
      (
      offsetof(DataType, messages_lost_in_recorder) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
