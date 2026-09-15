// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from resource_retriever_interfaces:srv\GetResource.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "resource_retriever_interfaces/srv/get_resource.hpp"


#ifndef RESOURCE_RETRIEVER_INTERFACES__SRV__DETAIL__GET_RESOURCE__TRAITS_HPP_
#define RESOURCE_RETRIEVER_INTERFACES__SRV__DETAIL__GET_RESOURCE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "resource_retriever_interfaces/srv/detail/get_resource__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace resource_retriever_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetResource_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: path
  {
    out << "path: ";
    rosidl_generator_traits::value_to_yaml(msg.path, out);
    out << ", ";
  }

  // member: etag
  {
    out << "etag: ";
    rosidl_generator_traits::value_to_yaml(msg.etag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetResource_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path: ";
    rosidl_generator_traits::value_to_yaml(msg.path, out);
    out << "\n";
  }

  // member: etag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "etag: ";
    rosidl_generator_traits::value_to_yaml(msg.etag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetResource_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, resource_retriever_interfaces::srv::GetResource_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).path,
    std::forward<T>(msg).etag);
}

}  // namespace srv

}  // namespace resource_retriever_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<resource_retriever_interfaces::srv::GetResource_Request>()
{
  return "resource_retriever_interfaces::srv::GetResource_Request";
}

template<>
constexpr const char * name<resource_retriever_interfaces::srv::GetResource_Request>()
{
  return "resource_retriever_interfaces/srv/GetResource_Request";
}

template<>
struct has_fixed_size<resource_retriever_interfaces::srv::GetResource_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<resource_retriever_interfaces::srv::GetResource_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<resource_retriever_interfaces::srv::GetResource_Request>
  : std::true_type {};

template<>
struct MessageTraits<resource_retriever_interfaces::srv::GetResource_Request>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "path",
    "etag",
  };
};

}  // namespace rosidl_generator_traits

namespace resource_retriever_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetResource_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status_code
  {
    out << "status_code: ";
    rosidl_generator_traits::value_to_yaml(msg.status_code, out);
    out << ", ";
  }

  // member: error_reason
  {
    out << "error_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.error_reason, out);
    out << ", ";
  }

  // member: expanded_path
  {
    out << "expanded_path: ";
    rosidl_generator_traits::value_to_yaml(msg.expanded_path, out);
    out << ", ";
  }

  // member: etag
  {
    out << "etag: ";
    rosidl_generator_traits::value_to_yaml(msg.etag, out);
    out << ", ";
  }

  // member: body
  {
    if (msg.body.size() == 0) {
      out << "body: []";
    } else {
      out << "body: [";
      size_t pending_items = msg.body.size();
      for (auto item : msg.body) {
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
  const GetResource_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_code: ";
    rosidl_generator_traits::value_to_yaml(msg.status_code, out);
    out << "\n";
  }

  // member: error_reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.error_reason, out);
    out << "\n";
  }

  // member: expanded_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "expanded_path: ";
    rosidl_generator_traits::value_to_yaml(msg.expanded_path, out);
    out << "\n";
  }

  // member: etag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "etag: ";
    rosidl_generator_traits::value_to_yaml(msg.etag, out);
    out << "\n";
  }

  // member: body
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.body.size() == 0) {
      out << "body: []\n";
    } else {
      out << "body:\n";
      for (auto item : msg.body) {
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

inline std::string to_yaml(const GetResource_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, resource_retriever_interfaces::srv::GetResource_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).status_code,
    std::forward<T>(msg).error_reason,
    std::forward<T>(msg).expanded_path,
    std::forward<T>(msg).etag,
    std::forward<T>(msg).body);
}

}  // namespace srv

}  // namespace resource_retriever_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<resource_retriever_interfaces::srv::GetResource_Response>()
{
  return "resource_retriever_interfaces::srv::GetResource_Response";
}

template<>
constexpr const char * name<resource_retriever_interfaces::srv::GetResource_Response>()
{
  return "resource_retriever_interfaces/srv/GetResource_Response";
}

template<>
struct has_fixed_size<resource_retriever_interfaces::srv::GetResource_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<resource_retriever_interfaces::srv::GetResource_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<resource_retriever_interfaces::srv::GetResource_Response>
  : std::true_type {};

template<>
struct MessageTraits<resource_retriever_interfaces::srv::GetResource_Response>
{
  static constexpr std::size_t member_count = 5;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "status_code",
    "error_reason",
    "expanded_path",
    "etag",
    "body",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace resource_retriever_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetResource_Event & msg,
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
  const GetResource_Event & msg,
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

inline std::string to_yaml(const GetResource_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, resource_retriever_interfaces::srv::GetResource_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace resource_retriever_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<resource_retriever_interfaces::srv::GetResource_Event>()
{
  return "resource_retriever_interfaces::srv::GetResource_Event";
}

template<>
constexpr const char * name<resource_retriever_interfaces::srv::GetResource_Event>()
{
  return "resource_retriever_interfaces/srv/GetResource_Event";
}

template<>
struct has_fixed_size<resource_retriever_interfaces::srv::GetResource_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<resource_retriever_interfaces::srv::GetResource_Event>
  : std::integral_constant<bool, has_bounded_size<resource_retriever_interfaces::srv::GetResource_Request>::value && has_bounded_size<resource_retriever_interfaces::srv::GetResource_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<resource_retriever_interfaces::srv::GetResource_Event>
  : std::true_type {};

template<>
struct MessageTraits<resource_retriever_interfaces::srv::GetResource_Event>
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
constexpr const char * data_type<resource_retriever_interfaces::srv::GetResource>()
{
  return "resource_retriever_interfaces::srv::GetResource";
}

template<>
constexpr const char * name<resource_retriever_interfaces::srv::GetResource>()
{
  return "resource_retriever_interfaces/srv/GetResource";
}

template<>
struct has_fixed_size<resource_retriever_interfaces::srv::GetResource>
  : std::integral_constant<
    bool,
    has_fixed_size<resource_retriever_interfaces::srv::GetResource_Request>::value &&
    has_fixed_size<resource_retriever_interfaces::srv::GetResource_Response>::value
  >
{
};

template<>
struct has_bounded_size<resource_retriever_interfaces::srv::GetResource>
  : std::integral_constant<
    bool,
    has_bounded_size<resource_retriever_interfaces::srv::GetResource_Request>::value &&
    has_bounded_size<resource_retriever_interfaces::srv::GetResource_Response>::value
  >
{
};

template<>
struct is_service<resource_retriever_interfaces::srv::GetResource>
  : std::true_type
{
};

template<>
struct is_service_request<resource_retriever_interfaces::srv::GetResource_Request>
  : std::true_type
{
};

template<>
struct is_service_response<resource_retriever_interfaces::srv::GetResource_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RESOURCE_RETRIEVER_INTERFACES__SRV__DETAIL__GET_RESOURCE__TRAITS_HPP_
