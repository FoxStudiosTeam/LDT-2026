// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:srv\ProjectedMapsInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/projected_maps_info.hpp"


#ifndef MAP_MSGS__SRV__DETAIL__PROJECTED_MAPS_INFO__BUILDER_HPP_
#define MAP_MSGS__SRV__DETAIL__PROJECTED_MAPS_INFO__BUILDER_HPP_

#include <utility>

#include "map_msgs/srv/detail/projected_maps_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_ProjectedMapsInfo_Request_projected_maps_info
{
public:
  Init_ProjectedMapsInfo_Request_projected_maps_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_msgs::srv::ProjectedMapsInfo_Request projected_maps_info(::map_msgs::srv::ProjectedMapsInfo_Request::_projected_maps_info_type arg)
  {
    msg_.projected_maps_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::ProjectedMapsInfo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::ProjectedMapsInfo_Request>()
{
  return map_msgs::srv::builder::Init_ProjectedMapsInfo_Request_projected_maps_info();
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::ProjectedMapsInfo_Response>()
{
  return ::map_msgs::srv::ProjectedMapsInfo_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_ProjectedMapsInfo_Event_response
{
public:
  explicit Init_ProjectedMapsInfo_Event_response(::map_msgs::srv::ProjectedMapsInfo_Event & msg)
  : msg_(msg)
  {}
  ::map_msgs::srv::ProjectedMapsInfo_Event response(::map_msgs::srv::ProjectedMapsInfo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::ProjectedMapsInfo_Event msg_;
};

class Init_ProjectedMapsInfo_Event_request
{
public:
  explicit Init_ProjectedMapsInfo_Event_request(::map_msgs::srv::ProjectedMapsInfo_Event & msg)
  : msg_(msg)
  {}
  Init_ProjectedMapsInfo_Event_response request(::map_msgs::srv::ProjectedMapsInfo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ProjectedMapsInfo_Event_response(msg_);
  }

private:
  ::map_msgs::srv::ProjectedMapsInfo_Event msg_;
};

class Init_ProjectedMapsInfo_Event_info
{
public:
  Init_ProjectedMapsInfo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProjectedMapsInfo_Event_request info(::map_msgs::srv::ProjectedMapsInfo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ProjectedMapsInfo_Event_request(msg_);
  }

private:
  ::map_msgs::srv::ProjectedMapsInfo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::ProjectedMapsInfo_Event>()
{
  return map_msgs::srv::builder::Init_ProjectedMapsInfo_Event_info();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__SRV__DETAIL__PROJECTED_MAPS_INFO__BUILDER_HPP_
