// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:msg\PointCloud2Update.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/point_cloud2_update.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__BUILDER_HPP_
#define MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__BUILDER_HPP_

#include <utility>

#include "map_msgs/msg/detail/point_cloud2_update__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace msg
{

namespace builder
{

class Init_PointCloud2Update_points
{
public:
  explicit Init_PointCloud2Update_points(::map_msgs::msg::PointCloud2Update & msg)
  : msg_(msg)
  {}
  ::map_msgs::msg::PointCloud2Update points(::map_msgs::msg::PointCloud2Update::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::msg::PointCloud2Update msg_;
};

class Init_PointCloud2Update_type
{
public:
  explicit Init_PointCloud2Update_type(::map_msgs::msg::PointCloud2Update & msg)
  : msg_(msg)
  {}
  Init_PointCloud2Update_points type(::map_msgs::msg::PointCloud2Update::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_PointCloud2Update_points(msg_);
  }

private:
  ::map_msgs::msg::PointCloud2Update msg_;
};

class Init_PointCloud2Update_header
{
public:
  Init_PointCloud2Update_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointCloud2Update_type header(::map_msgs::msg::PointCloud2Update::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PointCloud2Update_type(msg_);
  }

private:
  ::map_msgs::msg::PointCloud2Update msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::msg::PointCloud2Update>()
{
  return map_msgs::msg::builder::Init_PointCloud2Update_header();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__BUILDER_HPP_
