// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from trajectory_msgs:msg\MultiDOFJointTrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_MSGS__MSG__DETAIL__MULTI_DOF_JOINT_TRAJECTORY_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TRAJECTORY_MSGS__MSG__DETAIL__MULTI_DOF_JOINT_TRAJECTORY_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "trajectory_msgs/msg/detail/multi_dof_joint_trajectory_point__struct.h"
#include "trajectory_msgs/msg/detail/multi_dof_joint_trajectory_point__functions.h"
#include "trajectory_msgs/msg/detail/multi_dof_joint_trajectory_point__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "builtin_interfaces/msg/detail/duration__functions.h"  // time_from_start
#include "geometry_msgs/msg/detail/transform__functions.h"  // transforms
#include "geometry_msgs/msg/detail/twist__functions.h"  // accelerations, velocities

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "geometry_msgs/msg/detail/transform__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "builtin_interfaces/msg/detail/duration__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _MultiDOFJointTrajectoryPoint__ros_msg_type = trajectory_msgs__msg__MultiDOFJointTrajectoryPoint;


inline
bool impl_cdr_serialize_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  const trajectory_msgs__msg__MultiDOFJointTrajectoryPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: transforms
  {
    size_t size = ros_message->transforms.size;
    auto array_ptr = ros_message->transforms.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_geometry_msgs__msg__Transform(
        &array_ptr[i], cdr);
    }
  }

  // Field name: velocities
  {
    size_t size = ros_message->velocities.size;
    auto array_ptr = ros_message->velocities.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_geometry_msgs__msg__Twist(
        &array_ptr[i], cdr);
    }
  }

  // Field name: accelerations
  {
    size_t size = ros_message->accelerations.size;
    auto array_ptr = ros_message->accelerations.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_geometry_msgs__msg__Twist(
        &array_ptr[i], cdr);
    }
  }

  // Field name: time_from_start
  {
    impl_cdr_serialize_builtin_interfaces__msg__Duration(
      &ros_message->time_from_start, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  eprosima::fastcdr::Cdr & cdr,
  trajectory_msgs__msg__MultiDOFJointTrajectoryPoint * ros_message)
{
  // Field name: transforms
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

    if (ros_message->transforms.data) {
      geometry_msgs__msg__Transform__Sequence__fini(&ros_message->transforms);
    }
    if (!geometry_msgs__msg__Transform__Sequence__init(&ros_message->transforms, size)) {
      fprintf(stderr, "failed to create array for field 'transforms'");
      return false;
    }
    auto array_ptr = ros_message->transforms.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_geometry_msgs__msg__Transform(cdr, &array_ptr[i]);
    }
  }

  // Field name: velocities
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

    if (ros_message->velocities.data) {
      geometry_msgs__msg__Twist__Sequence__fini(&ros_message->velocities);
    }
    if (!geometry_msgs__msg__Twist__Sequence__init(&ros_message->velocities, size)) {
      fprintf(stderr, "failed to create array for field 'velocities'");
      return false;
    }
    auto array_ptr = ros_message->velocities.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_geometry_msgs__msg__Twist(cdr, &array_ptr[i]);
    }
  }

  // Field name: accelerations
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

    if (ros_message->accelerations.data) {
      geometry_msgs__msg__Twist__Sequence__fini(&ros_message->accelerations);
    }
    if (!geometry_msgs__msg__Twist__Sequence__init(&ros_message->accelerations, size)) {
      fprintf(stderr, "failed to create array for field 'accelerations'");
      return false;
    }
    auto array_ptr = ros_message->accelerations.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_geometry_msgs__msg__Twist(cdr, &array_ptr[i]);
    }
  }

  // Field name: time_from_start
  {
    impl_cdr_deserialize_builtin_interfaces__msg__Duration(cdr, &ros_message->time_from_start);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MultiDOFJointTrajectoryPoint__ros_msg_type * ros_message = static_cast<const _MultiDOFJointTrajectoryPoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: transforms
  {
    size_t array_size = ros_message->transforms.size;
    auto array_ptr = ros_message->transforms.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_geometry_msgs__msg__Transform(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: velocities
  {
    size_t array_size = ros_message->velocities.size;
    auto array_ptr = ros_message->velocities.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_geometry_msgs__msg__Twist(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: accelerations
  {
    size_t array_size = ros_message->accelerations.size;
    auto array_ptr = ros_message->accelerations.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_geometry_msgs__msg__Twist(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: time_from_start
  current_alignment += impl_get_serialized_size_builtin_interfaces__msg__Duration(
    &(ros_message->time_from_start), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
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

  // Field name: transforms
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
        impl_max_serialized_size_geometry_msgs__msg__Transform(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: velocities
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
        impl_max_serialized_size_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accelerations
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
        impl_max_serialized_size_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: time_from_start
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_builtin_interfaces__msg__Duration(
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
    using DataType = trajectory_msgs__msg__MultiDOFJointTrajectoryPoint;
    is_plain =
      (
      offsetof(DataType, time_from_start) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  const trajectory_msgs__msg__MultiDOFJointTrajectoryPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: transforms
  {
    size_t size = ros_message->transforms.size;
    auto array_ptr = ros_message->transforms.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_geometry_msgs__msg__Transform(
        &array_ptr[i], cdr);
    }
  }

  // Field name: velocities
  {
    size_t size = ros_message->velocities.size;
    auto array_ptr = ros_message->velocities.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_geometry_msgs__msg__Twist(
        &array_ptr[i], cdr);
    }
  }

  // Field name: accelerations
  {
    size_t size = ros_message->accelerations.size;
    auto array_ptr = ros_message->accelerations.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_geometry_msgs__msg__Twist(
        &array_ptr[i], cdr);
    }
  }

  // Field name: time_from_start
  {
    impl_cdr_serialize_key_builtin_interfaces__msg__Duration(
      &ros_message->time_from_start, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MultiDOFJointTrajectoryPoint__ros_msg_type * ros_message = static_cast<const _MultiDOFJointTrajectoryPoint__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: transforms
  {
    size_t array_size = ros_message->transforms.size;
    auto array_ptr = ros_message->transforms.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Transform(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: velocities
  {
    size_t array_size = ros_message->velocities.size;
    auto array_ptr = ros_message->velocities.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Twist(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: accelerations
  {
    size_t array_size = ros_message->accelerations.size;
    auto array_ptr = ros_message->accelerations.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Twist(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: time_from_start
  current_alignment += impl_get_serialized_size_key_builtin_interfaces__msg__Duration(
    &(ros_message->time_from_start), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
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
  // Field name: transforms
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
        impl_max_serialized_size_key_geometry_msgs__msg__Transform(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: velocities
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
        impl_max_serialized_size_key_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accelerations
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
        impl_max_serialized_size_key_geometry_msgs__msg__Twist(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: time_from_start
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_builtin_interfaces__msg__Duration(
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
    using DataType = trajectory_msgs__msg__MultiDOFJointTrajectoryPoint;
    is_plain =
      (
      offsetof(DataType, time_from_start) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  const trajectory_msgs__msg__MultiDOFJointTrajectoryPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: transforms
  {
    size_t size = ros_message->transforms.size;
    auto array_ptr = ros_message->transforms.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Transform(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: velocities
  {
    size_t size = ros_message->velocities.size;
    auto array_ptr = ros_message->velocities.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Twist(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: accelerations
  {
    size_t size = ros_message->accelerations.size;
    auto array_ptr = ros_message->accelerations.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Twist(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: time_from_start
  {
    impl_cdr_serialize_with_endpoint_builtin_interfaces__msg__Duration(
      &ros_message->time_from_start, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_trajectory_msgs__msg__MultiDOFJointTrajectoryPoint(
  eprosima::fastcdr::Cdr & cdr,
  trajectory_msgs__msg__MultiDOFJointTrajectoryPoint * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: transforms
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

    if (ros_message->transforms.data) {
      geometry_msgs__msg__Transform__Sequence__fini(&ros_message->transforms);
    }
    if (!geometry_msgs__msg__Transform__Sequence__init(&ros_message->transforms, size)) {
      fprintf(stderr, "failed to create array for field 'transforms'");
      return false;
    }
    auto array_ptr = ros_message->transforms.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Transform(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: velocities
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

    if (ros_message->velocities.data) {
      geometry_msgs__msg__Twist__Sequence__fini(&ros_message->velocities);
    }
    if (!geometry_msgs__msg__Twist__Sequence__init(&ros_message->velocities, size)) {
      fprintf(stderr, "failed to create array for field 'velocities'");
      return false;
    }
    auto array_ptr = ros_message->velocities.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Twist(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: accelerations
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

    if (ros_message->accelerations.data) {
      geometry_msgs__msg__Twist__Sequence__fini(&ros_message->accelerations);
    }
    if (!geometry_msgs__msg__Twist__Sequence__init(&ros_message->accelerations, size)) {
      fprintf(stderr, "failed to create array for field 'accelerations'");
      return false;
    }
    auto array_ptr = ros_message->accelerations.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Twist(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: time_from_start
  {
    impl_cdr_deserialize_with_endpoint_builtin_interfaces__msg__Duration(cdr, &ros_message->time_from_start, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TRAJECTORY_MSGS__MSG__DETAIL__MULTI_DOF_JOINT_TRAJECTORY_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
