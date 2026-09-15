// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rcl_interfaces:msg\ParameterDescriptor.idl
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__DETAIL__PARAMETER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define RCL_INTERFACES__MSG__DETAIL__PARAMETER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rcl_interfaces/msg/detail/parameter_descriptor__struct.h"
#include "rcl_interfaces/msg/detail/parameter_descriptor__functions.h"
#include "rcl_interfaces/msg/detail/parameter_descriptor__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rcl_interfaces/msg/detail/floating_point_range__functions.h"  // floating_point_range
#include "rcl_interfaces/msg/detail/integer_range__functions.h"  // integer_range
#include "rosidl_runtime_c/string.h"  // additional_constraints, description, name
#include "rosidl_runtime_c/string_functions.h"  // additional_constraints, description, name

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rcl_interfaces/msg/detail/floating_point_range__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rcl_interfaces/msg/detail/integer_range__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ParameterDescriptor__ros_msg_type = rcl_interfaces__msg__ParameterDescriptor;


inline
bool impl_cdr_serialize_rcl_interfaces__msg__ParameterDescriptor(
  const rcl_interfaces__msg__ParameterDescriptor * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: description
  {
    const rosidl_runtime_c__String * str = &ros_message->description;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: additional_constraints
  {
    const rosidl_runtime_c__String * str = &ros_message->additional_constraints;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: read_only
  {
    cdr << (ros_message->read_only ? true : false);
  }

  // Field name: dynamic_typing
  {
    cdr << (ros_message->dynamic_typing ? true : false);
  }

  // Field name: floating_point_range
  {
    size_t size = ros_message->floating_point_range.size;
    auto array_ptr = ros_message->floating_point_range.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__FloatingPointRange(
        &array_ptr[i], cdr);
    }
  }

  // Field name: integer_range
  {
    size_t size = ros_message->integer_range.size;
    auto array_ptr = ros_message->integer_range.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__IntegerRange(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_rcl_interfaces__msg__ParameterDescriptor(
  eprosima::fastcdr::Cdr & cdr,
  rcl_interfaces__msg__ParameterDescriptor * ros_message)
{
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: description
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->description.data) {
      rosidl_runtime_c__String__init(&ros_message->description);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->description,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'description'\n");
      return false;
    }
  }

  // Field name: additional_constraints
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->additional_constraints.data) {
      rosidl_runtime_c__String__init(&ros_message->additional_constraints);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->additional_constraints,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'additional_constraints'\n");
      return false;
    }
  }

  // Field name: read_only
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->read_only = tmp ? true : false;
  }

  // Field name: dynamic_typing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->dynamic_typing = tmp ? true : false;
  }

  // Field name: floating_point_range
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

    if (ros_message->floating_point_range.data) {
      rcl_interfaces__msg__FloatingPointRange__Sequence__fini(&ros_message->floating_point_range);
    }
    if (!rcl_interfaces__msg__FloatingPointRange__Sequence__init(&ros_message->floating_point_range, size)) {
      fprintf(stderr, "failed to create array for field 'floating_point_range'");
      return false;
    }
    auto array_ptr = ros_message->floating_point_range.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__FloatingPointRange(cdr, &array_ptr[i]);
    }
  }

  // Field name: integer_range
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

    if (ros_message->integer_range.data) {
      rcl_interfaces__msg__IntegerRange__Sequence__fini(&ros_message->integer_range);
    }
    if (!rcl_interfaces__msg__IntegerRange__Sequence__init(&ros_message->integer_range, size)) {
      fprintf(stderr, "failed to create array for field 'integer_range'");
      return false;
    }
    auto array_ptr = ros_message->integer_range.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__IntegerRange(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ParameterDescriptor__ros_msg_type * ros_message = static_cast<const _ParameterDescriptor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: description
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->description.size + 1);

  // Field name: additional_constraints
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->additional_constraints.size + 1);

  // Field name: read_only
  {
    size_t item_size = sizeof(ros_message->read_only);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dynamic_typing
  {
    size_t item_size = sizeof(ros_message->dynamic_typing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: floating_point_range
  {
    size_t array_size = ros_message->floating_point_range.size;
    auto array_ptr = ros_message->floating_point_range.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__FloatingPointRange(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: integer_range
  {
    size_t array_size = ros_message->integer_range.size;
    auto array_ptr = ros_message->integer_range.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__IntegerRange(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
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

  // Field name: name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: description
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: additional_constraints
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: read_only
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: dynamic_typing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: floating_point_range
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rcl_interfaces__msg__FloatingPointRange(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: integer_range
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rcl_interfaces__msg__IntegerRange(
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
    using DataType = rcl_interfaces__msg__ParameterDescriptor;
    is_plain =
      (
      offsetof(DataType, integer_range) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rcl_interfaces__msg__ParameterDescriptor(
  const rcl_interfaces__msg__ParameterDescriptor * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: description
  {
    const rosidl_runtime_c__String * str = &ros_message->description;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: additional_constraints
  {
    const rosidl_runtime_c__String * str = &ros_message->additional_constraints;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: read_only
  {
    cdr << (ros_message->read_only ? true : false);
  }

  // Field name: dynamic_typing
  {
    cdr << (ros_message->dynamic_typing ? true : false);
  }

  // Field name: floating_point_range
  {
    size_t size = ros_message->floating_point_range.size;
    auto array_ptr = ros_message->floating_point_range.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__FloatingPointRange(
        &array_ptr[i], cdr);
    }
  }

  // Field name: integer_range
  {
    size_t size = ros_message->integer_range.size;
    auto array_ptr = ros_message->integer_range.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__IntegerRange(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ParameterDescriptor__ros_msg_type * ros_message = static_cast<const _ParameterDescriptor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: description
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->description.size + 1);

  // Field name: additional_constraints
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->additional_constraints.size + 1);

  // Field name: read_only
  {
    size_t item_size = sizeof(ros_message->read_only);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dynamic_typing
  {
    size_t item_size = sizeof(ros_message->dynamic_typing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: floating_point_range
  {
    size_t array_size = ros_message->floating_point_range.size;
    auto array_ptr = ros_message->floating_point_range.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__FloatingPointRange(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: integer_range
  {
    size_t array_size = ros_message->integer_range.size;
    auto array_ptr = ros_message->integer_range.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__IntegerRange(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
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
  // Field name: name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: description
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: additional_constraints
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: read_only
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: dynamic_typing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: floating_point_range
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rcl_interfaces__msg__FloatingPointRange(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: integer_range
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rcl_interfaces__msg__IntegerRange(
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
    using DataType = rcl_interfaces__msg__ParameterDescriptor;
    is_plain =
      (
      offsetof(DataType, integer_range) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(
  const rcl_interfaces__msg__ParameterDescriptor * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: description
  {
    const rosidl_runtime_c__String * str = &ros_message->description;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: additional_constraints
  {
    const rosidl_runtime_c__String * str = &ros_message->additional_constraints;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: read_only
  {
    cdr << (ros_message->read_only ? true : false);
  }

  // Field name: dynamic_typing
  {
    cdr << (ros_message->dynamic_typing ? true : false);
  }

  // Field name: floating_point_range
  {
    size_t size = ros_message->floating_point_range.size;
    auto array_ptr = ros_message->floating_point_range.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__FloatingPointRange(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: integer_range
  {
    size_t size = ros_message->integer_range.size;
    auto array_ptr = ros_message->integer_range.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__IntegerRange(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(
  eprosima::fastcdr::Cdr & cdr,
  rcl_interfaces__msg__ParameterDescriptor * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: description
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->description.data) {
      rosidl_runtime_c__String__init(&ros_message->description);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->description,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'description'\n");
      return false;
    }
  }

  // Field name: additional_constraints
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->additional_constraints.data) {
      rosidl_runtime_c__String__init(&ros_message->additional_constraints);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->additional_constraints,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'additional_constraints'\n");
      return false;
    }
  }

  // Field name: read_only
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->read_only = tmp ? true : false;
  }

  // Field name: dynamic_typing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->dynamic_typing = tmp ? true : false;
  }

  // Field name: floating_point_range
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

    if (ros_message->floating_point_range.data) {
      rcl_interfaces__msg__FloatingPointRange__Sequence__fini(&ros_message->floating_point_range);
    }
    if (!rcl_interfaces__msg__FloatingPointRange__Sequence__init(&ros_message->floating_point_range, size)) {
      fprintf(stderr, "failed to create array for field 'floating_point_range'");
      return false;
    }
    auto array_ptr = ros_message->floating_point_range.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__FloatingPointRange(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: integer_range
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

    if (ros_message->integer_range.data) {
      rcl_interfaces__msg__IntegerRange__Sequence__fini(&ros_message->integer_range);
    }
    if (!rcl_interfaces__msg__IntegerRange__Sequence__init(&ros_message->integer_range, size)) {
      fprintf(stderr, "failed to create array for field 'integer_range'");
      return false;
    }
    auto array_ptr = ros_message->integer_range.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__IntegerRange(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // RCL_INTERFACES__MSG__DETAIL__PARAMETER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
