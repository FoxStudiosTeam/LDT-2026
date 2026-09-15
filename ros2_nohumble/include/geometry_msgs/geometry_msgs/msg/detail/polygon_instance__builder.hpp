// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from geometry_msgs:msg\PolygonInstance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geometry_msgs/msg/polygon_instance.hpp"


#ifndef GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE__BUILDER_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE__BUILDER_HPP_

#include <utility>

#include "geometry_msgs/msg/detail/polygon_instance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace geometry_msgs
{

namespace msg
{

namespace builder
{

class Init_PolygonInstance_id
{
public:
  explicit Init_PolygonInstance_id(::geometry_msgs::msg::PolygonInstance & msg)
  : msg_(msg)
  {}
  ::geometry_msgs::msg::PolygonInstance id(::geometry_msgs::msg::PolygonInstance::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::geometry_msgs::msg::PolygonInstance msg_;
};

class Init_PolygonInstance_polygon
{
public:
  Init_PolygonInstance_polygon()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonInstance_id polygon(::geometry_msgs::msg::PolygonInstance::_polygon_type arg)
  {
    msg_.polygon = std::move(arg);
    return Init_PolygonInstance_id(msg_);
  }

private:
  ::geometry_msgs::msg::PolygonInstance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::geometry_msgs::msg::PolygonInstance>()
{
  return geometry_msgs::msg::builder::Init_PolygonInstance_polygon();
}

}  // namespace geometry_msgs

#endif  // GEOMETRY_MSGS__MSG__DETAIL__POLYGON_INSTANCE__BUILDER_HPP_
