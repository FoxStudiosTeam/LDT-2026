// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from stereo_msgs:msg\DisparityImage.idl
// generated code does not contain a copyright notice

#ifndef STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "stereo_msgs/msg/detail/disparity_image__struct.h"
#include "stereo_msgs/msg/detail/disparity_image__functions.h"
#include "stereo_msgs/msg/detail/disparity_image__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "sensor_msgs/msg/detail/image__functions.h"  // image
#include "sensor_msgs/msg/detail/region_of_interest__functions.h"  // valid_window
#include "std_msgs/msg/detail/header__functions.h"  // header

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "std_msgs/msg/detail/header__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "sensor_msgs/msg/detail/region_of_interest__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _DisparityImage__ros_msg_type = stereo_msgs__msg__DisparityImage;


inline
bool impl_cdr_serialize_stereo_msgs__msg__DisparityImage(
  const stereo_msgs__msg__DisparityImage * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: image
  {
    impl_cdr_serialize_sensor_msgs__msg__Image(
      &ros_message->image, cdr);
  }

  // Field name: f
  {
    cdr << ros_message->f;
  }

  // Field name: t
  {
    cdr << ros_message->t;
  }

  // Field name: valid_window
  {
    impl_cdr_serialize_sensor_msgs__msg__RegionOfInterest(
      &ros_message->valid_window, cdr);
  }

  // Field name: min_disparity
  {
    cdr << ros_message->min_disparity;
  }

  // Field name: max_disparity
  {
    cdr << ros_message->max_disparity;
  }

  // Field name: delta_d
  {
    cdr << ros_message->delta_d;
  }

  return true;
}

inline
bool impl_cdr_deserialize_stereo_msgs__msg__DisparityImage(
  eprosima::fastcdr::Cdr & cdr,
  stereo_msgs__msg__DisparityImage * ros_message)
{
  // Field name: header
  {
    impl_cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: image
  {
    impl_cdr_deserialize_sensor_msgs__msg__Image(cdr, &ros_message->image);
  }

  // Field name: f
  {
    cdr >> ros_message->f;
  }

  // Field name: t
  {
    cdr >> ros_message->t;
  }

  // Field name: valid_window
  {
    impl_cdr_deserialize_sensor_msgs__msg__RegionOfInterest(cdr, &ros_message->valid_window);
  }

  // Field name: min_disparity
  {
    cdr >> ros_message->min_disparity;
  }

  // Field name: max_disparity
  {
    cdr >> ros_message->max_disparity;
  }

  // Field name: delta_d
  {
    cdr >> ros_message->delta_d;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_stereo_msgs__msg__DisparityImage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DisparityImage__ros_msg_type * ros_message = static_cast<const _DisparityImage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: image
  current_alignment += impl_get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->image), current_alignment);

  // Field name: f
  {
    size_t item_size = sizeof(ros_message->f);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: t
  {
    size_t item_size = sizeof(ros_message->t);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: valid_window
  current_alignment += impl_get_serialized_size_sensor_msgs__msg__RegionOfInterest(
    &(ros_message->valid_window), current_alignment);

  // Field name: min_disparity
  {
    size_t item_size = sizeof(ros_message->min_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_disparity
  {
    size_t item_size = sizeof(ros_message->max_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: delta_d
  {
    size_t item_size = sizeof(ros_message->delta_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_stereo_msgs__msg__DisparityImage(
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

  // Field name: image
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: f
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: t
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: valid_window
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_sensor_msgs__msg__RegionOfInterest(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: min_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: max_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: delta_d
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = stereo_msgs__msg__DisparityImage;
    is_plain =
      (
      offsetof(DataType, delta_d) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_stereo_msgs__msg__DisparityImage(
  const stereo_msgs__msg__DisparityImage * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    impl_cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: image
  {
    impl_cdr_serialize_key_sensor_msgs__msg__Image(
      &ros_message->image, cdr);
  }

  // Field name: f
  {
    cdr << ros_message->f;
  }

  // Field name: t
  {
    cdr << ros_message->t;
  }

  // Field name: valid_window
  {
    impl_cdr_serialize_key_sensor_msgs__msg__RegionOfInterest(
      &ros_message->valid_window, cdr);
  }

  // Field name: min_disparity
  {
    cdr << ros_message->min_disparity;
  }

  // Field name: max_disparity
  {
    cdr << ros_message->max_disparity;
  }

  // Field name: delta_d
  {
    cdr << ros_message->delta_d;
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_stereo_msgs__msg__DisparityImage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DisparityImage__ros_msg_type * ros_message = static_cast<const _DisparityImage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += impl_get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: image
  current_alignment += impl_get_serialized_size_key_sensor_msgs__msg__Image(
    &(ros_message->image), current_alignment);

  // Field name: f
  {
    size_t item_size = sizeof(ros_message->f);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: t
  {
    size_t item_size = sizeof(ros_message->t);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: valid_window
  current_alignment += impl_get_serialized_size_key_sensor_msgs__msg__RegionOfInterest(
    &(ros_message->valid_window), current_alignment);

  // Field name: min_disparity
  {
    size_t item_size = sizeof(ros_message->min_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: max_disparity
  {
    size_t item_size = sizeof(ros_message->max_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: delta_d
  {
    size_t item_size = sizeof(ros_message->delta_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_stereo_msgs__msg__DisparityImage(
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

  // Field name: image
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: f
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: t
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: valid_window
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_sensor_msgs__msg__RegionOfInterest(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: min_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: max_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: delta_d
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = stereo_msgs__msg__DisparityImage;
    is_plain =
      (
      offsetof(DataType, delta_d) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_stereo_msgs__msg__DisparityImage(
  const stereo_msgs__msg__DisparityImage * ros_message,
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

  // Field name: image
  {
    impl_cdr_serialize_with_endpoint_sensor_msgs__msg__Image(
      &ros_message->image, cdr, endpoint_info, serialization_context);
  }

  // Field name: f
  {
    cdr << ros_message->f;
  }

  // Field name: t
  {
    cdr << ros_message->t;
  }

  // Field name: valid_window
  {
    impl_cdr_serialize_with_endpoint_sensor_msgs__msg__RegionOfInterest(
      &ros_message->valid_window, cdr, endpoint_info, serialization_context);
  }

  // Field name: min_disparity
  {
    cdr << ros_message->min_disparity;
  }

  // Field name: max_disparity
  {
    cdr << ros_message->max_disparity;
  }

  // Field name: delta_d
  {
    cdr << ros_message->delta_d;
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_stereo_msgs__msg__DisparityImage(
  eprosima::fastcdr::Cdr & cdr,
  stereo_msgs__msg__DisparityImage * ros_message,
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

  // Field name: image
  {
    impl_cdr_deserialize_with_endpoint_sensor_msgs__msg__Image(cdr, &ros_message->image, endpoint_info, serialization_context);
  }

  // Field name: f
  {
    cdr >> ros_message->f;
  }

  // Field name: t
  {
    cdr >> ros_message->t;
  }

  // Field name: valid_window
  {
    impl_cdr_deserialize_with_endpoint_sensor_msgs__msg__RegionOfInterest(cdr, &ros_message->valid_window, endpoint_info, serialization_context);
  }

  // Field name: min_disparity
  {
    cdr >> ros_message->min_disparity;
  }

  // Field name: max_disparity
  {
    cdr >> ros_message->max_disparity;
  }

  // Field name: delta_d
  {
    cdr >> ros_message->delta_d;
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
