// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg\KeyedLong.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/keyed_long.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__KEYED_LONG__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__KEYED_LONG__BUILDER_HPP_

#include <utility>

#include "test_msgs/msg/detail/keyed_long__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_KeyedLong_value
{
public:
  explicit Init_KeyedLong_value(::test_msgs::msg::KeyedLong & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::KeyedLong value(::test_msgs::msg::KeyedLong::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::KeyedLong msg_;
};

class Init_KeyedLong_key
{
public:
  Init_KeyedLong_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KeyedLong_value key(::test_msgs::msg::KeyedLong::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_KeyedLong_value(msg_);
  }

private:
  ::test_msgs::msg::KeyedLong msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::KeyedLong>()
{
  return test_msgs::msg::builder::Init_KeyedLong_key();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__KEYED_LONG__BUILDER_HPP_
