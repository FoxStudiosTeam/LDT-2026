// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:srv\GetPointMapROI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/get_point_map_roi.hpp"


#ifndef MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__BUILDER_HPP_
#define MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__BUILDER_HPP_

#include <utility>

#include "map_msgs/srv/detail/get_point_map_roi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPointMapROI_Request_l_z
{
public:
  explicit Init_GetPointMapROI_Request_l_z(::map_msgs::srv::GetPointMapROI_Request & msg)
  : msg_(msg)
  {}
  ::map_msgs::srv::GetPointMapROI_Request l_z(::map_msgs::srv::GetPointMapROI_Request::_l_z_type arg)
  {
    msg_.l_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

class Init_GetPointMapROI_Request_l_y
{
public:
  explicit Init_GetPointMapROI_Request_l_y(::map_msgs::srv::GetPointMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetPointMapROI_Request_l_z l_y(::map_msgs::srv::GetPointMapROI_Request::_l_y_type arg)
  {
    msg_.l_y = std::move(arg);
    return Init_GetPointMapROI_Request_l_z(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

class Init_GetPointMapROI_Request_l_x
{
public:
  explicit Init_GetPointMapROI_Request_l_x(::map_msgs::srv::GetPointMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetPointMapROI_Request_l_y l_x(::map_msgs::srv::GetPointMapROI_Request::_l_x_type arg)
  {
    msg_.l_x = std::move(arg);
    return Init_GetPointMapROI_Request_l_y(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

class Init_GetPointMapROI_Request_r
{
public:
  explicit Init_GetPointMapROI_Request_r(::map_msgs::srv::GetPointMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetPointMapROI_Request_l_x r(::map_msgs::srv::GetPointMapROI_Request::_r_type arg)
  {
    msg_.r = std::move(arg);
    return Init_GetPointMapROI_Request_l_x(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

class Init_GetPointMapROI_Request_z
{
public:
  explicit Init_GetPointMapROI_Request_z(::map_msgs::srv::GetPointMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetPointMapROI_Request_r z(::map_msgs::srv::GetPointMapROI_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_GetPointMapROI_Request_r(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

class Init_GetPointMapROI_Request_y
{
public:
  explicit Init_GetPointMapROI_Request_y(::map_msgs::srv::GetPointMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetPointMapROI_Request_z y(::map_msgs::srv::GetPointMapROI_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GetPointMapROI_Request_z(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

class Init_GetPointMapROI_Request_x
{
public:
  Init_GetPointMapROI_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPointMapROI_Request_y x(::map_msgs::srv::GetPointMapROI_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetPointMapROI_Request_y(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::GetPointMapROI_Request>()
{
  return map_msgs::srv::builder::Init_GetPointMapROI_Request_x();
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPointMapROI_Response_sub_map
{
public:
  Init_GetPointMapROI_Response_sub_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_msgs::srv::GetPointMapROI_Response sub_map(::map_msgs::srv::GetPointMapROI_Response::_sub_map_type arg)
  {
    msg_.sub_map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::GetPointMapROI_Response>()
{
  return map_msgs::srv::builder::Init_GetPointMapROI_Response_sub_map();
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPointMapROI_Event_response
{
public:
  explicit Init_GetPointMapROI_Event_response(::map_msgs::srv::GetPointMapROI_Event & msg)
  : msg_(msg)
  {}
  ::map_msgs::srv::GetPointMapROI_Event response(::map_msgs::srv::GetPointMapROI_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Event msg_;
};

class Init_GetPointMapROI_Event_request
{
public:
  explicit Init_GetPointMapROI_Event_request(::map_msgs::srv::GetPointMapROI_Event & msg)
  : msg_(msg)
  {}
  Init_GetPointMapROI_Event_response request(::map_msgs::srv::GetPointMapROI_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPointMapROI_Event_response(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Event msg_;
};

class Init_GetPointMapROI_Event_info
{
public:
  Init_GetPointMapROI_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPointMapROI_Event_request info(::map_msgs::srv::GetPointMapROI_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPointMapROI_Event_request(msg_);
  }

private:
  ::map_msgs::srv::GetPointMapROI_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::GetPointMapROI_Event>()
{
  return map_msgs::srv::builder::Init_GetPointMapROI_Event_info();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__BUILDER_HPP_
