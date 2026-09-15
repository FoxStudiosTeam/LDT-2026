// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_test_msgdefs:msg\BasicIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/basic_idl.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__BUILDER_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__BUILDER_HPP_

#include <utility>

#include "rosbag2_test_msgdefs/msg/detail/basic_idl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_test_msgdefs
{

namespace msg
{

namespace builder
{

class Init_BasicIdl_x
{
public:
  Init_BasicIdl_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::msg::BasicIdl x(::rosbag2_test_msgdefs::msg::BasicIdl::_x_type arg)
  {
    msg_.x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::msg::BasicIdl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::msg::BasicIdl>()
{
  return rosbag2_test_msgdefs::msg::builder::Init_BasicIdl_x();
}

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__BUILDER_HPP_
