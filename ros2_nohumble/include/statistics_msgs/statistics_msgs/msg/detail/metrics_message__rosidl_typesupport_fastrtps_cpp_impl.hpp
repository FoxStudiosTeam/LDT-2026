// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from statistics_msgs:msg\MetricsMessage.idl
// generated code does not contain a copyright notice

#ifndef STATISTICS_MSGS__MSG__DETAIL__METRICS_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define STATISTICS_MSGS__MSG__DETAIL__METRICS_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "statistics_msgs/msg/detail/metrics_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "builtin_interfaces/msg/detail/time__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "statistics_msgs/msg/detail/statistic_data_point__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace statistics_msgs
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
  const statistics_msgs::msg::MetricsMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: measurement_source_name
  cdr << ros_message.measurement_source_name;

  // Member: metrics_source
  cdr << ros_message.metrics_source;

  // Member: unit
  cdr << ros_message.unit;

  // Member: window_start
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.window_start,
    cdr);

  // Member: window_stop
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.window_stop,
    cdr);

  // Member: statistics
  {
    size_t size = ros_message.statistics.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      statistics_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.statistics[i],
        cdr);
    }
  }

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  statistics_msgs::msg::MetricsMessage & ros_message)
{
  // Member: measurement_source_name
  cdr >> ros_message.measurement_source_name;

  // Member: metrics_source
  cdr >> ros_message.metrics_source;

  // Member: unit
  cdr >> ros_message.unit;

  // Member: window_start
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.window_start);

  // Member: window_stop
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.window_stop);

  // Member: statistics
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

    ros_message.statistics.resize(size);
    for (size_t i = 0; i < size; i++) {
      statistics_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.statistics[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const statistics_msgs::msg::MetricsMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: measurement_source_name
    cdr << ros_message.measurement_source_name;
    // Member: metrics_source
    cdr << ros_message.metrics_source;
    // Member: unit
    cdr << ros_message.unit;
    // Member: window_start
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.window_start,
      cdr, endpoint_info, serialization_context);
    // Member: window_stop
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.window_stop,
      cdr, endpoint_info, serialization_context);
    // Member: statistics
    {
      size_t size = ros_message.statistics.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        statistics_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.statistics[i],
          cdr, endpoint_info, serialization_context);
      }
    }
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "statistics_msgs.typesupport_fastrtps_cpp",
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
  statistics_msgs::msg::MetricsMessage & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: measurement_source_name
  cdr >> ros_message.measurement_source_name;

  // Member: metrics_source
  cdr >> ros_message.metrics_source;

  // Member: unit
  cdr >> ros_message.unit;

  // Member: window_start
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.window_start,
    endpoint_info,
    serialization_context);

  // Member: window_stop
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.window_stop,
    endpoint_info,
    serialization_context);

  // Member: statistics
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

    ros_message.statistics.resize(size);
    for (size_t i = 0; i < size; i++) {
      statistics_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.statistics[i],
        endpoint_info,
        serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const statistics_msgs::msg::MetricsMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: measurement_source_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.measurement_source_name.size() + 1);

  // Member: metrics_source
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.metrics_source.size() + 1);

  // Member: unit
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.unit.size() + 1);

  // Member: window_start
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.window_start, current_alignment);

  // Member: window_stop
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.window_stop, current_alignment);

  // Member: statistics
  {
    size_t array_size = ros_message.statistics.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        statistics_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.statistics[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_MetricsMessage(
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

  // Member: measurement_source_name
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
  // Member: metrics_source
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
  // Member: unit
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
  // Member: window_start
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
  // Member: window_stop
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
  // Member: statistics
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        statistics_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_StatisticDataPoint(
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
    using DataType = statistics_msgs::msg::MetricsMessage;
    is_plain =
      (
      offsetof(DataType, statistics) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const statistics_msgs::msg::MetricsMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: measurement_source_name
  cdr << ros_message.measurement_source_name;

  // Member: metrics_source
  cdr << ros_message.metrics_source;

  // Member: unit
  cdr << ros_message.unit;

  // Member: window_start
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.window_start,
    cdr);

  // Member: window_stop
  builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.window_stop,
    cdr);

  // Member: statistics
  {
    size_t size = ros_message.statistics.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      statistics_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.statistics[i],
        cdr);
    }
  }

  return true;
}

inline
size_t
get_serialized_size_key(
  const statistics_msgs::msg::MetricsMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: measurement_source_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.measurement_source_name.size() + 1);

  // Member: metrics_source
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.metrics_source.size() + 1);

  // Member: unit
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.unit.size() + 1);

  // Member: window_start
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.window_start, current_alignment);

  // Member: window_stop
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.window_stop, current_alignment);

  // Member: statistics
  {
    size_t array_size = ros_message.statistics.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        statistics_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.statistics[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_MetricsMessage(
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

  // Member: measurement_source_name
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

  // Member: metrics_source
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

  // Member: unit
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

  // Member: window_start
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

  // Member: window_stop
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

  // Member: statistics
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        statistics_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_StatisticDataPoint(
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
    using DataType = statistics_msgs::msg::MetricsMessage;
    is_plain =
      (
      offsetof(DataType, statistics) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace statistics_msgs

#endif  // STATISTICS_MSGS__MSG__DETAIL__METRICS_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
