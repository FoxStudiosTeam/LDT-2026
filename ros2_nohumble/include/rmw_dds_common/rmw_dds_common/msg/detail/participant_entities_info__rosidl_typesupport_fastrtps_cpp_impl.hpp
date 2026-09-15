// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from rmw_dds_common:msg\ParticipantEntitiesInfo.idl
// generated code does not contain a copyright notice

#ifndef RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rmw_dds_common/msg/detail/participant_entities_info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rmw_dds_common/msg/detail/gid__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "rmw_dds_common/msg/detail/node_entities_info__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace rmw_dds_common
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
  const rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gid
  rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.gid,
    cdr);

  // Member: node_entities_info_seq
  {
    size_t size = ros_message.node_entities_info_seq.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.node_entities_info_seq[i],
        cdr);
    }
  }

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message)
{
  // Member: gid
  rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.gid);

  // Member: node_entities_info_seq
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

    ros_message.node_entities_info_seq.resize(size);
    for (size_t i = 0; i < size; i++) {
      rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.node_entities_info_seq[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: gid
    rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.gid,
      cdr, endpoint_info, serialization_context);
    // Member: node_entities_info_seq
    {
      size_t size = ros_message.node_entities_info_seq.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.node_entities_info_seq[i],
          cdr, endpoint_info, serialization_context);
      }
    }
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "rmw_dds_common.typesupport_fastrtps_cpp",
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
  rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: gid
  rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.gid,
    endpoint_info,
    serialization_context);

  // Member: node_entities_info_seq
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

    ros_message.node_entities_info_seq.resize(size);
    for (size_t i = 0; i < size; i++) {
      rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.node_entities_info_seq[i],
        endpoint_info,
        serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gid
  current_alignment +=
    rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.gid, current_alignment);

  // Member: node_entities_info_seq
  {
    size_t array_size = ros_message.node_entities_info_seq.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.node_entities_info_seq[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_ParticipantEntitiesInfo(
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

  // Member: gid
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Gid(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: node_entities_info_seq
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
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_NodeEntitiesInfo(
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
    using DataType = rmw_dds_common::msg::ParticipantEntitiesInfo;
    is_plain =
      (
      offsetof(DataType, node_entities_info_seq) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gid
  rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.gid,
    cdr);

  // Member: node_entities_info_seq
  {
    size_t size = ros_message.node_entities_info_seq.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.node_entities_info_seq[i],
        cdr);
    }
  }

  return true;
}

inline
size_t
get_serialized_size_key(
  const rmw_dds_common::msg::ParticipantEntitiesInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gid
  current_alignment +=
    rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.gid, current_alignment);

  // Member: node_entities_info_seq
  {
    size_t array_size = ros_message.node_entities_info_seq.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.node_entities_info_seq[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_ParticipantEntitiesInfo(
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

  // Member: gid
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Gid(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: node_entities_info_seq
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
        rmw_dds_common::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_NodeEntitiesInfo(
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
    using DataType = rmw_dds_common::msg::ParticipantEntitiesInfo;
    is_plain =
      (
      offsetof(DataType, node_entities_info_seq) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rmw_dds_common

#endif  // RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
