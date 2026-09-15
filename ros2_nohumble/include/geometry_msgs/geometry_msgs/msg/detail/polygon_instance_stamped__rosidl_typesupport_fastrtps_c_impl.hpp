// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from geometry_msgs:msg\PolygonInstanceStamped.idl
// generated code does not contain a copyright notice

#ifndef GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "geometry_msgs/msg/detail/polygon_instance_stamped__struct.h"
#include "geometry_msgs/msg/detail/polygon_instance_stamped__functions.h"
#include "geometry_msgs/msg/detail/polygon_instance_stamped__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "geometry_msgs/msg/detail/polygon_instance__functions.h"  // polygon
#include "std_msgs/msg/detail/header__functions.h"  // header

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "std_msgs/msg/detail/header__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "geometry_msgs/msg/detail/polygon_instance__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _PolygonInstanceStamped__ros_msg_type = geometry_msgs__msg__PolygonInstanceStamped;


inline
bool impl_cdr_serialize_geometry_msgs__msg__PolygonInstanceStamped(
  const geometry_msgs__msg__PolygonInstanceStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: polygon
  {
    impl_cdr_serialize_geometry_msgs__msg__PolygonInstance(
      &ros_message->polygon, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_geometry_msgs__msg__PolygonInstanceStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PolygonInstanceStamped * ros_message)
{
  // Field name: header
  {
    impl_cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: polygon
  {
    impl_cdr_deserialize_geometry_msgs__msg__PolygonInstance(cdr, &ros_message->polygon);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_geometry_msgs__msg__PolygonInstanceStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PolygonInstanceStamped__ros_msg_type * ros_message = static_cast<const _PolygonInstanceStamped__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: polygon
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__PolygonInstance(
    &(ros_message->polygon), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_geometry_msgs__msg__PolygonInstanceStamped(
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

  // Field name: polygon
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__PolygonInstance(
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
    using DataType = geometry_msgs__msg__PolygonInstanceStamped;
    is_plain =
      (
      offsetof(DataType, polygon) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_geometry_msgs__msg__PolygonInstanceStamped(
  const geometry_msgs__msg__PolygonInstanceStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: polygon
  {
    impl_cdr_serialize_key_geometry_msgs__msg__PolygonInstance(
      &ros_message->polygon, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_geometry_msgs__msg__PolygonInstanceStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PolygonInstanceStamped__ros_msg_type * ros_message = static_cast<const _PolygonInstanceStamped__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: polygon
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__PolygonInstance(
    &(ros_message->polygon), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_geometry_msgs__msg__PolygonInstanceStamped(
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

  // Field name: polygon
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__PolygonInstance(
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
    using DataType = geometry_msgs__msg__PolygonInstanceStamped;
    is_plain =
      (
      offsetof(DataType, polygon) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_geometry_msgs__msg__PolygonInstanceStamped(
  const geometry_msgs__msg__PolygonInstanceStamped * ros_message,
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

  // Field name: polygon
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__PolygonInstance(
      &ros_message->polygon, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__PolygonInstanceStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PolygonInstanceStamped * ros_message,
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

  // Field name: polygon
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__PolygonInstance(cdr, &ros_message->polygon, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
