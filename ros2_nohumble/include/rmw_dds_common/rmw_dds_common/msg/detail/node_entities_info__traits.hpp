// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmw_dds_common:msg\NodeEntitiesInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rmw_dds_common/msg/node_entities_info.hpp"


#ifndef RMW_DDS_COMMON__MSG__DETAIL__NODE_ENTITIES_INFO__TRAITS_HPP_
#define RMW_DDS_COMMON__MSG__DETAIL__NODE_ENTITIES_INFO__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rmw_dds_common/msg/detail/node_entities_info__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'reader_gid_seq'
// Member 'writer_gid_seq'
#include "rmw_dds_common/msg/detail/gid__traits.hpp"

namespace rmw_dds_common
{

namespace msg
{

inline void to_flow_style_yaml(
  const NodeEntitiesInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: node_namespace
  {
    out << "node_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.node_namespace, out);
    out << ", ";
  }

  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << ", ";
  }

  // member: reader_gid_seq
  {
    if (msg.reader_gid_seq.size() == 0) {
      out << "reader_gid_seq: []";
    } else {
      out << "reader_gid_seq: [";
      size_t pending_items = msg.reader_gid_seq.size();
      for (auto item : msg.reader_gid_seq) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: writer_gid_seq
  {
    if (msg.writer_gid_seq.size() == 0) {
      out << "writer_gid_seq: []";
    } else {
      out << "writer_gid_seq: [";
      size_t pending_items = msg.writer_gid_seq.size();
      for (auto item : msg.writer_gid_seq) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NodeEntitiesInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: node_namespace
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.node_namespace, out);
    out << "\n";
  }

  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }

  // member: reader_gid_seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reader_gid_seq.size() == 0) {
      out << "reader_gid_seq: []\n";
    } else {
      out << "reader_gid_seq:\n";
      for (auto item : msg.reader_gid_seq) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: writer_gid_seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.writer_gid_seq.size() == 0) {
      out << "writer_gid_seq: []\n";
    } else {
      out << "writer_gid_seq:\n";
      for (auto item : msg.writer_gid_seq) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NodeEntitiesInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rmw_dds_common::msg::NodeEntitiesInfo>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).node_namespace,
    std::forward<T>(msg).node_name,
    std::forward<T>(msg).reader_gid_seq,
    std::forward<T>(msg).writer_gid_seq);
}

}  // namespace msg

}  // namespace rmw_dds_common

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rmw_dds_common::msg::NodeEntitiesInfo>()
{
  return "rmw_dds_common::msg::NodeEntitiesInfo";
}

template<>
constexpr const char * name<rmw_dds_common::msg::NodeEntitiesInfo>()
{
  return "rmw_dds_common/msg/NodeEntitiesInfo";
}

template<>
struct has_fixed_size<rmw_dds_common::msg::NodeEntitiesInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmw_dds_common::msg::NodeEntitiesInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmw_dds_common::msg::NodeEntitiesInfo>
  : std::true_type {};

template<>
struct MessageTraits<rmw_dds_common::msg::NodeEntitiesInfo>
{
  static constexpr std::size_t member_count = 4;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "node_namespace",
    "node_name",
    "reader_gid_seq",
    "writer_gid_seq",
  };
};

}  // namespace rosidl_generator_traits

#endif  // RMW_DDS_COMMON__MSG__DETAIL__NODE_ENTITIES_INFO__TRAITS_HPP_
