#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to pendulum_msgs__msg__JointState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JointState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub position: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub effort: f64,

}



impl Default for JointState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::JointState::default())
  }
}

impl rosidl_runtime_rs::Message for JointState {
  type RmwMsg = super::msg::rmw::JointState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: msg.position,
        velocity: msg.velocity,
        effort: msg.effort,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      position: msg.position,
      velocity: msg.velocity,
      effort: msg.effort,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position: msg.position,
      velocity: msg.velocity,
      effort: msg.effort,
    }
  }
}


// Corresponds to pendulum_msgs__msg__JointCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JointCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub position: f64,

}



impl Default for JointCommand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::JointCommand::default())
  }
}

impl rosidl_runtime_rs::Message for JointCommand {
  type RmwMsg = super::msg::rmw::JointCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: msg.position,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      position: msg.position,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position: msg.position,
    }
  }
}


// Corresponds to pendulum_msgs__msg__RttestResults

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RttestResults {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command: super::msg::JointCommand,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: super::msg::JointState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cur_latency: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mean_latency: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub min_latency: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_latency: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub minor_pagefaults: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub major_pagefaults: u64,

}



impl Default for RttestResults {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RttestResults::default())
  }
}

impl rosidl_runtime_rs::Message for RttestResults {
  type RmwMsg = super::msg::rmw::RttestResults;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        command: super::msg::JointCommand::into_rmw_message(std::borrow::Cow::Owned(msg.command)).into_owned(),
        state: super::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(msg.state)).into_owned(),
        cur_latency: msg.cur_latency,
        mean_latency: msg.mean_latency,
        min_latency: msg.min_latency,
        max_latency: msg.max_latency,
        minor_pagefaults: msg.minor_pagefaults,
        major_pagefaults: msg.major_pagefaults,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
        command: super::msg::JointCommand::into_rmw_message(std::borrow::Cow::Borrowed(&msg.command)).into_owned(),
        state: super::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.state)).into_owned(),
      cur_latency: msg.cur_latency,
      mean_latency: msg.mean_latency,
      min_latency: msg.min_latency,
      max_latency: msg.max_latency,
      minor_pagefaults: msg.minor_pagefaults,
      major_pagefaults: msg.major_pagefaults,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      command: super::msg::JointCommand::from_rmw_message(msg.command),
      state: super::msg::JointState::from_rmw_message(msg.state),
      cur_latency: msg.cur_latency,
      mean_latency: msg.mean_latency,
      min_latency: msg.min_latency,
      max_latency: msg.max_latency,
      minor_pagefaults: msg.minor_pagefaults,
      major_pagefaults: msg.major_pagefaults,
    }
  }
}


