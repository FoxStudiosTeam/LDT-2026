// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_test_msgdefs:msg\AnotherBasicMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/another_basic_msg.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__BUILDER_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__BUILDER_HPP_

#include <utility>

#include "rosbag2_test_msgdefs/msg/detail/another_basic_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_test_msgdefs
{

namespace msg
{

namespace builder
{

class Init_AnotherBasicMsg_c
{
public:
  Init_AnotherBasicMsg_c()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::msg::AnotherBasicMsg c(::rosbag2_test_msgdefs::msg::AnotherBasicMsg::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::msg::AnotherBasicMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::msg::AnotherBasicMsg>()
{
  return rosbag2_test_msgdefs::msg::builder::Init_AnotherBasicMsg_c();
}

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__ANOTHER_BASIC_MSG__BUILDER_HPP_
