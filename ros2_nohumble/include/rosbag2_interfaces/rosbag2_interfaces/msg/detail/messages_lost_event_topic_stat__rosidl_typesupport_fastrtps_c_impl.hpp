// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosbag2_interfaces:msg\MessagesLostEventTopicStat.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__struct.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__functions.h"
#include "rosbag2_interfaces/msg/detail/messages_lost_event_topic_stat__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/string.h"  // topic_name
#include "rosidl_runtime_c/string_functions.h"  // topic_name

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _MessagesLostEventTopicStat__ros_msg_type = rosbag2_interfaces__msg__MessagesLostEventTopicStat;


inline
bool impl_cdr_serialize_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: topic_name
  {
    const rosidl_runtime_c__String * str = &ros_message->topic_name;
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

  // Field name: messages_lost_in_transport
  {
    cdr << ros_message->messages_lost_in_transport;
  }

  // Field name: messages_lost_in_recorder
  {
    cdr << ros_message->messages_lost_in_recorder;
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message)
{
  // Field name: topic_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->topic_name.data) {
      rosidl_runtime_c__String__init(&ros_message->topic_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->topic_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'topic_name'\n");
      return false;
    }
  }

  // Field name: messages_lost_in_transport
  {
    cdr >> ros_message->messages_lost_in_transport;
  }

  // Field name: messages_lost_in_recorder
  {
    cdr >> ros_message->messages_lost_in_recorder;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MessagesLostEventTopicStat__ros_msg_type * ros_message = static_cast<const _MessagesLostEventTopicStat__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->topic_name.size + 1);

  // Field name: messages_lost_in_transport
  {
    size_t item_size = sizeof(ros_message->messages_lost_in_transport);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: messages_lost_in_recorder
  {
    size_t item_size = sizeof(ros_message->messages_lost_in_recorder);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
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

  // Field name: topic_name
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

  // Field name: messages_lost_in_transport
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: messages_lost_in_recorder
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
    using DataType = rosbag2_interfaces__msg__MessagesLostEventTopicStat;
    is_plain =
      (
      offsetof(DataType, messages_lost_in_recorder) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: topic_name
  {
    const rosidl_runtime_c__String * str = &ros_message->topic_name;
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

  // Field name: messages_lost_in_transport
  {
    cdr << ros_message->messages_lost_in_transport;
  }

  // Field name: messages_lost_in_recorder
  {
    cdr << ros_message->messages_lost_in_recorder;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MessagesLostEventTopicStat__ros_msg_type * ros_message = static_cast<const _MessagesLostEventTopicStat__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->topic_name.size + 1);

  // Field name: messages_lost_in_transport
  {
    size_t item_size = sizeof(ros_message->messages_lost_in_transport);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: messages_lost_in_recorder
  {
    size_t item_size = sizeof(ros_message->messages_lost_in_recorder);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
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
  // Field name: topic_name
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

  // Field name: messages_lost_in_transport
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: messages_lost_in_recorder
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
    using DataType = rosbag2_interfaces__msg__MessagesLostEventTopicStat;
    is_plain =
      (
      offsetof(DataType, messages_lost_in_recorder) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  const rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: topic_name
  {
    const rosidl_runtime_c__String * str = &ros_message->topic_name;
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

  // Field name: messages_lost_in_transport
  {
    cdr << ros_message->messages_lost_in_transport;
  }

  // Field name: messages_lost_in_recorder
  {
    cdr << ros_message->messages_lost_in_recorder;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosbag2_interfaces__msg__MessagesLostEventTopicStat(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_interfaces__msg__MessagesLostEventTopicStat * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: topic_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->topic_name.data) {
      rosidl_runtime_c__String__init(&ros_message->topic_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->topic_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'topic_name'\n");
      return false;
    }
  }

  // Field name: messages_lost_in_transport
  {
    cdr >> ros_message->messages_lost_in_transport;
  }

  // Field name: messages_lost_in_recorder
  {
    cdr >> ros_message->messages_lost_in_recorder;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSBAG2_INTERFACES__MSG__DETAIL__MESSAGES_LOST_EVENT_TOPIC_STAT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
