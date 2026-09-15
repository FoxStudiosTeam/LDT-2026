// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from type_description_interfaces:msg\TypeDescription.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "type_description_interfaces/msg/type_description.hpp"


#ifndef TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__TRAITS_HPP_
#define TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "type_description_interfaces/msg/detail/type_description__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'type_description'
// Member 'referenced_type_descriptions'
#include "type_description_interfaces/msg/detail/individual_type_description__traits.hpp"

namespace type_description_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TypeDescription & msg,
  std::ostream & out)
{
  out << "{";
  // member: type_description
  {
    out << "type_description: ";
    to_flow_style_yaml(msg.type_description, out);
    out << ", ";
  }

  // member: referenced_type_descriptions
  {
    if (msg.referenced_type_descriptions.size() == 0) {
      out << "referenced_type_descriptions: []";
    } else {
      out << "referenced_type_descriptions: [";
      size_t pending_items = msg.referenced_type_descriptions.size();
      for (auto item : msg.referenced_type_descriptions) {
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
  const TypeDescription & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_description:\n";
    to_block_style_yaml(msg.type_description, out, indentation + 2);
  }

  // member: referenced_type_descriptions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.referenced_type_descriptions.size() == 0) {
      out << "referenced_type_descriptions: []\n";
    } else {
      out << "referenced_type_descriptions:\n";
      for (auto item : msg.referenced_type_descriptions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TypeDescription & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, type_description_interfaces::msg::TypeDescription>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).type_description,
    std::forward<T>(msg).referenced_type_descriptions);
}

}  // namespace msg

}  // namespace type_description_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<type_description_interfaces::msg::TypeDescription>()
{
  return "type_description_interfaces::msg::TypeDescription";
}

template<>
constexpr const char * name<type_description_interfaces::msg::TypeDescription>()
{
  return "type_description_interfaces/msg/TypeDescription";
}

template<>
struct has_fixed_size<type_description_interfaces::msg::TypeDescription>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<type_description_interfaces::msg::TypeDescription>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<type_description_interfaces::msg::TypeDescription>
  : std::true_type {};

template<>
struct MessageTraits<type_description_interfaces::msg::TypeDescription>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "type_description",
    "referenced_type_descriptions",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_DESCRIPTION__TRAITS_HPP_
