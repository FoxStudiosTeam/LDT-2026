// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/rttest_results.hpp"


#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__BUILDER_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__BUILDER_HPP_

#include <utility>

#include "pendulum_msgs/msg/detail/rttest_results__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pendulum_msgs
{

namespace msg
{

namespace builder
{

class Init_RttestResults_major_pagefaults
{
public:
  explicit Init_RttestResults_major_pagefaults(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  ::pendulum_msgs::msg::RttestResults major_pagefaults(::pendulum_msgs::msg::RttestResults::_major_pagefaults_type arg)
  {
    msg_.major_pagefaults = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_minor_pagefaults
{
public:
  explicit Init_RttestResults_minor_pagefaults(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_major_pagefaults minor_pagefaults(::pendulum_msgs::msg::RttestResults::_minor_pagefaults_type arg)
  {
    msg_.minor_pagefaults = std::move(arg);
    return Init_RttestResults_major_pagefaults(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_max_latency
{
public:
  explicit Init_RttestResults_max_latency(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_minor_pagefaults max_latency(::pendulum_msgs::msg::RttestResults::_max_latency_type arg)
  {
    msg_.max_latency = std::move(arg);
    return Init_RttestResults_minor_pagefaults(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_min_latency
{
public:
  explicit Init_RttestResults_min_latency(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_max_latency min_latency(::pendulum_msgs::msg::RttestResults::_min_latency_type arg)
  {
    msg_.min_latency = std::move(arg);
    return Init_RttestResults_max_latency(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_mean_latency
{
public:
  explicit Init_RttestResults_mean_latency(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_min_latency mean_latency(::pendulum_msgs::msg::RttestResults::_mean_latency_type arg)
  {
    msg_.mean_latency = std::move(arg);
    return Init_RttestResults_min_latency(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_cur_latency
{
public:
  explicit Init_RttestResults_cur_latency(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_mean_latency cur_latency(::pendulum_msgs::msg::RttestResults::_cur_latency_type arg)
  {
    msg_.cur_latency = std::move(arg);
    return Init_RttestResults_mean_latency(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_state
{
public:
  explicit Init_RttestResults_state(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_cur_latency state(::pendulum_msgs::msg::RttestResults::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_RttestResults_cur_latency(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_command
{
public:
  explicit Init_RttestResults_command(::pendulum_msgs::msg::RttestResults & msg)
  : msg_(msg)
  {}
  Init_RttestResults_state command(::pendulum_msgs::msg::RttestResults::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_RttestResults_state(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

class Init_RttestResults_stamp
{
public:
  Init_RttestResults_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RttestResults_command stamp(::pendulum_msgs::msg::RttestResults::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_RttestResults_command(msg_);
  }

private:
  ::pendulum_msgs::msg::RttestResults msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pendulum_msgs::msg::RttestResults>()
{
  return pendulum_msgs::msg::builder::Init_RttestResults_stamp();
}

}  // namespace pendulum_msgs

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__BUILDER_HPP_
