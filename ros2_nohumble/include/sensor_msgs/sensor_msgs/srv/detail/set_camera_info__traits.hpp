// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:srv\SetCameraInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/srv/set_camera_info.hpp"


#ifndef SENSOR_MSGS__SRV__DETAIL__SET_CAMERA_INFO__TRAITS_HPP_
#define SENSOR_MSGS__SRV__DETAIL__SET_CAMERA_INFO__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/srv/detail/set_camera_info__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__traits.hpp"

namespace sensor_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetCameraInfo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: camera_info
  {
    out << "camera_info: ";
    to_flow_style_yaml(msg.camera_info, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetCameraInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: camera_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_info:\n";
    to_block_style_yaml(msg.camera_info, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetCameraInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::srv::SetCameraInfo_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).camera_info);
}

}  // namespace srv

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::srv::SetCameraInfo_Request>()
{
  return "sensor_msgs::srv::SetCameraInfo_Request";
}

template<>
constexpr const char * name<sensor_msgs::srv::SetCameraInfo_Request>()
{
  return "sensor_msgs/srv/SetCameraInfo_Request";
}

template<>
struct has_fixed_size<sensor_msgs::srv::SetCameraInfo_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::CameraInfo>::value> {};

template<>
struct has_bounded_size<sensor_msgs::srv::SetCameraInfo_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::CameraInfo>::value> {};

template<>
struct is_message<sensor_msgs::srv::SetCameraInfo_Request>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::srv::SetCameraInfo_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "camera_info",
  };
};

}  // namespace rosidl_generator_traits

namespace sensor_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetCameraInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetCameraInfo_Response & msg,
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

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetCameraInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::srv::SetCameraInfo_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).success,
    std::forward<T>(msg).status_message);
}

}  // namespace srv

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::srv::SetCameraInfo_Response>()
{
  return "sensor_msgs::srv::SetCameraInfo_Response";
}

template<>
constexpr const char * name<sensor_msgs::srv::SetCameraInfo_Response>()
{
  return "sensor_msgs/srv/SetCameraInfo_Response";
}

template<>
struct has_fixed_size<sensor_msgs::srv::SetCameraInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::srv::SetCameraInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_msgs::srv::SetCameraInfo_Response>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::srv::SetCameraInfo_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "success",
    "status_message",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace sensor_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetCameraInfo_Event & msg,
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
  const SetCameraInfo_Event & msg,
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

inline std::string to_yaml(const SetCameraInfo_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::srv::SetCameraInfo_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::srv::SetCameraInfo_Event>()
{
  return "sensor_msgs::srv::SetCameraInfo_Event";
}

template<>
constexpr const char * name<sensor_msgs::srv::SetCameraInfo_Event>()
{
  return "sensor_msgs/srv/SetCameraInfo_Event";
}

template<>
struct has_fixed_size<sensor_msgs::srv::SetCameraInfo_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::srv::SetCameraInfo_Event>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::srv::SetCameraInfo_Request>::value && has_bounded_size<sensor_msgs::srv::SetCameraInfo_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<sensor_msgs::srv::SetCameraInfo_Event>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::srv::SetCameraInfo_Event>
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
constexpr const char * data_type<sensor_msgs::srv::SetCameraInfo>()
{
  return "sensor_msgs::srv::SetCameraInfo";
}

template<>
constexpr const char * name<sensor_msgs::srv::SetCameraInfo>()
{
  return "sensor_msgs/srv/SetCameraInfo";
}

template<>
struct has_fixed_size<sensor_msgs::srv::SetCameraInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<sensor_msgs::srv::SetCameraInfo_Request>::value &&
    has_fixed_size<sensor_msgs::srv::SetCameraInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<sensor_msgs::srv::SetCameraInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<sensor_msgs::srv::SetCameraInfo_Request>::value &&
    has_bounded_size<sensor_msgs::srv::SetCameraInfo_Response>::value
  >
{
};

template<>
struct is_service<sensor_msgs::srv::SetCameraInfo>
  : std::true_type
{
};

template<>
struct is_service_request<sensor_msgs::srv::SetCameraInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sensor_msgs::srv::SetCameraInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__SRV__DETAIL__SET_CAMERA_INFO__TRAITS_HPP_
