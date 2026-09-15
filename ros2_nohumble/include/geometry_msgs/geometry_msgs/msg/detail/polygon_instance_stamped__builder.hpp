// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from geometry_msgs:msg\PolygonInstanceStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geometry_msgs/msg/polygon_instance_stamped.hpp"


#ifndef GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE_STAMPED__BUILDER_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE_STAMPED__BUILDER_HPP_

#include <utility>

#include "geometry_msgs/msg/detail/polygon_instance_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace geometry_msgs
{

namespace msg
{

namespace builder
{

class Init_PolygonInstanceStamped_polygon
{
public:
  explicit Init_PolygonInstanceStamped_polygon(::geometry_msgs::msg::PolygonInstanceStamped & msg)
  : msg_(msg)
  {}
  ::geometry_msgs::msg::PolygonInstanceStamped polygon(::geometry_msgs::msg::PolygonInstanceStamped::_polygon_type arg)
  {
    msg_.polygon = std::move(arg);
    return std::move(msg_);
  }

private:
  ::geometry_msgs::msg::PolygonInstanceStamped msg_;
};

class Init_PolygonInstanceStamped_header
{
public:
  Init_PolygonInstanceStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonInstanceStamped_polygon header(::geometry_msgs::msg::PolygonInstanceStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PolygonInstanceStamped_polygon(msg_);
  }

private:
  ::geometry_msgs::msg::PolygonInstanceStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::geometry_msgs::msg::PolygonInstanceStamped>()
{
  return geometry_msgs::msg::builder::Init_PolygonInstanceStamped_header();
}

}  // namespace geometry_msgs

#endif  // GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE_STAMPED__BUILDER_HPP_
