// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from visualization_msgs:msg\InteractiveMarkerUpdate.idl
// generated code does not contain a copyright notice

#ifndef VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_UPDATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_UPDATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "visualization_msgs/msg/detail/interactive_marker_update__struct.h"
#include "visualization_msgs/msg/detail/interactive_marker_update__functions.h"
#include "visualization_msgs/msg/detail/interactive_marker_update__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/string.h"  // erases, server_id
#include "rosidl_runtime_c/string_functions.h"  // erases, server_id
#include "visualization_msgs/msg/detail/interactive_marker__functions.h"  // markers
#include "visualization_msgs/msg/detail/interactive_marker_pose__functions.h"  // poses

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "visualization_msgs/msg/detail/interactive_marker__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "visualization_msgs/msg/detail/interactive_marker_pose__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _InteractiveMarkerUpdate__ros_msg_type = visualization_msgs__msg__InteractiveMarkerUpdate;


inline
bool impl_cdr_serialize_visualization_msgs__msg__InteractiveMarkerUpdate(
  const visualization_msgs__msg__InteractiveMarkerUpdate * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: server_id
  {
    const rosidl_runtime_c__String * str = &ros_message->server_id;
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

  // Field name: seq_num
  {
    cdr << ros_message->seq_num;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: markers
  {
    size_t size = ros_message->markers.size;
    auto array_ptr = ros_message->markers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_visualization_msgs__msg__InteractiveMarker(
        &array_ptr[i], cdr);
    }
  }

  // Field name: poses
  {
    size_t size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_visualization_msgs__msg__InteractiveMarkerPose(
        &array_ptr[i], cdr);
    }
  }

  // Field name: erases
  {
    size_t size = ros_message->erases.size;
    auto array_ptr = ros_message->erases.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  return true;
}

inline
bool impl_cdr_deserialize_visualization_msgs__msg__InteractiveMarkerUpdate(
  eprosima::fastcdr::Cdr & cdr,
  visualization_msgs__msg__InteractiveMarkerUpdate * ros_message)
{
  // Field name: server_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->server_id.data) {
      rosidl_runtime_c__String__init(&ros_message->server_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->server_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'server_id'\n");
      return false;
    }
  }

  // Field name: seq_num
  {
    cdr >> ros_message->seq_num;
  }

  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: markers
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

    if (ros_message->markers.data) {
      visualization_msgs__msg__InteractiveMarker__Sequence__fini(&ros_message->markers);
    }
    if (!visualization_msgs__msg__InteractiveMarker__Sequence__init(&ros_message->markers, size)) {
      fprintf(stderr, "failed to create array for field 'markers'");
      return false;
    }
    auto array_ptr = ros_message->markers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_visualization_msgs__msg__InteractiveMarker(cdr, &array_ptr[i]);
    }
  }

  // Field name: poses
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

    if (ros_message->poses.data) {
      visualization_msgs__msg__InteractiveMarkerPose__Sequence__fini(&ros_message->poses);
    }
    if (!visualization_msgs__msg__InteractiveMarkerPose__Sequence__init(&ros_message->poses, size)) {
      fprintf(stderr, "failed to create array for field 'poses'");
      return false;
    }
    auto array_ptr = ros_message->poses.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_visualization_msgs__msg__InteractiveMarkerPose(cdr, &array_ptr[i]);
    }
  }

  // Field name: erases
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

    if (ros_message->erases.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->erases);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->erases, size)) {
      fprintf(stderr, "failed to create array for field 'erases'");
      return false;
    }
    auto array_ptr = ros_message->erases.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'erases'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_visualization_msgs__msg__InteractiveMarkerUpdate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InteractiveMarkerUpdate__ros_msg_type * ros_message = static_cast<const _InteractiveMarkerUpdate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: server_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->server_id.size + 1);

  // Field name: seq_num
  {
    size_t item_size = sizeof(ros_message->seq_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: markers
  {
    size_t array_size = ros_message->markers.size;
    auto array_ptr = ros_message->markers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_visualization_msgs__msg__InteractiveMarker(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: poses
  {
    size_t array_size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_visualization_msgs__msg__InteractiveMarkerPose(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: erases
  {
    size_t array_size = ros_message->erases.size;
    auto array_ptr = ros_message->erases.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_visualization_msgs__msg__InteractiveMarkerUpdate(
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

  // Field name: server_id
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

  // Field name: seq_num
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: markers
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
        impl_max_serialized_size_visualization_msgs__msg__InteractiveMarker(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: poses
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
        impl_max_serialized_size_visualization_msgs__msg__InteractiveMarkerPose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: erases
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = visualization_msgs__msg__InteractiveMarkerUpdate;
    is_plain =
      (
      offsetof(DataType, erases) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_visualization_msgs__msg__InteractiveMarkerUpdate(
  const visualization_msgs__msg__InteractiveMarkerUpdate * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: server_id
  {
    const rosidl_runtime_c__String * str = &ros_message->server_id;
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

  // Field name: seq_num
  {
    cdr << ros_message->seq_num;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: markers
  {
    size_t size = ros_message->markers.size;
    auto array_ptr = ros_message->markers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_visualization_msgs__msg__InteractiveMarker(
        &array_ptr[i], cdr);
    }
  }

  // Field name: poses
  {
    size_t size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_visualization_msgs__msg__InteractiveMarkerPose(
        &array_ptr[i], cdr);
    }
  }

  // Field name: erases
  {
    size_t size = ros_message->erases.size;
    auto array_ptr = ros_message->erases.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_visualization_msgs__msg__InteractiveMarkerUpdate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InteractiveMarkerUpdate__ros_msg_type * ros_message = static_cast<const _InteractiveMarkerUpdate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: server_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->server_id.size + 1);

  // Field name: seq_num
  {
    size_t item_size = sizeof(ros_message->seq_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: markers
  {
    size_t array_size = ros_message->markers.size;
    auto array_ptr = ros_message->markers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_visualization_msgs__msg__InteractiveMarker(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: poses
  {
    size_t array_size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_visualization_msgs__msg__InteractiveMarkerPose(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: erases
  {
    size_t array_size = ros_message->erases.size;
    auto array_ptr = ros_message->erases.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_visualization_msgs__msg__InteractiveMarkerUpdate(
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
  // Field name: server_id
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

  // Field name: seq_num
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: markers
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
        impl_max_serialized_size_key_visualization_msgs__msg__InteractiveMarker(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: poses
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
        impl_max_serialized_size_key_visualization_msgs__msg__InteractiveMarkerPose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: erases
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = visualization_msgs__msg__InteractiveMarkerUpdate;
    is_plain =
      (
      offsetof(DataType, erases) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_visualization_msgs__msg__InteractiveMarkerUpdate(
  const visualization_msgs__msg__InteractiveMarkerUpdate * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: server_id
  {
    const rosidl_runtime_c__String * str = &ros_message->server_id;
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

  // Field name: seq_num
  {
    cdr << ros_message->seq_num;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: markers
  {
    size_t size = ros_message->markers.size;
    auto array_ptr = ros_message->markers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_visualization_msgs__msg__InteractiveMarker(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: poses
  {
    size_t size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_visualization_msgs__msg__InteractiveMarkerPose(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: erases
  {
    size_t size = ros_message->erases.size;
    auto array_ptr = ros_message->erases.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_visualization_msgs__msg__InteractiveMarkerUpdate(
  eprosima::fastcdr::Cdr & cdr,
  visualization_msgs__msg__InteractiveMarkerUpdate * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: server_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->server_id.data) {
      rosidl_runtime_c__String__init(&ros_message->server_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->server_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'server_id'\n");
      return false;
    }
  }

  // Field name: seq_num
  {
    cdr >> ros_message->seq_num;
  }

  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: markers
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

    if (ros_message->markers.data) {
      visualization_msgs__msg__InteractiveMarker__Sequence__fini(&ros_message->markers);
    }
    if (!visualization_msgs__msg__InteractiveMarker__Sequence__init(&ros_message->markers, size)) {
      fprintf(stderr, "failed to create array for field 'markers'");
      return false;
    }
    auto array_ptr = ros_message->markers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_visualization_msgs__msg__InteractiveMarker(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: poses
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

    if (ros_message->poses.data) {
      visualization_msgs__msg__InteractiveMarkerPose__Sequence__fini(&ros_message->poses);
    }
    if (!visualization_msgs__msg__InteractiveMarkerPose__Sequence__init(&ros_message->poses, size)) {
      fprintf(stderr, "failed to create array for field 'poses'");
      return false;
    }
    auto array_ptr = ros_message->poses.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_visualization_msgs__msg__InteractiveMarkerPose(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: erases
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

    if (ros_message->erases.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->erases);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->erases, size)) {
      fprintf(stderr, "failed to create array for field 'erases'");
      return false;
    }
    auto array_ptr = ros_message->erases.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'erases'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_UPDATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
