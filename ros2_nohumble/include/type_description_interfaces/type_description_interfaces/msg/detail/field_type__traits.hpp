// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from type_description_interfaces:msg\FieldType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "type_description_interfaces/msg/field_type.hpp"


#ifndef TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__FIELD_TYPE__TRAITS_HPP_
#define TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__FIELD_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "type_description_interfaces/msg/detail/field_type__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace type_description_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FieldType & msg,
  std::ostream & out)
{
  out << "{";
  // member: type_id
  {
    out << "type_id: ";
    rosidl_generator_traits::value_to_yaml(msg.type_id, out);
    out << ", ";
  }

  // member: capacity
  {
    out << "capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity, out);
    out << ", ";
  }

  // member: string_capacity
  {
    out << "string_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.string_capacity, out);
    out << ", ";
  }

  // member: nested_type_name
  {
    out << "nested_type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.nested_type_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FieldType & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_id: ";
    rosidl_generator_traits::value_to_yaml(msg.type_id, out);
    out << "\n";
  }

  // member: capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity, out);
    out << "\n";
  }

  // member: string_capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.string_capacity, out);
    out << "\n";
  }

  // member: nested_type_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nested_type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.nested_type_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FieldType & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, type_description_interfaces::msg::FieldType>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).type_id,
    std::forward<T>(msg).capacity,
    std::forward<T>(msg).string_capacity,
    std::forward<T>(msg).nested_type_name);
}

}  // namespace msg

}  // namespace type_description_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<type_description_interfaces::msg::FieldType>()
{
  return "type_description_interfaces::msg::FieldType";
}

template<>
constexpr const char * name<type_description_interfaces::msg::FieldType>()
{
  return "type_description_interfaces/msg/FieldType";
}

template<>
struct has_fixed_size<type_description_interfaces::msg::FieldType>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<type_description_interfaces::msg::FieldType>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<type_description_interfaces::msg::FieldType>
  : std::true_type {};

template<>
struct MessageTraits<type_description_interfaces::msg::FieldType>
{
  static constexpr std::size_t member_count = 4;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "type_id",
    "capacity",
    "string_capacity",
    "nested_type_name",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TYPE_DESCRIPTION_INTERFACES__MSG__DETAIL__FIELD_TYPE__TRAITS_HPP_
