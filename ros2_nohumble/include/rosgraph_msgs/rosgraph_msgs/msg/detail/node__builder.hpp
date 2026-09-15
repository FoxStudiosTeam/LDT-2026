// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\Node.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/node.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__NODE__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__NODE__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_Node_action_servers
{
public:
  explicit Init_Node_action_servers(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  ::rosgraph_msgs::msg::Node action_servers(::rosgraph_msgs::msg::Node::_action_servers_type arg)
  {
    msg_.action_servers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_action_clients
{
public:
  explicit Init_Node_action_clients(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_action_servers action_clients(::rosgraph_msgs::msg::Node::_action_clients_type arg)
  {
    msg_.action_clients = std::move(arg);
    return Init_Node_action_servers(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_service_servers
{
public:
  explicit Init_Node_service_servers(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_action_clients service_servers(::rosgraph_msgs::msg::Node::_service_servers_type arg)
  {
    msg_.service_servers = std::move(arg);
    return Init_Node_action_clients(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_service_clients
{
public:
  explicit Init_Node_service_clients(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_service_servers service_clients(::rosgraph_msgs::msg::Node::_service_clients_type arg)
  {
    msg_.service_clients = std::move(arg);
    return Init_Node_service_servers(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_subscriptions
{
public:
  explicit Init_Node_subscriptions(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_service_clients subscriptions(::rosgraph_msgs::msg::Node::_subscriptions_type arg)
  {
    msg_.subscriptions = std::move(arg);
    return Init_Node_service_clients(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_publishers
{
public:
  explicit Init_Node_publishers(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_subscriptions publishers(::rosgraph_msgs::msg::Node::_publishers_type arg)
  {
    msg_.publishers = std::move(arg);
    return Init_Node_subscriptions(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_parameter_values
{
public:
  explicit Init_Node_parameter_values(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_publishers parameter_values(::rosgraph_msgs::msg::Node::_parameter_values_type arg)
  {
    msg_.parameter_values = std::move(arg);
    return Init_Node_publishers(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_parameters
{
public:
  explicit Init_Node_parameters(::rosgraph_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_parameter_values parameters(::rosgraph_msgs::msg::Node::_parameters_type arg)
  {
    msg_.parameters = std::move(arg);
    return Init_Node_parameter_values(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

class Init_Node_name
{
public:
  Init_Node_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Node_parameters name(::rosgraph_msgs::msg::Node::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Node_parameters(msg_);
  }

private:
  ::rosgraph_msgs::msg::Node msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::Node>()
{
  return rosgraph_msgs::msg::builder::Init_Node_name();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__NODE__BUILDER_HPP_
