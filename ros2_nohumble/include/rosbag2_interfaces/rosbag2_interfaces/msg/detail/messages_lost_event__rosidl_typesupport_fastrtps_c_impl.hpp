// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEvent.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event__struct.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event__functions.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__functions.h"  // messages_lost_statistics
#include "rosidl_runtime_c/string.h"  // node_name
#include "rosidl_runtime_c/string_functions.h"  // node_name

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _MessagesLostEvent__ros_msg_type = rosbag2_interfaces__msg__MessagesLostEvent;


inline
bool impl_cdr_serialize_rosbag2_interfaces__msg__MessagesLostEvent(
  const rosbag2_interfaces__msg__MessagesLostEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: node_name
  {
    const rosidl_runtime_c__String * str = &ros_message->node_name;
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

  // Field name: messages_lost_statistics
  {
    size_t size = ros_message->messages_lost_statistics.size;
    auto array_ptr = ros_message->messages_lost_statistics.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosbag2_interfaces__msg__MessagesLostEvent(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_interfaces__msg__MessagesLostEvent * ros_message)
{
  // Field name: node_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->node_name.data) {
      rosidl_runtime_c__String__init(&ros_message->node_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->node_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'node_name'\n");
      return false;
    }
  }

  // Field name: messages_lost_statistics
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

    if (ros_message->messages_lost_statistics.data) {
      rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__fini(&ros_message->messages_lost_statistics);
    }
    if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__init(&ros_message->messages_lost_statistics, size)) {
      fprintf(stderr, "failed to create array for field 'messages_lost_statistics'");
      return false;
    }
    auto array_ptr = ros_message->messages_lost_statistics.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosbag2_interfaces__msg__MessagesLostEventTopicStat(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosbag2_interfaces__msg__MessagesLostEvent(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MessagesLostEvent__ros_msg_type * ros_message = static_cast<const _MessagesLostEvent__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: node_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->node_name.size + 1);

  // Field name: messages_lost_statistics
  {
    size_t array_size = ros_message->messages_lost_statistics.size;
    auto array_ptr = ros_message->messages_lost_statistics.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosbag2_interfaces__msg__MessagesLostEvent(
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

  // Field name: node_name
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

  // Field name: messages_lost_statistics
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
        impl_max_serialized_size_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
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
    using DataType = rosbag2_interfaces__msg__MessagesLostEvent;
    is_plain =
      (
      offsetof(DataType, messages_lost_statistics) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosbag2_interfaces__msg__MessagesLostEvent(
  const rosbag2_interfaces__msg__MessagesLostEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: node_name
  {
    const rosidl_runtime_c__String * str = &ros_message->node_name;
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

  // Field name: messages_lost_statistics
  {
    size_t size = ros_message->messages_lost_statistics.size;
    auto array_ptr = ros_message->messages_lost_statistics.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEvent(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MessagesLostEvent__ros_msg_type * ros_message = static_cast<const _MessagesLostEvent__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: node_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->node_name.size + 1);

  // Field name: messages_lost_statistics
  {
    size_t array_size = ros_message->messages_lost_statistics.size;
    auto array_ptr = ros_message->messages_lost_statistics.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEvent(
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
  // Field name: node_name
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

  // Field name: messages_lost_statistics
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
        impl_max_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
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
    using DataType = rosbag2_interfaces__msg__MessagesLostEvent;
    is_plain =
      (
      offsetof(DataType, messages_lost_statistics) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosbag2_interfaces__msg__MessagesLostEvent(
  const rosbag2_interfaces__msg__MessagesLostEvent * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: node_name
  {
    const rosidl_runtime_c__String * str = &ros_message->node_name;
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

  // Field name: messages_lost_statistics
  {
    size_t size = ros_message->messages_lost_statistics.size;
    auto array_ptr = ros_message->messages_lost_statistics.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosbag2_interfaces__msg__MessagesLostEvent(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_interfaces__msg__MessagesLostEvent * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: node_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->node_name.data) {
      rosidl_runtime_c__String__init(&ros_message->node_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->node_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'node_name'\n");
      return false;
    }
  }

  // Field name: messages_lost_statistics
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

    if (ros_message->messages_lost_statistics.data) {
      rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__fini(&ros_message->messages_lost_statistics);
    }
    if (!rosbag2_interfaces__msg__MessagesLostEventTopicStat__Sequence__init(&ros_message->messages_lost_statistics, size)) {
      fprintf(stderr, "failed to create array for field 'messages_lost_statistics'");
      return false;
    }
    auto array_ptr = ros_message->messages_lost_statistics.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosbag2_interfaces__msg__MessagesLostEventTopicStat(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
