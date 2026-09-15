
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Goal {
    /// Comment - Nesting Level 3: 1 of 2
    pub short_varied_nested: super::msg::ShortVariedNested,

}



impl Default for ShortVariedMultiNested_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Goal {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied_nested: super::msg::ShortVariedNested::into_rmw_message(std::borrow::Cow::Owned(msg.short_varied_nested)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        short_varied_nested: super::msg::ShortVariedNested::into_rmw_message(std::borrow::Cow::Borrowed(&msg.short_varied_nested)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      short_varied_nested: super::msg::ShortVariedNested::from_rmw_message(msg.short_varied_nested),
    }
  }
}


// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Result {
    /// Comment - Nesting Level 3: 2 of 2
    pub bool_value: bool,

}



impl Default for ShortVariedMultiNested_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_Result::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Result {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_value: msg.bool_value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      bool_value: msg.bool_value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_value: msg.bool_value,
    }
  }
}


// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub bool_values: [bool; 3],

}



impl Default for ShortVariedMultiNested_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_Feedback {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        bool_values: msg.bool_values,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      bool_values: msg.bool_values,
    }
  }
}


// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::ShortVariedMultiNested_Feedback,

}



impl Default for ShortVariedMultiNested_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_FeedbackMessage {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::ShortVariedMultiNested_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::ShortVariedMultiNested_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::ShortVariedMultiNested_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::ShortVariedMultiNested_Goal,

}



impl Default for ShortVariedMultiNested_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_SendGoal_Request {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::ShortVariedMultiNested_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::ShortVariedMultiNested_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::ShortVariedMultiNested_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for ShortVariedMultiNested_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_SendGoal_Response {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for ShortVariedMultiNested_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_GetResult_Request {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ShortVariedMultiNested_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::ShortVariedMultiNested_Result,

}



impl Default for ShortVariedMultiNested_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ShortVariedMultiNested_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ShortVariedMultiNested_GetResult_Response {
  type RmwMsg = super::action::rmw::ShortVariedMultiNested_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::ShortVariedMultiNested_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::ShortVariedMultiNested_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::ShortVariedMultiNested_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested_SendGoal;

impl rosidl_runtime_rs::Service for ShortVariedMultiNested_SendGoal {
    type Request = ShortVariedMultiNested_SendGoal_Request;
    type Response = ShortVariedMultiNested_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_SendGoal() }
    }
}




#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested_GetResult;

impl rosidl_runtime_rs::Service for ShortVariedMultiNested_GetResult {
    type Request = ShortVariedMultiNested_GetResult_Request;
    type Response = ShortVariedMultiNested_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested_GetResult() }
    }
}






#[link(name = "ros2cli_test_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested() -> *const std::ffi::c_void;
}

// Corresponds to ros2cli_test_interfaces__action__ShortVariedMultiNested
#[allow(missing_docs, non_camel_case_types)]
pub struct ShortVariedMultiNested;

impl rosidl_runtime_rs::Action for ShortVariedMultiNested {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = ShortVariedMultiNested_Goal;

  /// The result message defined in the action definition.
  type Result = ShortVariedMultiNested_Result;

  /// The feedback message defined in the action definition.
  type Feedback = ShortVariedMultiNested_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::ShortVariedMultiNested_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::ShortVariedMultiNested_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::ShortVariedMultiNested_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__ros2cli_test_interfaces__action__ShortVariedMultiNested() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::ShortVariedMultiNested_Goal,
  ) -> super::action::rmw::ShortVariedMultiNested_SendGoal_Request {
   super::action::rmw::ShortVariedMultiNested_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::ShortVariedMultiNested_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::ShortVariedMultiNested_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::ShortVariedMultiNested_SendGoal_Response {
   super::action::rmw::ShortVariedMultiNested_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::ShortVariedMultiNested_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::ShortVariedMultiNested_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::ShortVariedMultiNested_Feedback,
  ) -> super::action::rmw::ShortVariedMultiNested_FeedbackMessage {
    let mut message = super::action::rmw::ShortVariedMultiNested_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::ShortVariedMultiNested_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::ShortVariedMultiNested_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::ShortVariedMultiNested_GetResult_Request {
   super::action::rmw::ShortVariedMultiNested_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::ShortVariedMultiNested_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::ShortVariedMultiNested_Result,
  ) -> super::action::rmw::ShortVariedMultiNested_GetResult_Response {
   super::action::rmw::ShortVariedMultiNested_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::ShortVariedMultiNested_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::ShortVariedMultiNested_Result,
  ) {
    (response.status, response.result)
  }
}


