// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from statistics_msgs:msg\MetricsMessage.idl
// generated code does not contain a copyright notice

#ifndef STATISTICS_MSGS__MSG__DETAIL__METRICS_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define STATISTICS_MSGS__MSG__DETAIL__METRICS_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "statistics_msgs/msg/detail/metrics_message__struct.h"
#include "statistics_msgs/msg/detail/metrics_message__functions.h"
#include "statistics_msgs/msg/detail/metrics_message__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "builtin_interfaces/msg/detail/time__functions.h"  // window_start, window_stop
#include "rosidl_runtime_c/string.h"  // measurement_source_name, metrics_source, unit
#include "rosidl_runtime_c/string_functions.h"  // measurement_source_name, metrics_source, unit
#include "statistics_msgs/msg/detail/statistic_data_point__functions.h"  // statistics

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "statistics_msgs/msg/detail/statistic_data_point__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _MetricsMessage__ros_msg_type = statistics_msgs__msg__MetricsMessage;


inline
bool impl_cdr_serialize_statistics_msgs__msg__MetricsMessage(
  const statistics_msgs__msg__MetricsMessage * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: measurement_source_name
  {
    const rosidl_runtime_c__String * str = &ros_message->measurement_source_name;
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

  // Field name: metrics_source
  {
    const rosidl_runtime_c__String * str = &ros_message->metrics_source;
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

  // Field name: unit
  {
    const rosidl_runtime_c__String * str = &ros_message->unit;
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

  // Field name: window_start
  {
    impl_cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->window_start, cdr);
  }

  // Field name: window_stop
  {
    impl_cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->window_stop, cdr);
  }

  // Field name: statistics
  {
    size_t size = ros_message->statistics.size;
    auto array_ptr = ros_message->statistics.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_statistics_msgs__msg__StatisticDataPoint(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_statistics_msgs__msg__MetricsMessage(
  eprosima::fastcdr::Cdr & cdr,
  statistics_msgs__msg__MetricsMessage * ros_message)
{
  // Field name: measurement_source_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->measurement_source_name.data) {
      rosidl_runtime_c__String__init(&ros_message->measurement_source_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->measurement_source_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'measurement_source_name'\n");
      return false;
    }
  }

  // Field name: metrics_source
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->metrics_source.data) {
      rosidl_runtime_c__String__init(&ros_message->metrics_source);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->metrics_source,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'metrics_source'\n");
      return false;
    }
  }

  // Field name: unit
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->unit.data) {
      rosidl_runtime_c__String__init(&ros_message->unit);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->unit,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'unit'\n");
      return false;
    }
  }

  // Field name: window_start
  {
    impl_cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->window_start);
  }

  // Field name: window_stop
  {
    impl_cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->window_stop);
  }

  // Field name: statistics
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

    if (ros_message->statistics.data) {
      statistics_msgs__msg__StatisticDataPoint__Sequence__fini(&ros_message->statistics);
    }
    if (!statistics_msgs__msg__StatisticDataPoint__Sequence__init(&ros_message->statistics, size)) {
      fprintf(stderr, "failed to create array for field 'statistics'");
      return false;
    }
    auto array_ptr = ros_message->statistics.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_statistics_msgs__msg__StatisticDataPoint(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_statistics_msgs__msg__MetricsMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MetricsMessage__ros_msg_type * ros_message = static_cast<const _MetricsMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: measurement_source_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->measurement_source_name.size + 1);

  // Field name: metrics_source
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->metrics_source.size + 1);

  // Field name: unit
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->unit.size + 1);

  // Field name: window_start
  current_alignment += impl_get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->window_start), current_alignment);

  // Field name: window_stop
  current_alignment += impl_get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->window_stop), current_alignment);

  // Field name: statistics
  {
    size_t array_size = ros_message->statistics.size;
    auto array_ptr = ros_message->statistics.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_statistics_msgs__msg__StatisticDataPoint(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_statistics_msgs__msg__MetricsMessage(
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

  // Field name: measurement_source_name
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

  // Field name: metrics_source
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

  // Field name: unit
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

  // Field name: window_start
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: window_stop
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: statistics
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_statistics_msgs__msg__StatisticDataPoint(
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
    using DataType = statistics_msgs__msg__MetricsMessage;
    is_plain =
      (
      offsetof(DataType, statistics) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_statistics_msgs__msg__MetricsMessage(
  const statistics_msgs__msg__MetricsMessage * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: measurement_source_name
  {
    const rosidl_runtime_c__String * str = &ros_message->measurement_source_name;
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

  // Field name: metrics_source
  {
    const rosidl_runtime_c__String * str = &ros_message->metrics_source;
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

  // Field name: unit
  {
    const rosidl_runtime_c__String * str = &ros_message->unit;
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

  // Field name: window_start
  {
    impl_cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->window_start, cdr);
  }

  // Field name: window_stop
  {
    impl_cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->window_stop, cdr);
  }

  // Field name: statistics
  {
    size_t size = ros_message->statistics.size;
    auto array_ptr = ros_message->statistics.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_statistics_msgs__msg__StatisticDataPoint(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_statistics_msgs__msg__MetricsMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MetricsMessage__ros_msg_type * ros_message = static_cast<const _MetricsMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: measurement_source_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->measurement_source_name.size + 1);

  // Field name: metrics_source
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->metrics_source.size + 1);

  // Field name: unit
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->unit.size + 1);

  // Field name: window_start
  current_alignment += impl_get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->window_start), current_alignment);

  // Field name: window_stop
  current_alignment += impl_get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->window_stop), current_alignment);

  // Field name: statistics
  {
    size_t array_size = ros_message->statistics.size;
    auto array_ptr = ros_message->statistics.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_statistics_msgs__msg__StatisticDataPoint(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_statistics_msgs__msg__MetricsMessage(
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
  // Field name: measurement_source_name
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

  // Field name: metrics_source
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

  // Field name: unit
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

  // Field name: window_start
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: window_stop
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: statistics
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
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_statistics_msgs__msg__StatisticDataPoint(
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
    using DataType = statistics_msgs__msg__MetricsMessage;
    is_plain =
      (
      offsetof(DataType, statistics) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_statistics_msgs__msg__MetricsMessage(
  const statistics_msgs__msg__MetricsMessage * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: measurement_source_name
  {
    const rosidl_runtime_c__String * str = &ros_message->measurement_source_name;
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

  // Field name: metrics_source
  {
    const rosidl_runtime_c__String * str = &ros_message->metrics_source;
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

  // Field name: unit
  {
    const rosidl_runtime_c__String * str = &ros_message->unit;
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

  // Field name: window_start
  {
    impl_cdr_serialize_with_endpoint_builtin_interfaces__msg__Time(
      &ros_message->window_start, cdr, endpoint_info, serialization_context);
  }

  // Field name: window_stop
  {
    impl_cdr_serialize_with_endpoint_builtin_interfaces__msg__Time(
      &ros_message->window_stop, cdr, endpoint_info, serialization_context);
  }

  // Field name: statistics
  {
    size_t size = ros_message->statistics.size;
    auto array_ptr = ros_message->statistics.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_statistics_msgs__msg__StatisticDataPoint(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_statistics_msgs__msg__MetricsMessage(
  eprosima::fastcdr::Cdr & cdr,
  statistics_msgs__msg__MetricsMessage * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: measurement_source_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->measurement_source_name.data) {
      rosidl_runtime_c__String__init(&ros_message->measurement_source_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->measurement_source_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'measurement_source_name'\n");
      return false;
    }
  }

  // Field name: metrics_source
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->metrics_source.data) {
      rosidl_runtime_c__String__init(&ros_message->metrics_source);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->metrics_source,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'metrics_source'\n");
      return false;
    }
  }

  // Field name: unit
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->unit.data) {
      rosidl_runtime_c__String__init(&ros_message->unit);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->unit,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'unit'\n");
      return false;
    }
  }

  // Field name: window_start
  {
    impl_cdr_deserialize_with_endpoint_builtin_interfaces__msg__Time(cdr, &ros_message->window_start, endpoint_info, serialization_context);
  }

  // Field name: window_stop
  {
    impl_cdr_deserialize_with_endpoint_builtin_interfaces__msg__Time(cdr, &ros_message->window_stop, endpoint_info, serialization_context);
  }

  // Field name: statistics
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

    if (ros_message->statistics.data) {
      statistics_msgs__msg__StatisticDataPoint__Sequence__fini(&ros_message->statistics);
    }
    if (!statistics_msgs__msg__StatisticDataPoint__Sequence__init(&ros_message->statistics, size)) {
      fprintf(stderr, "failed to create array for field 'statistics'");
      return false;
    }
    auto array_ptr = ros_message->statistics.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_statistics_msgs__msg__StatisticDataPoint(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // STATISTICS_MSGS__MSG__DETAIL__METRICS_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
