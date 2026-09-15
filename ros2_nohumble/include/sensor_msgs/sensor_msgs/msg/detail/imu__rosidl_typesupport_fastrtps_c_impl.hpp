// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from sensor_msgs:msg\Imu.idl
// generated code does not contain a copyright notice

#ifndef SENSOR_MSGS__MSG__DETAIL__IMU__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define SENSOR_MSGS__MSG__DETAIL__IMU__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "sensor_msgs/msg/detail/imu__struct.h"
#include "sensor_msgs/msg/detail/imu__functions.h"
#include "sensor_msgs/msg/detail/imu__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "geometry_msgs/msg/detail/quaternion__functions.h"  // orientation
#include "geometry_msgs/msg/detail/vector3__functions.h"  // angular_velocity, linear_acceleration
#include "std_msgs/msg/detail/header__functions.h"  // header

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "std_msgs/msg/detail/header__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Imu__ros_msg_type = sensor_msgs__msg__Imu;


inline
bool impl_cdr_serialize_sensor_msgs__msg__Imu(
  const sensor_msgs__msg__Imu * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: orientation
  {
    impl_cdr_serialize_geometry_msgs__msg__Quaternion(
      &ros_message->orientation, cdr);
  }

  // Field name: orientation_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    impl_cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->angular_velocity, cdr);
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: linear_acceleration
  {
    impl_cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->linear_acceleration, cdr);
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_sensor_msgs__msg__Imu(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__Imu * ros_message)
{
  // Field name: header
  {
    impl_cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: orientation
  {
    impl_cdr_deserialize_geometry_msgs__msg__Quaternion(cdr, &ros_message->orientation);
  }

  // Field name: orientation_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    impl_cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->angular_velocity);
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: linear_acceleration
  {
    impl_cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->linear_acceleration);
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_sensor_msgs__msg__Imu(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Imu__ros_msg_type * ros_message = static_cast<const _Imu__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: orientation
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Quaternion(
    &(ros_message->orientation), current_alignment);

  // Field name: orientation_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: angular_velocity
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->angular_velocity), current_alignment);

  // Field name: angular_velocity_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: linear_acceleration
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->linear_acceleration), current_alignment);

  // Field name: linear_acceleration_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_sensor_msgs__msg__Imu(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: orientation
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__Quaternion(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: orientation_covariance
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: angular_velocity
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: angular_velocity_covariance
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: linear_acceleration
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: linear_acceleration_covariance
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = sensor_msgs__msg__Imu;
    is_plain =
      (
      offsetof(DataType, linear_acceleration_covariance) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_sensor_msgs__msg__Imu(
  const sensor_msgs__msg__Imu * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: orientation
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Quaternion(
      &ros_message->orientation, cdr);
  }

  // Field name: orientation_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->angular_velocity, cdr);
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: linear_acceleration
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->linear_acceleration, cdr);
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_sensor_msgs__msg__Imu(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Imu__ros_msg_type * ros_message = static_cast<const _Imu__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: orientation
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Quaternion(
    &(ros_message->orientation), current_alignment);

  // Field name: orientation_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: angular_velocity
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->angular_velocity), current_alignment);

  // Field name: angular_velocity_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: linear_acceleration
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->linear_acceleration), current_alignment);

  // Field name: linear_acceleration_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_sensor_msgs__msg__Imu(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: orientation
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__Quaternion(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: orientation_covariance
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: angular_velocity
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: angular_velocity_covariance
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: linear_acceleration
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: linear_acceleration_covariance
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = sensor_msgs__msg__Imu;
    is_plain =
      (
      offsetof(DataType, linear_acceleration_covariance) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_sensor_msgs__msg__Imu(
  const sensor_msgs__msg__Imu * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: header
  {
    impl_cdr_serialize_with_endpoint_std_msgs__msg__Header(
      &ros_message->header, cdr, endpoint_info, serialization_context);
  }

  // Field name: orientation
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Quaternion(
      &ros_message->orientation, cdr, endpoint_info, serialization_context);
  }

  // Field name: orientation_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Vector3(
      &ros_message->angular_velocity, cdr, endpoint_info, serialization_context);
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: linear_acceleration
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Vector3(
      &ros_message->linear_acceleration, cdr, endpoint_info, serialization_context);
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_sensor_msgs__msg__Imu(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__Imu * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: header
  {
    impl_cdr_deserialize_with_endpoint_std_msgs__msg__Header(cdr, &ros_message->header, endpoint_info, serialization_context);
  }

  // Field name: orientation
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Quaternion(cdr, &ros_message->orientation, endpoint_info, serialization_context);
  }

  // Field name: orientation_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->orientation_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: angular_velocity
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Vector3(cdr, &ros_message->angular_velocity, endpoint_info, serialization_context);
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: linear_acceleration
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Vector3(cdr, &ros_message->linear_acceleration, endpoint_info, serialization_context);
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // SENSOR_MSGS__MSG__DETAIL__IMU__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
