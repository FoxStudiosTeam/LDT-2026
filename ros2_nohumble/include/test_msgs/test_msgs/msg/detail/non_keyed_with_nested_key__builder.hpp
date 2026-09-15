// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg\NonKeyedWithNestedKey.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/non_keyed_with_nested_key.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__BUILDER_HPP_

#include <utility>

#include "test_msgs/msg/detail/non_keyed_with_nested_key__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_NonKeyedWithNestedKey_some_int
{
public:
  explicit Init_NonKeyedWithNestedKey_some_int(::test_msgs::msg::NonKeyedWithNestedKey & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::NonKeyedWithNestedKey some_int(::test_msgs::msg::NonKeyedWithNestedKey::_some_int_type arg)
  {
    msg_.some_int = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::NonKeyedWithNestedKey msg_;
};

class Init_NonKeyedWithNestedKey_nested_data
{
public:
  Init_NonKeyedWithNestedKey_nested_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NonKeyedWithNestedKey_some_int nested_data(::test_msgs::msg::NonKeyedWithNestedKey::_nested_data_type arg)
  {
    msg_.nested_data = std::move(arg);
    return Init_NonKeyedWithNestedKey_some_int(msg_);
  }

private:
  ::test_msgs::msg::NonKeyedWithNestedKey msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::NonKeyedWithNestedKey>()
{
  return test_msgs::msg::builder::Init_NonKeyedWithNestedKey_nested_data();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__BUILDER_HPP_
