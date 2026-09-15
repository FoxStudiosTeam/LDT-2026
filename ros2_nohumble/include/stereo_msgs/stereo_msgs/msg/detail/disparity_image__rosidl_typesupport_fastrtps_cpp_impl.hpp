// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from stereo_msgs:msg\DisparityImage.idl
// generated code does not contain a copyright notice

#ifndef STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "stereo_msgs/msg/detail/disparity_image__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "std_msgs/msg/detail/header__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "sensor_msgs/msg/detail/region_of_interest__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace stereo_msgs
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
  const stereo_msgs::msg::DisparityImage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.header,
    cdr);

  // Member: image
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.image,
    cdr);

  // Member: f
  cdr << ros_message.f;

  // Member: t
  cdr << ros_message.t;

  // Member: valid_window
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
    ros_message.valid_window,
    cdr);

  // Member: min_disparity
  cdr << ros_message.min_disparity;

  // Member: max_disparity
  cdr << ros_message.max_disparity;

  // Member: delta_d
  cdr << ros_message.delta_d;

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  stereo_msgs::msg::DisparityImage & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.header);

  // Member: image
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.image);

  // Member: f
  cdr >> ros_message.f;

  // Member: t
  cdr >> ros_message.t;

  // Member: valid_window
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
    cdr, ros_message.valid_window);

  // Member: min_disparity
  cdr >> ros_message.min_disparity;

  // Member: max_disparity
  cdr >> ros_message.max_disparity;

  // Member: delta_d
  cdr >> ros_message.delta_d;

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const stereo_msgs::msg::DisparityImage & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: header
    std_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.header,
      cdr, endpoint_info, serialization_context);
    // Member: image
    sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.image,
      cdr, endpoint_info, serialization_context);
    // Member: f
    cdr << ros_message.f;
    // Member: t
    cdr << ros_message.t;
    // Member: valid_window
    sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
      ros_message.valid_window,
      cdr, endpoint_info, serialization_context);
    // Member: min_disparity
    cdr << ros_message.min_disparity;
    // Member: max_disparity
    cdr << ros_message.max_disparity;
    // Member: delta_d
    cdr << ros_message.delta_d;
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "stereo_msgs.typesupport_fastrtps_cpp",
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
  stereo_msgs::msg::DisparityImage & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.header,
    endpoint_info,
    serialization_context);

  // Member: image
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.image,
    endpoint_info,
    serialization_context);

  // Member: f
  cdr >> ros_message.f;

  // Member: t
  cdr >> ros_message.t;

  // Member: valid_window
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
    cdr,
    ros_message.valid_window,
    endpoint_info,
    serialization_context);

  // Member: min_disparity
  cdr >> ros_message.min_disparity;

  // Member: max_disparity
  cdr >> ros_message.max_disparity;

  // Member: delta_d
  cdr >> ros_message.delta_d;

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const stereo_msgs::msg::DisparityImage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.header, current_alignment);

  // Member: image
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.image, current_alignment);

  // Member: f
  {
    size_t item_size = sizeof(ros_message.f);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: t
  {
    size_t item_size = sizeof(ros_message.t);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: valid_window
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
    ros_message.valid_window, current_alignment);

  // Member: min_disparity
  {
    size_t item_size = sizeof(ros_message.min_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: max_disparity
  {
    size_t item_size = sizeof(ros_message.max_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: delta_d
  {
    size_t item_size = sizeof(ros_message.delta_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_DisparityImage(
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

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: image
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: f
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: t
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: valid_window
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_RegionOfInterest(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: min_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: max_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: delta_d
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
    using DataType = stereo_msgs::msg::DisparityImage;
    is_plain =
      (
      offsetof(DataType, delta_d) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const stereo_msgs::msg::DisparityImage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.header,
    cdr);

  // Member: image
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.image,
    cdr);

  // Member: f
  cdr << ros_message.f;

  // Member: t
  cdr << ros_message.t;

  // Member: valid_window
  sensor_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
    ros_message.valid_window,
    cdr);

  // Member: min_disparity
  cdr << ros_message.min_disparity;

  // Member: max_disparity
  cdr << ros_message.max_disparity;

  // Member: delta_d
  cdr << ros_message.delta_d;

  return true;
}

inline
size_t
get_serialized_size_key(
  const stereo_msgs::msg::DisparityImage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.header, current_alignment);

  // Member: image
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.image, current_alignment);

  // Member: f
  {
    size_t item_size = sizeof(ros_message.f);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: t
  {
    size_t item_size = sizeof(ros_message.t);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: valid_window
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
    ros_message.valid_window, current_alignment);

  // Member: min_disparity
  {
    size_t item_size = sizeof(ros_message.min_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: max_disparity
  {
    size_t item_size = sizeof(ros_message.max_disparity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: delta_d
  {
    size_t item_size = sizeof(ros_message.delta_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_DisparityImage(
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

  // Member: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: image
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: f
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: t
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: valid_window
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_RegionOfInterest(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: min_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: max_disparity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: delta_d
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
    using DataType = stereo_msgs::msg::DisparityImage;
    is_plain =
      (
      offsetof(DataType, delta_d) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace stereo_msgs

#endif  // STEREO_MSGS__MSG__DETAIL__DISPARITY_IMAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
