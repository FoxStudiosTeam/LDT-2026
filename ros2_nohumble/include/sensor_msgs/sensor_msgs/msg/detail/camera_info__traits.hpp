// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\CameraInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/camera_info.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__CAMERA_INFO__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__CAMERA_INFO__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/camera_info__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'roi'
#include "sensor_msgs/msg/detail/region_of_interest__traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CameraInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: distortion_model
  {
    out << "distortion_model: ";
    rosidl_generator_traits::value_to_yaml(msg.distortion_model, out);
    out << ", ";
  }

  // member: d
  {
    if (msg.d.size() == 0) {
      out << "d: []";
    } else {
      out << "d: [";
      size_t pending_items = msg.d.size();
      for (auto item : msg.d) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: k
  {
    if (msg.k.size() == 0) {
      out << "k: []";
    } else {
      out << "k: [";
      size_t pending_items = msg.k.size();
      for (auto item : msg.k) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: r
  {
    if (msg.r.size() == 0) {
      out << "r: []";
    } else {
      out << "r: [";
      size_t pending_items = msg.r.size();
      for (auto item : msg.r) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: p
  {
    if (msg.p.size() == 0) {
      out << "p: []";
    } else {
      out << "p: [";
      size_t pending_items = msg.p.size();
      for (auto item : msg.p) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: binning_x
  {
    out << "binning_x: ";
    rosidl_generator_traits::value_to_yaml(msg.binning_x, out);
    out << ", ";
  }

  // member: binning_y
  {
    out << "binning_y: ";
    rosidl_generator_traits::value_to_yaml(msg.binning_y, out);
    out << ", ";
  }

  // member: roi
  {
    out << "roi: ";
    to_flow_style_yaml(msg.roi, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CameraInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: distortion_model
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distortion_model: ";
    rosidl_generator_traits::value_to_yaml(msg.distortion_model, out);
    out << "\n";
  }

  // member: d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.d.size() == 0) {
      out << "d: []\n";
    } else {
      out << "d:\n";
      for (auto item : msg.d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: k
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.k.size() == 0) {
      out << "k: []\n";
    } else {
      out << "k:\n";
      for (auto item : msg.k) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.r.size() == 0) {
      out << "r: []\n";
    } else {
      out << "r:\n";
      for (auto item : msg.r) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: p
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.p.size() == 0) {
      out << "p: []\n";
    } else {
      out << "p:\n";
      for (auto item : msg.p) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: binning_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "binning_x: ";
    rosidl_generator_traits::value_to_yaml(msg.binning_x, out);
    out << "\n";
  }

  // member: binning_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "binning_y: ";
    rosidl_generator_traits::value_to_yaml(msg.binning_y, out);
    out << "\n";
  }

  // member: roi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roi:\n";
    to_block_style_yaml(msg.roi, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CameraInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::CameraInfo>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).height,
    std::forward<T>(msg).width,
    std::forward<T>(msg).distortion_model,
    std::forward<T>(msg).d,
    std::forward<T>(msg).k,
    std::forward<T>(msg).r,
    std::forward<T>(msg).p,
    std::forward<T>(msg).binning_x,
    std::forward<T>(msg).binning_y,
    std::forward<T>(msg).roi);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::CameraInfo>()
{
  return "sensor_msgs::msg::CameraInfo";
}

template<>
constexpr const char * name<sensor_msgs::msg::CameraInfo>()
{
  return "sensor_msgs/msg/CameraInfo";
}

template<>
struct has_fixed_size<sensor_msgs::msg::CameraInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::msg::CameraInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_msgs::msg::CameraInfo>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::CameraInfo>
{
  static constexpr std::size_t member_count = 11;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "height",
    "width",
    "distortion_model",
    "d",
    "k",
    "r",
    "p",
    "binning_x",
    "binning_y",
    "roi",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__CAMERA_INFO__TRAITS_HPP_
