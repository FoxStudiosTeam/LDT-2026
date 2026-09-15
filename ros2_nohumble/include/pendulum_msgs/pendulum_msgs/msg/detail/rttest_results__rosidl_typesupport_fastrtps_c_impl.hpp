// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pendulum_msgs/msg/detail/rttest_results__struct.h"
#include "pendulum_msgs/msg/detail/rttest_results__functions.h"
#include "pendulum_msgs/msg/detail/rttest_results__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp
#include "pendulum_msgs/msg/detail/joint_command__functions.h"  // command
#include "pendulum_msgs/msg/detail/joint_state__functions.h"  // state

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "pendulum_msgs/msg/detail/joint_command__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "pendulum_msgs/msg/detail/joint_state__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _RttestResults__ros_msg_type = pendulum_msgs__msg__RttestResults;


inline
bool impl_cdr_serialize_pendulum_msgs__msg__RttestResults(
  const pendulum_msgs__msg__RttestResults * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: stamp
  {
    impl_cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->stamp, cdr);
  }

  // Field name: command
  {
    impl_cdr_serialize_pendulum_msgs__msg__JointCommand(
      &ros_message->command, cdr);
  }

  // Field name: state
  {
    impl_cdr_serialize_pendulum_msgs__msg__JointState(
      &ros_message->state, cdr);
  }

  // Field name: cur_latency
  {
    cdr << ros_message->cur_latency;
  }

  // Field name: mean_latency
  {
    cdr << ros_message->mean_latency;
  }

  // Field name: min_latency
  {
    cdr << ros_message->min_latency;
  }

  // Field name: max_latency
  {
    cdr << ros_message->max_latency;
  }

  // Field name: minor_pagefaults
  {
    cdr << ros_message->minor_pagefaults;
  }

  // Field name: major_pagefaults
  {
    cdr << ros_message->major_pagefaults;
  }

  return true;
}

inline
bool impl_cdr_deserialize_pendulum_msgs__msg__RttestResults(
  eprosima::fastcdr::Cdr & cdr,
  pendulum_msgs__msg__RttestResults * ros_message)
{
  // Field name: stamp
  {
    impl_cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->stamp);
  }

  // Field name: command
  {
    impl_cdr_deserialize_pendulum_msgs__msg__JointCommand(cdr, &ros_message->command);
  }

  // Field name: state
  {
    impl_cdr_deserialize_pendulum_msgs__msg__JointState(cdr, &ros_message->state);
  }

  // Field name: cur_latency
  {
    cdr >> ros_message->cur_latency;
  }

  // Field name: mean_latency
  {
    cdr >> ros_message->mean_latency;
  }

  // Field name: min_latency
  {
    cdr >> ros_message->min_latency;
  }

  // Field name: max_latency
  {
    cdr >> ros_message->max_latency;
  }

  // Field name: minor_pagefaults
  {
    cdr >> ros_message->minor_pagefaults;
  }

  // Field name: major_pagefaults
  {
    cdr >> ros_message->major_pagefaults;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_pendulum_msgs__msg__RttestResults(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RttestResults__ros_msg_type * ros_message = static_cast<const _RttestResults__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: stamp
  current_alignment += impl_get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);

  // Field name: command
  current_alignment += impl_get_serialized_size_pendulum_msgs__msg__JointCommand(
    &(ros_message->command), current_alignment);

  // Field name: state
  current_alignment += impl_get_serialized_size_pendulum_msgs__msg__JointState(
    &(ros_message->state), current_alignment);

  // Field name: cur_latency
  {
    size_t item_size = sizeof(ros_message->cur_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_latency
  {
    size_t item_size = sizeof(ros_message->mean_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: min_latency
  {
    size_t item_size = sizeof(ros_message->min_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_latency
  {
    size_t item_size = sizeof(ros_message->max_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: minor_pagefaults
  {
    size_t item_size = sizeof(ros_message->minor_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: major_pagefaults
  {
    size_t item_size = sizeof(ros_message->major_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_pendulum_msgs__msg__RttestResults(
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

  // Field name: stamp
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

  // Field name: command
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_pendulum_msgs__msg__JointCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_pendulum_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cur_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mean_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: min_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: max_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: minor_pagefaults
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: major_pagefaults
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
    using DataType = pendulum_msgs__msg__RttestResults;
    is_plain =
      (
      offsetof(DataType, major_pagefaults) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_pendulum_msgs__msg__RttestResults(
  const pendulum_msgs__msg__RttestResults * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: stamp
  {
    impl_cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->stamp, cdr);
  }

  // Field name: command
  {
    impl_cdr_serialize_key_pendulum_msgs__msg__JointCommand(
      &ros_message->command, cdr);
  }

  // Field name: state
  {
    impl_cdr_serialize_key_pendulum_msgs__msg__JointState(
      &ros_message->state, cdr);
  }

  // Field name: cur_latency
  {
    cdr << ros_message->cur_latency;
  }

  // Field name: mean_latency
  {
    cdr << ros_message->mean_latency;
  }

  // Field name: min_latency
  {
    cdr << ros_message->min_latency;
  }

  // Field name: max_latency
  {
    cdr << ros_message->max_latency;
  }

  // Field name: minor_pagefaults
  {
    cdr << ros_message->minor_pagefaults;
  }

  // Field name: major_pagefaults
  {
    cdr << ros_message->major_pagefaults;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_pendulum_msgs__msg__RttestResults(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RttestResults__ros_msg_type * ros_message = static_cast<const _RttestResults__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: stamp
  current_alignment += impl_get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);

  // Field name: command
  current_alignment += impl_get_serialized_size_key_pendulum_msgs__msg__JointCommand(
    &(ros_message->command), current_alignment);

  // Field name: state
  current_alignment += impl_get_serialized_size_key_pendulum_msgs__msg__JointState(
    &(ros_message->state), current_alignment);

  // Field name: cur_latency
  {
    size_t item_size = sizeof(ros_message->cur_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mean_latency
  {
    size_t item_size = sizeof(ros_message->mean_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: min_latency
  {
    size_t item_size = sizeof(ros_message->min_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_latency
  {
    size_t item_size = sizeof(ros_message->max_latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: minor_pagefaults
  {
    size_t item_size = sizeof(ros_message->minor_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: major_pagefaults
  {
    size_t item_size = sizeof(ros_message->major_pagefaults);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_pendulum_msgs__msg__RttestResults(
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
  // Field name: stamp
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

  // Field name: command
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_pendulum_msgs__msg__JointCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_pendulum_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cur_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mean_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: min_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: max_latency
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: minor_pagefaults
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: major_pagefaults
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
    using DataType = pendulum_msgs__msg__RttestResults;
    is_plain =
      (
      offsetof(DataType, major_pagefaults) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_pendulum_msgs__msg__RttestResults(
  const pendulum_msgs__msg__RttestResults * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: stamp
  {
    impl_cdr_serialize_with_endpoint_builtin_interfaces__msg__Time(
      &ros_message->stamp, cdr, endpoint_info, serialization_context);
  }

  // Field name: command
  {
    impl_cdr_serialize_with_endpoint_pendulum_msgs__msg__JointCommand(
      &ros_message->command, cdr, endpoint_info, serialization_context);
  }

  // Field name: state
  {
    impl_cdr_serialize_with_endpoint_pendulum_msgs__msg__JointState(
      &ros_message->state, cdr, endpoint_info, serialization_context);
  }

  // Field name: cur_latency
  {
    cdr << ros_message->cur_latency;
  }

  // Field name: mean_latency
  {
    cdr << ros_message->mean_latency;
  }

  // Field name: min_latency
  {
    cdr << ros_message->min_latency;
  }

  // Field name: max_latency
  {
    cdr << ros_message->max_latency;
  }

  // Field name: minor_pagefaults
  {
    cdr << ros_message->minor_pagefaults;
  }

  // Field name: major_pagefaults
  {
    cdr << ros_message->major_pagefaults;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_pendulum_msgs__msg__RttestResults(
  eprosima::fastcdr::Cdr & cdr,
  pendulum_msgs__msg__RttestResults * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: stamp
  {
    impl_cdr_deserialize_with_endpoint_builtin_interfaces__msg__Time(cdr, &ros_message->stamp, endpoint_info, serialization_context);
  }

  // Field name: command
  {
    impl_cdr_deserialize_with_endpoint_pendulum_msgs__msg__JointCommand(cdr, &ros_message->command, endpoint_info, serialization_context);
  }

  // Field name: state
  {
    impl_cdr_deserialize_with_endpoint_pendulum_msgs__msg__JointState(cdr, &ros_message->state, endpoint_info, serialization_context);
  }

  // Field name: cur_latency
  {
    cdr >> ros_message->cur_latency;
  }

  // Field name: mean_latency
  {
    cdr >> ros_message->mean_latency;
  }

  // Field name: min_latency
  {
    cdr >> ros_message->min_latency;
  }

  // Field name: max_latency
  {
    cdr >> ros_message->max_latency;
  }

  // Field name: minor_pagefaults
  {
    cdr >> ros_message->minor_pagefaults;
  }

  // Field name: major_pagefaults
  {
    cdr >> ros_message->major_pagefaults;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
