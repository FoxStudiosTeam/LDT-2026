// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from action_msgs:msg\GoalStatus.idl
// generated code does not contain a copyright notice

#ifndef ACTION_MSGS__MSG__DETAIL__GOAL_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ACTION_MSGS__MSG__DETAIL__GOAL_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "action_msgs/msg/detail/goal_status__struct.h"
#include "action_msgs/msg/detail/goal_status__functions.h"
#include "action_msgs/msg/detail/goal_status__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "action_msgs/msg/detail/goal_info__functions.h"  // goal_info

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "action_msgs/msg/detail/goal_info__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _GoalStatus__ros_msg_type = action_msgs__msg__GoalStatus;


inline
bool impl_cdr_serialize_action_msgs__msg__GoalStatus(
  const action_msgs__msg__GoalStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: goal_info
  {
    impl_cdr_serialize_action_msgs__msg__GoalInfo(
      &ros_message->goal_info, cdr);
  }

  // Field name: status
  {
    cdr << ros_message->status;
  }

  return true;
}

inline
bool impl_cdr_deserialize_action_msgs__msg__GoalStatus(
  eprosima::fastcdr::Cdr & cdr,
  action_msgs__msg__GoalStatus * ros_message)
{
  // Field name: goal_info
  {
    impl_cdr_deserialize_action_msgs__msg__GoalInfo(cdr, &ros_message->goal_info);
  }

  // Field name: status
  {
    cdr >> ros_message->status;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_action_msgs__msg__GoalStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GoalStatus__ros_msg_type * ros_message = static_cast<const _GoalStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: goal_info
  current_alignment += impl_get_serialized_size_action_msgs__msg__GoalInfo(
    &(ros_message->goal_info), current_alignment);

  // Field name: status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_action_msgs__msg__GoalStatus(
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

  // Field name: goal_info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_action_msgs__msg__GoalInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = action_msgs__msg__GoalStatus;
    is_plain =
      (
      offsetof(DataType, status) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_action_msgs__msg__GoalStatus(
  const action_msgs__msg__GoalStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: goal_info
  {
    impl_cdr_serialize_key_action_msgs__msg__GoalInfo(
      &ros_message->goal_info, cdr);
  }

  // Field name: status
  {
    cdr << ros_message->status;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_action_msgs__msg__GoalStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GoalStatus__ros_msg_type * ros_message = static_cast<const _GoalStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: goal_info
  current_alignment += impl_get_serialized_size_key_action_msgs__msg__GoalInfo(
    &(ros_message->goal_info), current_alignment);

  // Field name: status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_action_msgs__msg__GoalStatus(
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
  // Field name: goal_info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_action_msgs__msg__GoalInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = action_msgs__msg__GoalStatus;
    is_plain =
      (
      offsetof(DataType, status) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_action_msgs__msg__GoalStatus(
  const action_msgs__msg__GoalStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: goal_info
  {
    impl_cdr_serialize_with_endpoint_action_msgs__msg__GoalInfo(
      &ros_message->goal_info, cdr, endpoint_info, serialization_context);
  }

  // Field name: status
  {
    cdr << ros_message->status;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_action_msgs__msg__GoalStatus(
  eprosima::fastcdr::Cdr & cdr,
  action_msgs__msg__GoalStatus * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: goal_info
  {
    impl_cdr_deserialize_with_endpoint_action_msgs__msg__GoalInfo(cdr, &ros_message->goal_info, endpoint_info, serialization_context);
  }

  // Field name: status
  {
    cdr >> ros_message->status;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ACTION_MSGS__MSG__DETAIL__GOAL_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
