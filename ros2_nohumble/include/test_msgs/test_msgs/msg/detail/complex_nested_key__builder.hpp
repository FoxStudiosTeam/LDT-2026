// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg\ComplexNestedKey.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/complex_nested_key.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__BUILDER_HPP_

#include <utility>

#include "test_msgs/msg/detail/complex_nested_key__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_ComplexNestedKey_float64_value
{
public:
  explicit Init_ComplexNestedKey_float64_value(::test_msgs::msg::ComplexNestedKey & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::ComplexNestedKey float64_value(::test_msgs::msg::ComplexNestedKey::_float64_value_type arg)
  {
    msg_.float64_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::ComplexNestedKey msg_;
};

class Init_ComplexNestedKey_nested_keys
{
public:
  explicit Init_ComplexNestedKey_nested_keys(::test_msgs::msg::ComplexNestedKey & msg)
  : msg_(msg)
  {}
  Init_ComplexNestedKey_float64_value nested_keys(::test_msgs::msg::ComplexNestedKey::_nested_keys_type arg)
  {
    msg_.nested_keys = std::move(arg);
    return Init_ComplexNestedKey_float64_value(msg_);
  }

private:
  ::test_msgs::msg::ComplexNestedKey msg_;
};

class Init_ComplexNestedKey_uint32_key
{
public:
  Init_ComplexNestedKey_uint32_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexNestedKey_nested_keys uint32_key(::test_msgs::msg::ComplexNestedKey::_uint32_key_type arg)
  {
    msg_.uint32_key = std::move(arg);
    return Init_ComplexNestedKey_nested_keys(msg_);
  }

private:
  ::test_msgs::msg::ComplexNestedKey msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::ComplexNestedKey>()
{
  return test_msgs::msg::builder::Init_ComplexNestedKey_uint32_key();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__BUILDER_HPP_
