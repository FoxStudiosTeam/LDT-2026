// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:srv\GetMapROI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/get_map_roi.hpp"


#ifndef MAP_MSGS__SRV__DETAIL__GET_MAP_ROI__BUILDER_HPP_
#define MAP_MSGS__SRV__DETAIL__GET_MAP_ROI__BUILDER_HPP_

#include <utility>

#include "map_msgs/srv/detail/get_map_roi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMapROI_Request_l_y
{
public:
  explicit Init_GetMapROI_Request_l_y(::map_msgs::srv::GetMapROI_Request & msg)
  : msg_(msg)
  {}
  ::map_msgs::srv::GetMapROI_Request l_y(::map_msgs::srv::GetMapROI_Request::_l_y_type arg)
  {
    msg_.l_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Request msg_;
};

class Init_GetMapROI_Request_l_x
{
public:
  explicit Init_GetMapROI_Request_l_x(::map_msgs::srv::GetMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetMapROI_Request_l_y l_x(::map_msgs::srv::GetMapROI_Request::_l_x_type arg)
  {
    msg_.l_x = std::move(arg);
    return Init_GetMapROI_Request_l_y(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Request msg_;
};

class Init_GetMapROI_Request_y
{
public:
  explicit Init_GetMapROI_Request_y(::map_msgs::srv::GetMapROI_Request & msg)
  : msg_(msg)
  {}
  Init_GetMapROI_Request_l_x y(::map_msgs::srv::GetMapROI_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GetMapROI_Request_l_x(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Request msg_;
};

class Init_GetMapROI_Request_x
{
public:
  Init_GetMapROI_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMapROI_Request_y x(::map_msgs::srv::GetMapROI_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetMapROI_Request_y(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::GetMapROI_Request>()
{
  return map_msgs::srv::builder::Init_GetMapROI_Request_x();
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMapROI_Response_sub_map
{
public:
  Init_GetMapROI_Response_sub_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_msgs::srv::GetMapROI_Response sub_map(::map_msgs::srv::GetMapROI_Response::_sub_map_type arg)
  {
    msg_.sub_map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::GetMapROI_Response>()
{
  return map_msgs::srv::builder::Init_GetMapROI_Response_sub_map();
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMapROI_Event_response
{
public:
  explicit Init_GetMapROI_Event_response(::map_msgs::srv::GetMapROI_Event & msg)
  : msg_(msg)
  {}
  ::map_msgs::srv::GetMapROI_Event response(::map_msgs::srv::GetMapROI_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Event msg_;
};

class Init_GetMapROI_Event_request
{
public:
  explicit Init_GetMapROI_Event_request(::map_msgs::srv::GetMapROI_Event & msg)
  : msg_(msg)
  {}
  Init_GetMapROI_Event_response request(::map_msgs::srv::GetMapROI_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetMapROI_Event_response(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Event msg_;
};

class Init_GetMapROI_Event_info
{
public:
  Init_GetMapROI_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMapROI_Event_request info(::map_msgs::srv::GetMapROI_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetMapROI_Event_request(msg_);
  }

private:
  ::map_msgs::srv::GetMapROI_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::GetMapROI_Event>()
{
  return map_msgs::srv::builder::Init_GetMapROI_Event_info();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__SRV__DETAIL__GET_MAP_ROI__BUILDER_HPP_
