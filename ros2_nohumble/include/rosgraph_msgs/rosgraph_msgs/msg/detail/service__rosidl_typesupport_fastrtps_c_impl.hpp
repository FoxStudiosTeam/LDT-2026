// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosgraph_msgs:msg\Service.idl
// generated code does not contain a copyright notice

#ifndef ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosgraph_msgs/msg/detail/service__struct.h"
#include "rosgraph_msgs/msg/detail/service__functions.h"
#include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosgraph_msgs/msg/detail/interface_type__functions.h"  // request_type, response_type
#include "rosgraph_msgs/msg/detail/qo_s_profile__functions.h"  // request_qos, response_qos
#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rosgraph_msgs/msg/detail/interface_type__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rosgraph_msgs/msg/detail/qo_s_profile__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Service__ros_msg_type = rosgraph_msgs__msg__Service;


inline
bool impl_cdr_serialize_rosgraph_msgs__msg__Service(
  const rosgraph_msgs__msg__Service * ros_message,
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

  // Field name: request_type
  {
    impl_cdr_serialize_rosgraph_msgs__msg__InterfaceType(
      &ros_message->request_type, cdr);
  }

  // Field name: request_qos
  {
    impl_cdr_serialize_rosgraph_msgs__msg__QoSProfile(
      &ros_message->request_qos, cdr);
  }

  // Field name: response_type
  {
    impl_cdr_serialize_rosgraph_msgs__msg__InterfaceType(
      &ros_message->response_type, cdr);
  }

  // Field name: response_qos
  {
    impl_cdr_serialize_rosgraph_msgs__msg__QoSProfile(
      &ros_message->response_qos, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosgraph_msgs__msg__Service(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs__msg__Service * ros_message)
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

  // Field name: request_type
  {
    impl_cdr_deserialize_rosgraph_msgs__msg__InterfaceType(cdr, &ros_message->request_type);
  }

  // Field name: request_qos
  {
    impl_cdr_deserialize_rosgraph_msgs__msg__QoSProfile(cdr, &ros_message->request_qos);
  }

  // Field name: response_type
  {
    impl_cdr_deserialize_rosgraph_msgs__msg__InterfaceType(cdr, &ros_message->response_type);
  }

  // Field name: response_qos
  {
    impl_cdr_deserialize_rosgraph_msgs__msg__QoSProfile(cdr, &ros_message->response_qos);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosgraph_msgs__msg__Service(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Service__ros_msg_type * ros_message = static_cast<const _Service__ros_msg_type *>(untyped_ros_message);
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

  // Field name: request_type
  current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__InterfaceType(
    &(ros_message->request_type), current_alignment);

  // Field name: request_qos
  current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__QoSProfile(
    &(ros_message->request_qos), current_alignment);

  // Field name: response_type
  current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__InterfaceType(
    &(ros_message->response_type), current_alignment);

  // Field name: response_qos
  current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__QoSProfile(
    &(ros_message->response_qos), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosgraph_msgs__msg__Service(
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

  // Field name: request_type
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosgraph_msgs__msg__InterfaceType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request_qos
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosgraph_msgs__msg__QoSProfile(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response_type
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosgraph_msgs__msg__InterfaceType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response_qos
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosgraph_msgs__msg__QoSProfile(
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
    using DataType = rosgraph_msgs__msg__Service;
    is_plain =
      (
      offsetof(DataType, response_qos) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosgraph_msgs__msg__Service(
  const rosgraph_msgs__msg__Service * ros_message,
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

  // Field name: request_type
  {
    impl_cdr_serialize_key_rosgraph_msgs__msg__InterfaceType(
      &ros_message->request_type, cdr);
  }

  // Field name: request_qos
  {
    impl_cdr_serialize_key_rosgraph_msgs__msg__QoSProfile(
      &ros_message->request_qos, cdr);
  }

  // Field name: response_type
  {
    impl_cdr_serialize_key_rosgraph_msgs__msg__InterfaceType(
      &ros_message->response_type, cdr);
  }

  // Field name: response_qos
  {
    impl_cdr_serialize_key_rosgraph_msgs__msg__QoSProfile(
      &ros_message->response_qos, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosgraph_msgs__msg__Service(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Service__ros_msg_type * ros_message = static_cast<const _Service__ros_msg_type *>(untyped_ros_message);
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

  // Field name: request_type
  current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__InterfaceType(
    &(ros_message->request_type), current_alignment);

  // Field name: request_qos
  current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__QoSProfile(
    &(ros_message->request_qos), current_alignment);

  // Field name: response_type
  current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__InterfaceType(
    &(ros_message->response_type), current_alignment);

  // Field name: response_qos
  current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__QoSProfile(
    &(ros_message->response_qos), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosgraph_msgs__msg__Service(
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

  // Field name: request_type
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosgraph_msgs__msg__InterfaceType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request_qos
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosgraph_msgs__msg__QoSProfile(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response_type
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosgraph_msgs__msg__InterfaceType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response_qos
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosgraph_msgs__msg__QoSProfile(
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
    using DataType = rosgraph_msgs__msg__Service;
    is_plain =
      (
      offsetof(DataType, response_qos) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Service(
  const rosgraph_msgs__msg__Service * ros_message,
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

  // Field name: request_type
  {
    impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__InterfaceType(
      &ros_message->request_type, cdr, endpoint_info, serialization_context);
  }

  // Field name: request_qos
  {
    impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__QoSProfile(
      &ros_message->request_qos, cdr, endpoint_info, serialization_context);
  }

  // Field name: response_type
  {
    impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__InterfaceType(
      &ros_message->response_type, cdr, endpoint_info, serialization_context);
  }

  // Field name: response_qos
  {
    impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__QoSProfile(
      &ros_message->response_qos, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Service(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs__msg__Service * ros_message,
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

  // Field name: request_type
  {
    impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__InterfaceType(cdr, &ros_message->request_type, endpoint_info, serialization_context);
  }

  // Field name: request_qos
  {
    impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__QoSProfile(cdr, &ros_message->request_qos, endpoint_info, serialization_context);
  }

  // Field name: response_type
  {
    impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__InterfaceType(cdr, &ros_message->response_type, endpoint_info, serialization_context);
  }

  // Field name: response_qos
  {
    impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__QoSProfile(cdr, &ros_message->response_qos, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
