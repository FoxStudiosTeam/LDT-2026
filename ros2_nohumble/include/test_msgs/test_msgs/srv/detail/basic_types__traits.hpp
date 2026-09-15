// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:srv\BasicTypes.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/srv/basic_types.hpp"


#ifndef TEST_MSGS__SRV__DETAIL__BASIC_TYPES__TRAITS_HPP_
#define TEST_MSGS__SRV__DETAIL__BASIC_TYPES__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/srv/detail/basic_types__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace test_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BasicTypes_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: bool_value
  {
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << ", ";
  }

  // member: byte_value
  {
    out << "byte_value: ";
    rosidl_generator_traits::character_value_to_yaml(msg.byte_value, out);
    out << ", ";
  }

  // member: char_value
  {
    out << "char_value: ";
    rosidl_generator_traits::value_to_yaml(msg.char_value, out);
    out << ", ";
  }

  // member: float32_value
  {
    out << "float32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float32_value, out);
    out << ", ";
  }

  // member: float64_value
  {
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
    out << ", ";
  }

  // member: int8_value
  {
    out << "int8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int8_value, out);
    out << ", ";
  }

  // member: uint8_value
  {
    out << "uint8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint8_value, out);
    out << ", ";
  }

  // member: int16_value
  {
    out << "int16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int16_value, out);
    out << ", ";
  }

  // member: uint16_value
  {
    out << "uint16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint16_value, out);
    out << ", ";
  }

  // member: int32_value
  {
    out << "int32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int32_value, out);
    out << ", ";
  }

  // member: uint32_value
  {
    out << "uint32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_value, out);
    out << ", ";
  }

  // member: int64_value
  {
    out << "int64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int64_value, out);
    out << ", ";
  }

  // member: uint64_value
  {
    out << "uint64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint64_value, out);
    out << ", ";
  }

  // member: string_value
  {
    out << "string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BasicTypes_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bool_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << "\n";
  }

  // member: byte_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte_value: ";
    rosidl_generator_traits::character_value_to_yaml(msg.byte_value, out);
    out << "\n";
  }

  // member: char_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "char_value: ";
    rosidl_generator_traits::value_to_yaml(msg.char_value, out);
    out << "\n";
  }

  // member: float32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float32_value, out);
    out << "\n";
  }

  // member: float64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
    out << "\n";
  }

  // member: int8_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int8_value, out);
    out << "\n";
  }

  // member: uint8_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint8_value, out);
    out << "\n";
  }

  // member: int16_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int16_value, out);
    out << "\n";
  }

  // member: uint16_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint16_value, out);
    out << "\n";
  }

  // member: int32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int32_value, out);
    out << "\n";
  }

  // member: uint32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_value, out);
    out << "\n";
  }

  // member: int64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int64_value, out);
    out << "\n";
  }

  // member: uint64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint64_value, out);
    out << "\n";
  }

  // member: string_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BasicTypes_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::srv::BasicTypes_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).bool_value,
    std::forward<T>(msg).byte_value,
    std::forward<T>(msg).char_value,
    std::forward<T>(msg).float32_value,
    std::forward<T>(msg).float64_value,
    std::forward<T>(msg).int8_value,
    std::forward<T>(msg).uint8_value,
    std::forward<T>(msg).int16_value,
    std::forward<T>(msg).uint16_value,
    std::forward<T>(msg).int32_value,
    std::forward<T>(msg).uint32_value,
    std::forward<T>(msg).int64_value,
    std::forward<T>(msg).uint64_value,
    std::forward<T>(msg).string_value);
}

}  // namespace srv

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::srv::BasicTypes_Request>()
{
  return "test_msgs::srv::BasicTypes_Request";
}

template<>
constexpr const char * name<test_msgs::srv::BasicTypes_Request>()
{
  return "test_msgs/srv/BasicTypes_Request";
}

template<>
struct has_fixed_size<test_msgs::srv::BasicTypes_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::srv::BasicTypes_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::srv::BasicTypes_Request>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::srv::BasicTypes_Request>
{
  static constexpr std::size_t member_count = 14;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "bool_value",
    "byte_value",
    "char_value",
    "float32_value",
    "float64_value",
    "int8_value",
    "uint8_value",
    "int16_value",
    "uint16_value",
    "int32_value",
    "uint32_value",
    "int64_value",
    "uint64_value",
    "string_value",
  };
};

}  // namespace rosidl_generator_traits

namespace test_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BasicTypes_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: bool_value
  {
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << ", ";
  }

  // member: byte_value
  {
    out << "byte_value: ";
    rosidl_generator_traits::character_value_to_yaml(msg.byte_value, out);
    out << ", ";
  }

  // member: char_value
  {
    out << "char_value: ";
    rosidl_generator_traits::value_to_yaml(msg.char_value, out);
    out << ", ";
  }

  // member: float32_value
  {
    out << "float32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float32_value, out);
    out << ", ";
  }

  // member: float64_value
  {
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
    out << ", ";
  }

  // member: int8_value
  {
    out << "int8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int8_value, out);
    out << ", ";
  }

  // member: uint8_value
  {
    out << "uint8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint8_value, out);
    out << ", ";
  }

  // member: int16_value
  {
    out << "int16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int16_value, out);
    out << ", ";
  }

  // member: uint16_value
  {
    out << "uint16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint16_value, out);
    out << ", ";
  }

  // member: int32_value
  {
    out << "int32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int32_value, out);
    out << ", ";
  }

  // member: uint32_value
  {
    out << "uint32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_value, out);
    out << ", ";
  }

  // member: int64_value
  {
    out << "int64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int64_value, out);
    out << ", ";
  }

  // member: uint64_value
  {
    out << "uint64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint64_value, out);
    out << ", ";
  }

  // member: string_value
  {
    out << "string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BasicTypes_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bool_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bool_value: ";
    rosidl_generator_traits::value_to_yaml(msg.bool_value, out);
    out << "\n";
  }

  // member: byte_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte_value: ";
    rosidl_generator_traits::character_value_to_yaml(msg.byte_value, out);
    out << "\n";
  }

  // member: char_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "char_value: ";
    rosidl_generator_traits::value_to_yaml(msg.char_value, out);
    out << "\n";
  }

  // member: float32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float32_value, out);
    out << "\n";
  }

  // member: float64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "float64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.float64_value, out);
    out << "\n";
  }

  // member: int8_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int8_value, out);
    out << "\n";
  }

  // member: uint8_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint8_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint8_value, out);
    out << "\n";
  }

  // member: int16_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int16_value, out);
    out << "\n";
  }

  // member: uint16_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint16_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint16_value, out);
    out << "\n";
  }

  // member: int32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int32_value, out);
    out << "\n";
  }

  // member: uint32_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint32_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint32_value, out);
    out << "\n";
  }

  // member: int64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.int64_value, out);
    out << "\n";
  }

  // member: uint64_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uint64_value: ";
    rosidl_generator_traits::value_to_yaml(msg.uint64_value, out);
    out << "\n";
  }

  // member: string_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "string_value: ";
    rosidl_generator_traits::value_to_yaml(msg.string_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BasicTypes_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::srv::BasicTypes_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).bool_value,
    std::forward<T>(msg).byte_value,
    std::forward<T>(msg).char_value,
    std::forward<T>(msg).float32_value,
    std::forward<T>(msg).float64_value,
    std::forward<T>(msg).int8_value,
    std::forward<T>(msg).uint8_value,
    std::forward<T>(msg).int16_value,
    std::forward<T>(msg).uint16_value,
    std::forward<T>(msg).int32_value,
    std::forward<T>(msg).uint32_value,
    std::forward<T>(msg).int64_value,
    std::forward<T>(msg).uint64_value,
    std::forward<T>(msg).string_value);
}

}  // namespace srv

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::srv::BasicTypes_Response>()
{
  return "test_msgs::srv::BasicTypes_Response";
}

template<>
constexpr const char * name<test_msgs::srv::BasicTypes_Response>()
{
  return "test_msgs/srv/BasicTypes_Response";
}

template<>
struct has_fixed_size<test_msgs::srv::BasicTypes_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::srv::BasicTypes_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::srv::BasicTypes_Response>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::srv::BasicTypes_Response>
{
  static constexpr std::size_t member_count = 14;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "bool_value",
    "byte_value",
    "char_value",
    "float32_value",
    "float64_value",
    "int8_value",
    "uint8_value",
    "int16_value",
    "uint16_value",
    "int32_value",
    "uint32_value",
    "int64_value",
    "uint64_value",
    "string_value",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace test_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BasicTypes_Event & msg,
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
  const BasicTypes_Event & msg,
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

inline std::string to_yaml(const BasicTypes_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::srv::BasicTypes_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::srv::BasicTypes_Event>()
{
  return "test_msgs::srv::BasicTypes_Event";
}

template<>
constexpr const char * name<test_msgs::srv::BasicTypes_Event>()
{
  return "test_msgs/srv/BasicTypes_Event";
}

template<>
struct has_fixed_size<test_msgs::srv::BasicTypes_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::srv::BasicTypes_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<test_msgs::srv::BasicTypes_Request>::value && has_bounded_size<test_msgs::srv::BasicTypes_Response>::value> {};

template<>
struct is_message<test_msgs::srv::BasicTypes_Event>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::srv::BasicTypes_Event>
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
constexpr const char * data_type<test_msgs::srv::BasicTypes>()
{
  return "test_msgs::srv::BasicTypes";
}

template<>
constexpr const char * name<test_msgs::srv::BasicTypes>()
{
  return "test_msgs/srv/BasicTypes";
}

template<>
struct has_fixed_size<test_msgs::srv::BasicTypes>
  : std::integral_constant<
    bool,
    has_fixed_size<test_msgs::srv::BasicTypes_Request>::value &&
    has_fixed_size<test_msgs::srv::BasicTypes_Response>::value
  >
{
};

template<>
struct has_bounded_size<test_msgs::srv::BasicTypes>
  : std::integral_constant<
    bool,
    has_bounded_size<test_msgs::srv::BasicTypes_Request>::value &&
    has_bounded_size<test_msgs::srv::BasicTypes_Response>::value
  >
{
};

template<>
struct is_service<test_msgs::srv::BasicTypes>
  : std::true_type
{
};

template<>
struct is_service_request<test_msgs::srv::BasicTypes_Request>
  : std::true_type
{
};

template<>
struct is_service_response<test_msgs::srv::BasicTypes_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__SRV__DETAIL__BASIC_TYPES__TRAITS_HPP_
