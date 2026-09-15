// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgraph_msgs:msg\Graph.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/graph.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__BUILDER_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__BUILDER_HPP_

#include <utility>

#include "rosgraph_msgs/msg/detail/graph__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgraph_msgs
{

namespace msg
{

namespace builder
{

class Init_Graph_nodes
{
public:
  Init_Graph_nodes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosgraph_msgs::msg::Graph nodes(::rosgraph_msgs::msg::Graph::_nodes_type arg)
  {
    msg_.nodes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgraph_msgs::msg::Graph msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgraph_msgs::msg::Graph>()
{
  return rosgraph_msgs::msg::builder::Init_Graph_nodes();
}

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__BUILDER_HPP_
