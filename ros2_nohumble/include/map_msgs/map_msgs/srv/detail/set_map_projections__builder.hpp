// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:srv\SetMapProjections.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/set_map_projections.hpp"


#ifndef MAP_MSGS__SRV__DETAIL__SET_MAP_PROJECTIONS__BUILDER_HPP_
#define MAP_MSGS__SRV__DETAIL__SET_MAP_PROJECTIONS__BUILDER_HPP_

#include <utility>

#include "map_msgs/srv/detail/set_map_projections__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::SetMapProjections_Request>()
{
  return ::map_msgs::srv::SetMapProjections_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMapProjections_Response_projected_maps_info
{
public:
  Init_SetMapProjections_Response_projected_maps_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_msgs::srv::SetMapProjections_Response projected_maps_info(::map_msgs::srv::SetMapProjections_Response::_projected_maps_info_type arg)
  {
    msg_.projected_maps_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::SetMapProjections_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::SetMapProjections_Response>()
{
  return map_msgs::srv::builder::Init_SetMapProjections_Response_projected_maps_info();
}

}  // namespace map_msgs


namespace map_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMapProjections_Event_response
{
public:
  explicit Init_SetMapProjections_Event_response(::map_msgs::srv::SetMapProjections_Event & msg)
  : msg_(msg)
  {}
  ::map_msgs::srv::SetMapProjections_Event response(::map_msgs::srv::SetMapProjections_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::srv::SetMapProjections_Event msg_;
};

class Init_SetMapProjections_Event_request
{
public:
  explicit Init_SetMapProjections_Event_request(::map_msgs::srv::SetMapProjections_Event & msg)
  : msg_(msg)
  {}
  Init_SetMapProjections_Event_response request(::map_msgs::srv::SetMapProjections_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetMapProjections_Event_response(msg_);
  }

private:
  ::map_msgs::srv::SetMapProjections_Event msg_;
};

class Init_SetMapProjections_Event_info
{
public:
  Init_SetMapProjections_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMapProjections_Event_request info(::map_msgs::srv::SetMapProjections_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetMapProjections_Event_request(msg_);
  }

private:
  ::map_msgs::srv::SetMapProjections_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::srv::SetMapProjections_Event>()
{
  return map_msgs::srv::builder::Init_SetMapProjections_Event_info();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__SRV__DETAIL__SET_MAP_PROJECTIONS__BUILDER_HPP_
