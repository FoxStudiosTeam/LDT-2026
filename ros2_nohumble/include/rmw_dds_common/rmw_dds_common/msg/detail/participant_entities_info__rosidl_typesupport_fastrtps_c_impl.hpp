// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rmw_dds_common:msg\ParticipantEntitiesInfo.idl
// generated code does not contain a copyright notice

#ifndef RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rmw_dds_common/msg/detail/participant_entities_info__struct.h"
#include "rmw_dds_common/msg/detail/participant_entities_info__functions.h"
#include "rmw_dds_common/msg/detail/participant_entities_info__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rmw_dds_common/msg/detail/gid__functions.h"  // gid
#include "rmw_dds_common/msg/detail/node_entities_info__functions.h"  // node_entities_info_seq

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rmw_dds_common/msg/detail/gid__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rmw_dds_common/msg/detail/node_entities_info__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ParticipantEntitiesInfo__ros_msg_type = rmw_dds_common__msg__ParticipantEntitiesInfo;


inline
bool impl_cdr_serialize_rmw_dds_common__msg__ParticipantEntitiesInfo(
  const rmw_dds_common__msg__ParticipantEntitiesInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gid
  {
    impl_cdr_serialize_rmw_dds_common__msg__Gid(
      &ros_message->gid, cdr);
  }

  // Field name: node_entities_info_seq
  {
    size_t size = ros_message->node_entities_info_seq.size;
    auto array_ptr = ros_message->node_entities_info_seq.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rmw_dds_common__msg__NodeEntitiesInfo(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_rmw_dds_common__msg__ParticipantEntitiesInfo(
  eprosima::fastcdr::Cdr & cdr,
  rmw_dds_common__msg__ParticipantEntitiesInfo * ros_message)
{
  // Field name: gid
  {
    impl_cdr_deserialize_rmw_dds_common__msg__Gid(cdr, &ros_message->gid);
  }

  // Field name: node_entities_info_seq
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

    if (ros_message->node_entities_info_seq.data) {
      rmw_dds_common__msg__NodeEntitiesInfo__Sequence__fini(&ros_message->node_entities_info_seq);
    }
    if (!rmw_dds_common__msg__NodeEntitiesInfo__Sequence__init(&ros_message->node_entities_info_seq, size)) {
      fprintf(stderr, "failed to create array for field 'node_entities_info_seq'");
      return false;
    }
    auto array_ptr = ros_message->node_entities_info_seq.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rmw_dds_common__msg__NodeEntitiesInfo(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rmw_dds_common__msg__ParticipantEntitiesInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ParticipantEntitiesInfo__ros_msg_type * ros_message = static_cast<const _ParticipantEntitiesInfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gid
  current_alignment += impl_get_serialized_size_rmw_dds_common__msg__Gid(
    &(ros_message->gid), current_alignment);

  // Field name: node_entities_info_seq
  {
    size_t array_size = ros_message->node_entities_info_seq.size;
    auto array_ptr = ros_message->node_entities_info_seq.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rmw_dds_common__msg__NodeEntitiesInfo(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rmw_dds_common__msg__ParticipantEntitiesInfo(
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

  // Field name: gid
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rmw_dds_common__msg__Gid(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: node_entities_info_seq
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
        impl_max_serialized_size_rmw_dds_common__msg__NodeEntitiesInfo(
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
    using DataType = rmw_dds_common__msg__ParticipantEntitiesInfo;
    is_plain =
      (
      offsetof(DataType, node_entities_info_seq) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rmw_dds_common__msg__ParticipantEntitiesInfo(
  const rmw_dds_common__msg__ParticipantEntitiesInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: gid
  {
    impl_cdr_serialize_key_rmw_dds_common__msg__Gid(
      &ros_message->gid, cdr);
  }

  // Field name: node_entities_info_seq
  {
    size_t size = ros_message->node_entities_info_seq.size;
    auto array_ptr = ros_message->node_entities_info_seq.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rmw_dds_common__msg__NodeEntitiesInfo(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rmw_dds_common__msg__ParticipantEntitiesInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ParticipantEntitiesInfo__ros_msg_type * ros_message = static_cast<const _ParticipantEntitiesInfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: gid
  current_alignment += impl_get_serialized_size_key_rmw_dds_common__msg__Gid(
    &(ros_message->gid), current_alignment);

  // Field name: node_entities_info_seq
  {
    size_t array_size = ros_message->node_entities_info_seq.size;
    auto array_ptr = ros_message->node_entities_info_seq.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rmw_dds_common__msg__NodeEntitiesInfo(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rmw_dds_common__msg__ParticipantEntitiesInfo(
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
  // Field name: gid
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rmw_dds_common__msg__Gid(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: node_entities_info_seq
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
        impl_max_serialized_size_key_rmw_dds_common__msg__NodeEntitiesInfo(
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
    using DataType = rmw_dds_common__msg__ParticipantEntitiesInfo;
    is_plain =
      (
      offsetof(DataType, node_entities_info_seq) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rmw_dds_common__msg__ParticipantEntitiesInfo(
  const rmw_dds_common__msg__ParticipantEntitiesInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: gid
  {
    impl_cdr_serialize_with_endpoint_rmw_dds_common__msg__Gid(
      &ros_message->gid, cdr, endpoint_info, serialization_context);
  }

  // Field name: node_entities_info_seq
  {
    size_t size = ros_message->node_entities_info_seq.size;
    auto array_ptr = ros_message->node_entities_info_seq.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rmw_dds_common__msg__NodeEntitiesInfo(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rmw_dds_common__msg__ParticipantEntitiesInfo(
  eprosima::fastcdr::Cdr & cdr,
  rmw_dds_common__msg__ParticipantEntitiesInfo * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: gid
  {
    impl_cdr_deserialize_with_endpoint_rmw_dds_common__msg__Gid(cdr, &ros_message->gid, endpoint_info, serialization_context);
  }

  // Field name: node_entities_info_seq
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

    if (ros_message->node_entities_info_seq.data) {
      rmw_dds_common__msg__NodeEntitiesInfo__Sequence__fini(&ros_message->node_entities_info_seq);
    }
    if (!rmw_dds_common__msg__NodeEntitiesInfo__Sequence__init(&ros_message->node_entities_info_seq, size)) {
      fprintf(stderr, "failed to create array for field 'node_entities_info_seq'");
      return false;
    }
    auto array_ptr = ros_message->node_entities_info_seq.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rmw_dds_common__msg__NodeEntitiesInfo(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
