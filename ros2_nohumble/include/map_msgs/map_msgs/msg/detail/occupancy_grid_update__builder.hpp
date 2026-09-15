// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:msg\OccupancyGridUpdate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/occupancy_grid_update.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__BUILDER_HPP_
#define MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__BUILDER_HPP_

#include <utility>

#include "map_msgs/msg/detail/occupancy_grid_update__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace msg
{

namespace builder
{

class Init_OccupancyGridUpdate_data
{
public:
  explicit Init_OccupancyGridUpdate_data(::map_msgs::msg::OccupancyGridUpdate & msg)
  : msg_(msg)
  {}
  ::map_msgs::msg::OccupancyGridUpdate data(::map_msgs::msg::OccupancyGridUpdate::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::msg::OccupancyGridUpdate msg_;
};

class Init_OccupancyGridUpdate_height
{
public:
  explicit Init_OccupancyGridUpdate_height(::map_msgs::msg::OccupancyGridUpdate & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUpdate_data height(::map_msgs::msg::OccupancyGridUpdate::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_OccupancyGridUpdate_data(msg_);
  }

private:
  ::map_msgs::msg::OccupancyGridUpdate msg_;
};

class Init_OccupancyGridUpdate_width
{
public:
  explicit Init_OccupancyGridUpdate_width(::map_msgs::msg::OccupancyGridUpdate & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUpdate_height width(::map_msgs::msg::OccupancyGridUpdate::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_OccupancyGridUpdate_height(msg_);
  }

private:
  ::map_msgs::msg::OccupancyGridUpdate msg_;
};

class Init_OccupancyGridUpdate_y
{
public:
  explicit Init_OccupancyGridUpdate_y(::map_msgs::msg::OccupancyGridUpdate & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUpdate_width y(::map_msgs::msg::OccupancyGridUpdate::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_OccupancyGridUpdate_width(msg_);
  }

private:
  ::map_msgs::msg::OccupancyGridUpdate msg_;
};

class Init_OccupancyGridUpdate_x
{
public:
  explicit Init_OccupancyGridUpdate_x(::map_msgs::msg::OccupancyGridUpdate & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUpdate_y x(::map_msgs::msg::OccupancyGridUpdate::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_OccupancyGridUpdate_y(msg_);
  }

private:
  ::map_msgs::msg::OccupancyGridUpdate msg_;
};

class Init_OccupancyGridUpdate_header
{
public:
  Init_OccupancyGridUpdate_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OccupancyGridUpdate_x header(::map_msgs::msg::OccupancyGridUpdate::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_OccupancyGridUpdate_x(msg_);
  }

private:
  ::map_msgs::msg::OccupancyGridUpdate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::msg::OccupancyGridUpdate>()
{
  return map_msgs::msg::builder::Init_OccupancyGridUpdate_header();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__BUILDER_HPP_
