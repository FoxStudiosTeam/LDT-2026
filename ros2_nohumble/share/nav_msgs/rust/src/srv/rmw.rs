#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__GetMap_Request__init(msg: *mut GetMap_Request) -> bool;
    fn nav_msgs__srv__GetMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetMap_Request>, size: usize) -> bool;
    fn nav_msgs__srv__GetMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetMap_Request>);
    fn nav_msgs__srv__GetMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetMap_Request>) -> bool;
}

// Corresponds to nav_msgs__srv__GetMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__GetMap_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__GetMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/GetMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetMap_Request() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__GetMap_Response__init(msg: *mut GetMap_Response) -> bool;
    fn nav_msgs__srv__GetMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetMap_Response>, size: usize) -> bool;
    fn nav_msgs__srv__GetMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetMap_Response>);
    fn nav_msgs__srv__GetMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetMap_Response>) -> bool;
}

// Corresponds to nav_msgs__srv__GetMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map: super::super::msg::rmw::OccupancyGrid,

}



impl Default for GetMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__GetMap_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__GetMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/GetMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetMap_Response() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetPlan_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__GetPlan_Request__init(msg: *mut GetPlan_Request) -> bool;
    fn nav_msgs__srv__GetPlan_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPlan_Request>, size: usize) -> bool;
    fn nav_msgs__srv__GetPlan_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPlan_Request>);
    fn nav_msgs__srv__GetPlan_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPlan_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPlan_Request>) -> bool;
}

// Corresponds to nav_msgs__srv__GetPlan_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlan_Request {
    /// The start pose for the plan
    pub start: geometry_msgs::msg::rmw::PoseStamped,

    /// The final pose of the goal position
    pub goal: geometry_msgs::msg::rmw::PoseStamped,

    /// If the goal is obstructed, how many meters the planner can
    /// relax the constraint in x and y before failing.
    pub tolerance: f32,

}



impl Default for GetPlan_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__GetPlan_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__GetPlan_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPlan_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetPlan_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetPlan_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetPlan_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPlan_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPlan_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/GetPlan_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetPlan_Request() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetPlan_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__GetPlan_Response__init(msg: *mut GetPlan_Response) -> bool;
    fn nav_msgs__srv__GetPlan_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPlan_Response>, size: usize) -> bool;
    fn nav_msgs__srv__GetPlan_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPlan_Response>);
    fn nav_msgs__srv__GetPlan_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPlan_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPlan_Response>) -> bool;
}

// Corresponds to nav_msgs__srv__GetPlan_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPlan_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub plan: super::super::msg::rmw::Path,

}



impl Default for GetPlan_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__GetPlan_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__GetPlan_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPlan_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetPlan_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetPlan_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__GetPlan_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPlan_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPlan_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/GetPlan_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__GetPlan_Response() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__LoadMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__LoadMap_Request__init(msg: *mut LoadMap_Request) -> bool;
    fn nav_msgs__srv__LoadMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadMap_Request>, size: usize) -> bool;
    fn nav_msgs__srv__LoadMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadMap_Request>);
    fn nav_msgs__srv__LoadMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadMap_Request>) -> bool;
}

// Corresponds to nav_msgs__srv__LoadMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub map_url: rosidl_runtime_rs::String,

}



impl Default for LoadMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__LoadMap_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__LoadMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__LoadMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__LoadMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__LoadMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/LoadMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__LoadMap_Request() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__LoadMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__LoadMap_Response__init(msg: *mut LoadMap_Response) -> bool;
    fn nav_msgs__srv__LoadMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadMap_Response>, size: usize) -> bool;
    fn nav_msgs__srv__LoadMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadMap_Response>);
    fn nav_msgs__srv__LoadMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadMap_Response>) -> bool;
}

// Corresponds to nav_msgs__srv__LoadMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadMap_Response {
    /// Returned map is only valid if result equals RESULT_SUCCESS
    pub map: super::super::msg::rmw::OccupancyGrid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: u8,

}

impl LoadMap_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_SUCCESS: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_MAP_DOES_NOT_EXIST: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_INVALID_MAP_DATA: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_INVALID_MAP_METADATA: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESULT_UNDEFINED_FAILURE: u8 = 255;

}


impl Default for LoadMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__LoadMap_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__LoadMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__LoadMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__LoadMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__LoadMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/LoadMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__LoadMap_Response() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__SetMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__SetMap_Request__init(msg: *mut SetMap_Request) -> bool;
    fn nav_msgs__srv__SetMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetMap_Request>, size: usize) -> bool;
    fn nav_msgs__srv__SetMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetMap_Request>);
    fn nav_msgs__srv__SetMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetMap_Request>) -> bool;
}

// Corresponds to nav_msgs__srv__SetMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMap_Request {
    /// Requested 2D map to be set.
    pub map: super::super::msg::rmw::OccupancyGrid,

    /// Estimated initial pose when setting new map.
    pub initial_pose: geometry_msgs::msg::rmw::PoseWithCovarianceStamped,

}



impl Default for SetMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__SetMap_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__SetMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__SetMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__SetMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__SetMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/SetMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__SetMap_Request() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__SetMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__srv__SetMap_Response__init(msg: *mut SetMap_Response) -> bool;
    fn nav_msgs__srv__SetMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetMap_Response>, size: usize) -> bool;
    fn nav_msgs__srv__SetMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetMap_Response>);
    fn nav_msgs__srv__SetMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetMap_Response>) -> bool;
}

// Corresponds to nav_msgs__srv__SetMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetMap_Response {
    /// True if the map was successfully set, false otherwise.
    pub success: bool,

}



impl Default for SetMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__srv__SetMap_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__srv__SetMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__SetMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__SetMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__srv__SetMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/srv/SetMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__srv__SetMap_Response() }
  }
}






#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__GetMap
#[allow(missing_docs, non_camel_case_types)]
pub struct GetMap;

impl rosidl_runtime_rs::Service for GetMap {
    type Request = GetMap_Request;
    type Response = GetMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetMap() }
    }
}




#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetPlan() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__GetPlan
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPlan;

impl rosidl_runtime_rs::Service for GetPlan {
    type Request = GetPlan_Request;
    type Response = GetPlan_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__GetPlan() }
    }
}




#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__LoadMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__LoadMap
#[allow(missing_docs, non_camel_case_types)]
pub struct LoadMap;

impl rosidl_runtime_rs::Service for LoadMap {
    type Request = LoadMap_Request;
    type Response = LoadMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__LoadMap() }
    }
}




#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__SetMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_msgs__srv__SetMap
#[allow(missing_docs, non_camel_case_types)]
pub struct SetMap;

impl rosidl_runtime_rs::Service for SetMap {
    type Request = SetMap_Request;
    type Response = SetMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_msgs__srv__SetMap() }
    }
}


