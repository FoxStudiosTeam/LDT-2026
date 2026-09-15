// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rcl_interfaces:msg\ParameterEventDescriptors.idl
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__DETAIL__PARAMETER_EVENT_DESCRIPTORS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define RCL_INTERFACES__MSG__DETAIL__PARAMETER_EVENT_DESCRIPTORS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rcl_interfaces/msg/detail/parameter_event_descriptors__struct.h"
#include "rcl_interfaces/msg/detail/parameter_event_descriptors__functions.h"
#include "rcl_interfaces/msg/detail/parameter_event_descriptors__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rcl_interfaces/msg/detail/parameter_descriptor__functions.h"  // changed_parameters, deleted_parameters, new_parameters

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rcl_interfaces/msg/detail/parameter_descriptor__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ParameterEventDescriptors__ros_msg_type = rcl_interfaces__msg__ParameterEventDescriptors;


inline
bool impl_cdr_serialize_rcl_interfaces__msg__ParameterEventDescriptors(
  const rcl_interfaces__msg__ParameterEventDescriptors * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: new_parameters
  {
    size_t size = ros_message->new_parameters.size;
    auto array_ptr = ros_message->new_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  // Field name: changed_parameters
  {
    size_t size = ros_message->changed_parameters.size;
    auto array_ptr = ros_message->changed_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  // Field name: deleted_parameters
  {
    size_t size = ros_message->deleted_parameters.size;
    auto array_ptr = ros_message->deleted_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_rcl_interfaces__msg__ParameterEventDescriptors(
  eprosima::fastcdr::Cdr & cdr,
  rcl_interfaces__msg__ParameterEventDescriptors * ros_message)
{
  // Field name: new_parameters
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

    if (ros_message->new_parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->new_parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->new_parameters, size)) {
      fprintf(stderr, "failed to create array for field 'new_parameters'");
      return false;
    }
    auto array_ptr = ros_message->new_parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i]);
    }
  }

  // Field name: changed_parameters
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

    if (ros_message->changed_parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->changed_parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->changed_parameters, size)) {
      fprintf(stderr, "failed to create array for field 'changed_parameters'");
      return false;
    }
    auto array_ptr = ros_message->changed_parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i]);
    }
  }

  // Field name: deleted_parameters
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

    if (ros_message->deleted_parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->deleted_parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->deleted_parameters, size)) {
      fprintf(stderr, "failed to create array for field 'deleted_parameters'");
      return false;
    }
    auto array_ptr = ros_message->deleted_parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rcl_interfaces__msg__ParameterEventDescriptors(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ParameterEventDescriptors__ros_msg_type * ros_message = static_cast<const _ParameterEventDescriptors__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: new_parameters
  {
    size_t array_size = ros_message->new_parameters.size;
    auto array_ptr = ros_message->new_parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: changed_parameters
  {
    size_t array_size = ros_message->changed_parameters.size;
    auto array_ptr = ros_message->changed_parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: deleted_parameters
  {
    size_t array_size = ros_message->deleted_parameters.size;
    auto array_ptr = ros_message->deleted_parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rcl_interfaces__msg__ParameterEventDescriptors(
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

  // Field name: new_parameters
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
        impl_max_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: changed_parameters
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
        impl_max_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: deleted_parameters
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
        impl_max_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
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
    using DataType = rcl_interfaces__msg__ParameterEventDescriptors;
    is_plain =
      (
      offsetof(DataType, deleted_parameters) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rcl_interfaces__msg__ParameterEventDescriptors(
  const rcl_interfaces__msg__ParameterEventDescriptors * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: new_parameters
  {
    size_t size = ros_message->new_parameters.size;
    auto array_ptr = ros_message->new_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  // Field name: changed_parameters
  {
    size_t size = ros_message->changed_parameters.size;
    auto array_ptr = ros_message->changed_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  // Field name: deleted_parameters
  {
    size_t size = ros_message->deleted_parameters.size;
    auto array_ptr = ros_message->deleted_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rcl_interfaces__msg__ParameterEventDescriptors(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ParameterEventDescriptors__ros_msg_type * ros_message = static_cast<const _ParameterEventDescriptors__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: new_parameters
  {
    size_t array_size = ros_message->new_parameters.size;
    auto array_ptr = ros_message->new_parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: changed_parameters
  {
    size_t array_size = ros_message->changed_parameters.size;
    auto array_ptr = ros_message->changed_parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: deleted_parameters
  {
    size_t array_size = ros_message->deleted_parameters.size;
    auto array_ptr = ros_message->deleted_parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rcl_interfaces__msg__ParameterEventDescriptors(
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
  // Field name: new_parameters
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
        impl_max_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: changed_parameters
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
        impl_max_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: deleted_parameters
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
        impl_max_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
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
    using DataType = rcl_interfaces__msg__ParameterEventDescriptors;
    is_plain =
      (
      offsetof(DataType, deleted_parameters) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterEventDescriptors(
  const rcl_interfaces__msg__ParameterEventDescriptors * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: new_parameters
  {
    size_t size = ros_message->new_parameters.size;
    auto array_ptr = ros_message->new_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: changed_parameters
  {
    size_t size = ros_message->changed_parameters.size;
    auto array_ptr = ros_message->changed_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: deleted_parameters
  {
    size_t size = ros_message->deleted_parameters.size;
    auto array_ptr = ros_message->deleted_parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterEventDescriptors(
  eprosima::fastcdr::Cdr & cdr,
  rcl_interfaces__msg__ParameterEventDescriptors * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: new_parameters
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

    if (ros_message->new_parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->new_parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->new_parameters, size)) {
      fprintf(stderr, "failed to create array for field 'new_parameters'");
      return false;
    }
    auto array_ptr = ros_message->new_parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: changed_parameters
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

    if (ros_message->changed_parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->changed_parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->changed_parameters, size)) {
      fprintf(stderr, "failed to create array for field 'changed_parameters'");
      return false;
    }
    auto array_ptr = ros_message->changed_parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: deleted_parameters
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

    if (ros_message->deleted_parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->deleted_parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->deleted_parameters, size)) {
      fprintf(stderr, "failed to create array for field 'deleted_parameters'");
      return false;
    }
    auto array_ptr = ros_message->deleted_parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // RCL_INTERFACES__MSG__DETAIL__PARAMETER_EVENT_DESCRIPTORS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
