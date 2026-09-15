// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_test_msgdefs:action\ComplexActionIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/action/complex_action_idl.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__ACTION__DETAIL__COMPLEX_ACTION_IDL__BUILDER_HPP_
#define ROSBAG2_TEST_MSGDEFS__ACTION__DETAIL__COMPLEX_ACTION_IDL__BUILDER_HPP_

#include <utility>

#include "rosbag2_test_msgdefs/action/detail/complex_action_idl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_Goal_goal
{
public:
  Init_ComplexActionIdl_Goal_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_Goal goal(::rosbag2_test_msgdefs::action::ComplexActionIdl_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_Goal>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_Goal_goal();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_Result_result
{
public:
  Init_ComplexActionIdl_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_Result result(::rosbag2_test_msgdefs::action::ComplexActionIdl_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_Result>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_Result_result();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_Feedback_feedback
{
public:
  Init_ComplexActionIdl_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_Feedback feedback(::rosbag2_test_msgdefs::action::ComplexActionIdl_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_Feedback>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_Feedback_feedback();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_SendGoal_Request_goal
{
public:
  explicit Init_ComplexActionIdl_SendGoal_Request_goal(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request goal(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request msg_;
};

class Init_ComplexActionIdl_SendGoal_Request_goal_id
{
public:
  Init_ComplexActionIdl_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexActionIdl_SendGoal_Request_goal goal_id(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ComplexActionIdl_SendGoal_Request_goal(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Request>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_SendGoal_Request_goal_id();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_SendGoal_Response_stamp
{
public:
  explicit Init_ComplexActionIdl_SendGoal_Response_stamp(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response stamp(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response msg_;
};

class Init_ComplexActionIdl_SendGoal_Response_accepted
{
public:
  Init_ComplexActionIdl_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexActionIdl_SendGoal_Response_stamp accepted(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ComplexActionIdl_SendGoal_Response_stamp(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Response>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_SendGoal_Response_accepted();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_SendGoal_Event_response
{
public:
  explicit Init_ComplexActionIdl_SendGoal_Event_response(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event response(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event msg_;
};

class Init_ComplexActionIdl_SendGoal_Event_request
{
public:
  explicit Init_ComplexActionIdl_SendGoal_Event_request(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ComplexActionIdl_SendGoal_Event_response request(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComplexActionIdl_SendGoal_Event_response(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event msg_;
};

class Init_ComplexActionIdl_SendGoal_Event_info
{
public:
  Init_ComplexActionIdl_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexActionIdl_SendGoal_Event_request info(::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComplexActionIdl_SendGoal_Event_request(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_SendGoal_Event>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_SendGoal_Event_info();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_GetResult_Request_goal_id
{
public:
  Init_ComplexActionIdl_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Request goal_id(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Request>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_GetResult_Request_goal_id();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_GetResult_Response_result
{
public:
  explicit Init_ComplexActionIdl_GetResult_Response_result(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response result(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response msg_;
};

class Init_ComplexActionIdl_GetResult_Response_status
{
public:
  Init_ComplexActionIdl_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexActionIdl_GetResult_Response_result status(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ComplexActionIdl_GetResult_Response_result(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Response>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_GetResult_Response_status();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_GetResult_Event_response
{
public:
  explicit Init_ComplexActionIdl_GetResult_Event_response(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event response(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event msg_;
};

class Init_ComplexActionIdl_GetResult_Event_request
{
public:
  explicit Init_ComplexActionIdl_GetResult_Event_request(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ComplexActionIdl_GetResult_Event_response request(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ComplexActionIdl_GetResult_Event_response(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event msg_;
};

class Init_ComplexActionIdl_GetResult_Event_info
{
public:
  Init_ComplexActionIdl_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexActionIdl_GetResult_Event_request info(::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ComplexActionIdl_GetResult_Event_request(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_GetResult_Event>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_GetResult_Event_info();
}

}  // namespace rosbag2_test_msgdefs


namespace rosbag2_test_msgdefs
{

namespace action
{

namespace builder
{

class Init_ComplexActionIdl_FeedbackMessage_feedback
{
public:
  explicit Init_ComplexActionIdl_FeedbackMessage_feedback(::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage feedback(::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage msg_;
};

class Init_ComplexActionIdl_FeedbackMessage_goal_id
{
public:
  Init_ComplexActionIdl_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComplexActionIdl_FeedbackMessage_feedback goal_id(::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ComplexActionIdl_FeedbackMessage_feedback(msg_);
  }

private:
  ::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_test_msgdefs::action::ComplexActionIdl_FeedbackMessage>()
{
  return rosbag2_test_msgdefs::action::builder::Init_ComplexActionIdl_FeedbackMessage_goal_id();
}

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__ACTION__DETAIL__COMPLEX_ACTION_IDL__BUILDER_HPP_
