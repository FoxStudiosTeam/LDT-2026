// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\Service.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/service.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_Service_response_qos
{
public:
  explicit Init_Service_response_qos(::rosgraph_msgs::msg::Service & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::Service response_qos(::rosgraph_msgs::msg::Service::_response_qos_type arg)
  {
    msg_.response_qos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::Service msg_;
};

class Init_Service_response_type
{
public:
  explicit Init_Service_response_type(::rosgraph_msgs::msg::Service & msg)
  : msg_(msg)
  {}
  Init_Service_response_qos response_type(::rosgraph_msgs::msg::Service::_response_type_type arg)
  {
    msg_.response_type = std::move(arg);
    return Init_Service_response_qos(msg_);
  }

private:
  ::rosgraph_msgs::msg::Service msg_;
};

class Init_Service_request_qos
{
public:
  explicit Init_Service_request_qos(::rosgraph_msgs::msg::Service & msg)
  : msg_(msg)
  {}
  Init_Service_response_type request_qos(::rosgraph_msgs::msg::Service::_request_qos_type arg)
  {
    msg_.request_qos = std::move(arg);
    return Init_Service_response_type(msg_);
  }

private:
  ::rosgraph_msgs::msg::Service msg_;
};

class Init_Service_request_type
{
public:
  explicit Init_Service_request_type(::rosgraph_msgs::msg::Service & msg)
  : msg_(msg)
  {}
  Init_Service_request_qos request_type(::rosgraph_msgs::msg::Service::_request_type_type arg)
  {
    msg_.request_type = std::move(arg);
    return Init_Service_request_qos(msg_);
  }

private:
  ::rosgraph_msgs::msg::Service msg_;
};

class Init_Service_name
{
public:
  Init_Service_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Service_request_type name(::rosgraph_msgs::msg::Service::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Service_request_type(msg_);
  }

private:
  ::rosgraph_msgs::msg::Service msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::Service>()
{
  return rosgraph_msgs::msg::builder::Init_Service_name();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__SERVICE__BUILDER_HPP_
