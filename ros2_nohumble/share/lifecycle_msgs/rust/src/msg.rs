#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to lifecycle_msgs__msg__State
/// Primary state definitions as depicted in:
/// http://design.ros2.org/articles/node_lifecycle.html

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct State {
    /// The state id value from the above definitions.
    pub id: u8,

    /// A text label of the state.
    pub label: std::string::String,

}

impl State {
    /// These are the primary states. State changes can only be requested when the
    /// node is in one of these states.
    /// Indicates state has not yet been set.
    pub const PRIMARY_STATE_UNKNOWN: u8 = 0;

    /// This is the life cycle state the node is in immediately after being
    /// instantiated.
    pub const PRIMARY_STATE_UNCONFIGURED: u8 = 1;

    /// This state represents a node that is not currently performing any processing.
    pub const PRIMARY_STATE_INACTIVE: u8 = 2;

    /// This is the main state of the node's life cycle. While in this state, the node
    /// performs any processing, responds to service requests, reads and processes
    /// data, produces output, etc.
    pub const PRIMARY_STATE_ACTIVE: u8 = 3;

    /// The finalized state is the state in which the node ends immediately before
    /// being destroyed.
    pub const PRIMARY_STATE_FINALIZED: u8 = 4;

    /// Temporary intermediate states. When a transition is requested, the node
    /// changes its state into one of these states.
    /// In this transition state the node's onConfigure callback will be called to
    /// allow the node to load its configuration and conduct any required setup.
    pub const TRANSITION_STATE_CONFIGURING: u8 = 10;

    /// In this transition state the node's callback onCleanup will be called to clear
    /// all state and return the node to a functionally equivalent state as when
    /// first created.
    pub const TRANSITION_STATE_CLEANINGUP: u8 = 11;

    /// In this transition state the callback onShutdown will be executed to do any
    /// cleanup necessary before destruction.
    pub const TRANSITION_STATE_SHUTTINGDOWN: u8 = 12;

    /// In this transition state the callback onActivate will be executed to do any
    /// final preparations to start executing.
    pub const TRANSITION_STATE_ACTIVATING: u8 = 13;

    /// In this transition state the callback onDeactivate will be executed to do any
    /// cleanup to start executing, and reverse the onActivate changes.
    pub const TRANSITION_STATE_DEACTIVATING: u8 = 14;

    /// This transition state is where any error may be cleaned up.
    pub const TRANSITION_STATE_ERRORPROCESSING: u8 = 15;

}


impl Default for State {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::State::default())
  }
}

impl rosidl_runtime_rs::Message for State {
  type RmwMsg = super::msg::rmw::State;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        label: msg.label.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        label: msg.label.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      label: msg.label.to_string(),
    }
  }
}


// Corresponds to lifecycle_msgs__msg__Transition
/// Default values for transitions as described in:
/// http://design.ros2.org/articles/node_lifecycle.html

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Transition {
    /// Fields
    ///
    /// The transition id from above definitions.
    pub id: u8,

    /// A text label of the transition.
    pub label: std::string::String,

}

impl Transition {
    /// Reserved, publicly available transitions.
    /// When a node is in one of these primary states, these transitions can be
    /// invoked.
    /// This transition will instantiate the node, but will not run any code beyond
    /// the constructor.
    pub const TRANSITION_CREATE: u8 = 0;

    /// The node's onConfigure callback will be called to allow the node to load its
    /// configuration and conduct any required setup.
    pub const TRANSITION_CONFIGURE: u8 = 1;

    /// The node's callback onCleanup will be called in this transition to allow the
    /// node to load its configuration and conduct any required setup.
    pub const TRANSITION_CLEANUP: u8 = 2;

    /// The node's callback onActivate will be executed to do any final preparations
    /// to start executing.
    pub const TRANSITION_ACTIVATE: u8 = 3;

    /// The node's callback onDeactivate will be executed to do any cleanup to start
    /// executing, and reverse the onActivate changes.
    pub const TRANSITION_DEACTIVATE: u8 = 4;

    /// This signals shutdown during an unconfigured state, the node's callback
    /// onShutdown will be executed to do any cleanup necessary before destruction.
    pub const TRANSITION_UNCONFIGURED_SHUTDOWN: u8 = 5;

    /// This signals shutdown during an inactive state, the node's callback onShutdown
    /// will be executed to do any cleanup necessary before destruction.
    pub const TRANSITION_INACTIVE_SHUTDOWN: u8 = 6;

    /// This signals shutdown during an active state, the node's callback onShutdown
    /// will be executed to do any cleanup necessary before destruction.
    pub const TRANSITION_ACTIVE_SHUTDOWN: u8 = 7;

    /// This transition will simply cause the deallocation of the node.
    pub const TRANSITION_DESTROY: u8 = 8;

    /// Reserved, private transitions
    /// These transitions are not publicly available and cannot be invoked by a user.
    /// The following transitions are implicitly invoked based on the callback
    /// feedback of the intermediate transition states.
    pub const TRANSITION_ON_CONFIGURE_SUCCESS: u8 = 10;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_CONFIGURE_FAILURE: u8 = 11;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_CONFIGURE_ERROR: u8 = 12;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_CLEANUP_SUCCESS: u8 = 20;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_CLEANUP_FAILURE: u8 = 21;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_CLEANUP_ERROR: u8 = 22;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_ACTIVATE_SUCCESS: u8 = 30;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_ACTIVATE_FAILURE: u8 = 31;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_ACTIVATE_ERROR: u8 = 32;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_DEACTIVATE_SUCCESS: u8 = 40;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_DEACTIVATE_FAILURE: u8 = 41;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_DEACTIVATE_ERROR: u8 = 42;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_SHUTDOWN_SUCCESS: u8 = 50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_SHUTDOWN_FAILURE: u8 = 51;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_SHUTDOWN_ERROR: u8 = 52;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_ERROR_SUCCESS: u8 = 60;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_ERROR_FAILURE: u8 = 61;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRANSITION_ON_ERROR_ERROR: u8 = 62;

    /// Reserved. Transition callback success values.
    /// These return values ought to be set as a return value for each callback.
    /// Depending on which return value, the transition will be executed correctly or
    /// fallback/error callbacks will be triggered.
    /// The transition callback successfully performed its required functionality.
    pub const TRANSITION_CALLBACK_SUCCESS: u8 = 97;

    /// The transition callback failed to perform its required functionality.
    pub const TRANSITION_CALLBACK_FAILURE: u8 = 98;

    /// The transition callback encountered an error that requires special cleanup, if
    /// possible.
    pub const TRANSITION_CALLBACK_ERROR: u8 = 99;

}


impl Default for Transition {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Transition::default())
  }
}

impl rosidl_runtime_rs::Message for Transition {
  type RmwMsg = super::msg::rmw::Transition;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        label: msg.label.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        label: msg.label.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      label: msg.label.to_string(),
    }
  }
}


// Corresponds to lifecycle_msgs__msg__TransitionDescription
/// The transition id and label of this description.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TransitionDescription {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transition: super::msg::Transition,

    /// The current state from which this transition transitions.
    pub start_state: super::msg::State,

    /// The desired target state of this transition.
    pub goal_state: super::msg::State,

}



impl Default for TransitionDescription {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TransitionDescription::default())
  }
}

impl rosidl_runtime_rs::Message for TransitionDescription {
  type RmwMsg = super::msg::rmw::TransitionDescription;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transition: super::msg::Transition::into_rmw_message(std::borrow::Cow::Owned(msg.transition)).into_owned(),
        start_state: super::msg::State::into_rmw_message(std::borrow::Cow::Owned(msg.start_state)).into_owned(),
        goal_state: super::msg::State::into_rmw_message(std::borrow::Cow::Owned(msg.goal_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transition: super::msg::Transition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.transition)).into_owned(),
        start_state: super::msg::State::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_state)).into_owned(),
        goal_state: super::msg::State::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      transition: super::msg::Transition::from_rmw_message(msg.transition),
      start_state: super::msg::State::from_rmw_message(msg.start_state),
      goal_state: super::msg::State::from_rmw_message(msg.goal_state),
    }
  }
}


// Corresponds to lifecycle_msgs__msg__TransitionEvent
/// The time point at which this event occurred.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TransitionEvent {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

    /// The id and label of this transition event.
    pub transition: super::msg::Transition,

    /// The starting state from which this event transitioned.
    pub start_state: super::msg::State,

    /// The end state of this transition event.
    pub goal_state: super::msg::State,

}



impl Default for TransitionEvent {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TransitionEvent::default())
  }
}

impl rosidl_runtime_rs::Message for TransitionEvent {
  type RmwMsg = super::msg::rmw::TransitionEvent;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        transition: super::msg::Transition::into_rmw_message(std::borrow::Cow::Owned(msg.transition)).into_owned(),
        start_state: super::msg::State::into_rmw_message(std::borrow::Cow::Owned(msg.start_state)).into_owned(),
        goal_state: super::msg::State::into_rmw_message(std::borrow::Cow::Owned(msg.goal_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
        transition: super::msg::Transition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.transition)).into_owned(),
        start_state: super::msg::State::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_state)).into_owned(),
        goal_state: super::msg::State::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      transition: super::msg::Transition::from_rmw_message(msg.transition),
      start_state: super::msg::State::from_rmw_message(msg.start_state),
      goal_state: super::msg::State::from_rmw_message(msg.goal_state),
    }
  }
}


