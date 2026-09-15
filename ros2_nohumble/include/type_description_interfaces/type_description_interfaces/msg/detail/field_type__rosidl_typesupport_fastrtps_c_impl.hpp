// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from type_description_interfaces:msg\FieldType.idl
// generated code does not contain a copyright notice

#ifndef TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__FIELD_TYPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__FIELD_TYPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "type_description_interfaces/msg/detail/field_type__struct.h"
#include "type_description_interfaces/msg/detail/field_type__functions.h"
#include "type_description_interfaces/msg/detail/field_type__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/string.h"  // nested_type_name
#include "rosidl_runtime_c/string_functions.h"  // nested_type_name

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _FieldType__ros_msg_type = type_description_interfaces__msg__FieldType;


inline
bool impl_cdr_serialize_type_description_interfaces__msg__FieldType(
  const type_description_interfaces__msg__FieldType * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type_id
  {
    cdr << ros_message->type_id;
  }

  // Field name: capacity
  {
    cdr << ros_message->capacity;
  }

  // Field name: string_capacity
  {
    cdr << ros_message->string_capacity;
  }

  // Field name: nested_type_name
  {
    const rosidl_runtime_c__String * str = &ros_message->nested_type_name;
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

  return true;
}

inline
bool impl_cdr_deserialize_type_description_interfaces__msg__FieldType(
  eprosima::fastcdr::Cdr & cdr,
  type_description_interfaces__msg__FieldType * ros_message)
{
  // Field name: type_id
  {
    cdr >> ros_message->type_id;
  }

  // Field name: capacity
  {
    cdr >> ros_message->capacity;
  }

  // Field name: string_capacity
  {
    cdr >> ros_message->string_capacity;
  }

  // Field name: nested_type_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->nested_type_name.data) {
      rosidl_runtime_c__String__init(&ros_message->nested_type_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->nested_type_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'nested_type_name'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_type_description_interfaces__msg__FieldType(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FieldType__ros_msg_type * ros_message = static_cast<const _FieldType__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type_id
  {
    size_t item_size = sizeof(ros_message->type_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: capacity
  {
    size_t item_size = sizeof(ros_message->capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_capacity
  {
    size_t item_size = sizeof(ros_message->string_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: nested_type_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->nested_type_name.size + 1);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_type_description_interfaces__msg__FieldType(
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

  // Field name: type_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: capacity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_capacity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: nested_type_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        255 +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = type_description_interfaces__msg__FieldType;
    is_plain =
      (
      offsetof(DataType, nested_type_name) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_type_description_interfaces__msg__FieldType(
  const type_description_interfaces__msg__FieldType * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: type_id
  {
    cdr << ros_message->type_id;
  }

  // Field name: capacity
  {
    cdr << ros_message->capacity;
  }

  // Field name: string_capacity
  {
    cdr << ros_message->string_capacity;
  }

  // Field name: nested_type_name
  {
    const rosidl_runtime_c__String * str = &ros_message->nested_type_name;
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

  return true;
}

inline
size_t impl_get_serialized_size_key_type_description_interfaces__msg__FieldType(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FieldType__ros_msg_type * ros_message = static_cast<const _FieldType__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: type_id
  {
    size_t item_size = sizeof(ros_message->type_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: capacity
  {
    size_t item_size = sizeof(ros_message->capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_capacity
  {
    size_t item_size = sizeof(ros_message->string_capacity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: nested_type_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->nested_type_name.size + 1);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_type_description_interfaces__msg__FieldType(
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
  // Field name: type_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: capacity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_capacity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: nested_type_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        255 +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = type_description_interfaces__msg__FieldType;
    is_plain =
      (
      offsetof(DataType, nested_type_name) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_type_description_interfaces__msg__FieldType(
  const type_description_interfaces__msg__FieldType * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: type_id
  {
    cdr << ros_message->type_id;
  }

  // Field name: capacity
  {
    cdr << ros_message->capacity;
  }

  // Field name: string_capacity
  {
    cdr << ros_message->string_capacity;
  }

  // Field name: nested_type_name
  {
    const rosidl_runtime_c__String * str = &ros_message->nested_type_name;
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

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_type_description_interfaces__msg__FieldType(
  eprosima::fastcdr::Cdr & cdr,
  type_description_interfaces__msg__FieldType * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: type_id
  {
    cdr >> ros_message->type_id;
  }

  // Field name: capacity
  {
    cdr >> ros_message->capacity;
  }

  // Field name: string_capacity
  {
    cdr >> ros_message->string_capacity;
  }

  // Field name: nested_type_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->nested_type_name.data) {
      rosidl_runtime_c__String__init(&ros_message->nested_type_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->nested_type_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'nested_type_name'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__FIELD_TYPE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
