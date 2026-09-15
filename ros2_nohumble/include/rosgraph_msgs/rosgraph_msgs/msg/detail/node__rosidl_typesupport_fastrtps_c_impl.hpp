// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosgraph_msgs:msg\Node.idl
// generated code does not contain a copyright notice

#ifndef ROSGRAPH_MSGS__MSG__DETAIL__NODE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__NODE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosgraph_msgs/msg/detail/node__struct.h"
#include "rosgraph_msgs/msg/detail/node__functions.h"
#include "rosgraph_msgs/msg/detail/node__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rcl_interfaces/msg/detail/parameter_descriptor__functions.h"  // parameters
#include "rcl_interfaces/msg/detail/parameter_value__functions.h"  // parameter_values
#include "rosgraph_msgs/msg/detail/action__functions.h"  // action_clients, action_servers
#include "rosgraph_msgs/msg/detail/service__functions.h"  // service_clients, service_servers
#include "rosgraph_msgs/msg/detail/topic__functions.h"  // publishers, subscriptions
#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rcl_interfaces/msg/detail/parameter_descriptor__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rcl_interfaces/msg/detail/parameter_value__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rosgraph_msgs/msg/detail/topic__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_c_impl.hpp"
#include "rosgraph_msgs/msg/detail/action__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _Node__ros_msg_type = rosgraph_msgs__msg__Node;


inline
bool impl_cdr_serialize_rosgraph_msgs__msg__Node(
  const rosgraph_msgs__msg__Node * ros_message,
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

  // Field name: parameters
  {
    size_t size = ros_message->parameters.size;
    auto array_ptr = ros_message->parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  // Field name: parameter_values
  {
    size_t size = ros_message->parameter_values.size;
    auto array_ptr = ros_message->parameter_values.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rcl_interfaces__msg__ParameterValue(
        &array_ptr[i], cdr);
    }
  }

  // Field name: publishers
  {
    size_t size = ros_message->publishers.size;
    auto array_ptr = ros_message->publishers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosgraph_msgs__msg__Topic(
        &array_ptr[i], cdr);
    }
  }

  // Field name: subscriptions
  {
    size_t size = ros_message->subscriptions.size;
    auto array_ptr = ros_message->subscriptions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosgraph_msgs__msg__Topic(
        &array_ptr[i], cdr);
    }
  }

  // Field name: service_clients
  {
    size_t size = ros_message->service_clients.size;
    auto array_ptr = ros_message->service_clients.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosgraph_msgs__msg__Service(
        &array_ptr[i], cdr);
    }
  }

  // Field name: service_servers
  {
    size_t size = ros_message->service_servers.size;
    auto array_ptr = ros_message->service_servers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosgraph_msgs__msg__Service(
        &array_ptr[i], cdr);
    }
  }

  // Field name: action_clients
  {
    size_t size = ros_message->action_clients.size;
    auto array_ptr = ros_message->action_clients.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosgraph_msgs__msg__Action(
        &array_ptr[i], cdr);
    }
  }

  // Field name: action_servers
  {
    size_t size = ros_message->action_servers.size;
    auto array_ptr = ros_message->action_servers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosgraph_msgs__msg__Action(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosgraph_msgs__msg__Node(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs__msg__Node * ros_message)
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

  // Field name: parameters
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

    if (ros_message->parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->parameters, size)) {
      fprintf(stderr, "failed to create array for field 'parameters'");
      return false;
    }
    auto array_ptr = ros_message->parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i]);
    }
  }

  // Field name: parameter_values
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

    if (ros_message->parameter_values.data) {
      rcl_interfaces__msg__ParameterValue__Sequence__fini(&ros_message->parameter_values);
    }
    if (!rcl_interfaces__msg__ParameterValue__Sequence__init(&ros_message->parameter_values, size)) {
      fprintf(stderr, "failed to create array for field 'parameter_values'");
      return false;
    }
    auto array_ptr = ros_message->parameter_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rcl_interfaces__msg__ParameterValue(cdr, &array_ptr[i]);
    }
  }

  // Field name: publishers
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

    if (ros_message->publishers.data) {
      rosgraph_msgs__msg__Topic__Sequence__fini(&ros_message->publishers);
    }
    if (!rosgraph_msgs__msg__Topic__Sequence__init(&ros_message->publishers, size)) {
      fprintf(stderr, "failed to create array for field 'publishers'");
      return false;
    }
    auto array_ptr = ros_message->publishers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosgraph_msgs__msg__Topic(cdr, &array_ptr[i]);
    }
  }

  // Field name: subscriptions
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

    if (ros_message->subscriptions.data) {
      rosgraph_msgs__msg__Topic__Sequence__fini(&ros_message->subscriptions);
    }
    if (!rosgraph_msgs__msg__Topic__Sequence__init(&ros_message->subscriptions, size)) {
      fprintf(stderr, "failed to create array for field 'subscriptions'");
      return false;
    }
    auto array_ptr = ros_message->subscriptions.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosgraph_msgs__msg__Topic(cdr, &array_ptr[i]);
    }
  }

  // Field name: service_clients
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

    if (ros_message->service_clients.data) {
      rosgraph_msgs__msg__Service__Sequence__fini(&ros_message->service_clients);
    }
    if (!rosgraph_msgs__msg__Service__Sequence__init(&ros_message->service_clients, size)) {
      fprintf(stderr, "failed to create array for field 'service_clients'");
      return false;
    }
    auto array_ptr = ros_message->service_clients.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosgraph_msgs__msg__Service(cdr, &array_ptr[i]);
    }
  }

  // Field name: service_servers
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

    if (ros_message->service_servers.data) {
      rosgraph_msgs__msg__Service__Sequence__fini(&ros_message->service_servers);
    }
    if (!rosgraph_msgs__msg__Service__Sequence__init(&ros_message->service_servers, size)) {
      fprintf(stderr, "failed to create array for field 'service_servers'");
      return false;
    }
    auto array_ptr = ros_message->service_servers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosgraph_msgs__msg__Service(cdr, &array_ptr[i]);
    }
  }

  // Field name: action_clients
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

    if (ros_message->action_clients.data) {
      rosgraph_msgs__msg__Action__Sequence__fini(&ros_message->action_clients);
    }
    if (!rosgraph_msgs__msg__Action__Sequence__init(&ros_message->action_clients, size)) {
      fprintf(stderr, "failed to create array for field 'action_clients'");
      return false;
    }
    auto array_ptr = ros_message->action_clients.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosgraph_msgs__msg__Action(cdr, &array_ptr[i]);
    }
  }

  // Field name: action_servers
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

    if (ros_message->action_servers.data) {
      rosgraph_msgs__msg__Action__Sequence__fini(&ros_message->action_servers);
    }
    if (!rosgraph_msgs__msg__Action__Sequence__init(&ros_message->action_servers, size)) {
      fprintf(stderr, "failed to create array for field 'action_servers'");
      return false;
    }
    auto array_ptr = ros_message->action_servers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosgraph_msgs__msg__Action(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosgraph_msgs__msg__Node(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Node__ros_msg_type * ros_message = static_cast<const _Node__ros_msg_type *>(untyped_ros_message);
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

  // Field name: parameters
  {
    size_t array_size = ros_message->parameters.size;
    auto array_ptr = ros_message->parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: parameter_values
  {
    size_t array_size = ros_message->parameter_values.size;
    auto array_ptr = ros_message->parameter_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rcl_interfaces__msg__ParameterValue(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: publishers
  {
    size_t array_size = ros_message->publishers.size;
    auto array_ptr = ros_message->publishers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__Topic(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: subscriptions
  {
    size_t array_size = ros_message->subscriptions.size;
    auto array_ptr = ros_message->subscriptions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__Topic(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: service_clients
  {
    size_t array_size = ros_message->service_clients.size;
    auto array_ptr = ros_message->service_clients.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__Service(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: service_servers
  {
    size_t array_size = ros_message->service_servers.size;
    auto array_ptr = ros_message->service_servers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__Service(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: action_clients
  {
    size_t array_size = ros_message->action_clients.size;
    auto array_ptr = ros_message->action_clients.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__Action(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: action_servers
  {
    size_t array_size = ros_message->action_servers.size;
    auto array_ptr = ros_message->action_servers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosgraph_msgs__msg__Action(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosgraph_msgs__msg__Node(
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

  // Field name: parameters
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
        impl_max_serialized_size_rcl_interfaces__msg__ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: parameter_values
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
        impl_max_serialized_size_rcl_interfaces__msg__ParameterValue(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: publishers
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
        impl_max_serialized_size_rosgraph_msgs__msg__Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: subscriptions
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
        impl_max_serialized_size_rosgraph_msgs__msg__Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: service_clients
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
        impl_max_serialized_size_rosgraph_msgs__msg__Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: service_servers
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
        impl_max_serialized_size_rosgraph_msgs__msg__Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: action_clients
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
        impl_max_serialized_size_rosgraph_msgs__msg__Action(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: action_servers
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
        impl_max_serialized_size_rosgraph_msgs__msg__Action(
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
    using DataType = rosgraph_msgs__msg__Node;
    is_plain =
      (
      offsetof(DataType, action_servers) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosgraph_msgs__msg__Node(
  const rosgraph_msgs__msg__Node * ros_message,
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

  // Field name: parameters
  {
    size_t size = ros_message->parameters.size;
    auto array_ptr = ros_message->parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr);
    }
  }

  // Field name: parameter_values
  {
    size_t size = ros_message->parameter_values.size;
    auto array_ptr = ros_message->parameter_values.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rcl_interfaces__msg__ParameterValue(
        &array_ptr[i], cdr);
    }
  }

  // Field name: publishers
  {
    size_t size = ros_message->publishers.size;
    auto array_ptr = ros_message->publishers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosgraph_msgs__msg__Topic(
        &array_ptr[i], cdr);
    }
  }

  // Field name: subscriptions
  {
    size_t size = ros_message->subscriptions.size;
    auto array_ptr = ros_message->subscriptions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosgraph_msgs__msg__Topic(
        &array_ptr[i], cdr);
    }
  }

  // Field name: service_clients
  {
    size_t size = ros_message->service_clients.size;
    auto array_ptr = ros_message->service_clients.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosgraph_msgs__msg__Service(
        &array_ptr[i], cdr);
    }
  }

  // Field name: service_servers
  {
    size_t size = ros_message->service_servers.size;
    auto array_ptr = ros_message->service_servers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosgraph_msgs__msg__Service(
        &array_ptr[i], cdr);
    }
  }

  // Field name: action_clients
  {
    size_t size = ros_message->action_clients.size;
    auto array_ptr = ros_message->action_clients.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosgraph_msgs__msg__Action(
        &array_ptr[i], cdr);
    }
  }

  // Field name: action_servers
  {
    size_t size = ros_message->action_servers.size;
    auto array_ptr = ros_message->action_servers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosgraph_msgs__msg__Action(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosgraph_msgs__msg__Node(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Node__ros_msg_type * ros_message = static_cast<const _Node__ros_msg_type *>(untyped_ros_message);
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

  // Field name: parameters
  {
    size_t array_size = ros_message->parameters.size;
    auto array_ptr = ros_message->parameters.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: parameter_values
  {
    size_t array_size = ros_message->parameter_values.size;
    auto array_ptr = ros_message->parameter_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rcl_interfaces__msg__ParameterValue(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: publishers
  {
    size_t array_size = ros_message->publishers.size;
    auto array_ptr = ros_message->publishers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__Topic(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: subscriptions
  {
    size_t array_size = ros_message->subscriptions.size;
    auto array_ptr = ros_message->subscriptions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__Topic(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: service_clients
  {
    size_t array_size = ros_message->service_clients.size;
    auto array_ptr = ros_message->service_clients.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__Service(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: service_servers
  {
    size_t array_size = ros_message->service_servers.size;
    auto array_ptr = ros_message->service_servers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__Service(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: action_clients
  {
    size_t array_size = ros_message->action_clients.size;
    auto array_ptr = ros_message->action_clients.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__Action(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: action_servers
  {
    size_t array_size = ros_message->action_servers.size;
    auto array_ptr = ros_message->action_servers.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosgraph_msgs__msg__Action(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosgraph_msgs__msg__Node(
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

  // Field name: parameters
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
        impl_max_serialized_size_key_rcl_interfaces__msg__ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: parameter_values
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
        impl_max_serialized_size_key_rcl_interfaces__msg__ParameterValue(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: publishers
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
        impl_max_serialized_size_key_rosgraph_msgs__msg__Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: subscriptions
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
        impl_max_serialized_size_key_rosgraph_msgs__msg__Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: service_clients
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
        impl_max_serialized_size_key_rosgraph_msgs__msg__Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: service_servers
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
        impl_max_serialized_size_key_rosgraph_msgs__msg__Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: action_clients
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
        impl_max_serialized_size_key_rosgraph_msgs__msg__Action(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: action_servers
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
        impl_max_serialized_size_key_rosgraph_msgs__msg__Action(
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
    using DataType = rosgraph_msgs__msg__Node;
    is_plain =
      (
      offsetof(DataType, action_servers) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Node(
  const rosgraph_msgs__msg__Node * ros_message,
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

  // Field name: parameters
  {
    size_t size = ros_message->parameters.size;
    auto array_ptr = ros_message->parameters.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: parameter_values
  {
    size_t size = ros_message->parameter_values.size;
    auto array_ptr = ros_message->parameter_values.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rcl_interfaces__msg__ParameterValue(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: publishers
  {
    size_t size = ros_message->publishers.size;
    auto array_ptr = ros_message->publishers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Topic(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: subscriptions
  {
    size_t size = ros_message->subscriptions.size;
    auto array_ptr = ros_message->subscriptions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Topic(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: service_clients
  {
    size_t size = ros_message->service_clients.size;
    auto array_ptr = ros_message->service_clients.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Service(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: service_servers
  {
    size_t size = ros_message->service_servers.size;
    auto array_ptr = ros_message->service_servers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Service(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: action_clients
  {
    size_t size = ros_message->action_clients.size;
    auto array_ptr = ros_message->action_clients.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Action(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: action_servers
  {
    size_t size = ros_message->action_servers.size;
    auto array_ptr = ros_message->action_servers.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosgraph_msgs__msg__Action(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Node(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs__msg__Node * ros_message,
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

  // Field name: parameters
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

    if (ros_message->parameters.data) {
      rcl_interfaces__msg__ParameterDescriptor__Sequence__fini(&ros_message->parameters);
    }
    if (!rcl_interfaces__msg__ParameterDescriptor__Sequence__init(&ros_message->parameters, size)) {
      fprintf(stderr, "failed to create array for field 'parameters'");
      return false;
    }
    auto array_ptr = ros_message->parameters.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterDescriptor(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: parameter_values
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

    if (ros_message->parameter_values.data) {
      rcl_interfaces__msg__ParameterValue__Sequence__fini(&ros_message->parameter_values);
    }
    if (!rcl_interfaces__msg__ParameterValue__Sequence__init(&ros_message->parameter_values, size)) {
      fprintf(stderr, "failed to create array for field 'parameter_values'");
      return false;
    }
    auto array_ptr = ros_message->parameter_values.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rcl_interfaces__msg__ParameterValue(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: publishers
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

    if (ros_message->publishers.data) {
      rosgraph_msgs__msg__Topic__Sequence__fini(&ros_message->publishers);
    }
    if (!rosgraph_msgs__msg__Topic__Sequence__init(&ros_message->publishers, size)) {
      fprintf(stderr, "failed to create array for field 'publishers'");
      return false;
    }
    auto array_ptr = ros_message->publishers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Topic(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: subscriptions
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

    if (ros_message->subscriptions.data) {
      rosgraph_msgs__msg__Topic__Sequence__fini(&ros_message->subscriptions);
    }
    if (!rosgraph_msgs__msg__Topic__Sequence__init(&ros_message->subscriptions, size)) {
      fprintf(stderr, "failed to create array for field 'subscriptions'");
      return false;
    }
    auto array_ptr = ros_message->subscriptions.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Topic(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: service_clients
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

    if (ros_message->service_clients.data) {
      rosgraph_msgs__msg__Service__Sequence__fini(&ros_message->service_clients);
    }
    if (!rosgraph_msgs__msg__Service__Sequence__init(&ros_message->service_clients, size)) {
      fprintf(stderr, "failed to create array for field 'service_clients'");
      return false;
    }
    auto array_ptr = ros_message->service_clients.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Service(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: service_servers
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

    if (ros_message->service_servers.data) {
      rosgraph_msgs__msg__Service__Sequence__fini(&ros_message->service_servers);
    }
    if (!rosgraph_msgs__msg__Service__Sequence__init(&ros_message->service_servers, size)) {
      fprintf(stderr, "failed to create array for field 'service_servers'");
      return false;
    }
    auto array_ptr = ros_message->service_servers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Service(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: action_clients
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

    if (ros_message->action_clients.data) {
      rosgraph_msgs__msg__Action__Sequence__fini(&ros_message->action_clients);
    }
    if (!rosgraph_msgs__msg__Action__Sequence__init(&ros_message->action_clients, size)) {
      fprintf(stderr, "failed to create array for field 'action_clients'");
      return false;
    }
    auto array_ptr = ros_message->action_clients.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Action(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: action_servers
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

    if (ros_message->action_servers.data) {
      rosgraph_msgs__msg__Action__Sequence__fini(&ros_message->action_servers);
    }
    if (!rosgraph_msgs__msg__Action__Sequence__init(&ros_message->action_servers, size)) {
      fprintf(stderr, "failed to create array for field 'action_servers'");
      return false;
    }
    auto array_ptr = ros_message->action_servers.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosgraph_msgs__msg__Action(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__NODE__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
