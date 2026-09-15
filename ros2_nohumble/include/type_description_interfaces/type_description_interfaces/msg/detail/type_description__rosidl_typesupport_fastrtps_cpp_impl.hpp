// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from type_description_interfaces:msg\TypeDescription.idl
// generated code does not contain a copyright notice

#ifndef TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "type_description_interfaces/msg/detail/type_description__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "type_description_interfaces/msg/detail/individual_type_description__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "type_description_interfaces/msg/detail/individual_type_description__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace type_description_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

// Inline implementations of the (de)serialization family of functions.
// Kept separate from the public, exported wrappers (see the generated
// `..._type_support.cpp`) so that nested-message call sites elsewhere can
// `#include` this header and let the compiler fully inline the recursive
// (de)serialization logic instead of making an opaque cross-library call.
namespace detail
{


inline
bool
cdr_serialize(
  const type_description_interfaces::msg::TypeDescription & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: type_description
  type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.type_description,
    cdr);

  // Member: referenced_type_descriptions
  {
    size_t size = ros_message.referenced_type_descriptions.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.referenced_type_descriptions[i],
        cdr);
    }
  }

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  type_description_interfaces::msg::TypeDescription & ros_message)
{
  // Member: type_description
  type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.type_description);

  // Member: referenced_type_descriptions
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

    ros_message.referenced_type_descriptions.resize(size);
    for (size_t i = 0; i < size; i++) {
      type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.referenced_type_descriptions[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const type_description_interfaces::msg::TypeDescription & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: type_description
    type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.type_description,
      cdr, endpoint_info, serialization_context);
    // Member: referenced_type_descriptions
    {
      size_t size = ros_message.referenced_type_descriptions.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.referenced_type_descriptions[i],
          cdr, endpoint_info, serialization_context);
      }
    }
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "type_description_interfaces.typesupport_fastrtps_cpp",
      "cdr_serialize_with_endpoint failed: %s", e.what());
    return false;
  }
  return true;
}

// Endpoint-aware deserialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_deserialize_with_endpoint(
  eprosima::fastcdr::Cdr & cdr,
  type_description_interfaces::msg::TypeDescription & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: type_description
  type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.type_description,
    endpoint_info,
    serialization_context);

  // Member: referenced_type_descriptions
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

    ros_message.referenced_type_descriptions.resize(size);
    for (size_t i = 0; i < size; i++) {
      type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.referenced_type_descriptions[i],
        endpoint_info,
        serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const type_description_interfaces::msg::TypeDescription & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: type_description
  current_alignment +=
    type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.type_description, current_alignment);

  // Member: referenced_type_descriptions
  {
    size_t array_size = ros_message.referenced_type_descriptions.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.referenced_type_descriptions[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_TypeDescription(
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

  // Member: type_description
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_IndividualTypeDescription(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: referenced_type_descriptions
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
      size_t inner_size =
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_IndividualTypeDescription(
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
    using DataType = type_description_interfaces::msg::TypeDescription;
    is_plain =
      (
      offsetof(DataType, referenced_type_descriptions) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const type_description_interfaces::msg::TypeDescription & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: type_description
  type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.type_description,
    cdr);

  // Member: referenced_type_descriptions
  {
    size_t size = ros_message.referenced_type_descriptions.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.referenced_type_descriptions[i],
        cdr);
    }
  }

  return true;
}

inline
size_t
get_serialized_size_key(
  const type_description_interfaces::msg::TypeDescription & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: type_description
  current_alignment +=
    type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.type_description, current_alignment);

  // Member: referenced_type_descriptions
  {
    size_t array_size = ros_message.referenced_type_descriptions.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.referenced_type_descriptions[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_TypeDescription(
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

  // Member: type_description
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_IndividualTypeDescription(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: referenced_type_descriptions
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
      size_t inner_size =
        type_description_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_IndividualTypeDescription(
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
    using DataType = type_description_interfaces::msg::TypeDescription;
    is_plain =
      (
      offsetof(DataType, referenced_type_descriptions) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace type_description_interfaces

#endif  // TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
