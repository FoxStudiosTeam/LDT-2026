#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__State() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__msg__State__init(msg: *mut State) -> bool;
    fn lifecycle_msgs__msg__State__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<State>, size: usize) -> bool;
    fn lifecycle_msgs__msg__State__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<State>);
    fn lifecycle_msgs__msg__State__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<State>, out_seq: *mut rosidl_runtime_rs::Sequence<State>) -> bool;
}

// Corresponds to lifecycle_msgs__msg__State
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Primary state definitions as depicted in:
/// http://design.ros2.org/articles/node_lifecycle.html

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct State {
    /// The state id value from the above definitions.
    pub id: u8,

    /// A text label of the state.
    pub label: rosidl_runtime_rs::String,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__msg__State__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__msg__State__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for State {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__State__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__State__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__State__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for State {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for State where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/msg/State";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__State() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__Transition() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__msg__Transition__init(msg: *mut Transition) -> bool;
    fn lifecycle_msgs__msg__Transition__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Transition>, size: usize) -> bool;
    fn lifecycle_msgs__msg__Transition__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Transition>);
    fn lifecycle_msgs__msg__Transition__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Transition>, out_seq: *mut rosidl_runtime_rs::Sequence<Transition>) -> bool;
}

// Corresponds to lifecycle_msgs__msg__Transition
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Default values for transitions as described in:
/// http://design.ros2.org/articles/node_lifecycle.html

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Transition {
    /// Fields
    ///
    /// The transition id from above definitions.
    pub id: u8,

    /// A text label of the transition.
    pub label: rosidl_runtime_rs::String,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__msg__Transition__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__msg__Transition__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Transition {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__Transition__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__Transition__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__Transition__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Transition {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Transition where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/msg/Transition";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__Transition() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__TransitionDescription() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__msg__TransitionDescription__init(msg: *mut TransitionDescription) -> bool;
    fn lifecycle_msgs__msg__TransitionDescription__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TransitionDescription>, size: usize) -> bool;
    fn lifecycle_msgs__msg__TransitionDescription__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TransitionDescription>);
    fn lifecycle_msgs__msg__TransitionDescription__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TransitionDescription>, out_seq: *mut rosidl_runtime_rs::Sequence<TransitionDescription>) -> bool;
}

// Corresponds to lifecycle_msgs__msg__TransitionDescription
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// The transition id and label of this description.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TransitionDescription {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transition: super::super::msg::rmw::Transition,

    /// The current state from which this transition transitions.
    pub start_state: super::super::msg::rmw::State,

    /// The desired target state of this transition.
    pub goal_state: super::super::msg::rmw::State,

}



impl Default for TransitionDescription {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__msg__TransitionDescription__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__msg__TransitionDescription__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TransitionDescription {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__TransitionDescription__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__TransitionDescription__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__TransitionDescription__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TransitionDescription {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TransitionDescription where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/msg/TransitionDescription";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__TransitionDescription() }
  }
}


#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__TransitionEvent() -> *const std::ffi::c_void;
}

#[link(name = "lifecycle_msgs__rosidl_generator_c")]
extern "C" {
    fn lifecycle_msgs__msg__TransitionEvent__init(msg: *mut TransitionEvent) -> bool;
    fn lifecycle_msgs__msg__TransitionEvent__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TransitionEvent>, size: usize) -> bool;
    fn lifecycle_msgs__msg__TransitionEvent__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TransitionEvent>);
    fn lifecycle_msgs__msg__TransitionEvent__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TransitionEvent>, out_seq: *mut rosidl_runtime_rs::Sequence<TransitionEvent>) -> bool;
}

// Corresponds to lifecycle_msgs__msg__TransitionEvent
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// The time point at which this event occurred.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TransitionEvent {

    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

    /// The id and label of this transition event.
    pub transition: super::super::msg::rmw::Transition,

    /// The starting state from which this event transitioned.
    pub start_state: super::super::msg::rmw::State,

    /// The end state of this transition event.
    pub goal_state: super::super::msg::rmw::State,

}



impl Default for TransitionEvent {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !lifecycle_msgs__msg__TransitionEvent__init(&mut msg as *mut _) {
        panic!("Call to lifecycle_msgs__msg__TransitionEvent__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TransitionEvent {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__TransitionEvent__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__TransitionEvent__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { lifecycle_msgs__msg__TransitionEvent__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TransitionEvent {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TransitionEvent where Self: Sized {
  const TYPE_NAME: &'static str = "lifecycle_msgs/msg/TransitionEvent";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__lifecycle_msgs__msg__TransitionEvent() }
  }
}


