// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_test_msgdefs:msg\ComplexMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/complex_msg.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG__BUILDER_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG__BUILDER_HPP_

#include <utility>

#include "rosbag2_test_msgdefs/msg/detail/complex_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_test_msgdefs
{

namespace msg
{

namespace builder
{

class Init_ComplexMsg_b
{
public:
  Init_ComplexMsg_b()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::msg::ComplexMsg b(::rosbag2_test_msgdefs::msg::ComplexMsg::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::msg::ComplexMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::msg::ComplexMsg>()
{
  return rosbag2_test_msgdefs::msg::builder::Init_ComplexMsg_b();
}

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_MSG__BUILDER_HPP_
