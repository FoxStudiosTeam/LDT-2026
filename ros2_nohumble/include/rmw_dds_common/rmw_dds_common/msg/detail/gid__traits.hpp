// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rmw_dds_common:msg\Gid.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rmw_dds_common/msg/gid.hpp"


#ifndef RMW_DDS_COMMON__MSG__DETAIL__GID__TRAITS_HPP_
#define RMW_DDS_COMMON__MSG__DETAIL__GID__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rmw_dds_common/msg/detail/gid__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rmw_dds_common
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gid & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const Gid & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gid & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rmw_dds_common::msg::Gid>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).data);
}

}  // namespace msg

}  // namespace rmw_dds_common

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rmw_dds_common::msg::Gid>()
{
  return "rmw_dds_common::msg::Gid";
}

template<>
constexpr const char * name<rmw_dds_common::msg::Gid>()
{
  return "rmw_dds_common/msg/Gid";
}

template<>
struct has_fixed_size<rmw_dds_common::msg::Gid>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rmw_dds_common::msg::Gid>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rmw_dds_common::msg::Gid>
  : std::true_type {};

template<>
struct MessageTraits<rmw_dds_common::msg::Gid>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "data",
  };
};

}  // namespace rosidl_generator_traits

#endif  // RMW_DDS_COMMON__MSG__DETAIL__GID__TRAITS_HPP_
