// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from test_msgs:srv\Arrays.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__SRV__DETAIL__ARRAYS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define TEST_MSGS__SRV__DETAIL__ARRAYS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "test_msgs/srv/detail/arrays__struct.h"
#include "test_msgs/srv/detail/arrays__functions.h"
#include "test_msgs/srv/detail/arrays__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosidl_runtime_c/string.h"  // string_values, string_values_default
#include "rosidl_runtime_c/string_functions.h"  // string_values, string_values_default
#include "test_msgs/msg/detail/basic_types__functions.h"  // basic_types_values
#include "test_msgs/msg/detail/constants__functions.h"  // constants_values
#include "test_msgs/msg/detail/defaults__functions.h"  // defaults_values

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "test_msgs/msg/detail/basic_types__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "test_msgs/msg/detail/constants__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "test_msgs/msg/detail/defaults__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Arrays_Request__ros_msg_type = test_msgs__srv__Arrays_Request;


inline
bool impl_cdr_serialize_test_msgs__srv__Arrays_Request(
  const test_msgs__srv__Arrays_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
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

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Constants(
        &array_ptr[i], cdr);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Defaults(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
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
bool impl_cdr_deserialize_test_msgs__srv__Arrays_Request(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__srv__Arrays_Request * ros_message)
{
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values'\n");
        return false;
      }
    }
  }

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__BasicTypes(cdr, &array_ptr[i]);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Constants(cdr, &array_ptr[i]);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Defaults(cdr, &array_ptr[i]);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values_default'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__srv__Arrays_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Arrays_Request__ros_msg_type * ros_message = static_cast<const _Arrays_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__BasicTypes(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Constants(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Defaults(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__srv__Arrays_Request(
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

  // Field name: bool_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
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
    using DataType = test_msgs__srv__Arrays_Request;
    is_plain =
      (
      offsetof(DataType, string_values_default) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__srv__Arrays_Request(
  const test_msgs__srv__Arrays_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
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

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Constants(
        &array_ptr[i], cdr);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Defaults(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
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
size_t impl_get_serialized_size_key_test_msgs__srv__Arrays_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Arrays_Request__ros_msg_type * ros_message = static_cast<const _Arrays_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__BasicTypes(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Constants(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Defaults(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__srv__Arrays_Request(
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
  // Field name: bool_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
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
    using DataType = test_msgs__srv__Arrays_Request;
    is_plain =
      (
      offsetof(DataType, string_values_default) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__srv__Arrays_Request(
  const test_msgs__srv__Arrays_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
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

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Constants(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Defaults(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
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
bool impl_cdr_deserialize_with_endpoint_test_msgs__srv__Arrays_Request(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__srv__Arrays_Request * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values'\n");
        return false;
      }
    }
  }

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__BasicTypes(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Constants(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Defaults(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values_default'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include <vector>
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "test_msgs/srv/detail/arrays__struct.h"
// already included above
// #include "test_msgs/srv/detail/arrays__functions.h"
// already included above
// #include "test_msgs/srv/detail/arrays__rosidl_typesupport_fastrtps_c.h"
// already included above
// #include "fastcdr/Cdr.h"

// already included above
// #include "rosidl_runtime_c/string.h"  // string_values, string_values_default
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // string_values, string_values_default
// already included above
// #include "test_msgs/msg/detail/basic_types__functions.h"  // basic_types_values
// already included above
// #include "test_msgs/msg/detail/constants__functions.h"  // constants_values
// already included above
// #include "test_msgs/msg/detail/defaults__functions.h"  // defaults_values

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
// already included above
// #include "test_msgs/msg/detail/basic_types__rosidl_typesupport_fastrtps_c_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/constants__rosidl_typesupport_fastrtps_c_impl.hpp"
// already included above
// #include "test_msgs/msg/detail/defaults__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Arrays_Response__ros_msg_type = test_msgs__srv__Arrays_Response;


inline
bool impl_cdr_serialize_test_msgs__srv__Arrays_Response(
  const test_msgs__srv__Arrays_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
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

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Constants(
        &array_ptr[i], cdr);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__msg__Defaults(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
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
bool impl_cdr_deserialize_test_msgs__srv__Arrays_Response(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__srv__Arrays_Response * ros_message)
{
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values'\n");
        return false;
      }
    }
  }

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__BasicTypes(cdr, &array_ptr[i]);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Constants(cdr, &array_ptr[i]);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__msg__Defaults(cdr, &array_ptr[i]);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values_default'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__srv__Arrays_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Arrays_Response__ros_msg_type * ros_message = static_cast<const _Arrays_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__BasicTypes(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Constants(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__msg__Defaults(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__srv__Arrays_Response(
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

  // Field name: bool_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__msg__Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
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
    using DataType = test_msgs__srv__Arrays_Response;
    is_plain =
      (
      offsetof(DataType, string_values_default) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__srv__Arrays_Response(
  const test_msgs__srv__Arrays_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
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

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Constants(
        &array_ptr[i], cdr);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__msg__Defaults(
        &array_ptr[i], cdr);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
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
size_t impl_get_serialized_size_key_test_msgs__srv__Arrays_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Arrays_Response__ros_msg_type * ros_message = static_cast<const _Arrays_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: bool_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__BasicTypes(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Constants(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__msg__Defaults(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->bool_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->byte_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->char_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->float64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->int64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__srv__Arrays_Response(
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
  // Field name: bool_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: basic_types_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__BasicTypes(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: constants_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Constants(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: defaults_values
  {
    size_t array_size = 3;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__msg__Defaults(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: bool_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: byte_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: char_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: float32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: float64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: int8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: uint8_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: int16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: uint16_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: int32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: uint32_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: int64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: uint64_values_default
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: string_values_default
  {
    size_t array_size = 3;
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
    using DataType = test_msgs__srv__Arrays_Response;
    is_plain =
      (
      offsetof(DataType, string_values_default) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__srv__Arrays_Response(
  const test_msgs__srv__Arrays_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
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

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__BasicTypes(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Constants(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__msg__Defaults(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
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
bool impl_cdr_deserialize_with_endpoint_test_msgs__srv__Arrays_Response(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__srv__Arrays_Response * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: bool_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values'\n");
        return false;
      }
    }
  }

  // Field name: basic_types_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->basic_types_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__BasicTypes(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: constants_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->constants_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Constants(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: defaults_values
  {
    size_t size = 3;
    auto array_ptr = ros_message->defaults_values;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__msg__Defaults(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: bool_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->bool_values_default;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: byte_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->byte_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: char_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->char_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: float64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->float64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint8_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint8_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint16_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint16_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint32_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint32_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: int64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->int64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: uint64_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->uint64_values_default;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: string_values_default
  {
    size_t size = 3;
    auto array_ptr = ros_message->string_values_default;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assignn(&ros_i, tmp.c_str(), tmp.size());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'string_values_default'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include <vector>
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "test_msgs/srv/detail/arrays__struct.h"
// already included above
// #include "test_msgs/srv/detail/arrays__functions.h"
// already included above
// #include "test_msgs/srv/detail/arrays__rosidl_typesupport_fastrtps_c.h"
// already included above
// #include "fastcdr/Cdr.h"

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Arrays_Event__ros_msg_type = test_msgs__srv__Arrays_Event;


inline
bool impl_cdr_serialize_test_msgs__srv__Arrays_Event(
  const test_msgs__srv__Arrays_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    impl_cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__srv__Arrays_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_test_msgs__srv__Arrays_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_test_msgs__srv__Arrays_Event(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__srv__Arrays_Event * ros_message)
{
  // Field name: info
  {
    impl_cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
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

    if (ros_message->request.data) {
      test_msgs__srv__Arrays_Request__Sequence__fini(&ros_message->request);
    }
    if (!test_msgs__srv__Arrays_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__srv__Arrays_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
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

    if (ros_message->response.data) {
      test_msgs__srv__Arrays_Response__Sequence__fini(&ros_message->response);
    }
    if (!test_msgs__srv__Arrays_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_test_msgs__srv__Arrays_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_test_msgs__srv__Arrays_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Arrays_Event__ros_msg_type * ros_message = static_cast<const _Arrays_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += impl_get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__srv__Arrays_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_test_msgs__srv__Arrays_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_test_msgs__srv__Arrays_Event(
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

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__srv__Arrays_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_test_msgs__srv__Arrays_Response(
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
    using DataType = test_msgs__srv__Arrays_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_test_msgs__srv__Arrays_Event(
  const test_msgs__srv__Arrays_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    impl_cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__srv__Arrays_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_test_msgs__srv__Arrays_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_test_msgs__srv__Arrays_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Arrays_Event__ros_msg_type * ros_message = static_cast<const _Arrays_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += impl_get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__srv__Arrays_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_test_msgs__srv__Arrays_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_test_msgs__srv__Arrays_Event(
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
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__srv__Arrays_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_test_msgs__srv__Arrays_Response(
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
    using DataType = test_msgs__srv__Arrays_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_test_msgs__srv__Arrays_Event(
  const test_msgs__srv__Arrays_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: info
  {
    impl_cdr_serialize_with_endpoint_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr, endpoint_info, serialization_context);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__srv__Arrays_Request(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_test_msgs__srv__Arrays_Response(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_test_msgs__srv__Arrays_Event(
  eprosima::fastcdr::Cdr & cdr,
  test_msgs__srv__Arrays_Event * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: info
  {
    impl_cdr_deserialize_with_endpoint_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info, endpoint_info, serialization_context);
  }

  // Field name: request
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

    if (ros_message->request.data) {
      test_msgs__srv__Arrays_Request__Sequence__fini(&ros_message->request);
    }
    if (!test_msgs__srv__Arrays_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__srv__Arrays_Request(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: response
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

    if (ros_message->response.data) {
      test_msgs__srv__Arrays_Response__Sequence__fini(&ros_message->response);
    }
    if (!test_msgs__srv__Arrays_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_test_msgs__srv__Arrays_Response(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // TEST_MSGS__SRV__DETAIL__ARRAYS__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
