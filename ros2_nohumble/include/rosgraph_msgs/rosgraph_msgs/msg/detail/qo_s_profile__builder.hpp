// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\QoSProfile.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/qo_s_profile.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__QO_S_PROFILE__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__QO_S_PROFILE__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/qo_s_profile__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_QoSProfile_liveliness_lease_duration
{
public:
  explicit Init_QoSProfile_liveliness_lease_duration(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::QoSProfile liveliness_lease_duration(::rosgraph_msgs::msg::QoSProfile::_liveliness_lease_duration_type arg)
  {
    msg_.liveliness_lease_duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_liveliness
{
public:
  explicit Init_QoSProfile_liveliness(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  Init_QoSProfile_liveliness_lease_duration liveliness(::rosgraph_msgs::msg::QoSProfile::_liveliness_type arg)
  {
    msg_.liveliness = std::move(arg);
    return Init_QoSProfile_liveliness_lease_duration(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_durability
{
public:
  explicit Init_QoSProfile_durability(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  Init_QoSProfile_liveliness durability(::rosgraph_msgs::msg::QoSProfile::_durability_type arg)
  {
    msg_.durability = std::move(arg);
    return Init_QoSProfile_liveliness(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_reliability
{
public:
  explicit Init_QoSProfile_reliability(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  Init_QoSProfile_durability reliability(::rosgraph_msgs::msg::QoSProfile::_reliability_type arg)
  {
    msg_.reliability = std::move(arg);
    return Init_QoSProfile_durability(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_history
{
public:
  explicit Init_QoSProfile_history(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  Init_QoSProfile_reliability history(::rosgraph_msgs::msg::QoSProfile::_history_type arg)
  {
    msg_.history = std::move(arg);
    return Init_QoSProfile_reliability(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_lifespan
{
public:
  explicit Init_QoSProfile_lifespan(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  Init_QoSProfile_history lifespan(::rosgraph_msgs::msg::QoSProfile::_lifespan_type arg)
  {
    msg_.lifespan = std::move(arg);
    return Init_QoSProfile_history(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_deadline
{
public:
  explicit Init_QoSProfile_deadline(::rosgraph_msgs::msg::QoSProfile & msg)
  : msg_(msg)
  {}
  Init_QoSProfile_lifespan deadline(::rosgraph_msgs::msg::QoSProfile::_deadline_type arg)
  {
    msg_.deadline = std::move(arg);
    return Init_QoSProfile_lifespan(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

class Init_QoSProfile_depth
{
public:
  Init_QoSProfile_depth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QoSProfile_deadline depth(::rosgraph_msgs::msg::QoSProfile::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_QoSProfile_deadline(msg_);
  }

private:
  ::rosgraph_msgs::msg::QoSProfile msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::QoSProfile>()
{
  return rosgraph_msgs::msg::builder::Init_QoSProfile_depth();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__QO_S_PROFILE__BUILDER_HPP_
