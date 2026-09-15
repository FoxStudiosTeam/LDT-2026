// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_test_msgdefs:msg\ComplexWithRelativeDep.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/complex_with_relative_dep.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__BUILDER_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__BUILDER_HPP_

#include <utility>

#include "rosbag2_test_msgdefs/msg/detail/complex_with_relative_dep__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_test_msgdefs
{

namespace msg
{

namespace builder
{

class Init_ComplexWithRelativeDep_a
{
public:
  Init_ComplexWithRelativeDep_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::msg::ComplexWithRelativeDep a(::rosbag2_test_msgdefs::msg::ComplexWithRelativeDep::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::msg::ComplexWithRelativeDep msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::msg::ComplexWithRelativeDep>()
{
  return rosbag2_test_msgdefs::msg::builder::Init_ComplexWithRelativeDep_a();
}

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__COMPLEX_WITH_RELATIVE_DEP__BUILDER_HPP_
