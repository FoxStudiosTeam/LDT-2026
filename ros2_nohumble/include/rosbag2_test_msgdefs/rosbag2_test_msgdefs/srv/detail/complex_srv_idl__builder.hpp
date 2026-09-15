// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_test_msgdefs:srv\ComplexSrvIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/srv/complex_srv_idl.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__BUILDER_HPP_
#define ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__BUILDER_HPP_

#include <utility>

#include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_test_msgdefs
{

namespace srv
{

namespace builder
{

class Init_ComplexSrvIdl_Request_req
{
public:
  Init_ComplexSrvIdl_Request_req()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request req(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request::_req_type arg)
  {
    msg_.req = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>()
{
  return rosbag2_test_msgdefs::srv::builder::Init_ComplexSrvIdl_Request_req();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace srv
{

namespace builder
{

class Init_ComplexSrvIdl_Response_resp
{
public:
  Init_ComplexSrvIdl_Response_resp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response resp(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response::_resp_type arg)
  {
    msg_.resp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>()
{
  return rosbag2_test_msgdefs::srv::builder::Init_ComplexSrvIdl_Response_resp();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace srv
{

namespace builder
{

class Init_ComplexSrvIdl_Event_response
{
public:
  explicit Init_ComplexSrvIdl_Event_response(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event response(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event msg_;
};

class Init_ComplexSrvIdl_Event_request
{
public:
  explicit Init_ComplexSrvIdl_Event_request(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event & msg)
  : msg_(msg)
  {}
  Init_ComplexSrvIdl_Event_response request(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComplexSrvIdl_Event_response(msg_);
  }

private:
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event msg_;
};

class Init_ComplexSrvIdl_Event_info
{
public:
  Init_ComplexSrvIdl_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexSrvIdl_Event_request info(::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComplexSrvIdl_Event_request(msg_);
  }

private:
  ::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>()
{
  return rosbag2_test_msgdefs::srv::builder::Init_ComplexSrvIdl_Event_info();
}

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__BUILDER_HPP_
