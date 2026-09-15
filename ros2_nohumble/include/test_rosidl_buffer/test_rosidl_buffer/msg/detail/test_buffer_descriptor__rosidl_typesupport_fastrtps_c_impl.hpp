// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_rosidl_buffer:msg\TestBufferDescriptor.idl
// generated code does not contain a copyright notice

#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__struct.h"
#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__functions.h"
#include "test_rosidl_buffer/msg/detail/test_buffer_descriptor__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"
#include "rosidl_typesupport_fastrtps_cpp/buffer_serialization.hpp"

#include "rosidl_runtime_c/primitives_sequence.h"  // data
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.

#if defined(__cplusplus)
extern "C"
{
#endif

using _TestBufferDescriptor__ros_msg_type = test_rosidl_buffer__msg__TestBufferDescriptor;


inline
bool impl_cdr_serialize_test_rosidl_buffer__msg__TestBufferDescriptor(
  const test_rosidl_buffer__msg__TestBufferDescriptor * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: size
  {
    cdr << ros_message->size;
  }

  // Field name: data_hash
  {
    cdr << ros_message->data_hash;
  }

  // Field name: data
  {
    // Regular path CPU fallback for rosidl_buffer-backed uint8[]
    if (ros_message->data.is_rosidl_buffer) {
      auto * buffer = reinterpret_cast<const rosidl::Buffer<uint8_t> *>(ros_message->data.data);
      if (buffer == nullptr) {
        fprintf(stderr, "null rosidl_buffer pointer for field 'data'\n");
        return false;
      }
      if (buffer->get_backend_type() == "cpu") {
        cdr << static_cast<uint32_t>(buffer->size());
        if (buffer->size() > 0) {
          cdr.serialize_array(buffer->data(), buffer->size());
        }
      } else {
        const std::vector<uint8_t> vec = buffer->to_vector();
        cdr << vec;
      }
    } else {
      size_t size = ros_message->data.size;
      auto array_ptr = ros_message->data.data;
      cdr << static_cast<uint32_t>(size);
      cdr.serialize_array(array_ptr, size);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_rosidl_buffer__msg__TestBufferDescriptor(
  eprosima::fastcdr::Cdr & cdr,
  test_rosidl_buffer__msg__TestBufferDescriptor * ros_message)
{
  // Field name: size
  {
    cdr >> ros_message->size;
  }

  // Field name: data_hash
  {
    cdr >> ros_message->data_hash;
  }

  // Field name: data
  {
    // Regular path CPU fallback for rosidl_buffer-backed uint8[]
    if (ros_message->data.is_rosidl_buffer) {
      auto * old_buffer = reinterpret_cast<rosidl::Buffer<uint8_t> *>(ros_message->data.data);
      delete old_buffer;
      ros_message->data.data = nullptr;
      ros_message->data.size = 0;
      ros_message->data.capacity = 0;
      ros_message->data.is_rosidl_buffer = false;
    }
    uint32_t seq_size = 0u;
    cdr >> seq_size;
    if (ros_message->data.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->data);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->data, seq_size)) {
      fprintf(stderr, "failed to create array for field 'data'");
      return false;
    }
    if (seq_size > 0) {
      cdr.deserialize_array(ros_message->data.data, seq_size);
    }
    ros_message->data.is_rosidl_buffer = false;
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_rosidl_buffer__msg__TestBufferDescriptor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TestBufferDescriptor__ros_msg_type * ros_message = static_cast<const _TestBufferDescriptor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: size
  {
    size_t item_size = sizeof(ros_message->size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data_hash
  {
    size_t item_size = sizeof(ros_message->data_hash);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data
  {
    if (ros_message->data.is_rosidl_buffer) {
      auto * buffer = reinterpret_cast<const rosidl::Buffer<uint8_t> *>(ros_message->data.data);
      if (buffer != nullptr) {
        current_alignment +=
          rosidl_typesupport_fastrtps_cpp::get_buffer_serialized_size(
          *buffer, current_alignment);
      }
    } else {
      size_t array_size = ros_message->data.size;
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
      current_alignment += array_size * sizeof(uint8_t) +
        eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint8_t));
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_rosidl_buffer__msg__TestBufferDescriptor(
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

  // Field name: size
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: data_hash
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_rosidl_buffer__msg__TestBufferDescriptor;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_rosidl_buffer__msg__TestBufferDescriptor(
  const test_rosidl_buffer__msg__TestBufferDescriptor * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: size
  {
    cdr << ros_message->size;
  }

  // Field name: data_hash
  {
    cdr << ros_message->data_hash;
  }

  // Field name: data
  {
    size_t size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_rosidl_buffer__msg__TestBufferDescriptor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TestBufferDescriptor__ros_msg_type * ros_message = static_cast<const _TestBufferDescriptor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: size
  {
    size_t item_size = sizeof(ros_message->size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data_hash
  {
    size_t item_size = sizeof(ros_message->data_hash);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: data
  {
    size_t array_size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_rosidl_buffer__msg__TestBufferDescriptor(
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
  // Field name: size
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: data_hash
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: data
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = test_rosidl_buffer__msg__TestBufferDescriptor;
    is_plain =
      (
      offsetof(DataType, data) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_rosidl_buffer__msg__TestBufferDescriptor(
  const test_rosidl_buffer__msg__TestBufferDescriptor * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: size
  {
    cdr << ros_message->size;
  }

  // Field name: data_hash
  {
    cdr << ros_message->data_hash;
  }

  // Field name: data
  {
    rosidl_typesupport_fastrtps_cpp::serialize_buffer_or_c_sequence_with_endpoint(
      cdr, ros_message->data, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_rosidl_buffer__msg__TestBufferDescriptor(
  eprosima::fastcdr::Cdr & cdr,
  test_rosidl_buffer__msg__TestBufferDescriptor * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: size
  {
    cdr >> ros_message->size;
  }

  // Field name: data_hash
  {
    cdr >> ros_message->data_hash;
  }

  // Field name: data
  {
    if (!rosidl_typesupport_fastrtps_cpp::deserialize_buffer_or_c_sequence_with_endpoint(
        cdr, ros_message->data, endpoint_info, serialization_context))
    {
      fprintf(stderr, "Failed to deserialize buffer field 'data'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__TEST_BUFFER_DESCRIPTOR__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
