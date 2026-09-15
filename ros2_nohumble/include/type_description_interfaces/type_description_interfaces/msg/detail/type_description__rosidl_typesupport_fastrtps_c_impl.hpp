// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from type_description_interfaces:msg\TypeDescription.idl
// generated code does not contain a copyright notice

#ifndef TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "type_description_interfaces/msg/detail/type_description__struct.h"
#include "type_description_interfaces/msg/detail/type_description__functions.h"
#include "type_description_interfaces/msg/detail/type_description__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "type_description_interfaces/msg/detail/individual_type_description__functions.h"  // referenced_type_descriptions, type_description

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "type_description_interfaces/msg/detail/individual_type_description__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _TypeDescription__ros_msg_type = type_description_interfaces__msg__TypeDescription;


inline
bool impl_cdr_serialize_type_description_interfaces__msg__TypeDescription(
  const type_description_interfaces__msg__TypeDescription * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type_description
  {
    impl_cdr_serialize_type_description_interfaces__msg__IndividualTypeDescription(
      &ros_message->type_description, cdr);
  }

  // Field name: referenced_type_descriptions
  {
    size_t size = ros_message->referenced_type_descriptions.size;
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_type_description_interfaces__msg__IndividualTypeDescription(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_type_description_interfaces__msg__TypeDescription(
  eprosima::fastcdr::Cdr & cdr,
  type_description_interfaces__msg__TypeDescription * ros_message)
{
  // Field name: type_description
  {
    impl_cdr_deserialize_type_description_interfaces__msg__IndividualTypeDescription(cdr, &ros_message->type_description);
  }

  // Field name: referenced_type_descriptions
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

    if (ros_message->referenced_type_descriptions.data) {
      type_description_interfaces__msg__IndividualTypeDescription__Sequence__fini(&ros_message->referenced_type_descriptions);
    }
    if (!type_description_interfaces__msg__IndividualTypeDescription__Sequence__init(&ros_message->referenced_type_descriptions, size)) {
      fprintf(stderr, "failed to create array for field 'referenced_type_descriptions'");
      return false;
    }
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_type_description_interfaces__msg__IndividualTypeDescription(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_type_description_interfaces__msg__TypeDescription(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TypeDescription__ros_msg_type * ros_message = static_cast<const _TypeDescription__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type_description
  current_alignment += impl_get_serialized_size_type_description_interfaces__msg__IndividualTypeDescription(
    &(ros_message->type_description), current_alignment);

  // Field name: referenced_type_descriptions
  {
    size_t array_size = ros_message->referenced_type_descriptions.size;
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_type_description_interfaces__msg__IndividualTypeDescription(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_type_description_interfaces__msg__TypeDescription(
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

  // Field name: type_description
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_type_description_interfaces__msg__IndividualTypeDescription(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: referenced_type_descriptions
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
        impl_max_serialized_size_type_description_interfaces__msg__IndividualTypeDescription(
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
    using DataType = type_description_interfaces__msg__TypeDescription;
    is_plain =
      (
      offsetof(DataType, referenced_type_descriptions) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_type_description_interfaces__msg__TypeDescription(
  const type_description_interfaces__msg__TypeDescription * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type_description
  {
    impl_cdr_serialize_key_type_description_interfaces__msg__IndividualTypeDescription(
      &ros_message->type_description, cdr);
  }

  // Field name: referenced_type_descriptions
  {
    size_t size = ros_message->referenced_type_descriptions.size;
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_type_description_interfaces__msg__IndividualTypeDescription(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_type_description_interfaces__msg__TypeDescription(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TypeDescription__ros_msg_type * ros_message = static_cast<const _TypeDescription__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type_description
  current_alignment += impl_get_serialized_size_key_type_description_interfaces__msg__IndividualTypeDescription(
    &(ros_message->type_description), current_alignment);

  // Field name: referenced_type_descriptions
  {
    size_t array_size = ros_message->referenced_type_descriptions.size;
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_type_description_interfaces__msg__IndividualTypeDescription(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_type_description_interfaces__msg__TypeDescription(
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
  // Field name: type_description
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_type_description_interfaces__msg__IndividualTypeDescription(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: referenced_type_descriptions
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
        impl_max_serialized_size_key_type_description_interfaces__msg__IndividualTypeDescription(
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
    using DataType = type_description_interfaces__msg__TypeDescription;
    is_plain =
      (
      offsetof(DataType, referenced_type_descriptions) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_type_description_interfaces__msg__TypeDescription(
  const type_description_interfaces__msg__TypeDescription * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: type_description
  {
    impl_cdr_serialize_with_endpoint_type_description_interfaces__msg__IndividualTypeDescription(
      &ros_message->type_description, cdr, endpoint_info, serialization_context);
  }

  // Field name: referenced_type_descriptions
  {
    size_t size = ros_message->referenced_type_descriptions.size;
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_type_description_interfaces__msg__IndividualTypeDescription(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_type_description_interfaces__msg__TypeDescription(
  eprosima::fastcdr::Cdr & cdr,
  type_description_interfaces__msg__TypeDescription * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: type_description
  {
    impl_cdr_deserialize_with_endpoint_type_description_interfaces__msg__IndividualTypeDescription(cdr, &ros_message->type_description, endpoint_info, serialization_context);
  }

  // Field name: referenced_type_descriptions
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

    if (ros_message->referenced_type_descriptions.data) {
      type_description_interfaces__msg__IndividualTypeDescription__Sequence__fini(&ros_message->referenced_type_descriptions);
    }
    if (!type_description_interfaces__msg__IndividualTypeDescription__Sequence__init(&ros_message->referenced_type_descriptions, size)) {
      fprintf(stderr, "failed to create array for field 'referenced_type_descriptions'");
      return false;
    }
    auto array_ptr = ros_message->referenced_type_descriptions.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_type_description_interfaces__msg__IndividualTypeDescription(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
