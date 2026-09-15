// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from map_msgs:msg\ProjectedMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "map_msgs/msg/detail/projected_map__struct.h"
#include "map_msgs/msg/detail/projected_map__functions.h"
#include "map_msgs/msg/detail/projected_map__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "nav_msgs/msg/detail/occupancy_grid__functions.h"  // map

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "nav_msgs/msg/detail/occupancy_grid__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ProjectedMap__ros_msg_type = map_msgs__msg__ProjectedMap;


inline
bool impl_cdr_serialize_map_msgs__msg__ProjectedMap(
  const map_msgs__msg__ProjectedMap * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: map
  {
    impl_cdr_serialize_nav_msgs__msg__OccupancyGrid(
      &ros_message->map, cdr);
  }

  // Field name: min_z
  {
    cdr << ros_message->min_z;
  }

  // Field name: max_z
  {
    cdr << ros_message->max_z;
  }

  return true;
}

inline
bool impl_cdr_deserialize_map_msgs__msg__ProjectedMap(
  eprosima::fastcdr::Cdr & cdr,
  map_msgs__msg__ProjectedMap * ros_message)
{
  // Field name: map
  {
    impl_cdr_deserialize_nav_msgs__msg__OccupancyGrid(cdr, &ros_message->map);
  }

  // Field name: min_z
  {
    cdr >> ros_message->min_z;
  }

  // Field name: max_z
  {
    cdr >> ros_message->max_z;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_map_msgs__msg__ProjectedMap(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ProjectedMap__ros_msg_type * ros_message = static_cast<const _ProjectedMap__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: map
  current_alignment += impl_get_serialized_size_nav_msgs__msg__OccupancyGrid(
    &(ros_message->map), current_alignment);

  // Field name: min_z
  {
    size_t item_size = sizeof(ros_message->min_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_z
  {
    size_t item_size = sizeof(ros_message->max_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_map_msgs__msg__ProjectedMap(
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

  // Field name: map
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_nav_msgs__msg__OccupancyGrid(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: min_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: max_z
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
    using DataType = map_msgs__msg__ProjectedMap;
    is_plain =
      (
      offsetof(DataType, max_z) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_map_msgs__msg__ProjectedMap(
  const map_msgs__msg__ProjectedMap * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: map
  {
    impl_cdr_serialize_key_nav_msgs__msg__OccupancyGrid(
      &ros_message->map, cdr);
  }

  // Field name: min_z
  {
    cdr << ros_message->min_z;
  }

  // Field name: max_z
  {
    cdr << ros_message->max_z;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_map_msgs__msg__ProjectedMap(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ProjectedMap__ros_msg_type * ros_message = static_cast<const _ProjectedMap__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: map
  current_alignment += impl_get_serialized_size_key_nav_msgs__msg__OccupancyGrid(
    &(ros_message->map), current_alignment);

  // Field name: min_z
  {
    size_t item_size = sizeof(ros_message->min_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_z
  {
    size_t item_size = sizeof(ros_message->max_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_map_msgs__msg__ProjectedMap(
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
  // Field name: map
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_nav_msgs__msg__OccupancyGrid(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: min_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: max_z
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
    using DataType = map_msgs__msg__ProjectedMap;
    is_plain =
      (
      offsetof(DataType, max_z) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_map_msgs__msg__ProjectedMap(
  const map_msgs__msg__ProjectedMap * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: map
  {
    impl_cdr_serialize_with_endpoint_nav_msgs__msg__OccupancyGrid(
      &ros_message->map, cdr, endpoint_info, serialization_context);
  }

  // Field name: min_z
  {
    cdr << ros_message->min_z;
  }

  // Field name: max_z
  {
    cdr << ros_message->max_z;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_map_msgs__msg__ProjectedMap(
  eprosima::fastcdr::Cdr & cdr,
  map_msgs__msg__ProjectedMap * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: map
  {
    impl_cdr_deserialize_with_endpoint_nav_msgs__msg__OccupancyGrid(cdr, &ros_message->map, endpoint_info, serialization_context);
  }

  // Field name: min_z
  {
    cdr >> ros_message->min_z;
  }

  // Field name: max_z
  {
    cdr >> ros_message->max_z;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
