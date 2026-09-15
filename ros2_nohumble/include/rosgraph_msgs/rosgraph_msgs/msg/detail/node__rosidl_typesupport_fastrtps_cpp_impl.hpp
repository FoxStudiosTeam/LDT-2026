// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support_impl.hpp.em
// with input from rosgraph_msgs:msg\Node.idl
// generated code does not contain a copyright notice

#ifndef ROSGRAPH_MSGS__MSG__DETAIL__NODE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__NODE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_

#include <cstddef>
#include <cstdio>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include "rcutils/logging_macros.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosgraph_msgs/msg/detail/node__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fastcdr/Cdr.h"

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rcl_interfaces/msg/detail/parameter_descriptor__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "rcl_interfaces/msg/detail/parameter_value__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "rosgraph_msgs/msg/detail/topic__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "rosgraph_msgs/msg/detail/topic__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "rosgraph_msgs/msg/detail/service__rosidl_typesupport_fastrtps_cpp_impl.hpp"
#include "rosgraph_msgs/msg/detail/action__rosidl_typesupport_fastrtps_cpp_impl.hpp"
// already included above
// #include "rosgraph_msgs/msg/detail/action__rosidl_typesupport_fastrtps_cpp_impl.hpp"


namespace rosgraph_msgs
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
  const rosgraph_msgs::msg::Node & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;

  // Member: parameters
  {
    size_t size = ros_message.parameters.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.parameters[i],
        cdr);
    }
  }

  // Member: parameter_values
  {
    size_t size = ros_message.parameter_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.parameter_values[i],
        cdr);
    }
  }

  // Member: publishers
  {
    size_t size = ros_message.publishers.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.publishers[i],
        cdr);
    }
  }

  // Member: subscriptions
  {
    size_t size = ros_message.subscriptions.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.subscriptions[i],
        cdr);
    }
  }

  // Member: service_clients
  {
    size_t size = ros_message.service_clients.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.service_clients[i],
        cdr);
    }
  }

  // Member: service_servers
  {
    size_t size = ros_message.service_servers.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.service_servers[i],
        cdr);
    }
  }

  // Member: action_clients
  {
    size_t size = ros_message.action_clients.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.action_clients[i],
        cdr);
    }
  }

  // Member: action_servers
  {
    size_t size = ros_message.action_servers.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize(
        ros_message.action_servers[i],
        cdr);
    }
  }

  return true;
}

inline
bool
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosgraph_msgs::msg::Node & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: parameters
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

    ros_message.parameters.resize(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.parameters[i]);
    }
  }

  // Member: parameter_values
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

    ros_message.parameter_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.parameter_values[i]);
    }
  }

  // Member: publishers
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

    ros_message.publishers.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.publishers[i]);
    }
  }

  // Member: subscriptions
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

    ros_message.subscriptions.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.subscriptions[i]);
    }
  }

  // Member: service_clients
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

    ros_message.service_clients.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.service_clients[i]);
    }
  }

  // Member: service_servers
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

    ros_message.service_servers.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.service_servers[i]);
    }
  }

  // Member: action_clients
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

    ros_message.action_clients.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.action_clients[i]);
    }
  }

  // Member: action_servers
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

    ros_message.action_servers.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize(
        cdr, ros_message.action_servers[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

// Endpoint-aware serialization. Always emitted so parent messages can recurse
// through non-Buffer intermediate message types.
inline
bool
cdr_serialize_with_endpoint(
  const rosgraph_msgs::msg::Node & ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  try {
    // Member: name
    cdr << ros_message.name;
    // Member: parameters
    {
      size_t size = ros_message.parameters.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.parameters[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: parameter_values
    {
      size_t size = ros_message.parameter_values.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.parameter_values[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: publishers
    {
      size_t size = ros_message.publishers.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.publishers[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: subscriptions
    {
      size_t size = ros_message.subscriptions.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.subscriptions[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: service_clients
    {
      size_t size = ros_message.service_clients.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.service_clients[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: service_servers
    {
      size_t size = ros_message.service_servers.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.service_servers[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: action_clients
    {
      size_t size = ros_message.action_clients.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.action_clients[i],
          cdr, endpoint_info, serialization_context);
      }
    }
    // Member: action_servers
    {
      size_t size = ros_message.action_servers.size();
      cdr << static_cast<uint32_t>(size);
      for (size_t i = 0; i < size; i++) {
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_with_endpoint(
          ros_message.action_servers[i],
          cdr, endpoint_info, serialization_context);
      }
    }
  } catch (const std::exception & e) {
    RCUTILS_LOG_ERROR_NAMED(
      "rosgraph_msgs.typesupport_fastrtps_cpp",
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
  rosgraph_msgs::msg::Node & ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Member: name
  cdr >> ros_message.name;

  // Member: parameters
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

    ros_message.parameters.resize(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.parameters[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: parameter_values
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

    ros_message.parameter_values.resize(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.parameter_values[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: publishers
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

    ros_message.publishers.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.publishers[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: subscriptions
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

    ros_message.subscriptions.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.subscriptions[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: service_clients
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

    ros_message.service_clients.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.service_clients[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: service_servers
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

    ros_message.service_servers.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.service_servers[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: action_clients
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

    ros_message.action_clients.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.action_clients[i],
        endpoint_info,
        serialization_context);
    }
  }

  // Member: action_servers
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

    ros_message.action_servers.resize(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_deserialize_with_endpoint(
        cdr,
        ros_message.action_servers[i],
        endpoint_info,
        serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

inline
size_t
get_serialized_size(
  const rosgraph_msgs::msg::Node & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);

  // Member: parameters
  {
    size_t array_size = ros_message.parameters.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.parameters[index], current_alignment);
    }
  }

  // Member: parameter_values
  {
    size_t array_size = ros_message.parameter_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.parameter_values[index], current_alignment);
    }
  }

  // Member: publishers
  {
    size_t array_size = ros_message.publishers.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.publishers[index], current_alignment);
    }
  }

  // Member: subscriptions
  {
    size_t array_size = ros_message.subscriptions.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.subscriptions[index], current_alignment);
    }
  }

  // Member: service_clients
  {
    size_t array_size = ros_message.service_clients.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.service_clients[index], current_alignment);
    }
  }

  // Member: service_servers
  {
    size_t array_size = ros_message.service_servers.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.service_servers[index], current_alignment);
    }
  }

  // Member: action_clients
  {
    size_t array_size = ros_message.action_clients.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.action_clients[index], current_alignment);
    }
  }

  // Member: action_servers
  {
    size_t array_size = ros_message.action_servers.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size(
        ros_message.action_servers[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t
max_serialized_size_Node(
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

  // Member: name
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
  // Member: parameters
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
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: parameter_values
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
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_ParameterValue(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: publishers
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: subscriptions
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: service_clients
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: service_servers
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: action_clients
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Action(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: action_servers
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_Action(
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
    using DataType = rosgraph_msgs::msg::Node;
    is_plain =
      (
      offsetof(DataType, action_servers) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

inline
bool
cdr_serialize_key(
  const rosgraph_msgs::msg::Node & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;

  // Member: parameters
  {
    size_t size = ros_message.parameters.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.parameters[i],
        cdr);
    }
  }

  // Member: parameter_values
  {
    size_t size = ros_message.parameter_values.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.parameter_values[i],
        cdr);
    }
  }

  // Member: publishers
  {
    size_t size = ros_message.publishers.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.publishers[i],
        cdr);
    }
  }

  // Member: subscriptions
  {
    size_t size = ros_message.subscriptions.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.subscriptions[i],
        cdr);
    }
  }

  // Member: service_clients
  {
    size_t size = ros_message.service_clients.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.service_clients[i],
        cdr);
    }
  }

  // Member: service_servers
  {
    size_t size = ros_message.service_servers.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.service_servers[i],
        cdr);
    }
  }

  // Member: action_clients
  {
    size_t size = ros_message.action_clients.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.action_clients[i],
        cdr);
    }
  }

  // Member: action_servers
  {
    size_t size = ros_message.action_servers.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::cdr_serialize_key(
        ros_message.action_servers[i],
        cdr);
    }
  }

  return true;
}

inline
size_t
get_serialized_size_key(
  const rosgraph_msgs::msg::Node & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);

  // Member: parameters
  {
    size_t array_size = ros_message.parameters.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.parameters[index], current_alignment);
    }
  }

  // Member: parameter_values
  {
    size_t array_size = ros_message.parameter_values.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.parameter_values[index], current_alignment);
    }
  }

  // Member: publishers
  {
    size_t array_size = ros_message.publishers.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.publishers[index], current_alignment);
    }
  }

  // Member: subscriptions
  {
    size_t array_size = ros_message.subscriptions.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.subscriptions[index], current_alignment);
    }
  }

  // Member: service_clients
  {
    size_t array_size = ros_message.service_clients.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.service_clients[index], current_alignment);
    }
  }

  // Member: service_servers
  {
    size_t array_size = ros_message.service_servers.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.service_servers[index], current_alignment);
    }
  }

  // Member: action_clients
  {
    size_t array_size = ros_message.action_clients.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.action_clients[index], current_alignment);
    }
  }

  // Member: action_servers
  {
    size_t array_size = ros_message.action_servers.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::get_serialized_size_key(
        ros_message.action_servers[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t
max_serialized_size_key_Node(
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

  // Member: name
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

  // Member: parameters
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
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_ParameterDescriptor(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: parameter_values
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
        rcl_interfaces::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_ParameterValue(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: publishers
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: subscriptions
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Topic(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: service_clients
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: service_servers
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Service(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: action_clients
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Action(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: action_servers
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
        rosgraph_msgs::msg::typesupport_fastrtps_cpp::detail::max_serialized_size_key_Action(
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
    using DataType = rosgraph_msgs::msg::Node;
    is_plain =
      (
      offsetof(DataType, action_servers) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

}  // namespace detail

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__NODE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPL_HPP_
