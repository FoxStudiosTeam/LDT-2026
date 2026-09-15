// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from type_description_interfaces:msg\TypeSource.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "type_description_interfaces/msg/type_source.hpp"


#ifndef TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_SOURCE__TRAITS_HPP_
#define TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_SOURCE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "type_description_interfaces/msg/detail/type_source__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace type_description_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TypeSource & msg,
  std::ostream & out)
{
  out << "{";
  // member: type_name
  {
    out << "type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.type_name, out);
    out << ", ";
  }

  // member: encoding
  {
    out << "encoding: ";
    rosidl_generator_traits::value_to_yaml(msg.encoding, out);
    out << ", ";
  }

  // member: raw_file_contents
  {
    out << "raw_file_contents: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_file_contents, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TypeSource & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.type_name, out);
    out << "\n";
  }

  // member: encoding
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoding: ";
    rosidl_generator_traits::value_to_yaml(msg.encoding, out);
    out << "\n";
  }

  // member: raw_file_contents
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_file_contents: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_file_contents, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TypeSource & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, type_description_interfaces::msg::TypeSource>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).type_name,
    std::forward<T>(msg).encoding,
    std::forward<T>(msg).raw_file_contents);
}

}  // namespace msg

}  // namespace type_description_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<type_description_interfaces::msg::TypeSource>()
{
  return "type_description_interfaces::msg::TypeSource";
}

template<>
constexpr const char * name<type_description_interfaces::msg::TypeSource>()
{
  return "type_description_interfaces/msg/TypeSource";
}

template<>
struct has_fixed_size<type_description_interfaces::msg::TypeSource>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<type_description_interfaces::msg::TypeSource>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<type_description_interfaces::msg::TypeSource>
  : std::true_type {};

template<>
struct MessageTraits<type_description_interfaces::msg::TypeSource>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "type_name",
    "encoding",
    "raw_file_contents",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__TYPE_SOURCE__TRAITS_HPP_
