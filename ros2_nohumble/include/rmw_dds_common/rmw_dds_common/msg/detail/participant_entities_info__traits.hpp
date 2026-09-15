// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmw_dds_common:msg\ParticipantEntitiesInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rmw_dds_common/msg/participant_entities_info.hpp"


#ifndef RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__TRAITS_HPP_
#define RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rmw_dds_common/msg/detail/participant_entities_info__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gid'
#include "rmw_dds_common/msg/detail/gid__traits.hpp"
// Member 'node_entities_info_seq'
#include "rmw_dds_common/msg/detail/node_entities_info__traits.hpp"

namespace rmw_dds_common
{

namespace msg
{

inline void to_flow_style_yaml(
  const ParticipantEntitiesInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: gid
  {
    out << "gid: ";
    to_flow_style_yaml(msg.gid, out);
    out << ", ";
  }

  // member: node_entities_info_seq
  {
    if (msg.node_entities_info_seq.size() == 0) {
      out << "node_entities_info_seq: []";
    } else {
      out << "node_entities_info_seq: [";
      size_t pending_items = msg.node_entities_info_seq.size();
      for (auto item : msg.node_entities_info_seq) {
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
  const ParticipantEntitiesInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gid:\n";
    to_block_style_yaml(msg.gid, out, indentation + 2);
  }

  // member: node_entities_info_seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.node_entities_info_seq.size() == 0) {
      out << "node_entities_info_seq: []\n";
    } else {
      out << "node_entities_info_seq:\n";
      for (auto item : msg.node_entities_info_seq) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ParticipantEntitiesInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rmw_dds_common::msg::ParticipantEntitiesInfo>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).gid,
    std::forward<T>(msg).node_entities_info_seq);
}

}  // namespace msg

}  // namespace rmw_dds_common

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rmw_dds_common::msg::ParticipantEntitiesInfo>()
{
  return "rmw_dds_common::msg::ParticipantEntitiesInfo";
}

template<>
constexpr const char * name<rmw_dds_common::msg::ParticipantEntitiesInfo>()
{
  return "rmw_dds_common/msg/ParticipantEntitiesInfo";
}

template<>
struct has_fixed_size<rmw_dds_common::msg::ParticipantEntitiesInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rmw_dds_common::msg::ParticipantEntitiesInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rmw_dds_common::msg::ParticipantEntitiesInfo>
  : std::true_type {};

template<>
struct MessageTraits<rmw_dds_common::msg::ParticipantEntitiesInfo>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "gid",
    "node_entities_info_seq",
  };
};

}  // namespace rosidl_generator_traits

#endif  // RMW_DDS_COMMON__MSG__DETAIL__PARTICIPANT_ENTITIES_INFO__TRAITS_HPP_
