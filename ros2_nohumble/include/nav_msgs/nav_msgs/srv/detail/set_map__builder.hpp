// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nav_msgs:srv\SetMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/srv/set_map.hpp"


#ifndef NAV_MSGS__SRV__DETAIL__SET_MAP__BUILDER_HPP_
#define NAV_MSGS__SRV__DETAIL__SET_MAP__BUILDER_HPP_

#include <utility>

#include "nav_msgs/srv/detail/set_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nav_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMap_Request_initial_pose
{
public:
  explicit Init_SetMap_Request_initial_pose(::nav_msgs::srv::SetMap_Request & msg)
  : msg_(msg)
  {}
  ::nav_msgs::srv::SetMap_Request initial_pose(::nav_msgs::srv::SetMap_Request::_initial_pose_type arg)
  {
    msg_.initial_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_msgs::srv::SetMap_Request msg_;
};

class Init_SetMap_Request_map
{
public:
  Init_SetMap_Request_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMap_Request_initial_pose map(::nav_msgs::srv::SetMap_Request::_map_type arg)
  {
    msg_.map = std::move(arg);
    return Init_SetMap_Request_initial_pose(msg_);
  }

private:
  ::nav_msgs::srv::SetMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_msgs::srv::SetMap_Request>()
{
  return nav_msgs::srv::builder::Init_SetMap_Request_map();
}

}  // namespace nav_msgs


namespace nav_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMap_Response_success
{
public:
  Init_SetMap_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::nav_msgs::srv::SetMap_Response success(::nav_msgs::srv::SetMap_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_msgs::srv::SetMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_msgs::srv::SetMap_Response>()
{
  return nav_msgs::srv::builder::Init_SetMap_Response_success();
}

}  // namespace nav_msgs


namespace nav_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMap_Event_response
{
public:
  explicit Init_SetMap_Event_response(::nav_msgs::srv::SetMap_Event & msg)
  : msg_(msg)
  {}
  ::nav_msgs::srv::SetMap_Event response(::nav_msgs::srv::SetMap_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nav_msgs::srv::SetMap_Event msg_;
};

class Init_SetMap_Event_request
{
public:
  explicit Init_SetMap_Event_request(::nav_msgs::srv::SetMap_Event & msg)
  : msg_(msg)
  {}
  Init_SetMap_Event_response request(::nav_msgs::srv::SetMap_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetMap_Event_response(msg_);
  }

private:
  ::nav_msgs::srv::SetMap_Event msg_;
};

class Init_SetMap_Event_info
{
public:
  Init_SetMap_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMap_Event_request info(::nav_msgs::srv::SetMap_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetMap_Event_request(msg_);
  }

private:
  ::nav_msgs::srv::SetMap_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nav_msgs::srv::SetMap_Event>()
{
  return nav_msgs::srv::builder::Init_SetMap_Event_info();
}

}  // namespace nav_msgs

#endif  // NAV_MSGS__SRV__DETAIL__SET_MAP__BUILDER_HPP_
