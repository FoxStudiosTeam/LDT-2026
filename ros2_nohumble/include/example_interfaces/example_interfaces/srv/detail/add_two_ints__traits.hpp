// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_interfaces:srv\AddTwoInts.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "example_interfaces/srv/add_two_ints.hpp"


#ifndef EXAMPLE_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__TRAITS_HPP_
#define EXAMPLE_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "example_interfaces/srv/detail/add_two_ints__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddTwoInts_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddTwoInts_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddTwoInts_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, example_interfaces::srv::AddTwoInts_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).a,
    std::forward<T>(msg).b);
}

}  // namespace srv

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::srv::AddTwoInts_Request>()
{
  return "example_interfaces::srv::AddTwoInts_Request";
}

template<>
constexpr const char * name<example_interfaces::srv::AddTwoInts_Request>()
{
  return "example_interfaces/srv/AddTwoInts_Request";
}

template<>
struct has_fixed_size<example_interfaces::srv::AddTwoInts_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<example_interfaces::srv::AddTwoInts_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<example_interfaces::srv::AddTwoInts_Request>
  : std::true_type {};

template<>
struct MessageTraits<example_interfaces::srv::AddTwoInts_Request>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "a",
    "b",
  };
};

}  // namespace rosidl_generator_traits

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddTwoInts_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sum
  {
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddTwoInts_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddTwoInts_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, example_interfaces::srv::AddTwoInts_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).sum);
}

}  // namespace srv

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::srv::AddTwoInts_Response>()
{
  return "example_interfaces::srv::AddTwoInts_Response";
}

template<>
constexpr const char * name<example_interfaces::srv::AddTwoInts_Response>()
{
  return "example_interfaces/srv/AddTwoInts_Response";
}

template<>
struct has_fixed_size<example_interfaces::srv::AddTwoInts_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<example_interfaces::srv::AddTwoInts_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<example_interfaces::srv::AddTwoInts_Response>
  : std::true_type {};

template<>
struct MessageTraits<example_interfaces::srv::AddTwoInts_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "sum",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace example_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddTwoInts_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
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
  const AddTwoInts_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddTwoInts_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, example_interfaces::srv::AddTwoInts_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace example_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::srv::AddTwoInts_Event>()
{
  return "example_interfaces::srv::AddTwoInts_Event";
}

template<>
constexpr const char * name<example_interfaces::srv::AddTwoInts_Event>()
{
  return "example_interfaces/srv/AddTwoInts_Event";
}

template<>
struct has_fixed_size<example_interfaces::srv::AddTwoInts_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<example_interfaces::srv::AddTwoInts_Event>
  : std::integral_constant<bool, has_bounded_size<example_interfaces::srv::AddTwoInts_Request>::value && has_bounded_size<example_interfaces::srv::AddTwoInts_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<example_interfaces::srv::AddTwoInts_Event>
  : std::true_type {};

template<>
struct MessageTraits<example_interfaces::srv::AddTwoInts_Event>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "info",
    "request",
    "response",
  };
};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<example_interfaces::srv::AddTwoInts>()
{
  return "example_interfaces::srv::AddTwoInts";
}

template<>
constexpr const char * name<example_interfaces::srv::AddTwoInts>()
{
  return "example_interfaces/srv/AddTwoInts";
}

template<>
struct has_fixed_size<example_interfaces::srv::AddTwoInts>
  : std::integral_constant<
    bool,
    has_fixed_size<example_interfaces::srv::AddTwoInts_Request>::value &&
    has_fixed_size<example_interfaces::srv::AddTwoInts_Response>::value
  >
{
};

template<>
struct has_bounded_size<example_interfaces::srv::AddTwoInts>
  : std::integral_constant<
    bool,
    has_bounded_size<example_interfaces::srv::AddTwoInts_Request>::value &&
    has_bounded_size<example_interfaces::srv::AddTwoInts_Response>::value
  >
{
};

template<>
struct is_service<example_interfaces::srv::AddTwoInts>
  : std::true_type
{
};

template<>
struct is_service_request<example_interfaces::srv::AddTwoInts_Request>
  : std::true_type
{
};

template<>
struct is_service_response<example_interfaces::srv::AddTwoInts_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__TRAITS_HPP_
