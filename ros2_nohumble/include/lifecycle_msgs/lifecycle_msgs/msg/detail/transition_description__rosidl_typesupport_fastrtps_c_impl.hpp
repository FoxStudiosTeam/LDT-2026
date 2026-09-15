// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from lifecycle_msgs:msg\TransitionDescription.idl
// generated code does not contain a copyright notice

#ifndef LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lifecycle_msgs/msg/detail/transition_description__struct.h"
#include "lifecycle_msgs/msg/detail/transition_description__functions.h"
#include "lifecycle_msgs/msg/detail/transition_description__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "lifecycle_msgs/msg/detail/state__functions.h"  // goal_state, start_state
#include "lifecycle_msgs/msg/detail/transition__functions.h"  // transition

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "lifecycle_msgs/msg/detail/transition__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "lifecycle_msgs/msg/detail/state__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _TransitionDescription__ros_msg_type = lifecycle_msgs__msg__TransitionDescription;


inline
bool impl_cdr_serialize_lifecycle_msgs__msg__TransitionDescription(
  const lifecycle_msgs__msg__TransitionDescription * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: transition
  {
    impl_cdr_serialize_lifecycle_msgs__msg__Transition(
      &ros_message->transition, cdr);
  }

  // Field name: start_state
  {
    impl_cdr_serialize_lifecycle_msgs__msg__State(
      &ros_message->start_state, cdr);
  }

  // Field name: goal_state
  {
    impl_cdr_serialize_lifecycle_msgs__msg__State(
      &ros_message->goal_state, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_lifecycle_msgs__msg__TransitionDescription(
  eprosima::fastcdr::Cdr & cdr,
  lifecycle_msgs__msg__TransitionDescription * ros_message)
{
  // Field name: transition
  {
    impl_cdr_deserialize_lifecycle_msgs__msg__Transition(cdr, &ros_message->transition);
  }

  // Field name: start_state
  {
    impl_cdr_deserialize_lifecycle_msgs__msg__State(cdr, &ros_message->start_state);
  }

  // Field name: goal_state
  {
    impl_cdr_deserialize_lifecycle_msgs__msg__State(cdr, &ros_message->goal_state);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_lifecycle_msgs__msg__TransitionDescription(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TransitionDescription__ros_msg_type * ros_message = static_cast<const _TransitionDescription__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: transition
  current_alignment += impl_get_serialized_size_lifecycle_msgs__msg__Transition(
    &(ros_message->transition), current_alignment);

  // Field name: start_state
  current_alignment += impl_get_serialized_size_lifecycle_msgs__msg__State(
    &(ros_message->start_state), current_alignment);

  // Field name: goal_state
  current_alignment += impl_get_serialized_size_lifecycle_msgs__msg__State(
    &(ros_message->goal_state), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_lifecycle_msgs__msg__TransitionDescription(
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

  // Field name: transition
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_lifecycle_msgs__msg__Transition(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: start_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_lifecycle_msgs__msg__State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: goal_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_lifecycle_msgs__msg__State(
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
    using DataType = lifecycle_msgs__msg__TransitionDescription;
    is_plain =
      (
      offsetof(DataType, goal_state) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_lifecycle_msgs__msg__TransitionDescription(
  const lifecycle_msgs__msg__TransitionDescription * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: transition
  {
    impl_cdr_serialize_key_lifecycle_msgs__msg__Transition(
      &ros_message->transition, cdr);
  }

  // Field name: start_state
  {
    impl_cdr_serialize_key_lifecycle_msgs__msg__State(
      &ros_message->start_state, cdr);
  }

  // Field name: goal_state
  {
    impl_cdr_serialize_key_lifecycle_msgs__msg__State(
      &ros_message->goal_state, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_lifecycle_msgs__msg__TransitionDescription(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TransitionDescription__ros_msg_type * ros_message = static_cast<const _TransitionDescription__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: transition
  current_alignment += impl_get_serialized_size_key_lifecycle_msgs__msg__Transition(
    &(ros_message->transition), current_alignment);

  // Field name: start_state
  current_alignment += impl_get_serialized_size_key_lifecycle_msgs__msg__State(
    &(ros_message->start_state), current_alignment);

  // Field name: goal_state
  current_alignment += impl_get_serialized_size_key_lifecycle_msgs__msg__State(
    &(ros_message->goal_state), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_lifecycle_msgs__msg__TransitionDescription(
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
  // Field name: transition
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_lifecycle_msgs__msg__Transition(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: start_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_lifecycle_msgs__msg__State(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: goal_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_lifecycle_msgs__msg__State(
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
    using DataType = lifecycle_msgs__msg__TransitionDescription;
    is_plain =
      (
      offsetof(DataType, goal_state) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_lifecycle_msgs__msg__TransitionDescription(
  const lifecycle_msgs__msg__TransitionDescription * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: transition
  {
    impl_cdr_serialize_with_endpoint_lifecycle_msgs__msg__Transition(
      &ros_message->transition, cdr, endpoint_info, serialization_context);
  }

  // Field name: start_state
  {
    impl_cdr_serialize_with_endpoint_lifecycle_msgs__msg__State(
      &ros_message->start_state, cdr, endpoint_info, serialization_context);
  }

  // Field name: goal_state
  {
    impl_cdr_serialize_with_endpoint_lifecycle_msgs__msg__State(
      &ros_message->goal_state, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_lifecycle_msgs__msg__TransitionDescription(
  eprosima::fastcdr::Cdr & cdr,
  lifecycle_msgs__msg__TransitionDescription * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: transition
  {
    impl_cdr_deserialize_with_endpoint_lifecycle_msgs__msg__Transition(cdr, &ros_message->transition, endpoint_info, serialization_context);
  }

  // Field name: start_state
  {
    impl_cdr_deserialize_with_endpoint_lifecycle_msgs__msg__State(cdr, &ros_message->start_state, endpoint_info, serialization_context);
  }

  // Field name: goal_state
  {
    impl_cdr_deserialize_with_endpoint_lifecycle_msgs__msg__State(cdr, &ros_message->goal_state, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
