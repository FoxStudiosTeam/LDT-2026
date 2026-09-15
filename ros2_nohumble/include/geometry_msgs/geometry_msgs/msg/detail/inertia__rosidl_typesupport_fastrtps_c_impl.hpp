// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from geometry_msgs:msg\Inertia.idl
// generated code does not contain a copyright notice

#ifndef GEOMETRY_MSGS__MSG__DETAIL__INERTIA__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__INERTIA__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "geometry_msgs/msg/detail/inertia__struct.h"
#include "geometry_msgs/msg/detail/inertia__functions.h"
#include "geometry_msgs/msg/detail/inertia__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "geometry_msgs/msg/detail/vector3__functions.h"  // com

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Inertia__ros_msg_type = geometry_msgs__msg__Inertia;


inline
bool impl_cdr_serialize_geometry_msgs__msg__Inertia(
  const geometry_msgs__msg__Inertia * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: m
  {
    cdr << ros_message->m;
  }

  // Field name: com
  {
    impl_cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->com, cdr);
  }

  // Field name: ixx
  {
    cdr << ros_message->ixx;
  }

  // Field name: ixy
  {
    cdr << ros_message->ixy;
  }

  // Field name: ixz
  {
    cdr << ros_message->ixz;
  }

  // Field name: iyy
  {
    cdr << ros_message->iyy;
  }

  // Field name: iyz
  {
    cdr << ros_message->iyz;
  }

  // Field name: izz
  {
    cdr << ros_message->izz;
  }

  return true;
}

inline
bool impl_cdr_deserialize_geometry_msgs__msg__Inertia(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Inertia * ros_message)
{
  // Field name: m
  {
    cdr >> ros_message->m;
  }

  // Field name: com
  {
    impl_cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->com);
  }

  // Field name: ixx
  {
    cdr >> ros_message->ixx;
  }

  // Field name: ixy
  {
    cdr >> ros_message->ixy;
  }

  // Field name: ixz
  {
    cdr >> ros_message->ixz;
  }

  // Field name: iyy
  {
    cdr >> ros_message->iyy;
  }

  // Field name: iyz
  {
    cdr >> ros_message->iyz;
  }

  // Field name: izz
  {
    cdr >> ros_message->izz;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_geometry_msgs__msg__Inertia(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Inertia__ros_msg_type * ros_message = static_cast<const _Inertia__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: m
  {
    size_t item_size = sizeof(ros_message->m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: com
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->com), current_alignment);

  // Field name: ixx
  {
    size_t item_size = sizeof(ros_message->ixx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ixy
  {
    size_t item_size = sizeof(ros_message->ixy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ixz
  {
    size_t item_size = sizeof(ros_message->ixz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: iyy
  {
    size_t item_size = sizeof(ros_message->iyy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: iyz
  {
    size_t item_size = sizeof(ros_message->iyz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: izz
  {
    size_t item_size = sizeof(ros_message->izz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_geometry_msgs__msg__Inertia(
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

  // Field name: m
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: com
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

  // Field name: ixx
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ixy
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ixz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: iyy
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: iyz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: izz
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
    using DataType = geometry_msgs__msg__Inertia;
    is_plain =
      (
      offsetof(DataType, izz) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_geometry_msgs__msg__Inertia(
  const geometry_msgs__msg__Inertia * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: m
  {
    cdr << ros_message->m;
  }

  // Field name: com
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->com, cdr);
  }

  // Field name: ixx
  {
    cdr << ros_message->ixx;
  }

  // Field name: ixy
  {
    cdr << ros_message->ixy;
  }

  // Field name: ixz
  {
    cdr << ros_message->ixz;
  }

  // Field name: iyy
  {
    cdr << ros_message->iyy;
  }

  // Field name: iyz
  {
    cdr << ros_message->iyz;
  }

  // Field name: izz
  {
    cdr << ros_message->izz;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_geometry_msgs__msg__Inertia(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Inertia__ros_msg_type * ros_message = static_cast<const _Inertia__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: m
  {
    size_t item_size = sizeof(ros_message->m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: com
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->com), current_alignment);

  // Field name: ixx
  {
    size_t item_size = sizeof(ros_message->ixx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ixy
  {
    size_t item_size = sizeof(ros_message->ixy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ixz
  {
    size_t item_size = sizeof(ros_message->ixz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: iyy
  {
    size_t item_size = sizeof(ros_message->iyy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: iyz
  {
    size_t item_size = sizeof(ros_message->iyz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: izz
  {
    size_t item_size = sizeof(ros_message->izz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_geometry_msgs__msg__Inertia(
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
  // Field name: m
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: com
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

  // Field name: ixx
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ixy
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ixz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: iyy
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: iyz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: izz
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
    using DataType = geometry_msgs__msg__Inertia;
    is_plain =
      (
      offsetof(DataType, izz) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Inertia(
  const geometry_msgs__msg__Inertia * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: m
  {
    cdr << ros_message->m;
  }

  // Field name: com
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Vector3(
      &ros_message->com, cdr, endpoint_info, serialization_context);
  }

  // Field name: ixx
  {
    cdr << ros_message->ixx;
  }

  // Field name: ixy
  {
    cdr << ros_message->ixy;
  }

  // Field name: ixz
  {
    cdr << ros_message->ixz;
  }

  // Field name: iyy
  {
    cdr << ros_message->iyy;
  }

  // Field name: iyz
  {
    cdr << ros_message->iyz;
  }

  // Field name: izz
  {
    cdr << ros_message->izz;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Inertia(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Inertia * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: m
  {
    cdr >> ros_message->m;
  }

  // Field name: com
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Vector3(cdr, &ros_message->com, endpoint_info, serialization_context);
  }

  // Field name: ixx
  {
    cdr >> ros_message->ixx;
  }

  // Field name: ixy
  {
    cdr >> ros_message->ixy;
  }

  // Field name: ixz
  {
    cdr >> ros_message->ixz;
  }

  // Field name: iyy
  {
    cdr >> ros_message->iyy;
  }

  // Field name: iyz
  {
    cdr >> ros_message->iyz;
  }

  // Field name: izz
  {
    cdr >> ros_message->izz;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // GEOMETRY_MSGS__MSG__DETAIL__INERTIA__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
