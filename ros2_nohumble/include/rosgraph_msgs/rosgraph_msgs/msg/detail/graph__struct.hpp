// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\Graph.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/graph.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'nodes'
#include "rosgraph_msgs/msg/detail/node__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__Graph __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__Graph __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Graph_
{
  using Type = Graph_<ContainerAllocator>;

  explicit Graph_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Graph_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _nodes_type =
    std::vector<rosgraph_msgs::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Node_<ContainerAllocator>>>;
  _nodes_type nodes;

  // setters for named parameter idiom
  Type & set__nodes(
    const std::vector<rosgraph_msgs::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Node_<ContainerAllocator>>> & _arg)
  {
    this->nodes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::Graph_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::Graph_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Graph_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Graph_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__Graph
    std::shared_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__Graph
    std::shared_ptr<rosgraph_msgs::msg::Graph_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Graph_ & other) const
  {
    if (this->nodes != other.nodes) {
      return false;
    }
    return true;
  }
  bool operator!=(const Graph_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Graph_

// alias to use template instance with default allocator
using Graph =
  rosgraph_msgs::msg::Graph_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__GRAPH__STRUCT_HPP_
