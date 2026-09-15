// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg\KeyedString.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/keyed_string.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__KEYED_STRING__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__KEYED_STRING__BUILDER_HPP_

#include <utility>

#include "test_msgs/msg/detail/keyed_string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_KeyedString_value
{
public:
  explicit Init_KeyedString_value(::test_msgs::msg::KeyedString & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::KeyedString value(::test_msgs::msg::KeyedString::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::KeyedString msg_;
};

class Init_KeyedString_key
{
public:
  Init_KeyedString_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KeyedString_value key(::test_msgs::msg::KeyedString::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_KeyedString_value(msg_);
  }

private:
  ::test_msgs::msg::KeyedString msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::KeyedString>()
{
  return test_msgs::msg::builder::Init_KeyedString_key();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__KEYED_STRING__BUILDER_HPP_
