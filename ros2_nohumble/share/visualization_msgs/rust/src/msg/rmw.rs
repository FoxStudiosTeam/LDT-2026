#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__ImageMarker() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__ImageMarker__init(msg: *mut ImageMarker) -> bool;
    fn visualization_msgs__msg__ImageMarker__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ImageMarker>, size: usize) -> bool;
    fn visualization_msgs__msg__ImageMarker__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ImageMarker>);
    fn visualization_msgs__msg__ImageMarker__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ImageMarker>, out_seq: *mut rosidl_runtime_rs::Sequence<ImageMarker>) -> bool;
}

// Corresponds to visualization_msgs__msg__ImageMarker
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ImageMarker {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Namespace which is used with the id to form a unique id.
    pub ns: rosidl_runtime_rs::String,

    /// Unique id within the namespace.
    pub id: i32,

    /// One of the above types, e.g. CIRCLE, LINE_STRIP, etc.
    pub type_: i32,

    /// Either ADD or REMOVE.
    pub action: i32,

    /// Two-dimensional coordinate position, in pixel-coordinates.
    pub position: geometry_msgs::msg::rmw::Point,

    /// The scale of the object, e.g. the diameter for a CIRCLE.
    pub scale: f32,

    /// The outline color of the marker.
    pub outline_color: std_msgs::msg::rmw::ColorRGBA,

    /// Whether or not to fill in the shape with color.
    pub filled: u8,

    /// Fill color; in the range:
    pub fill_color: std_msgs::msg::rmw::ColorRGBA,

    /// How long the object should last before being automatically deleted.
    /// 0 indicates forever.
    pub lifetime: builtin_interfaces::msg::rmw::Duration,

    /// Coordinates in 2D in pixel coords. Used for LINE_STRIP, LINE_LIST, POINTS, etc.
    pub points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,

    /// The color for each line, point, etc. in the points field.
    pub outline_colors: rosidl_runtime_rs::Sequence<std_msgs::msg::rmw::ColorRGBA>,

}

impl ImageMarker {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CIRCLE: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LINE_STRIP: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LINE_LIST: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POLYGON: i32 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POINTS: i32 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ADD: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REMOVE: i32 = 1;

}


impl Default for ImageMarker {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__ImageMarker__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__ImageMarker__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ImageMarker {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__ImageMarker__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__ImageMarker__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__ImageMarker__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ImageMarker {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ImageMarker where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/ImageMarker";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__ImageMarker() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarker() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__InteractiveMarker__init(msg: *mut InteractiveMarker) -> bool;
    fn visualization_msgs__msg__InteractiveMarker__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarker>, size: usize) -> bool;
    fn visualization_msgs__msg__InteractiveMarker__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarker>);
    fn visualization_msgs__msg__InteractiveMarker__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InteractiveMarker>, out_seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarker>) -> bool;
}

// Corresponds to visualization_msgs__msg__InteractiveMarker
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Time/frame info.
/// If header.time is set to 0, the marker will be retransformed into
/// its frame on each timestep. You will receive the pose feedback
/// in the same frame.
/// Otherwise, you might receive feedback in a different frame.
/// For rviz, this will be the current 'fixed frame' set by the user.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarker {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Initial pose. Also, defines the pivot point for rotations.
    pub pose: geometry_msgs::msg::rmw::Pose,

    /// Identifying string. Must be globally unique in
    /// the topic that this message is sent through.
    pub name: rosidl_runtime_rs::String,

    /// Short description (< 40 characters).
    pub description: rosidl_runtime_rs::String,

    /// Scale to be used for default controls (default=1).
    pub scale: f32,

    /// All menu and submenu entries associated with this marker.
    pub menu_entries: rosidl_runtime_rs::Sequence<super::super::msg::rmw::MenuEntry>,

    /// List of controls displayed for this marker.
    pub controls: rosidl_runtime_rs::Sequence<super::super::msg::rmw::InteractiveMarkerControl>,

}



impl Default for InteractiveMarker {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__InteractiveMarker__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__InteractiveMarker__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InteractiveMarker {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarker__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarker__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarker__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarker {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InteractiveMarker where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/InteractiveMarker";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarker() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerControl() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__InteractiveMarkerControl__init(msg: *mut InteractiveMarkerControl) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerControl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerControl>, size: usize) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerControl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerControl>);
    fn visualization_msgs__msg__InteractiveMarkerControl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InteractiveMarkerControl>, out_seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerControl>) -> bool;
}

// Corresponds to visualization_msgs__msg__InteractiveMarkerControl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Represents a control that is to be displayed together with an interactive marker

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerControl {
    /// Identifying string for this control.
    /// You need to assign a unique value to this to receive feedback from the GUI
    /// on what actions the user performs on this control (e.g. a button click).
    pub name: rosidl_runtime_rs::String,

    /// Defines the local coordinate frame (relative to the pose of the parent
    /// interactive marker) in which is being rotated and translated.
    /// Default: Identity
    pub orientation: geometry_msgs::msg::rmw::Quaternion,


    // This member is not documented.
    #[allow(missing_docs)]
    pub orientation_mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub interaction_mode: u8,

    /// If true, the contained markers will also be visible
    /// when the gui is not in interactive mode.
    pub always_visible: bool,

    /// Markers to be displayed as custom visual representation.
    /// Leave this empty to use the default control handles.
    ///
    /// Note:
    /// - The markers can be defined in an arbitrary coordinate frame,
    ///   but will be transformed into the local frame of the interactive marker.
    /// - If the header of a marker is empty, its pose will be interpreted as
    ///   relative to the pose of the parent interactive marker.
    pub markers: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Marker>,

    /// In VIEW_FACING mode, set this to true if you don't want the markers
    /// to be aligned with the camera view point. The markers will show up
    /// as in INHERIT mode.
    pub independent_marker_orientation: bool,

    /// Short description (< 40 characters) of what this control does,
    /// e.g. "Move the robot".
    /// Default: A generic description based on the interaction mode
    pub description: rosidl_runtime_rs::String,

}

impl InteractiveMarkerControl {
    /// Orientation mode: controls how orientation changes.
    /// INHERIT: Follow orientation of interactive marker
    /// FIXED: Keep orientation fixed at initial state
    /// VIEW_FACING: Align y-z plane with screen (x: forward, y:left, z:up).
    pub const INHERIT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIXED: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VIEW_FACING: u8 = 2;

    /// Interaction mode for this control
    ///
    /// NONE: This control is only meant for visualization; no context menu.
    /// MENU: Like NONE, but right-click menu is active.
    /// BUTTON: Element can be left-clicked.
    /// MOVE_AXIS: Translate along local x-axis.
    /// MOVE_PLANE: Translate in local y-z plane.
    /// ROTATE_AXIS: Rotate around local x-axis.
    /// MOVE_ROTATE: Combines MOVE_PLANE and ROTATE_AXIS.
    pub const NONE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MENU: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BUTTON: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOVE_AXIS: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOVE_PLANE: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROTATE_AXIS: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOVE_ROTATE: u8 = 6;

    /// "3D" interaction modes work with the mouse+SHIFT+CTRL or with 3D cursors.
    /// MOVE_3D: Translate freely in 3D space.
    /// ROTATE_3D: Rotate freely in 3D space about the origin of parent frame.
    /// MOVE_ROTATE_3D: Full 6-DOF freedom of translation and rotation about the cursor origin.
    pub const MOVE_3D: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROTATE_3D: u8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOVE_ROTATE_3D: u8 = 9;

}


impl Default for InteractiveMarkerControl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__InteractiveMarkerControl__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__InteractiveMarkerControl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InteractiveMarkerControl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerControl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerControl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerControl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerControl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InteractiveMarkerControl where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/InteractiveMarkerControl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerControl() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerFeedback() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__InteractiveMarkerFeedback__init(msg: *mut InteractiveMarkerFeedback) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerFeedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerFeedback>, size: usize) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerFeedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerFeedback>);
    fn visualization_msgs__msg__InteractiveMarkerFeedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InteractiveMarkerFeedback>, out_seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerFeedback>) -> bool;
}

// Corresponds to visualization_msgs__msg__InteractiveMarkerFeedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Time/frame info.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerFeedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Identifying string. Must be unique in the topic namespace.
    pub client_id: rosidl_runtime_rs::String,

    /// Feedback message sent back from the GUI, e.g.
    /// when the status of an interactive marker was modified by the user.
    /// Specifies which interactive marker and control this message refers to
    pub marker_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub control_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub event_type: u8,

    /// Current pose of the marker
    /// Note: Has to be valid for all feedback types.
    pub pose: geometry_msgs::msg::rmw::Pose,

    /// Contains the ID of the selected menu entry
    /// Only valid for MENU_SELECT events.
    pub menu_entry_id: u32,

    /// If event_type is BUTTON_CLICK, MOUSE_DOWN, or MOUSE_UP, mouse_point
    /// may contain the 3 dimensional position of the event on the
    /// control.  If it does, mouse_point_valid will be true.  mouse_point
    /// will be relative to the frame listed in the header.
    pub mouse_point: geometry_msgs::msg::rmw::Point,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mouse_point_valid: bool,

}

impl InteractiveMarkerFeedback {
    /// Type of the event
    /// KEEP_ALIVE: sent while dragging to keep up control of the marker
    /// MENU_SELECT: a menu entry has been selected
    /// BUTTON_CLICK: a button control has been clicked
    /// POSE_UPDATE: the pose has been changed using one of the controls
    pub const KEEP_ALIVE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POSE_UPDATE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MENU_SELECT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BUTTON_CLICK: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOUSE_DOWN: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MOUSE_UP: u8 = 5;

}


impl Default for InteractiveMarkerFeedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__InteractiveMarkerFeedback__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__InteractiveMarkerFeedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InteractiveMarkerFeedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerFeedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerFeedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerFeedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerFeedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InteractiveMarkerFeedback where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/InteractiveMarkerFeedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerFeedback() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerInit() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__InteractiveMarkerInit__init(msg: *mut InteractiveMarkerInit) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerInit__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerInit>, size: usize) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerInit__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerInit>);
    fn visualization_msgs__msg__InteractiveMarkerInit__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InteractiveMarkerInit>, out_seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerInit>) -> bool;
}

// Corresponds to visualization_msgs__msg__InteractiveMarkerInit
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Identifying string. Must be unique in the topic namespace
/// that this server works on.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerInit {

    // This member is not documented.
    #[allow(missing_docs)]
    pub server_id: rosidl_runtime_rs::String,

    /// Sequence number.
    /// The client will use this to detect if it has missed a subsequent
    /// update.  Every update message will have the same sequence number as
    /// an init message.  Clients will likely want to unsubscribe from the
    /// init topic after a successful initialization to avoid receiving
    /// duplicate data.
    pub seq_num: u64,

    /// All markers.
    pub markers: rosidl_runtime_rs::Sequence<super::super::msg::rmw::InteractiveMarker>,

}



impl Default for InteractiveMarkerInit {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__InteractiveMarkerInit__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__InteractiveMarkerInit__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InteractiveMarkerInit {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerInit__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerInit__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerInit__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerInit {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InteractiveMarkerInit where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/InteractiveMarkerInit";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerInit() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerPose() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__InteractiveMarkerPose__init(msg: *mut InteractiveMarkerPose) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerPose__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerPose>, size: usize) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerPose__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerPose>);
    fn visualization_msgs__msg__InteractiveMarkerPose__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InteractiveMarkerPose>, out_seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerPose>) -> bool;
}

// Corresponds to visualization_msgs__msg__InteractiveMarkerPose
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerPose {
    /// Time/frame info.
    pub header: std_msgs::msg::rmw::Header,

    /// Initial pose. Also, defines the pivot point for rotations.
    pub pose: geometry_msgs::msg::rmw::Pose,

    /// Identifying string. Must be globally unique in
    /// the topic that this message is sent through.
    pub name: rosidl_runtime_rs::String,

}



impl Default for InteractiveMarkerPose {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__InteractiveMarkerPose__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__InteractiveMarkerPose__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InteractiveMarkerPose {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerPose__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerPose__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerPose__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerPose {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InteractiveMarkerPose where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/InteractiveMarkerPose";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerPose() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerUpdate() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__InteractiveMarkerUpdate__init(msg: *mut InteractiveMarkerUpdate) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerUpdate__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerUpdate>, size: usize) -> bool;
    fn visualization_msgs__msg__InteractiveMarkerUpdate__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerUpdate>);
    fn visualization_msgs__msg__InteractiveMarkerUpdate__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InteractiveMarkerUpdate>, out_seq: *mut rosidl_runtime_rs::Sequence<InteractiveMarkerUpdate>) -> bool;
}

// Corresponds to visualization_msgs__msg__InteractiveMarkerUpdate
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerUpdate {
    /// Identifying string. Must be unique in the topic namespace
    /// that this server works on.
    pub server_id: rosidl_runtime_rs::String,

    /// Sequence number.
    /// The client will use this to detect if it has missed an update.
    pub seq_num: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub type_: u8,

    /// Note: No guarantees on the order of processing.
    ///       Contents must be kept consistent by sender.
    /// Markers to be added or updated
    pub markers: rosidl_runtime_rs::Sequence<super::super::msg::rmw::InteractiveMarker>,

    /// Poses of markers that should be moved
    pub poses: rosidl_runtime_rs::Sequence<super::super::msg::rmw::InteractiveMarkerPose>,

    /// Names of markers to be erased
    pub erases: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}

impl InteractiveMarkerUpdate {
    /// Type holds the purpose of this message.  It must be one of UPDATE or KEEP_ALIVE.
    /// UPDATE: Incremental update to previous state.
    ///         The sequence number must be 1 higher than for
    ///         the previous update.
    /// KEEP_ALIVE: Indicates the that the server is still living.
    ///             The sequence number does not increase.
    ///             No payload data should be filled out (markers, poses, or erases).
    pub const KEEP_ALIVE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UPDATE: u8 = 1;

}


impl Default for InteractiveMarkerUpdate {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__InteractiveMarkerUpdate__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__InteractiveMarkerUpdate__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InteractiveMarkerUpdate {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerUpdate__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerUpdate__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__InteractiveMarkerUpdate__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerUpdate {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InteractiveMarkerUpdate where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/InteractiveMarkerUpdate";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__InteractiveMarkerUpdate() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__Marker() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__Marker__init(msg: *mut Marker) -> bool;
    fn visualization_msgs__msg__Marker__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Marker>, size: usize) -> bool;
    fn visualization_msgs__msg__Marker__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Marker>);
    fn visualization_msgs__msg__Marker__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Marker>, out_seq: *mut rosidl_runtime_rs::Sequence<Marker>) -> bool;
}

// Corresponds to visualization_msgs__msg__Marker
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// See:
///  - http://www.ros.org/wiki/rviz/DisplayTypes/Marker
///  - http://www.ros.org/wiki/rviz/Tutorials/Markers%3A%20Basic%20Shapes
///
/// for more information on using this message with rviz.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Marker {
    /// Header for timestamp and frame id.
    pub header: std_msgs::msg::rmw::Header,

    /// Namespace in which to place the object.
    /// Used in conjunction with id to create a unique name for the object.
    pub ns: rosidl_runtime_rs::String,

    /// Object ID used in conjunction with the namespace for manipulating and deleting the object later.
    pub id: i32,

    /// Type of object.
    pub type_: i32,

    /// Action to take; one of:
    ///  - 0 add/modify an object
    ///  - 1 (deprecated)
    ///  - 2 deletes an object (with the given ns and id)
    ///  - 3 deletes all objects (or those with the given ns if any)
    pub action: i32,

    /// Pose of the object with respect the frame_id specified in the header.
    pub pose: geometry_msgs::msg::rmw::Pose,

    /// Scale of the object; 1,1,1 means default (usually 1 meter square).
    pub scale: geometry_msgs::msg::rmw::Vector3,

    /// Color of the object; in the range:
    pub color: std_msgs::msg::rmw::ColorRGBA,

    /// How long the object should last before being automatically deleted.
    /// 0 indicates forever.
    pub lifetime: builtin_interfaces::msg::rmw::Duration,

    /// If this marker should be frame-locked, i.e. retransformed into its frame every timestep.
    pub frame_locked: bool,

    /// Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, ARROW_STRIP, etc.)
    pub points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,

    /// Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, etc.)
    /// The number of colors provided must either be 0 or equal to the number of points provided.
    /// NOTE: alpha is not yet used
    pub colors: rosidl_runtime_rs::Sequence<std_msgs::msg::rmw::ColorRGBA>,

    /// Texture resource is a special URI that can either reference a texture file in
    /// a format acceptable to (resource retriever)
    /// or an embedded texture via a string matching the format:
    ///   "embedded://texture_name"
    pub texture_resource: rosidl_runtime_rs::String,

    /// An image to be loaded into the rendering engine as the texture for this marker.
    /// This will be used iff texture_resource is set to embedded.
    pub texture: sensor_msgs::msg::rmw::CompressedImage,

    /// Location of each vertex within the texture; in the range:
    pub uv_coordinates: rosidl_runtime_rs::Sequence<super::super::msg::rmw::UVCoordinate>,

    /// Only used for text markers
    pub text: rosidl_runtime_rs::String,

    /// Only used for MESH_RESOURCE markers.
    /// Similar to texture_resource, mesh_resource uses resource retriever to load a mesh.
    /// Optionally, a mesh file can be sent in-message via the mesh_file field. If doing so,
    /// use the following format for mesh_resource:
    ///   "embedded://mesh_name"
    pub mesh_resource: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mesh_file: super::super::msg::rmw::MeshFile,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mesh_use_embedded_materials: bool,

}

impl Marker {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ARROW: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CUBE: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPHERE: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CYLINDER: i32 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LINE_STRIP: i32 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LINE_LIST: i32 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CUBE_LIST: i32 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPHERE_LIST: i32 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POINTS: i32 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TEXT_VIEW_FACING: i32 = 9;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MESH_RESOURCE: i32 = 10;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRIANGLE_LIST: i32 = 11;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ARROW_STRIP: i32 = 12;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ADD: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODIFY: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DELETE: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DELETEALL: i32 = 3;

}


impl Default for Marker {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__Marker__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__Marker__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Marker {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__Marker__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__Marker__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__Marker__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Marker {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Marker where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/Marker";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__Marker() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__MarkerArray() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__MarkerArray__init(msg: *mut MarkerArray) -> bool;
    fn visualization_msgs__msg__MarkerArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MarkerArray>, size: usize) -> bool;
    fn visualization_msgs__msg__MarkerArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MarkerArray>);
    fn visualization_msgs__msg__MarkerArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MarkerArray>, out_seq: *mut rosidl_runtime_rs::Sequence<MarkerArray>) -> bool;
}

// Corresponds to visualization_msgs__msg__MarkerArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MarkerArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub markers: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Marker>,

}



impl Default for MarkerArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__MarkerArray__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__MarkerArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MarkerArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MarkerArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MarkerArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MarkerArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MarkerArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MarkerArray where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/MarkerArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__MarkerArray() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__MenuEntry() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__MenuEntry__init(msg: *mut MenuEntry) -> bool;
    fn visualization_msgs__msg__MenuEntry__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MenuEntry>, size: usize) -> bool;
    fn visualization_msgs__msg__MenuEntry__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MenuEntry>);
    fn visualization_msgs__msg__MenuEntry__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MenuEntry>, out_seq: *mut rosidl_runtime_rs::Sequence<MenuEntry>) -> bool;
}

// Corresponds to visualization_msgs__msg__MenuEntry
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// MenuEntry message.
///
/// Each InteractiveMarker message has an array of MenuEntry messages.
/// A collection of MenuEntries together describe a
/// menu/submenu/subsubmenu/etc tree, though they are stored in a flat
/// array.  The tree structure is represented by giving each menu entry
/// an ID number and a "parent_id" field.  Top-level entries are the
/// ones with parent_id = 0.  Menu entries are ordered within their
/// level the same way they are ordered in the containing array.  Parent
/// entries must appear before their children.
///
/// Example:
/// - id = 3
///   parent_id = 0
///   title = "fun"
/// - id = 2
///   parent_id = 0
///   title = "robot"
/// - id = 4
///   parent_id = 2
///   title = "pr2"
/// - id = 5
///   parent_id = 2
///   title = "turtle"
///
/// Gives a menu tree like this:
///  - fun
///  - robot
///    - pr2
///    - turtle

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MenuEntry {
    /// ID is a number for each menu entry.  Must be unique within the
    /// control, and should never be 0.
    pub id: u32,

    /// ID of the parent of this menu entry, if it is a submenu.  If this
    /// menu entry is a top-level entry, set parent_id to 0.
    pub parent_id: u32,

    /// menu / entry title
    pub title: rosidl_runtime_rs::String,

    /// Arguments to command indicated by command_type (below)
    pub command: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command_type: u8,

}

impl MenuEntry {
    /// Command_type stores the type of response desired when this menu
    /// entry is clicked.
    /// FEEDBACK: send an InteractiveMarkerFeedback message with menu_entry_id set to this entry's id.
    /// ROSRUN: execute "rosrun" with arguments given in the command field (above).
    /// ROSLAUNCH: execute "roslaunch" with arguments given in the command field (above).
    pub const FEEDBACK: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROSRUN: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROSLAUNCH: u8 = 2;

}


impl Default for MenuEntry {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__MenuEntry__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__MenuEntry__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MenuEntry {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MenuEntry__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MenuEntry__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MenuEntry__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MenuEntry {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MenuEntry where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/MenuEntry";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__MenuEntry() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__MeshFile() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__MeshFile__init(msg: *mut MeshFile) -> bool;
    fn visualization_msgs__msg__MeshFile__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MeshFile>, size: usize) -> bool;
    fn visualization_msgs__msg__MeshFile__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MeshFile>);
    fn visualization_msgs__msg__MeshFile__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MeshFile>, out_seq: *mut rosidl_runtime_rs::Sequence<MeshFile>) -> bool;
}

// Corresponds to visualization_msgs__msg__MeshFile
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Used to send raw mesh files.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MeshFile {
    /// The filename is used for both debug purposes and to provide a file extension
    /// for whatever parser is used.
    pub filename: rosidl_runtime_rs::String,

    /// This stores the raw text of the mesh file.
    pub data: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for MeshFile {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__MeshFile__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__MeshFile__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MeshFile {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MeshFile__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MeshFile__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__MeshFile__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MeshFile {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MeshFile where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/MeshFile";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__MeshFile() }
  }
}


#[link(name = "visualization_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__UVCoordinate() -> *const std::ffi::c_void;
}

#[link(name = "visualization_msgs__rosidl_generator_c")]
extern "C" {
    fn visualization_msgs__msg__UVCoordinate__init(msg: *mut UVCoordinate) -> bool;
    fn visualization_msgs__msg__UVCoordinate__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UVCoordinate>, size: usize) -> bool;
    fn visualization_msgs__msg__UVCoordinate__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UVCoordinate>);
    fn visualization_msgs__msg__UVCoordinate__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UVCoordinate>, out_seq: *mut rosidl_runtime_rs::Sequence<UVCoordinate>) -> bool;
}

// Corresponds to visualization_msgs__msg__UVCoordinate
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Location of the pixel as a ratio of the width of a 2D texture.
/// Values should be in range:.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UVCoordinate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub u: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v: f32,

}



impl Default for UVCoordinate {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !visualization_msgs__msg__UVCoordinate__init(&mut msg as *mut _) {
        panic!("Call to visualization_msgs__msg__UVCoordinate__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UVCoordinate {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__UVCoordinate__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__UVCoordinate__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { visualization_msgs__msg__UVCoordinate__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UVCoordinate {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UVCoordinate where Self: Sized {
  const TYPE_NAME: &'static str = "visualization_msgs/msg/UVCoordinate";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__visualization_msgs__msg__UVCoordinate() }
  }
}


