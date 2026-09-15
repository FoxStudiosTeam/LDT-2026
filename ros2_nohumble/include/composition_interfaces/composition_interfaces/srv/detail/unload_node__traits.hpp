// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from composition_interfaces:srv\UnloadNode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "composition_interfaces/srv/unload_node.hpp"


#ifndef COMPOSITION_INTERFACES__SRV__DETAIL__UNLOAD_NODE__TRAITS_HPP_
#define COMPOSITION_INTERFACES__SRV__DETAIL__UNLOAD_NODE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "composition_interfaces/srv/detail/unload_node__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace composition_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnloadNode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: unique_id
  {
    out << "unique_id: ";
    rosidl_generator_traits::value_to_yaml(msg.unique_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UnloadNode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: unique_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unique_id: ";
    rosidl_generator_traits::value_to_yaml(msg.unique_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UnloadNode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, composition_interfaces::srv::UnloadNode_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).unique_id);
}

}  // namespace srv

}  // namespace composition_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<composition_interfaces::srv::UnloadNode_Request>()
{
  return "composition_interfaces::srv::UnloadNode_Request";
}

template<>
constexpr const char * name<composition_interfaces::srv::UnloadNode_Request>()
{
  return "composition_interfaces/srv/UnloadNode_Request";
}

template<>
struct has_fixed_size<composition_interfaces::srv::UnloadNode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<composition_interfaces::srv::UnloadNode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<composition_interfaces::srv::UnloadNode_Request>
  : std::true_type {};

template<>
struct MessageTraits<composition_interfaces::srv::UnloadNode_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "unique_id",
  };
};

}  // namespace rosidl_generator_traits

namespace composition_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnloadNode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_message
  {
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UnloadNode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: error_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UnloadNode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, composition_interfaces::srv::UnloadNode_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).success,
    std::forward<T>(msg).error_message);
}

}  // namespace srv

}  // namespace composition_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<composition_interfaces::srv::UnloadNode_Response>()
{
  return "composition_interfaces::srv::UnloadNode_Response";
}

template<>
constexpr const char * name<composition_interfaces::srv::UnloadNode_Response>()
{
  return "composition_interfaces/srv/UnloadNode_Response";
}

template<>
struct has_fixed_size<composition_interfaces::srv::UnloadNode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<composition_interfaces::srv::UnloadNode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<composition_interfaces::srv::UnloadNode_Response>
  : std::true_type {};

template<>
struct MessageTraits<composition_interfaces::srv::UnloadNode_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "success",
    "error_message",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace composition_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnloadNode_Event & msg,
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
  const UnloadNode_Event & msg,
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

inline std::string to_yaml(const UnloadNode_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, composition_interfaces::srv::UnloadNode_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace composition_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<composition_interfaces::srv::UnloadNode_Event>()
{
  return "composition_interfaces::srv::UnloadNode_Event";
}

template<>
constexpr const char * name<composition_interfaces::srv::UnloadNode_Event>()
{
  return "composition_interfaces/srv/UnloadNode_Event";
}

template<>
struct has_fixed_size<composition_interfaces::srv::UnloadNode_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<composition_interfaces::srv::UnloadNode_Event>
  : std::integral_constant<bool, has_bounded_size<composition_interfaces::srv::UnloadNode_Request>::value && has_bounded_size<composition_interfaces::srv::UnloadNode_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<composition_interfaces::srv::UnloadNode_Event>
  : std::true_type {};

template<>
struct MessageTraits<composition_interfaces::srv::UnloadNode_Event>
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
constexpr const char * data_type<composition_interfaces::srv::UnloadNode>()
{
  return "composition_interfaces::srv::UnloadNode";
}

template<>
constexpr const char * name<composition_interfaces::srv::UnloadNode>()
{
  return "composition_interfaces/srv/UnloadNode";
}

template<>
struct has_fixed_size<composition_interfaces::srv::UnloadNode>
  : std::integral_constant<
    bool,
    has_fixed_size<composition_interfaces::srv::UnloadNode_Request>::value &&
    has_fixed_size<composition_interfaces::srv::UnloadNode_Response>::value
  >
{
};

template<>
struct has_bounded_size<composition_interfaces::srv::UnloadNode>
  : std::integral_constant<
    bool,
    has_bounded_size<composition_interfaces::srv::UnloadNode_Request>::value &&
    has_bounded_size<composition_interfaces::srv::UnloadNode_Response>::value
  >
{
};

template<>
struct is_service<composition_interfaces::srv::UnloadNode>
  : std::true_type
{
};

template<>
struct is_service_request<composition_interfaces::srv::UnloadNode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<composition_interfaces::srv::UnloadNode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COMPOSITION_INTERFACES__SRV__DETAIL__UNLOAD_NODE__TRAITS_HPP_
