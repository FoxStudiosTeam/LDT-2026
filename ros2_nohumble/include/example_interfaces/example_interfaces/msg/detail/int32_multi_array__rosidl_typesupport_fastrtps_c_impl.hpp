// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from example_interfaces:msg\Int32MultiArray.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_INTERFACES__MSG__DETAIL__INT32_MULTI_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define EXAMPLE_INTERFACES__MSG__DETAIL__INT32_MULTI_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "example_interfaces/msg/detail/int32_multi_array__struct.h"
#include "example_interfaces/msg/detail/int32_multi_array__functions.h"
#include "example_interfaces/msg/detail/int32_multi_array__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "example_interfaces/msg/detail/multi_array_layout__functions.h"  // layout
#include "rosidl_runtime_c/primitives_sequence.h"  // data
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "example_interfaces/msg/detail/multi_array_layout__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Int32MultiArray__ros_msg_type = example_interfaces__msg__Int32MultiArray;


inline
bool impl_cdr_serialize_example_interfaces__msg__Int32MultiArray(
  const example_interfaces__msg__Int32MultiArray * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: layout
  {
    impl_cdr_serialize_example_interfaces__msg__MultiArrayLayout(
      &ros_message->layout, cdr);
  }

  // Field name: data
  {
    size_t size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_example_interfaces__msg__Int32MultiArray(
  eprosima::fastcdr::Cdr & cdr,
  example_interfaces__msg__Int32MultiArray * ros_message)
{
  // Field name: layout
  {
    impl_cdr_deserialize_example_interfaces__msg__MultiArrayLayout(cdr, &ros_message->layout);
  }

  // Field name: data
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

    if (ros_message->data.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->data);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->data, size)) {
      fprintf(stderr, "failed to create array for field 'data'");
      return false;
    }
    auto array_ptr = ros_message->data.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_example_interfaces__msg__Int32MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Int32MultiArray__ros_msg_type * ros_message = static_cast<const _Int32MultiArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: layout
  current_alignment += impl_get_serialized_size_example_interfaces__msg__MultiArrayLayout(
    &(ros_message->layout), current_alignment);

  // Field name: data
  {
    size_t array_size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_example_interfaces__msg__Int32MultiArray(
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

  // Field name: layout
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_example_interfaces__msg__MultiArrayLayout(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = example_interfaces__msg__Int32MultiArray;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_example_interfaces__msg__Int32MultiArray(
  const example_interfaces__msg__Int32MultiArray * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: layout
  {
    impl_cdr_serialize_key_example_interfaces__msg__MultiArrayLayout(
      &ros_message->layout, cdr);
  }

  // Field name: data
  {
    size_t size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_example_interfaces__msg__Int32MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Int32MultiArray__ros_msg_type * ros_message = static_cast<const _Int32MultiArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: layout
  current_alignment += impl_get_serialized_size_key_example_interfaces__msg__MultiArrayLayout(
    &(ros_message->layout), current_alignment);

  // Field name: data
  {
    size_t array_size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_example_interfaces__msg__Int32MultiArray(
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
  // Field name: layout
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_example_interfaces__msg__MultiArrayLayout(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = example_interfaces__msg__Int32MultiArray;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_example_interfaces__msg__Int32MultiArray(
  const example_interfaces__msg__Int32MultiArray * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: layout
  {
    impl_cdr_serialize_with_endpoint_example_interfaces__msg__MultiArrayLayout(
      &ros_message->layout, cdr, endpoint_info, serialization_context);
  }

  // Field name: data
  {
    size_t size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_example_interfaces__msg__Int32MultiArray(
  eprosima::fastcdr::Cdr & cdr,
  example_interfaces__msg__Int32MultiArray * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: layout
  {
    impl_cdr_deserialize_with_endpoint_example_interfaces__msg__MultiArrayLayout(cdr, &ros_message->layout, endpoint_info, serialization_context);
  }

  // Field name: data
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

    if (ros_message->data.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->data);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->data, size)) {
      fprintf(stderr, "failed to create array for field 'data'");
      return false;
    }
    auto array_ptr = ros_message->data.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // EXAMPLE_INTERFACES__MSG__DETAIL__INT32_MULTI_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
