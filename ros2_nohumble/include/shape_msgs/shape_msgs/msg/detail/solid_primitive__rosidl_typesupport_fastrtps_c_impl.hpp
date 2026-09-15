// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from shape_msgs:msg\SolidPrimitive.idl
// generated code does not contain a copyright notice

#ifndef SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "shape_msgs/msg/detail/solid_primitive__struct.h"
#include "shape_msgs/msg/detail/solid_primitive__functions.h"
#include "shape_msgs/msg/detail/solid_primitive__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "geometry_msgs/msg/detail/polygon__functions.h"  // polygon
#include "rosidl_runtime_c/primitives_sequence.h"  // dimensions
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // dimensions

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _SolidPrimitive__ros_msg_type = shape_msgs__msg__SolidPrimitive;


inline
bool impl_cdr_serialize_shape_msgs__msg__SolidPrimitive(
  const shape_msgs__msg__SolidPrimitive * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: dimensions
  {
    size_t size = ros_message->dimensions.size;
    auto array_ptr = ros_message->dimensions.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: polygon
  {
    impl_cdr_serialize_geometry_msgs__msg__Polygon(
      &ros_message->polygon, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_shape_msgs__msg__SolidPrimitive(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__SolidPrimitive * ros_message)
{
  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: dimensions
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

    if (ros_message->dimensions.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->dimensions);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->dimensions, size)) {
      fprintf(stderr, "failed to create array for field 'dimensions'");
      return false;
    }
    auto array_ptr = ros_message->dimensions.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: polygon
  {
    impl_cdr_deserialize_geometry_msgs__msg__Polygon(cdr, &ros_message->polygon);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_shape_msgs__msg__SolidPrimitive(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SolidPrimitive__ros_msg_type * ros_message = static_cast<const _SolidPrimitive__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dimensions
  {
    size_t array_size = ros_message->dimensions.size;
    auto array_ptr = ros_message->dimensions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: polygon
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Polygon(
    &(ros_message->polygon), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_shape_msgs__msg__SolidPrimitive(
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

  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: dimensions
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
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
        impl_max_serialized_size_geometry_msgs__msg__Polygon(
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
    using DataType = shape_msgs__msg__SolidPrimitive;
    is_plain =
      (
      offsetof(DataType, polygon) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_shape_msgs__msg__SolidPrimitive(
  const shape_msgs__msg__SolidPrimitive * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: dimensions
  {
    size_t size = ros_message->dimensions.size;
    auto array_ptr = ros_message->dimensions.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: polygon
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Polygon(
      &ros_message->polygon, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_shape_msgs__msg__SolidPrimitive(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SolidPrimitive__ros_msg_type * ros_message = static_cast<const _SolidPrimitive__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dimensions
  {
    size_t array_size = ros_message->dimensions.size;
    auto array_ptr = ros_message->dimensions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: polygon
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Polygon(
    &(ros_message->polygon), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_shape_msgs__msg__SolidPrimitive(
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
  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: dimensions
  {
    size_t array_size = 3;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
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
        impl_max_serialized_size_key_geometry_msgs__msg__Polygon(
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
    using DataType = shape_msgs__msg__SolidPrimitive;
    is_plain =
      (
      offsetof(DataType, polygon) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_shape_msgs__msg__SolidPrimitive(
  const shape_msgs__msg__SolidPrimitive * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: dimensions
  {
    size_t size = ros_message->dimensions.size;
    auto array_ptr = ros_message->dimensions.data;
    if (size > 3) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: polygon
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Polygon(
      &ros_message->polygon, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_shape_msgs__msg__SolidPrimitive(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__SolidPrimitive * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: dimensions
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

    if (ros_message->dimensions.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->dimensions);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->dimensions, size)) {
      fprintf(stderr, "failed to create array for field 'dimensions'");
      return false;
    }
    auto array_ptr = ros_message->dimensions.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: polygon
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Polygon(cdr, &ros_message->polygon, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // SHAPE_MSGS__MSG__DETAIL__SOLID_PRIMITIVE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
