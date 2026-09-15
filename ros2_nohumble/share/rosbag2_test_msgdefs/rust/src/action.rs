
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to rosbag2_test_msgdefs__action__BasicAction_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: std::string::String,

}



impl Default for BasicAction_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_Goal {
  type RmwMsg = super::action::rmw::BasicAction_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: msg.goal.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: msg.goal.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal: msg.goal.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicAction_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: std::string::String,

}



impl Default for BasicAction_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_Result::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_Result {
  type RmwMsg = super::action::rmw::BasicAction_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicAction_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: std::string::String,

}



impl Default for BasicAction_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_Feedback {
  type RmwMsg = super::action::rmw::BasicAction_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: msg.feedback.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: msg.feedback.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      feedback: msg.feedback.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicAction_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::BasicAction_Feedback,

}



impl Default for BasicAction_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_FeedbackMessage {
  type RmwMsg = super::action::rmw::BasicAction_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::BasicAction_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::BasicAction_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::BasicAction_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: std::string::String,

}



impl Default for BasicMsg_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_Goal {
  type RmwMsg = super::action::rmw::BasicMsg_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: msg.goal.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: msg.goal.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal: msg.goal.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: std::string::String,

}



impl Default for BasicMsg_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_Result::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_Result {
  type RmwMsg = super::action::rmw::BasicMsg_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: std::string::String,

}



impl Default for BasicMsg_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_Feedback {
  type RmwMsg = super::action::rmw::BasicMsg_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: msg.feedback.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: msg.feedback.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      feedback: msg.feedback.to_string(),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::BasicMsg_Feedback,

}



impl Default for BasicMsg_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_FeedbackMessage {
  type RmwMsg = super::action::rmw::BasicMsg_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::BasicMsg_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::BasicMsg_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::BasicMsg_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::msg::BasicMsg,

}



impl Default for ComplexActionMsg_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_Goal {
  type RmwMsg = super::action::rmw::ComplexActionMsg_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal: super::msg::BasicMsg::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::msg::BasicMsg,

}



impl Default for ComplexActionMsg_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_Result::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_Result {
  type RmwMsg = super::action::rmw::ComplexActionMsg_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: super::msg::BasicMsg::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::msg::BasicMsg,

}



impl Default for ComplexActionMsg_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_Feedback {
  type RmwMsg = super::action::rmw::ComplexActionMsg_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: super::msg::BasicMsg::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      feedback: super::msg::BasicMsg::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::ComplexActionMsg_Feedback,

}



impl Default for ComplexActionMsg_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_FeedbackMessage {
  type RmwMsg = super::action::rmw::ComplexActionMsg_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::ComplexActionMsg_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::ComplexActionMsg_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::ComplexActionMsg_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::msg::BasicIdl,

}



impl Default for ComplexActionIdl_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_Goal {
  type RmwMsg = super::action::rmw::ComplexActionIdl_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal: super::msg::BasicIdl::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::msg::BasicIdl,

}



impl Default for ComplexActionIdl_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_Result::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_Result {
  type RmwMsg = super::action::rmw::ComplexActionIdl_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: super::msg::BasicIdl::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::msg::BasicIdl,

}



impl Default for ComplexActionIdl_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_Feedback {
  type RmwMsg = super::action::rmw::ComplexActionIdl_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        feedback: super::msg::BasicIdl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      feedback: super::msg::BasicIdl::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::ComplexActionIdl_Feedback,

}



impl Default for ComplexActionIdl_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_FeedbackMessage {
  type RmwMsg = super::action::rmw::ComplexActionIdl_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::ComplexActionIdl_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::ComplexActionIdl_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::ComplexActionIdl_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to rosbag2_test_msgdefs__action__BasicAction_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::BasicAction_Goal,

}



impl Default for BasicAction_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_SendGoal_Request {
  type RmwMsg = super::action::rmw::BasicAction_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::BasicAction_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::BasicAction_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::BasicAction_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicAction_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for BasicAction_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_SendGoal_Response {
  type RmwMsg = super::action::rmw::BasicAction_SendGoal_Response;

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


// Corresponds to rosbag2_test_msgdefs__action__BasicAction_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for BasicAction_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_GetResult_Request {
  type RmwMsg = super::action::rmw::BasicAction_GetResult_Request;

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


// Corresponds to rosbag2_test_msgdefs__action__BasicAction_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicAction_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::BasicAction_Result,

}



impl Default for BasicAction_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicAction_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BasicAction_GetResult_Response {
  type RmwMsg = super::action::rmw::BasicAction_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::BasicAction_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::BasicAction_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::BasicAction_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::BasicMsg_Goal,

}



impl Default for BasicMsg_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_SendGoal_Request {
  type RmwMsg = super::action::rmw::BasicMsg_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::BasicMsg_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::BasicMsg_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::BasicMsg_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for BasicMsg_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_SendGoal_Response {
  type RmwMsg = super::action::rmw::BasicMsg_SendGoal_Response;

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


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for BasicMsg_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_GetResult_Request {
  type RmwMsg = super::action::rmw::BasicMsg_GetResult_Request;

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


// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BasicMsg_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::BasicMsg_Result,

}



impl Default for BasicMsg_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::BasicMsg_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BasicMsg_GetResult_Response {
  type RmwMsg = super::action::rmw::BasicMsg_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::BasicMsg_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::BasicMsg_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::BasicMsg_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::ComplexActionMsg_Goal,

}



impl Default for ComplexActionMsg_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_SendGoal_Request {
  type RmwMsg = super::action::rmw::ComplexActionMsg_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::ComplexActionMsg_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::ComplexActionMsg_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::ComplexActionMsg_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for ComplexActionMsg_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_SendGoal_Response {
  type RmwMsg = super::action::rmw::ComplexActionMsg_SendGoal_Response;

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


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for ComplexActionMsg_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_GetResult_Request {
  type RmwMsg = super::action::rmw::ComplexActionMsg_GetResult_Request;

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


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionMsg_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::ComplexActionMsg_Result,

}



impl Default for ComplexActionMsg_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionMsg_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionMsg_GetResult_Response {
  type RmwMsg = super::action::rmw::ComplexActionMsg_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::ComplexActionMsg_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::ComplexActionMsg_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::ComplexActionMsg_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::ComplexActionIdl_Goal,

}



impl Default for ComplexActionIdl_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_SendGoal_Request {
  type RmwMsg = super::action::rmw::ComplexActionIdl_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::ComplexActionIdl_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::ComplexActionIdl_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::ComplexActionIdl_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for ComplexActionIdl_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_SendGoal_Response {
  type RmwMsg = super::action::rmw::ComplexActionIdl_SendGoal_Response;

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


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for ComplexActionIdl_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_GetResult_Request {
  type RmwMsg = super::action::rmw::ComplexActionIdl_GetResult_Request;

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


// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ComplexActionIdl_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::ComplexActionIdl_Result,

}



impl Default for ComplexActionIdl_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ComplexActionIdl_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ComplexActionIdl_GetResult_Response {
  type RmwMsg = super::action::rmw::ComplexActionIdl_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::ComplexActionIdl_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::ComplexActionIdl_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::ComplexActionIdl_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicAction_SendGoal;

impl rosidl_runtime_rs::Service for BasicAction_SendGoal {
    type Request = BasicAction_SendGoal_Request;
    type Response = BasicAction_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicAction_GetResult;

impl rosidl_runtime_rs::Service for BasicAction_GetResult {
    type Request = BasicAction_GetResult_Request;
    type Response = BasicAction_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicAction_GetResult() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicMsg_SendGoal;

impl rosidl_runtime_rs::Service for BasicMsg_SendGoal {
    type Request = BasicMsg_SendGoal_Request;
    type Response = BasicMsg_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicMsg_GetResult;

impl rosidl_runtime_rs::Service for BasicMsg_GetResult {
    type Request = BasicMsg_GetResult_Request;
    type Response = BasicMsg_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg_GetResult() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionMsg_SendGoal;

impl rosidl_runtime_rs::Service for ComplexActionMsg_SendGoal {
    type Request = ComplexActionMsg_SendGoal_Request;
    type Response = ComplexActionMsg_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionMsg_GetResult;

impl rosidl_runtime_rs::Service for ComplexActionMsg_GetResult {
    type Request = ComplexActionMsg_GetResult_Request;
    type Response = ComplexActionMsg_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg_GetResult() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionIdl_SendGoal;

impl rosidl_runtime_rs::Service for ComplexActionIdl_SendGoal {
    type Request = ComplexActionIdl_SendGoal_Request;
    type Response = ComplexActionIdl_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_SendGoal() }
    }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionIdl_GetResult;

impl rosidl_runtime_rs::Service for ComplexActionIdl_GetResult {
    type Request = ComplexActionIdl_GetResult_Request;
    type Response = ComplexActionIdl_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl_GetResult() }
    }
}






#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__BasicAction() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicAction
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicAction;

impl rosidl_runtime_rs::Action for BasicAction {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = BasicAction_Goal;

  /// The result message defined in the action definition.
  type Result = BasicAction_Result;

  /// The feedback message defined in the action definition.
  type Feedback = BasicAction_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::BasicAction_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::BasicAction_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::BasicAction_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__BasicAction() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::BasicAction_Goal,
  ) -> super::action::rmw::BasicAction_SendGoal_Request {
   super::action::rmw::BasicAction_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::BasicAction_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::BasicAction_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::BasicAction_SendGoal_Response {
   super::action::rmw::BasicAction_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::BasicAction_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::BasicAction_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::BasicAction_Feedback,
  ) -> super::action::rmw::BasicAction_FeedbackMessage {
    let mut message = super::action::rmw::BasicAction_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::BasicAction_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::BasicAction_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::BasicAction_GetResult_Request {
   super::action::rmw::BasicAction_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::BasicAction_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::BasicAction_Result,
  ) -> super::action::rmw::BasicAction_GetResult_Response {
   super::action::rmw::BasicAction_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::BasicAction_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::BasicAction_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__BasicMsg
#[allow(missing_docs, non_camel_case_types)]
pub struct BasicMsg;

impl rosidl_runtime_rs::Action for BasicMsg {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = BasicMsg_Goal;

  /// The result message defined in the action definition.
  type Result = BasicMsg_Result;

  /// The feedback message defined in the action definition.
  type Feedback = BasicMsg_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::BasicMsg_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::BasicMsg_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::BasicMsg_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__BasicMsg() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::BasicMsg_Goal,
  ) -> super::action::rmw::BasicMsg_SendGoal_Request {
   super::action::rmw::BasicMsg_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::BasicMsg_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::BasicMsg_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::BasicMsg_SendGoal_Response {
   super::action::rmw::BasicMsg_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::BasicMsg_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::BasicMsg_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::BasicMsg_Feedback,
  ) -> super::action::rmw::BasicMsg_FeedbackMessage {
    let mut message = super::action::rmw::BasicMsg_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::BasicMsg_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::BasicMsg_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::BasicMsg_GetResult_Request {
   super::action::rmw::BasicMsg_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::BasicMsg_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::BasicMsg_Result,
  ) -> super::action::rmw::BasicMsg_GetResult_Response {
   super::action::rmw::BasicMsg_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::BasicMsg_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::BasicMsg_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionMsg
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionMsg;

impl rosidl_runtime_rs::Action for ComplexActionMsg {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = ComplexActionMsg_Goal;

  /// The result message defined in the action definition.
  type Result = ComplexActionMsg_Result;

  /// The feedback message defined in the action definition.
  type Feedback = ComplexActionMsg_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::ComplexActionMsg_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::ComplexActionMsg_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::ComplexActionMsg_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionMsg() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::ComplexActionMsg_Goal,
  ) -> super::action::rmw::ComplexActionMsg_SendGoal_Request {
   super::action::rmw::ComplexActionMsg_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::ComplexActionMsg_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::ComplexActionMsg_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::ComplexActionMsg_SendGoal_Response {
   super::action::rmw::ComplexActionMsg_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::ComplexActionMsg_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::ComplexActionMsg_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::ComplexActionMsg_Feedback,
  ) -> super::action::rmw::ComplexActionMsg_FeedbackMessage {
    let mut message = super::action::rmw::ComplexActionMsg_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::ComplexActionMsg_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::ComplexActionMsg_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::ComplexActionMsg_GetResult_Request {
   super::action::rmw::ComplexActionMsg_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::ComplexActionMsg_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::ComplexActionMsg_Result,
  ) -> super::action::rmw::ComplexActionMsg_GetResult_Response {
   super::action::rmw::ComplexActionMsg_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::ComplexActionMsg_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::ComplexActionMsg_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "rosbag2_test_msgdefs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_test_msgdefs__action__ComplexActionIdl
#[allow(missing_docs, non_camel_case_types)]
pub struct ComplexActionIdl;

impl rosidl_runtime_rs::Action for ComplexActionIdl {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = ComplexActionIdl_Goal;

  /// The result message defined in the action definition.
  type Result = ComplexActionIdl_Result;

  /// The feedback message defined in the action definition.
  type Feedback = ComplexActionIdl_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::ComplexActionIdl_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::ComplexActionIdl_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::ComplexActionIdl_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__rosbag2_test_msgdefs__action__ComplexActionIdl() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::ComplexActionIdl_Goal,
  ) -> super::action::rmw::ComplexActionIdl_SendGoal_Request {
   super::action::rmw::ComplexActionIdl_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::ComplexActionIdl_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::ComplexActionIdl_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::ComplexActionIdl_SendGoal_Response {
   super::action::rmw::ComplexActionIdl_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::ComplexActionIdl_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::ComplexActionIdl_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::ComplexActionIdl_Feedback,
  ) -> super::action::rmw::ComplexActionIdl_FeedbackMessage {
    let mut message = super::action::rmw::ComplexActionIdl_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::ComplexActionIdl_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::ComplexActionIdl_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::ComplexActionIdl_GetResult_Request {
   super::action::rmw::ComplexActionIdl_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::ComplexActionIdl_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::ComplexActionIdl_Result,
  ) -> super::action::rmw::ComplexActionIdl_GetResult_Response {
   super::action::rmw::ComplexActionIdl_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::ComplexActionIdl_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::ComplexActionIdl_Result,
  ) {
    (response.status, response.result)
  }
}


