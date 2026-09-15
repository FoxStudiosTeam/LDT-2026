// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:srv\Arrays.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/srv/arrays.hpp"


#ifndef TEST_MSGS__SRV__DETAIL__ARRAYS__TRAITS_HPP_
#define TEST_MSGS__SRV__DETAIL__ARRAYS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "test_msgs/srv/detail/arrays__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'basic_types_values'
#include "test_msgs/msg/detail/basic_types__traits.hpp"
// Member 'constants_values'
#include "test_msgs/msg/detail/constants__traits.hpp"
// Member 'defaults_values'
#include "test_msgs/msg/detail/defaults__traits.hpp"

namespace test_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Arrays_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: bool_values
  {
    if (msg.bool_values.size() == 0) {
      out << "bool_values: []";
    } else {
      out << "bool_values: [";
      size_t pending_items = msg.bool_values.size();
      for (auto item : msg.bool_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: byte_values
  {
    if (msg.byte_values.size() == 0) {
      out << "byte_values: []";
    } else {
      out << "byte_values: [";
      size_t pending_items = msg.byte_values.size();
      for (auto item : msg.byte_values) {
        rosidl_generator_traits::character_value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: char_values
  {
    if (msg.char_values.size() == 0) {
      out << "char_values: []";
    } else {
      out << "char_values: [";
      size_t pending_items = msg.char_values.size();
      for (auto item : msg.char_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float32_values
  {
    if (msg.float32_values.size() == 0) {
      out << "float32_values: []";
    } else {
      out << "float32_values: [";
      size_t pending_items = msg.float32_values.size();
      for (auto item : msg.float32_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float64_values
  {
    if (msg.float64_values.size() == 0) {
      out << "float64_values: []";
    } else {
      out << "float64_values: [";
      size_t pending_items = msg.float64_values.size();
      for (auto item : msg.float64_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int8_values
  {
    if (msg.int8_values.size() == 0) {
      out << "int8_values: []";
    } else {
      out << "int8_values: [";
      size_t pending_items = msg.int8_values.size();
      for (auto item : msg.int8_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint8_values
  {
    if (msg.uint8_values.size() == 0) {
      out << "uint8_values: []";
    } else {
      out << "uint8_values: [";
      size_t pending_items = msg.uint8_values.size();
      for (auto item : msg.uint8_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int16_values
  {
    if (msg.int16_values.size() == 0) {
      out << "int16_values: []";
    } else {
      out << "int16_values: [";
      size_t pending_items = msg.int16_values.size();
      for (auto item : msg.int16_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint16_values
  {
    if (msg.uint16_values.size() == 0) {
      out << "uint16_values: []";
    } else {
      out << "uint16_values: [";
      size_t pending_items = msg.uint16_values.size();
      for (auto item : msg.uint16_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int32_values
  {
    if (msg.int32_values.size() == 0) {
      out << "int32_values: []";
    } else {
      out << "int32_values: [";
      size_t pending_items = msg.int32_values.size();
      for (auto item : msg.int32_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint32_values
  {
    if (msg.uint32_values.size() == 0) {
      out << "uint32_values: []";
    } else {
      out << "uint32_values: [";
      size_t pending_items = msg.uint32_values.size();
      for (auto item : msg.uint32_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int64_values
  {
    if (msg.int64_values.size() == 0) {
      out << "int64_values: []";
    } else {
      out << "int64_values: [";
      size_t pending_items = msg.int64_values.size();
      for (auto item : msg.int64_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint64_values
  {
    if (msg.uint64_values.size() == 0) {
      out << "uint64_values: []";
    } else {
      out << "uint64_values: [";
      size_t pending_items = msg.uint64_values.size();
      for (auto item : msg.uint64_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: string_values
  {
    if (msg.string_values.size() == 0) {
      out << "string_values: []";
    } else {
      out << "string_values: [";
      size_t pending_items = msg.string_values.size();
      for (auto item : msg.string_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: basic_types_values
  {
    if (msg.basic_types_values.size() == 0) {
      out << "basic_types_values: []";
    } else {
      out << "basic_types_values: [";
      size_t pending_items = msg.basic_types_values.size();
      for (auto item : msg.basic_types_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: constants_values
  {
    if (msg.constants_values.size() == 0) {
      out << "constants_values: []";
    } else {
      out << "constants_values: [";
      size_t pending_items = msg.constants_values.size();
      for (auto item : msg.constants_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: defaults_values
  {
    if (msg.defaults_values.size() == 0) {
      out << "defaults_values: []";
    } else {
      out << "defaults_values: [";
      size_t pending_items = msg.defaults_values.size();
      for (auto item : msg.defaults_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bool_values_default
  {
    if (msg.bool_values_default.size() == 0) {
      out << "bool_values_default: []";
    } else {
      out << "bool_values_default: [";
      size_t pending_items = msg.bool_values_default.size();
      for (auto item : msg.bool_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: byte_values_default
  {
    if (msg.byte_values_default.size() == 0) {
      out << "byte_values_default: []";
    } else {
      out << "byte_values_default: [";
      size_t pending_items = msg.byte_values_default.size();
      for (auto item : msg.byte_values_default) {
        rosidl_generator_traits::character_value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: char_values_default
  {
    if (msg.char_values_default.size() == 0) {
      out << "char_values_default: []";
    } else {
      out << "char_values_default: [";
      size_t pending_items = msg.char_values_default.size();
      for (auto item : msg.char_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float32_values_default
  {
    if (msg.float32_values_default.size() == 0) {
      out << "float32_values_default: []";
    } else {
      out << "float32_values_default: [";
      size_t pending_items = msg.float32_values_default.size();
      for (auto item : msg.float32_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float64_values_default
  {
    if (msg.float64_values_default.size() == 0) {
      out << "float64_values_default: []";
    } else {
      out << "float64_values_default: [";
      size_t pending_items = msg.float64_values_default.size();
      for (auto item : msg.float64_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int8_values_default
  {
    if (msg.int8_values_default.size() == 0) {
      out << "int8_values_default: []";
    } else {
      out << "int8_values_default: [";
      size_t pending_items = msg.int8_values_default.size();
      for (auto item : msg.int8_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint8_values_default
  {
    if (msg.uint8_values_default.size() == 0) {
      out << "uint8_values_default: []";
    } else {
      out << "uint8_values_default: [";
      size_t pending_items = msg.uint8_values_default.size();
      for (auto item : msg.uint8_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int16_values_default
  {
    if (msg.int16_values_default.size() == 0) {
      out << "int16_values_default: []";
    } else {
      out << "int16_values_default: [";
      size_t pending_items = msg.int16_values_default.size();
      for (auto item : msg.int16_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint16_values_default
  {
    if (msg.uint16_values_default.size() == 0) {
      out << "uint16_values_default: []";
    } else {
      out << "uint16_values_default: [";
      size_t pending_items = msg.uint16_values_default.size();
      for (auto item : msg.uint16_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int32_values_default
  {
    if (msg.int32_values_default.size() == 0) {
      out << "int32_values_default: []";
    } else {
      out << "int32_values_default: [";
      size_t pending_items = msg.int32_values_default.size();
      for (auto item : msg.int32_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint32_values_default
  {
    if (msg.uint32_values_default.size() == 0) {
      out << "uint32_values_default: []";
    } else {
      out << "uint32_values_default: [";
      size_t pending_items = msg.uint32_values_default.size();
      for (auto item : msg.uint32_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int64_values_default
  {
    if (msg.int64_values_default.size() == 0) {
      out << "int64_values_default: []";
    } else {
      out << "int64_values_default: [";
      size_t pending_items = msg.int64_values_default.size();
      for (auto item : msg.int64_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint64_values_default
  {
    if (msg.uint64_values_default.size() == 0) {
      out << "uint64_values_default: []";
    } else {
      out << "uint64_values_default: [";
      size_t pending_items = msg.uint64_values_default.size();
      for (auto item : msg.uint64_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: string_values_default
  {
    if (msg.string_values_default.size() == 0) {
      out << "string_values_default: []";
    } else {
      out << "string_values_default: [";
      size_t pending_items = msg.string_values_default.size();
      for (auto item : msg.string_values_default) {
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
  const Arrays_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bool_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bool_values.size() == 0) {
      out << "bool_values: []\n";
    } else {
      out << "bool_values:\n";
      for (auto item : msg.bool_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: byte_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.byte_values.size() == 0) {
      out << "byte_values: []\n";
    } else {
      out << "byte_values:\n";
      for (auto item : msg.byte_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::character_value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: char_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.char_values.size() == 0) {
      out << "char_values: []\n";
    } else {
      out << "char_values:\n";
      for (auto item : msg.char_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float32_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float32_values.size() == 0) {
      out << "float32_values: []\n";
    } else {
      out << "float32_values:\n";
      for (auto item : msg.float32_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float64_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float64_values.size() == 0) {
      out << "float64_values: []\n";
    } else {
      out << "float64_values:\n";
      for (auto item : msg.float64_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int8_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int8_values.size() == 0) {
      out << "int8_values: []\n";
    } else {
      out << "int8_values:\n";
      for (auto item : msg.int8_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint8_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint8_values.size() == 0) {
      out << "uint8_values: []\n";
    } else {
      out << "uint8_values:\n";
      for (auto item : msg.uint8_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int16_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int16_values.size() == 0) {
      out << "int16_values: []\n";
    } else {
      out << "int16_values:\n";
      for (auto item : msg.int16_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint16_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint16_values.size() == 0) {
      out << "uint16_values: []\n";
    } else {
      out << "uint16_values:\n";
      for (auto item : msg.uint16_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int32_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int32_values.size() == 0) {
      out << "int32_values: []\n";
    } else {
      out << "int32_values:\n";
      for (auto item : msg.int32_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint32_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint32_values.size() == 0) {
      out << "uint32_values: []\n";
    } else {
      out << "uint32_values:\n";
      for (auto item : msg.uint32_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int64_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int64_values.size() == 0) {
      out << "int64_values: []\n";
    } else {
      out << "int64_values:\n";
      for (auto item : msg.int64_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint64_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint64_values.size() == 0) {
      out << "uint64_values: []\n";
    } else {
      out << "uint64_values:\n";
      for (auto item : msg.uint64_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: string_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.string_values.size() == 0) {
      out << "string_values: []\n";
    } else {
      out << "string_values:\n";
      for (auto item : msg.string_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: basic_types_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.basic_types_values.size() == 0) {
      out << "basic_types_values: []\n";
    } else {
      out << "basic_types_values:\n";
      for (auto item : msg.basic_types_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: constants_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.constants_values.size() == 0) {
      out << "constants_values: []\n";
    } else {
      out << "constants_values:\n";
      for (auto item : msg.constants_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: defaults_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.defaults_values.size() == 0) {
      out << "defaults_values: []\n";
    } else {
      out << "defaults_values:\n";
      for (auto item : msg.defaults_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: bool_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bool_values_default.size() == 0) {
      out << "bool_values_default: []\n";
    } else {
      out << "bool_values_default:\n";
      for (auto item : msg.bool_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: byte_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.byte_values_default.size() == 0) {
      out << "byte_values_default: []\n";
    } else {
      out << "byte_values_default:\n";
      for (auto item : msg.byte_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::character_value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: char_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.char_values_default.size() == 0) {
      out << "char_values_default: []\n";
    } else {
      out << "char_values_default:\n";
      for (auto item : msg.char_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float32_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float32_values_default.size() == 0) {
      out << "float32_values_default: []\n";
    } else {
      out << "float32_values_default:\n";
      for (auto item : msg.float32_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float64_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float64_values_default.size() == 0) {
      out << "float64_values_default: []\n";
    } else {
      out << "float64_values_default:\n";
      for (auto item : msg.float64_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int8_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int8_values_default.size() == 0) {
      out << "int8_values_default: []\n";
    } else {
      out << "int8_values_default:\n";
      for (auto item : msg.int8_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint8_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint8_values_default.size() == 0) {
      out << "uint8_values_default: []\n";
    } else {
      out << "uint8_values_default:\n";
      for (auto item : msg.uint8_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int16_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int16_values_default.size() == 0) {
      out << "int16_values_default: []\n";
    } else {
      out << "int16_values_default:\n";
      for (auto item : msg.int16_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint16_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint16_values_default.size() == 0) {
      out << "uint16_values_default: []\n";
    } else {
      out << "uint16_values_default:\n";
      for (auto item : msg.uint16_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int32_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int32_values_default.size() == 0) {
      out << "int32_values_default: []\n";
    } else {
      out << "int32_values_default:\n";
      for (auto item : msg.int32_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint32_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint32_values_default.size() == 0) {
      out << "uint32_values_default: []\n";
    } else {
      out << "uint32_values_default:\n";
      for (auto item : msg.uint32_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int64_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int64_values_default.size() == 0) {
      out << "int64_values_default: []\n";
    } else {
      out << "int64_values_default:\n";
      for (auto item : msg.int64_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint64_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint64_values_default.size() == 0) {
      out << "uint64_values_default: []\n";
    } else {
      out << "uint64_values_default:\n";
      for (auto item : msg.uint64_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: string_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.string_values_default.size() == 0) {
      out << "string_values_default: []\n";
    } else {
      out << "string_values_default:\n";
      for (auto item : msg.string_values_default) {
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

inline std::string to_yaml(const Arrays_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::srv::Arrays_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).bool_values,
    std::forward<T>(msg).byte_values,
    std::forward<T>(msg).char_values,
    std::forward<T>(msg).float32_values,
    std::forward<T>(msg).float64_values,
    std::forward<T>(msg).int8_values,
    std::forward<T>(msg).uint8_values,
    std::forward<T>(msg).int16_values,
    std::forward<T>(msg).uint16_values,
    std::forward<T>(msg).int32_values,
    std::forward<T>(msg).uint32_values,
    std::forward<T>(msg).int64_values,
    std::forward<T>(msg).uint64_values,
    std::forward<T>(msg).string_values,
    std::forward<T>(msg).basic_types_values,
    std::forward<T>(msg).constants_values,
    std::forward<T>(msg).defaults_values,
    std::forward<T>(msg).bool_values_default,
    std::forward<T>(msg).byte_values_default,
    std::forward<T>(msg).char_values_default,
    std::forward<T>(msg).float32_values_default,
    std::forward<T>(msg).float64_values_default,
    std::forward<T>(msg).int8_values_default,
    std::forward<T>(msg).uint8_values_default,
    std::forward<T>(msg).int16_values_default,
    std::forward<T>(msg).uint16_values_default,
    std::forward<T>(msg).int32_values_default,
    std::forward<T>(msg).uint32_values_default,
    std::forward<T>(msg).int64_values_default,
    std::forward<T>(msg).uint64_values_default,
    std::forward<T>(msg).string_values_default);
}

}  // namespace srv

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::srv::Arrays_Request>()
{
  return "test_msgs::srv::Arrays_Request";
}

template<>
constexpr const char * name<test_msgs::srv::Arrays_Request>()
{
  return "test_msgs/srv/Arrays_Request";
}

template<>
struct has_fixed_size<test_msgs::srv::Arrays_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::srv::Arrays_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::srv::Arrays_Request>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::srv::Arrays_Request>
{
  static constexpr std::size_t member_count = 31;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "bool_values",
    "byte_values",
    "char_values",
    "float32_values",
    "float64_values",
    "int8_values",
    "uint8_values",
    "int16_values",
    "uint16_values",
    "int32_values",
    "uint32_values",
    "int64_values",
    "uint64_values",
    "string_values",
    "basic_types_values",
    "constants_values",
    "defaults_values",
    "bool_values_default",
    "byte_values_default",
    "char_values_default",
    "float32_values_default",
    "float64_values_default",
    "int8_values_default",
    "uint8_values_default",
    "int16_values_default",
    "uint16_values_default",
    "int32_values_default",
    "uint32_values_default",
    "int64_values_default",
    "uint64_values_default",
    "string_values_default",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'basic_types_values'
// already included above
// #include "test_msgs/msg/detail/basic_types__traits.hpp"
// Member 'constants_values'
// already included above
// #include "test_msgs/msg/detail/constants__traits.hpp"
// Member 'defaults_values'
// already included above
// #include "test_msgs/msg/detail/defaults__traits.hpp"

namespace test_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Arrays_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: bool_values
  {
    if (msg.bool_values.size() == 0) {
      out << "bool_values: []";
    } else {
      out << "bool_values: [";
      size_t pending_items = msg.bool_values.size();
      for (auto item : msg.bool_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: byte_values
  {
    if (msg.byte_values.size() == 0) {
      out << "byte_values: []";
    } else {
      out << "byte_values: [";
      size_t pending_items = msg.byte_values.size();
      for (auto item : msg.byte_values) {
        rosidl_generator_traits::character_value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: char_values
  {
    if (msg.char_values.size() == 0) {
      out << "char_values: []";
    } else {
      out << "char_values: [";
      size_t pending_items = msg.char_values.size();
      for (auto item : msg.char_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float32_values
  {
    if (msg.float32_values.size() == 0) {
      out << "float32_values: []";
    } else {
      out << "float32_values: [";
      size_t pending_items = msg.float32_values.size();
      for (auto item : msg.float32_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float64_values
  {
    if (msg.float64_values.size() == 0) {
      out << "float64_values: []";
    } else {
      out << "float64_values: [";
      size_t pending_items = msg.float64_values.size();
      for (auto item : msg.float64_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int8_values
  {
    if (msg.int8_values.size() == 0) {
      out << "int8_values: []";
    } else {
      out << "int8_values: [";
      size_t pending_items = msg.int8_values.size();
      for (auto item : msg.int8_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint8_values
  {
    if (msg.uint8_values.size() == 0) {
      out << "uint8_values: []";
    } else {
      out << "uint8_values: [";
      size_t pending_items = msg.uint8_values.size();
      for (auto item : msg.uint8_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int16_values
  {
    if (msg.int16_values.size() == 0) {
      out << "int16_values: []";
    } else {
      out << "int16_values: [";
      size_t pending_items = msg.int16_values.size();
      for (auto item : msg.int16_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint16_values
  {
    if (msg.uint16_values.size() == 0) {
      out << "uint16_values: []";
    } else {
      out << "uint16_values: [";
      size_t pending_items = msg.uint16_values.size();
      for (auto item : msg.uint16_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int32_values
  {
    if (msg.int32_values.size() == 0) {
      out << "int32_values: []";
    } else {
      out << "int32_values: [";
      size_t pending_items = msg.int32_values.size();
      for (auto item : msg.int32_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint32_values
  {
    if (msg.uint32_values.size() == 0) {
      out << "uint32_values: []";
    } else {
      out << "uint32_values: [";
      size_t pending_items = msg.uint32_values.size();
      for (auto item : msg.uint32_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int64_values
  {
    if (msg.int64_values.size() == 0) {
      out << "int64_values: []";
    } else {
      out << "int64_values: [";
      size_t pending_items = msg.int64_values.size();
      for (auto item : msg.int64_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint64_values
  {
    if (msg.uint64_values.size() == 0) {
      out << "uint64_values: []";
    } else {
      out << "uint64_values: [";
      size_t pending_items = msg.uint64_values.size();
      for (auto item : msg.uint64_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: string_values
  {
    if (msg.string_values.size() == 0) {
      out << "string_values: []";
    } else {
      out << "string_values: [";
      size_t pending_items = msg.string_values.size();
      for (auto item : msg.string_values) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: basic_types_values
  {
    if (msg.basic_types_values.size() == 0) {
      out << "basic_types_values: []";
    } else {
      out << "basic_types_values: [";
      size_t pending_items = msg.basic_types_values.size();
      for (auto item : msg.basic_types_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: constants_values
  {
    if (msg.constants_values.size() == 0) {
      out << "constants_values: []";
    } else {
      out << "constants_values: [";
      size_t pending_items = msg.constants_values.size();
      for (auto item : msg.constants_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: defaults_values
  {
    if (msg.defaults_values.size() == 0) {
      out << "defaults_values: []";
    } else {
      out << "defaults_values: [";
      size_t pending_items = msg.defaults_values.size();
      for (auto item : msg.defaults_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bool_values_default
  {
    if (msg.bool_values_default.size() == 0) {
      out << "bool_values_default: []";
    } else {
      out << "bool_values_default: [";
      size_t pending_items = msg.bool_values_default.size();
      for (auto item : msg.bool_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: byte_values_default
  {
    if (msg.byte_values_default.size() == 0) {
      out << "byte_values_default: []";
    } else {
      out << "byte_values_default: [";
      size_t pending_items = msg.byte_values_default.size();
      for (auto item : msg.byte_values_default) {
        rosidl_generator_traits::character_value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: char_values_default
  {
    if (msg.char_values_default.size() == 0) {
      out << "char_values_default: []";
    } else {
      out << "char_values_default: [";
      size_t pending_items = msg.char_values_default.size();
      for (auto item : msg.char_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float32_values_default
  {
    if (msg.float32_values_default.size() == 0) {
      out << "float32_values_default: []";
    } else {
      out << "float32_values_default: [";
      size_t pending_items = msg.float32_values_default.size();
      for (auto item : msg.float32_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: float64_values_default
  {
    if (msg.float64_values_default.size() == 0) {
      out << "float64_values_default: []";
    } else {
      out << "float64_values_default: [";
      size_t pending_items = msg.float64_values_default.size();
      for (auto item : msg.float64_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int8_values_default
  {
    if (msg.int8_values_default.size() == 0) {
      out << "int8_values_default: []";
    } else {
      out << "int8_values_default: [";
      size_t pending_items = msg.int8_values_default.size();
      for (auto item : msg.int8_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint8_values_default
  {
    if (msg.uint8_values_default.size() == 0) {
      out << "uint8_values_default: []";
    } else {
      out << "uint8_values_default: [";
      size_t pending_items = msg.uint8_values_default.size();
      for (auto item : msg.uint8_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int16_values_default
  {
    if (msg.int16_values_default.size() == 0) {
      out << "int16_values_default: []";
    } else {
      out << "int16_values_default: [";
      size_t pending_items = msg.int16_values_default.size();
      for (auto item : msg.int16_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint16_values_default
  {
    if (msg.uint16_values_default.size() == 0) {
      out << "uint16_values_default: []";
    } else {
      out << "uint16_values_default: [";
      size_t pending_items = msg.uint16_values_default.size();
      for (auto item : msg.uint16_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int32_values_default
  {
    if (msg.int32_values_default.size() == 0) {
      out << "int32_values_default: []";
    } else {
      out << "int32_values_default: [";
      size_t pending_items = msg.int32_values_default.size();
      for (auto item : msg.int32_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint32_values_default
  {
    if (msg.uint32_values_default.size() == 0) {
      out << "uint32_values_default: []";
    } else {
      out << "uint32_values_default: [";
      size_t pending_items = msg.uint32_values_default.size();
      for (auto item : msg.uint32_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: int64_values_default
  {
    if (msg.int64_values_default.size() == 0) {
      out << "int64_values_default: []";
    } else {
      out << "int64_values_default: [";
      size_t pending_items = msg.int64_values_default.size();
      for (auto item : msg.int64_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: uint64_values_default
  {
    if (msg.uint64_values_default.size() == 0) {
      out << "uint64_values_default: []";
    } else {
      out << "uint64_values_default: [";
      size_t pending_items = msg.uint64_values_default.size();
      for (auto item : msg.uint64_values_default) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: string_values_default
  {
    if (msg.string_values_default.size() == 0) {
      out << "string_values_default: []";
    } else {
      out << "string_values_default: [";
      size_t pending_items = msg.string_values_default.size();
      for (auto item : msg.string_values_default) {
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
  const Arrays_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bool_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bool_values.size() == 0) {
      out << "bool_values: []\n";
    } else {
      out << "bool_values:\n";
      for (auto item : msg.bool_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: byte_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.byte_values.size() == 0) {
      out << "byte_values: []\n";
    } else {
      out << "byte_values:\n";
      for (auto item : msg.byte_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::character_value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: char_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.char_values.size() == 0) {
      out << "char_values: []\n";
    } else {
      out << "char_values:\n";
      for (auto item : msg.char_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float32_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float32_values.size() == 0) {
      out << "float32_values: []\n";
    } else {
      out << "float32_values:\n";
      for (auto item : msg.float32_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float64_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float64_values.size() == 0) {
      out << "float64_values: []\n";
    } else {
      out << "float64_values:\n";
      for (auto item : msg.float64_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int8_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int8_values.size() == 0) {
      out << "int8_values: []\n";
    } else {
      out << "int8_values:\n";
      for (auto item : msg.int8_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint8_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint8_values.size() == 0) {
      out << "uint8_values: []\n";
    } else {
      out << "uint8_values:\n";
      for (auto item : msg.uint8_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int16_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int16_values.size() == 0) {
      out << "int16_values: []\n";
    } else {
      out << "int16_values:\n";
      for (auto item : msg.int16_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint16_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint16_values.size() == 0) {
      out << "uint16_values: []\n";
    } else {
      out << "uint16_values:\n";
      for (auto item : msg.uint16_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int32_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int32_values.size() == 0) {
      out << "int32_values: []\n";
    } else {
      out << "int32_values:\n";
      for (auto item : msg.int32_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint32_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint32_values.size() == 0) {
      out << "uint32_values: []\n";
    } else {
      out << "uint32_values:\n";
      for (auto item : msg.uint32_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int64_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int64_values.size() == 0) {
      out << "int64_values: []\n";
    } else {
      out << "int64_values:\n";
      for (auto item : msg.int64_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint64_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint64_values.size() == 0) {
      out << "uint64_values: []\n";
    } else {
      out << "uint64_values:\n";
      for (auto item : msg.uint64_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: string_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.string_values.size() == 0) {
      out << "string_values: []\n";
    } else {
      out << "string_values:\n";
      for (auto item : msg.string_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: basic_types_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.basic_types_values.size() == 0) {
      out << "basic_types_values: []\n";
    } else {
      out << "basic_types_values:\n";
      for (auto item : msg.basic_types_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: constants_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.constants_values.size() == 0) {
      out << "constants_values: []\n";
    } else {
      out << "constants_values:\n";
      for (auto item : msg.constants_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: defaults_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.defaults_values.size() == 0) {
      out << "defaults_values: []\n";
    } else {
      out << "defaults_values:\n";
      for (auto item : msg.defaults_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: bool_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bool_values_default.size() == 0) {
      out << "bool_values_default: []\n";
    } else {
      out << "bool_values_default:\n";
      for (auto item : msg.bool_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: byte_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.byte_values_default.size() == 0) {
      out << "byte_values_default: []\n";
    } else {
      out << "byte_values_default:\n";
      for (auto item : msg.byte_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::character_value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: char_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.char_values_default.size() == 0) {
      out << "char_values_default: []\n";
    } else {
      out << "char_values_default:\n";
      for (auto item : msg.char_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float32_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float32_values_default.size() == 0) {
      out << "float32_values_default: []\n";
    } else {
      out << "float32_values_default:\n";
      for (auto item : msg.float32_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: float64_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.float64_values_default.size() == 0) {
      out << "float64_values_default: []\n";
    } else {
      out << "float64_values_default:\n";
      for (auto item : msg.float64_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int8_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int8_values_default.size() == 0) {
      out << "int8_values_default: []\n";
    } else {
      out << "int8_values_default:\n";
      for (auto item : msg.int8_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint8_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint8_values_default.size() == 0) {
      out << "uint8_values_default: []\n";
    } else {
      out << "uint8_values_default:\n";
      for (auto item : msg.uint8_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int16_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int16_values_default.size() == 0) {
      out << "int16_values_default: []\n";
    } else {
      out << "int16_values_default:\n";
      for (auto item : msg.int16_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint16_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint16_values_default.size() == 0) {
      out << "uint16_values_default: []\n";
    } else {
      out << "uint16_values_default:\n";
      for (auto item : msg.uint16_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int32_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int32_values_default.size() == 0) {
      out << "int32_values_default: []\n";
    } else {
      out << "int32_values_default:\n";
      for (auto item : msg.int32_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint32_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint32_values_default.size() == 0) {
      out << "uint32_values_default: []\n";
    } else {
      out << "uint32_values_default:\n";
      for (auto item : msg.uint32_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: int64_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.int64_values_default.size() == 0) {
      out << "int64_values_default: []\n";
    } else {
      out << "int64_values_default:\n";
      for (auto item : msg.int64_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: uint64_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.uint64_values_default.size() == 0) {
      out << "uint64_values_default: []\n";
    } else {
      out << "uint64_values_default:\n";
      for (auto item : msg.uint64_values_default) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: string_values_default
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.string_values_default.size() == 0) {
      out << "string_values_default: []\n";
    } else {
      out << "string_values_default:\n";
      for (auto item : msg.string_values_default) {
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

inline std::string to_yaml(const Arrays_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::srv::Arrays_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).bool_values,
    std::forward<T>(msg).byte_values,
    std::forward<T>(msg).char_values,
    std::forward<T>(msg).float32_values,
    std::forward<T>(msg).float64_values,
    std::forward<T>(msg).int8_values,
    std::forward<T>(msg).uint8_values,
    std::forward<T>(msg).int16_values,
    std::forward<T>(msg).uint16_values,
    std::forward<T>(msg).int32_values,
    std::forward<T>(msg).uint32_values,
    std::forward<T>(msg).int64_values,
    std::forward<T>(msg).uint64_values,
    std::forward<T>(msg).string_values,
    std::forward<T>(msg).basic_types_values,
    std::forward<T>(msg).constants_values,
    std::forward<T>(msg).defaults_values,
    std::forward<T>(msg).bool_values_default,
    std::forward<T>(msg).byte_values_default,
    std::forward<T>(msg).char_values_default,
    std::forward<T>(msg).float32_values_default,
    std::forward<T>(msg).float64_values_default,
    std::forward<T>(msg).int8_values_default,
    std::forward<T>(msg).uint8_values_default,
    std::forward<T>(msg).int16_values_default,
    std::forward<T>(msg).uint16_values_default,
    std::forward<T>(msg).int32_values_default,
    std::forward<T>(msg).uint32_values_default,
    std::forward<T>(msg).int64_values_default,
    std::forward<T>(msg).uint64_values_default,
    std::forward<T>(msg).string_values_default);
}

}  // namespace srv

}  // namespace test_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<test_msgs::srv::Arrays_Response>()
{
  return "test_msgs::srv::Arrays_Response";
}

template<>
constexpr const char * name<test_msgs::srv::Arrays_Response>()
{
  return "test_msgs/srv/Arrays_Response";
}

template<>
struct has_fixed_size<test_msgs::srv::Arrays_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::srv::Arrays_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::srv::Arrays_Response>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::srv::Arrays_Response>
{
  static constexpr std::size_t member_count = 31;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "bool_values",
    "byte_values",
    "char_values",
    "float32_values",
    "float64_values",
    "int8_values",
    "uint8_values",
    "int16_values",
    "uint16_values",
    "int32_values",
    "uint32_values",
    "int64_values",
    "uint64_values",
    "string_values",
    "basic_types_values",
    "constants_values",
    "defaults_values",
    "bool_values_default",
    "byte_values_default",
    "char_values_default",
    "float32_values_default",
    "float64_values_default",
    "int8_values_default",
    "uint8_values_default",
    "int16_values_default",
    "uint16_values_default",
    "int32_values_default",
    "uint32_values_default",
    "int64_values_default",
    "uint64_values_default",
    "string_values_default",
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
  const Arrays_Event & msg,
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
  const Arrays_Event & msg,
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

inline std::string to_yaml(const Arrays_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, test_msgs::srv::Arrays_Event>, int> = 0>
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
constexpr const char * data_type<test_msgs::srv::Arrays_Event>()
{
  return "test_msgs::srv::Arrays_Event";
}

template<>
constexpr const char * name<test_msgs::srv::Arrays_Event>()
{
  return "test_msgs/srv/Arrays_Event";
}

template<>
struct has_fixed_size<test_msgs::srv::Arrays_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::srv::Arrays_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<test_msgs::srv::Arrays_Request>::value && has_bounded_size<test_msgs::srv::Arrays_Response>::value> {};

template<>
struct is_message<test_msgs::srv::Arrays_Event>
  : std::true_type {};

template<>
struct MessageTraits<test_msgs::srv::Arrays_Event>
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
constexpr const char * data_type<test_msgs::srv::Arrays>()
{
  return "test_msgs::srv::Arrays";
}

template<>
constexpr const char * name<test_msgs::srv::Arrays>()
{
  return "test_msgs/srv/Arrays";
}

template<>
struct has_fixed_size<test_msgs::srv::Arrays>
  : std::integral_constant<
    bool,
    has_fixed_size<test_msgs::srv::Arrays_Request>::value &&
    has_fixed_size<test_msgs::srv::Arrays_Response>::value
  >
{
};

template<>
struct has_bounded_size<test_msgs::srv::Arrays>
  : std::integral_constant<
    bool,
    has_bounded_size<test_msgs::srv::Arrays_Request>::value &&
    has_bounded_size<test_msgs::srv::Arrays_Response>::value
  >
{
};

template<>
struct is_service<test_msgs::srv::Arrays>
  : std::true_type
{
};

template<>
struct is_service_request<test_msgs::srv::Arrays_Request>
  : std::true_type
{
};

template<>
struct is_service_response<test_msgs::srv::Arrays_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__SRV__DETAIL__ARRAYS__TRAITS_HPP_
