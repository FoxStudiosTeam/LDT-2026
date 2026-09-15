// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_performance_benchmarking_msgs/msg/byte_array.hpp"


#ifndef ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__BUILDER_HPP_
#define ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__BUILDER_HPP_

#include <utility>

#include "rosbag2_performance_benchmarking_msgs/msg/detail/byte_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_performance_benchmarking_msgs
{

namespace msg
{

namespace builder
{

class Init_ByteArray_data
{
public:
  Init_ByteArray_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_performance_benchmarking_msgs::msg::ByteArray data(::rosbag2_performance_benchmarking_msgs::msg::ByteArray::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_performance_benchmarking_msgs::msg::ByteArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_performance_benchmarking_msgs::msg::ByteArray>()
{
  return rosbag2_performance_benchmarking_msgs::msg::builder::Init_ByteArray_data();
}

}  // namespace rosbag2_performance_benchmarking_msgs

#endif  // ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__BUILDER_HPP_
