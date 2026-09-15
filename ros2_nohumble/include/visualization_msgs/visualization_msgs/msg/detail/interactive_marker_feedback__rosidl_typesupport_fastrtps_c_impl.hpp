// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from visualization_msgs:msg\InteractiveMarkerFeedback.idl
// generated code does not contain a copyright notice

#ifndef VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_FEEDBACK__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_FEEDBACK__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "visualization_msgs/msg/detail/interactive_marker_feedback__struct.h"
#include "visualization_msgs/msg/detail/interactive_marker_feedback__functions.h"
#include "visualization_msgs/msg/detail/interactive_marker_feedback__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "geometry_msgs/msg/detail/point__functions.h"  // mouse_point
#include "geometry_msgs/msg/detail/pose__functions.h"  // pose
#include "rosidl_runtime_c/string.h"  // client_id, control_name, marker_name
#include "rosidl_runtime_c/string_functions.h"  // client_id, control_name, marker_name
#include "std_msgs/msg/detail/header__functions.h"  // header

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "std_msgs/msg/detail/header__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _InteractiveMarkerFeedback__ros_msg_type = visualization_msgs__msg__InteractiveMarkerFeedback;


inline
bool impl_cdr_serialize_visualization_msgs__msg__InteractiveMarkerFeedback(
  const visualization_msgs__msg__InteractiveMarkerFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: client_id
  {
    const rosidl_runtime_c__String * str = &ros_message->client_id;
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

  // Field name: marker_name
  {
    const rosidl_runtime_c__String * str = &ros_message->marker_name;
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

  // Field name: control_name
  {
    const rosidl_runtime_c__String * str = &ros_message->control_name;
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

  // Field name: event_type
  {
    cdr << ros_message->event_type;
  }

  // Field name: pose
  {
    impl_cdr_serialize_geometry_msgs__msg__Pose(
      &ros_message->pose, cdr);
  }

  // Field name: menu_entry_id
  {
    cdr << ros_message->menu_entry_id;
  }

  // Field name: mouse_point
  {
    impl_cdr_serialize_geometry_msgs__msg__Point(
      &ros_message->mouse_point, cdr);
  }

  // Field name: mouse_point_valid
  {
    cdr << (ros_message->mouse_point_valid ? true : false);
  }

  return true;
}

inline
bool impl_cdr_deserialize_visualization_msgs__msg__InteractiveMarkerFeedback(
  eprosima::fastcdr::Cdr & cdr,
  visualization_msgs__msg__InteractiveMarkerFeedback * ros_message)
{
  // Field name: header
  {
    impl_cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: client_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->client_id.data) {
      rosidl_runtime_c__String__init(&ros_message->client_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->client_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'client_id'\n");
      return false;
    }
  }

  // Field name: marker_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->marker_name.data) {
      rosidl_runtime_c__String__init(&ros_message->marker_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->marker_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'marker_name'\n");
      return false;
    }
  }

  // Field name: control_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->control_name.data) {
      rosidl_runtime_c__String__init(&ros_message->control_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->control_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'control_name'\n");
      return false;
    }
  }

  // Field name: event_type
  {
    cdr >> ros_message->event_type;
  }

  // Field name: pose
  {
    impl_cdr_deserialize_geometry_msgs__msg__Pose(cdr, &ros_message->pose);
  }

  // Field name: menu_entry_id
  {
    cdr >> ros_message->menu_entry_id;
  }

  // Field name: mouse_point
  {
    impl_cdr_deserialize_geometry_msgs__msg__Point(cdr, &ros_message->mouse_point);
  }

  // Field name: mouse_point_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->mouse_point_valid = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_visualization_msgs__msg__InteractiveMarkerFeedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InteractiveMarkerFeedback__ros_msg_type * ros_message = static_cast<const _InteractiveMarkerFeedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: client_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->client_id.size + 1);

  // Field name: marker_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->marker_name.size + 1);

  // Field name: control_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->control_name.size + 1);

  // Field name: event_type
  {
    size_t item_size = sizeof(ros_message->event_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pose
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->pose), current_alignment);

  // Field name: menu_entry_id
  {
    size_t item_size = sizeof(ros_message->menu_entry_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mouse_point
  current_alignment += impl_get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->mouse_point), current_alignment);

  // Field name: mouse_point_valid
  {
    size_t item_size = sizeof(ros_message->mouse_point_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_visualization_msgs__msg__InteractiveMarkerFeedback(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: client_id
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

  // Field name: marker_name
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

  // Field name: control_name
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

  // Field name: event_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pose
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: menu_entry_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mouse_point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: mouse_point_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = visualization_msgs__msg__InteractiveMarkerFeedback;
    is_plain =
      (
      offsetof(DataType, mouse_point_valid) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_visualization_msgs__msg__InteractiveMarkerFeedback(
  const visualization_msgs__msg__InteractiveMarkerFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: client_id
  {
    const rosidl_runtime_c__String * str = &ros_message->client_id;
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

  // Field name: marker_name
  {
    const rosidl_runtime_c__String * str = &ros_message->marker_name;
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

  // Field name: control_name
  {
    const rosidl_runtime_c__String * str = &ros_message->control_name;
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

  // Field name: event_type
  {
    cdr << ros_message->event_type;
  }

  // Field name: pose
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Pose(
      &ros_message->pose, cdr);
  }

  // Field name: menu_entry_id
  {
    cdr << ros_message->menu_entry_id;
  }

  // Field name: mouse_point
  {
    impl_cdr_serialize_key_geometry_msgs__msg__Point(
      &ros_message->mouse_point, cdr);
  }

  // Field name: mouse_point_valid
  {
    cdr << (ros_message->mouse_point_valid ? true : false);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_visualization_msgs__msg__InteractiveMarkerFeedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InteractiveMarkerFeedback__ros_msg_type * ros_message = static_cast<const _InteractiveMarkerFeedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: client_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->client_id.size + 1);

  // Field name: marker_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->marker_name.size + 1);

  // Field name: control_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->control_name.size + 1);

  // Field name: event_type
  {
    size_t item_size = sizeof(ros_message->event_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pose
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Pose(
    &(ros_message->pose), current_alignment);

  // Field name: menu_entry_id
  {
    size_t item_size = sizeof(ros_message->menu_entry_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mouse_point
  current_alignment += impl_get_serialized_size_key_geometry_msgs__msg__Point(
    &(ros_message->mouse_point), current_alignment);

  // Field name: mouse_point_valid
  {
    size_t item_size = sizeof(ros_message->mouse_point_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_visualization_msgs__msg__InteractiveMarkerFeedback(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: client_id
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

  // Field name: marker_name
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

  // Field name: control_name
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

  // Field name: event_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: pose
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: menu_entry_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mouse_point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_geometry_msgs__msg__Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: mouse_point_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = visualization_msgs__msg__InteractiveMarkerFeedback;
    is_plain =
      (
      offsetof(DataType, mouse_point_valid) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_visualization_msgs__msg__InteractiveMarkerFeedback(
  const visualization_msgs__msg__InteractiveMarkerFeedback * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: header
  {
    impl_cdr_serialize_with_endpoint_std_msgs__msg__Header(
      &ros_message->header, cdr, endpoint_info, serialization_context);
  }

  // Field name: client_id
  {
    const rosidl_runtime_c__String * str = &ros_message->client_id;
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

  // Field name: marker_name
  {
    const rosidl_runtime_c__String * str = &ros_message->marker_name;
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

  // Field name: control_name
  {
    const rosidl_runtime_c__String * str = &ros_message->control_name;
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

  // Field name: event_type
  {
    cdr << ros_message->event_type;
  }

  // Field name: pose
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Pose(
      &ros_message->pose, cdr, endpoint_info, serialization_context);
  }

  // Field name: menu_entry_id
  {
    cdr << ros_message->menu_entry_id;
  }

  // Field name: mouse_point
  {
    impl_cdr_serialize_with_endpoint_geometry_msgs__msg__Point(
      &ros_message->mouse_point, cdr, endpoint_info, serialization_context);
  }

  // Field name: mouse_point_valid
  {
    cdr << (ros_message->mouse_point_valid ? true : false);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_visualization_msgs__msg__InteractiveMarkerFeedback(
  eprosima::fastcdr::Cdr & cdr,
  visualization_msgs__msg__InteractiveMarkerFeedback * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: header
  {
    impl_cdr_deserialize_with_endpoint_std_msgs__msg__Header(cdr, &ros_message->header, endpoint_info, serialization_context);
  }

  // Field name: client_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->client_id.data) {
      rosidl_runtime_c__String__init(&ros_message->client_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->client_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'client_id'\n");
      return false;
    }
  }

  // Field name: marker_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->marker_name.data) {
      rosidl_runtime_c__String__init(&ros_message->marker_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->marker_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'marker_name'\n");
      return false;
    }
  }

  // Field name: control_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->control_name.data) {
      rosidl_runtime_c__String__init(&ros_message->control_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->control_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'control_name'\n");
      return false;
    }
  }

  // Field name: event_type
  {
    cdr >> ros_message->event_type;
  }

  // Field name: pose
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Pose(cdr, &ros_message->pose, endpoint_info, serialization_context);
  }

  // Field name: menu_entry_id
  {
    cdr >> ros_message->menu_entry_id;
  }

  // Field name: mouse_point
  {
    impl_cdr_deserialize_with_endpoint_geometry_msgs__msg__Point(cdr, &ros_message->mouse_point, endpoint_info, serialization_context);
  }

  // Field name: mouse_point_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->mouse_point_valid = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // VISUALIZATION_MSGS__MSG__DETAIL__INTERACTIVE_MARKER_FEEDBACK__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
