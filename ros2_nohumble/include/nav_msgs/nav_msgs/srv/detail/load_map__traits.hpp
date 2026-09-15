// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_msgs:srv\LoadMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/srv/load_map.hpp"


#ifndef NAV_MSGS__SRV__DETAIL__LOAD_MAP__TRAITS_HPP_
#define NAV_MSGS__SRV__DETAIL__LOAD_MAP__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "nav_msgs/srv/detail/load_map__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace nav_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadMap_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: map_url
  {
    out << "map_url: ";
    rosidl_generator_traits::value_to_yaml(msg.map_url, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LoadMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map_url
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_url: ";
    rosidl_generator_traits::value_to_yaml(msg.map_url, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LoadMap_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, nav_msgs::srv::LoadMap_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).map_url);
}

}  // namespace srv

}  // namespace nav_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<nav_msgs::srv::LoadMap_Request>()
{
  return "nav_msgs::srv::LoadMap_Request";
}

template<>
constexpr const char * name<nav_msgs::srv::LoadMap_Request>()
{
  return "nav_msgs/srv/LoadMap_Request";
}

template<>
struct has_fixed_size<nav_msgs::srv::LoadMap_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_msgs::srv::LoadMap_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nav_msgs::srv::LoadMap_Request>
  : std::true_type {};

template<>
struct MessageTraits<nav_msgs::srv::LoadMap_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "map_url",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'map'
#include "nav_msgs/msg/detail/occupancy_grid__traits.hpp"

namespace nav_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: map
  {
    out << "map: ";
    to_flow_style_yaml(msg.map, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LoadMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map:\n";
    to_block_style_yaml(msg.map, out, indentation + 2);
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LoadMap_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, nav_msgs::srv::LoadMap_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).map,
    std::forward<T>(msg).result);
}

}  // namespace srv

}  // namespace nav_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<nav_msgs::srv::LoadMap_Response>()
{
  return "nav_msgs::srv::LoadMap_Response";
}

template<>
constexpr const char * name<nav_msgs::srv::LoadMap_Response>()
{
  return "nav_msgs/srv/LoadMap_Response";
}

template<>
struct has_fixed_size<nav_msgs::srv::LoadMap_Response>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::OccupancyGrid>::value> {};

template<>
struct has_bounded_size<nav_msgs::srv::LoadMap_Response>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::OccupancyGrid>::value> {};

template<>
struct is_message<nav_msgs::srv::LoadMap_Response>
  : std::true_type {};

template<>
struct MessageTraits<nav_msgs::srv::LoadMap_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "map",
    "result",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace nav_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadMap_Event & msg,
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
  const LoadMap_Event & msg,
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

inline std::string to_yaml(const LoadMap_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, nav_msgs::srv::LoadMap_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace nav_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<nav_msgs::srv::LoadMap_Event>()
{
  return "nav_msgs::srv::LoadMap_Event";
}

template<>
constexpr const char * name<nav_msgs::srv::LoadMap_Event>()
{
  return "nav_msgs/srv/LoadMap_Event";
}

template<>
struct has_fixed_size<nav_msgs::srv::LoadMap_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_msgs::srv::LoadMap_Event>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::srv::LoadMap_Request>::value && has_bounded_size<nav_msgs::srv::LoadMap_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<nav_msgs::srv::LoadMap_Event>
  : std::true_type {};

template<>
struct MessageTraits<nav_msgs::srv::LoadMap_Event>
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
constexpr const char * data_type<nav_msgs::srv::LoadMap>()
{
  return "nav_msgs::srv::LoadMap";
}

template<>
constexpr const char * name<nav_msgs::srv::LoadMap>()
{
  return "nav_msgs/srv/LoadMap";
}

template<>
struct has_fixed_size<nav_msgs::srv::LoadMap>
  : std::integral_constant<
    bool,
    has_fixed_size<nav_msgs::srv::LoadMap_Request>::value &&
    has_fixed_size<nav_msgs::srv::LoadMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<nav_msgs::srv::LoadMap>
  : std::integral_constant<
    bool,
    has_bounded_size<nav_msgs::srv::LoadMap_Request>::value &&
    has_bounded_size<nav_msgs::srv::LoadMap_Response>::value
  >
{
};

template<>
struct is_service<nav_msgs::srv::LoadMap>
  : std::true_type
{
};

template<>
struct is_service_request<nav_msgs::srv::LoadMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nav_msgs::srv::LoadMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAV_MSGS__SRV__DETAIL__LOAD_MAP__TRAITS_HPP_
