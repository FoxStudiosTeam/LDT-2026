#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to visualization_msgs__msg__ImageMarker

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ImageMarker {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Namespace which is used with the id to form a unique id.
    pub ns: std::string::String,

    /// Unique id within the namespace.
    pub id: i32,

    /// One of the above types, e.g. CIRCLE, LINE_STRIP, etc.
    pub type_: i32,

    /// Either ADD or REMOVE.
    pub action: i32,

    /// Two-dimensional coordinate position, in pixel-coordinates.
    pub position: geometry_msgs::msg::Point,

    /// The scale of the object, e.g. the diameter for a CIRCLE.
    pub scale: f32,

    /// The outline color of the marker.
    pub outline_color: std_msgs::msg::ColorRGBA,

    /// Whether or not to fill in the shape with color.
    pub filled: u8,

    /// Fill color; in the range:
    pub fill_color: std_msgs::msg::ColorRGBA,

    /// How long the object should last before being automatically deleted.
    /// 0 indicates forever.
    pub lifetime: builtin_interfaces::msg::Duration,

    /// Coordinates in 2D in pixel coords. Used for LINE_STRIP, LINE_LIST, POINTS, etc.
    pub points: Vec<geometry_msgs::msg::Point>,

    /// The color for each line, point, etc. in the points field.
    pub outline_colors: Vec<std_msgs::msg::ColorRGBA>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ImageMarker::default())
  }
}

impl rosidl_runtime_rs::Message for ImageMarker {
  type RmwMsg = super::msg::rmw::ImageMarker;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        ns: msg.ns.as_str().into(),
        id: msg.id,
        type_: msg.type_,
        action: msg.action,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        scale: msg.scale,
        outline_color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(msg.outline_color)).into_owned(),
        filled: msg.filled,
        fill_color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(msg.fill_color)).into_owned(),
        lifetime: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Owned(msg.lifetime)).into_owned(),
        points: msg.points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        outline_colors: msg.outline_colors
          .into_iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        ns: msg.ns.as_str().into(),
      id: msg.id,
      type_: msg.type_,
      action: msg.action,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      scale: msg.scale,
        outline_color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(&msg.outline_color)).into_owned(),
      filled: msg.filled,
        fill_color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(&msg.fill_color)).into_owned(),
        lifetime: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Borrowed(&msg.lifetime)).into_owned(),
        points: msg.points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        outline_colors: msg.outline_colors
          .iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      ns: msg.ns.to_string(),
      id: msg.id,
      type_: msg.type_,
      action: msg.action,
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
      scale: msg.scale,
      outline_color: std_msgs::msg::ColorRGBA::from_rmw_message(msg.outline_color),
      filled: msg.filled,
      fill_color: std_msgs::msg::ColorRGBA::from_rmw_message(msg.fill_color),
      lifetime: builtin_interfaces::msg::Duration::from_rmw_message(msg.lifetime),
      points: msg.points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      outline_colors: msg.outline_colors
          .into_iter()
          .map(std_msgs::msg::ColorRGBA::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to visualization_msgs__msg__InteractiveMarker
/// Time/frame info.
/// If header.time is set to 0, the marker will be retransformed into
/// its frame on each timestep. You will receive the pose feedback
/// in the same frame.
/// Otherwise, you might receive feedback in a different frame.
/// For rviz, this will be the current 'fixed frame' set by the user.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarker {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Initial pose. Also, defines the pivot point for rotations.
    pub pose: geometry_msgs::msg::Pose,

    /// Identifying string. Must be globally unique in
    /// the topic that this message is sent through.
    pub name: std::string::String,

    /// Short description (< 40 characters).
    pub description: std::string::String,

    /// Scale to be used for default controls (default=1).
    pub scale: f32,

    /// All menu and submenu entries associated with this marker.
    pub menu_entries: Vec<super::msg::MenuEntry>,

    /// List of controls displayed for this marker.
    pub controls: Vec<super::msg::InteractiveMarkerControl>,

}



impl Default for InteractiveMarker {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InteractiveMarker::default())
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarker {
  type RmwMsg = super::msg::rmw::InteractiveMarker;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        name: msg.name.as_str().into(),
        description: msg.description.as_str().into(),
        scale: msg.scale,
        menu_entries: msg.menu_entries
          .into_iter()
          .map(|elem| super::msg::MenuEntry::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        controls: msg.controls
          .into_iter()
          .map(|elem| super::msg::InteractiveMarkerControl::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        name: msg.name.as_str().into(),
        description: msg.description.as_str().into(),
      scale: msg.scale,
        menu_entries: msg.menu_entries
          .iter()
          .map(|elem| super::msg::MenuEntry::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        controls: msg.controls
          .iter()
          .map(|elem| super::msg::InteractiveMarkerControl::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
      name: msg.name.to_string(),
      description: msg.description.to_string(),
      scale: msg.scale,
      menu_entries: msg.menu_entries
          .into_iter()
          .map(super::msg::MenuEntry::from_rmw_message)
          .collect(),
      controls: msg.controls
          .into_iter()
          .map(super::msg::InteractiveMarkerControl::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to visualization_msgs__msg__InteractiveMarkerControl
/// Represents a control that is to be displayed together with an interactive marker

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerControl {
    /// Identifying string for this control.
    /// You need to assign a unique value to this to receive feedback from the GUI
    /// on what actions the user performs on this control (e.g. a button click).
    pub name: std::string::String,

    /// Defines the local coordinate frame (relative to the pose of the parent
    /// interactive marker) in which is being rotated and translated.
    /// Default: Identity
    pub orientation: geometry_msgs::msg::Quaternion,


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
    pub markers: Vec<super::msg::Marker>,

    /// In VIEW_FACING mode, set this to true if you don't want the markers
    /// to be aligned with the camera view point. The markers will show up
    /// as in INHERIT mode.
    pub independent_marker_orientation: bool,

    /// Short description (< 40 characters) of what this control does,
    /// e.g. "Move the robot".
    /// Default: A generic description based on the interaction mode
    pub description: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InteractiveMarkerControl::default())
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerControl {
  type RmwMsg = super::msg::rmw::InteractiveMarkerControl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        orientation: geometry_msgs::msg::Quaternion::into_rmw_message(std::borrow::Cow::Owned(msg.orientation)).into_owned(),
        orientation_mode: msg.orientation_mode,
        interaction_mode: msg.interaction_mode,
        always_visible: msg.always_visible,
        markers: msg.markers
          .into_iter()
          .map(|elem| super::msg::Marker::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        independent_marker_orientation: msg.independent_marker_orientation,
        description: msg.description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        orientation: geometry_msgs::msg::Quaternion::into_rmw_message(std::borrow::Cow::Borrowed(&msg.orientation)).into_owned(),
      orientation_mode: msg.orientation_mode,
      interaction_mode: msg.interaction_mode,
      always_visible: msg.always_visible,
        markers: msg.markers
          .iter()
          .map(|elem| super::msg::Marker::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      independent_marker_orientation: msg.independent_marker_orientation,
        description: msg.description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      orientation: geometry_msgs::msg::Quaternion::from_rmw_message(msg.orientation),
      orientation_mode: msg.orientation_mode,
      interaction_mode: msg.interaction_mode,
      always_visible: msg.always_visible,
      markers: msg.markers
          .into_iter()
          .map(super::msg::Marker::from_rmw_message)
          .collect(),
      independent_marker_orientation: msg.independent_marker_orientation,
      description: msg.description.to_string(),
    }
  }
}


// Corresponds to visualization_msgs__msg__InteractiveMarkerFeedback
/// Time/frame info.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerFeedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Identifying string. Must be unique in the topic namespace.
    pub client_id: std::string::String,

    /// Feedback message sent back from the GUI, e.g.
    /// when the status of an interactive marker was modified by the user.
    /// Specifies which interactive marker and control this message refers to
    pub marker_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub control_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub event_type: u8,

    /// Current pose of the marker
    /// Note: Has to be valid for all feedback types.
    pub pose: geometry_msgs::msg::Pose,

    /// Contains the ID of the selected menu entry
    /// Only valid for MENU_SELECT events.
    pub menu_entry_id: u32,

    /// If event_type is BUTTON_CLICK, MOUSE_DOWN, or MOUSE_UP, mouse_point
    /// may contain the 3 dimensional position of the event on the
    /// control.  If it does, mouse_point_valid will be true.  mouse_point
    /// will be relative to the frame listed in the header.
    pub mouse_point: geometry_msgs::msg::Point,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InteractiveMarkerFeedback::default())
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerFeedback {
  type RmwMsg = super::msg::rmw::InteractiveMarkerFeedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        client_id: msg.client_id.as_str().into(),
        marker_name: msg.marker_name.as_str().into(),
        control_name: msg.control_name.as_str().into(),
        event_type: msg.event_type,
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        menu_entry_id: msg.menu_entry_id,
        mouse_point: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.mouse_point)).into_owned(),
        mouse_point_valid: msg.mouse_point_valid,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        client_id: msg.client_id.as_str().into(),
        marker_name: msg.marker_name.as_str().into(),
        control_name: msg.control_name.as_str().into(),
      event_type: msg.event_type,
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
      menu_entry_id: msg.menu_entry_id,
        mouse_point: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.mouse_point)).into_owned(),
      mouse_point_valid: msg.mouse_point_valid,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      client_id: msg.client_id.to_string(),
      marker_name: msg.marker_name.to_string(),
      control_name: msg.control_name.to_string(),
      event_type: msg.event_type,
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
      menu_entry_id: msg.menu_entry_id,
      mouse_point: geometry_msgs::msg::Point::from_rmw_message(msg.mouse_point),
      mouse_point_valid: msg.mouse_point_valid,
    }
  }
}


// Corresponds to visualization_msgs__msg__InteractiveMarkerInit
/// Identifying string. Must be unique in the topic namespace
/// that this server works on.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerInit {

    // This member is not documented.
    #[allow(missing_docs)]
    pub server_id: std::string::String,

    /// Sequence number.
    /// The client will use this to detect if it has missed a subsequent
    /// update.  Every update message will have the same sequence number as
    /// an init message.  Clients will likely want to unsubscribe from the
    /// init topic after a successful initialization to avoid receiving
    /// duplicate data.
    pub seq_num: u64,

    /// All markers.
    pub markers: Vec<super::msg::InteractiveMarker>,

}



impl Default for InteractiveMarkerInit {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InteractiveMarkerInit::default())
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerInit {
  type RmwMsg = super::msg::rmw::InteractiveMarkerInit;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        server_id: msg.server_id.as_str().into(),
        seq_num: msg.seq_num,
        markers: msg.markers
          .into_iter()
          .map(|elem| super::msg::InteractiveMarker::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        server_id: msg.server_id.as_str().into(),
      seq_num: msg.seq_num,
        markers: msg.markers
          .iter()
          .map(|elem| super::msg::InteractiveMarker::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      server_id: msg.server_id.to_string(),
      seq_num: msg.seq_num,
      markers: msg.markers
          .into_iter()
          .map(super::msg::InteractiveMarker::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to visualization_msgs__msg__InteractiveMarkerPose

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerPose {
    /// Time/frame info.
    pub header: std_msgs::msg::Header,

    /// Initial pose. Also, defines the pivot point for rotations.
    pub pose: geometry_msgs::msg::Pose,

    /// Identifying string. Must be globally unique in
    /// the topic that this message is sent through.
    pub name: std::string::String,

}



impl Default for InteractiveMarkerPose {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InteractiveMarkerPose::default())
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerPose {
  type RmwMsg = super::msg::rmw::InteractiveMarkerPose;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        name: msg.name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        name: msg.name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
      name: msg.name.to_string(),
    }
  }
}


// Corresponds to visualization_msgs__msg__InteractiveMarkerUpdate

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InteractiveMarkerUpdate {
    /// Identifying string. Must be unique in the topic namespace
    /// that this server works on.
    pub server_id: std::string::String,

    /// Sequence number.
    /// The client will use this to detect if it has missed an update.
    pub seq_num: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub type_: u8,

    /// Note: No guarantees on the order of processing.
    ///       Contents must be kept consistent by sender.
    /// Markers to be added or updated
    pub markers: Vec<super::msg::InteractiveMarker>,

    /// Poses of markers that should be moved
    pub poses: Vec<super::msg::InteractiveMarkerPose>,

    /// Names of markers to be erased
    pub erases: Vec<std::string::String>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InteractiveMarkerUpdate::default())
  }
}

impl rosidl_runtime_rs::Message for InteractiveMarkerUpdate {
  type RmwMsg = super::msg::rmw::InteractiveMarkerUpdate;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        server_id: msg.server_id.as_str().into(),
        seq_num: msg.seq_num,
        type_: msg.type_,
        markers: msg.markers
          .into_iter()
          .map(|elem| super::msg::InteractiveMarker::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        poses: msg.poses
          .into_iter()
          .map(|elem| super::msg::InteractiveMarkerPose::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        erases: msg.erases
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        server_id: msg.server_id.as_str().into(),
      seq_num: msg.seq_num,
      type_: msg.type_,
        markers: msg.markers
          .iter()
          .map(|elem| super::msg::InteractiveMarker::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        poses: msg.poses
          .iter()
          .map(|elem| super::msg::InteractiveMarkerPose::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        erases: msg.erases
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      server_id: msg.server_id.to_string(),
      seq_num: msg.seq_num,
      type_: msg.type_,
      markers: msg.markers
          .into_iter()
          .map(super::msg::InteractiveMarker::from_rmw_message)
          .collect(),
      poses: msg.poses
          .into_iter()
          .map(super::msg::InteractiveMarkerPose::from_rmw_message)
          .collect(),
      erases: msg.erases
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
  }
}


// Corresponds to visualization_msgs__msg__Marker
/// See:
///  - http://www.ros.org/wiki/rviz/DisplayTypes/Marker
///  - http://www.ros.org/wiki/rviz/Tutorials/Markers%3A%20Basic%20Shapes
///
/// for more information on using this message with rviz.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Marker {
    /// Header for timestamp and frame id.
    pub header: std_msgs::msg::Header,

    /// Namespace in which to place the object.
    /// Used in conjunction with id to create a unique name for the object.
    pub ns: std::string::String,

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
    pub pose: geometry_msgs::msg::Pose,

    /// Scale of the object; 1,1,1 means default (usually 1 meter square).
    pub scale: geometry_msgs::msg::Vector3,

    /// Color of the object; in the range:
    pub color: std_msgs::msg::ColorRGBA,

    /// How long the object should last before being automatically deleted.
    /// 0 indicates forever.
    pub lifetime: builtin_interfaces::msg::Duration,

    /// If this marker should be frame-locked, i.e. retransformed into its frame every timestep.
    pub frame_locked: bool,

    /// Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, ARROW_STRIP, etc.)
    pub points: Vec<geometry_msgs::msg::Point>,

    /// Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, etc.)
    /// The number of colors provided must either be 0 or equal to the number of points provided.
    /// NOTE: alpha is not yet used
    pub colors: Vec<std_msgs::msg::ColorRGBA>,

    /// Texture resource is a special URI that can either reference a texture file in
    /// a format acceptable to (resource retriever)
    /// or an embedded texture via a string matching the format:
    ///   "embedded://texture_name"
    pub texture_resource: std::string::String,

    /// An image to be loaded into the rendering engine as the texture for this marker.
    /// This will be used iff texture_resource is set to embedded.
    pub texture: sensor_msgs::msg::CompressedImage,

    /// Location of each vertex within the texture; in the range:
    pub uv_coordinates: Vec<super::msg::UVCoordinate>,

    /// Only used for text markers
    pub text: std::string::String,

    /// Only used for MESH_RESOURCE markers.
    /// Similar to texture_resource, mesh_resource uses resource retriever to load a mesh.
    /// Optionally, a mesh file can be sent in-message via the mesh_file field. If doing so,
    /// use the following format for mesh_resource:
    ///   "embedded://mesh_name"
    pub mesh_resource: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mesh_file: super::msg::MeshFile,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Marker::default())
  }
}

impl rosidl_runtime_rs::Message for Marker {
  type RmwMsg = super::msg::rmw::Marker;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        ns: msg.ns.as_str().into(),
        id: msg.id,
        type_: msg.type_,
        action: msg.action,
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
        scale: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.scale)).into_owned(),
        color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(msg.color)).into_owned(),
        lifetime: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Owned(msg.lifetime)).into_owned(),
        frame_locked: msg.frame_locked,
        points: msg.points
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        colors: msg.colors
          .into_iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        texture_resource: msg.texture_resource.as_str().into(),
        texture: sensor_msgs::msg::CompressedImage::into_rmw_message(std::borrow::Cow::Owned(msg.texture)).into_owned(),
        uv_coordinates: msg.uv_coordinates
          .into_iter()
          .map(|elem| super::msg::UVCoordinate::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        text: msg.text.as_str().into(),
        mesh_resource: msg.mesh_resource.as_str().into(),
        mesh_file: super::msg::MeshFile::into_rmw_message(std::borrow::Cow::Owned(msg.mesh_file)).into_owned(),
        mesh_use_embedded_materials: msg.mesh_use_embedded_materials,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        ns: msg.ns.as_str().into(),
      id: msg.id,
      type_: msg.type_,
      action: msg.action,
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
        scale: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.scale)).into_owned(),
        color: std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(&msg.color)).into_owned(),
        lifetime: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Borrowed(&msg.lifetime)).into_owned(),
      frame_locked: msg.frame_locked,
        points: msg.points
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        colors: msg.colors
          .iter()
          .map(|elem| std_msgs::msg::ColorRGBA::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        texture_resource: msg.texture_resource.as_str().into(),
        texture: sensor_msgs::msg::CompressedImage::into_rmw_message(std::borrow::Cow::Borrowed(&msg.texture)).into_owned(),
        uv_coordinates: msg.uv_coordinates
          .iter()
          .map(|elem| super::msg::UVCoordinate::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        text: msg.text.as_str().into(),
        mesh_resource: msg.mesh_resource.as_str().into(),
        mesh_file: super::msg::MeshFile::into_rmw_message(std::borrow::Cow::Borrowed(&msg.mesh_file)).into_owned(),
      mesh_use_embedded_materials: msg.mesh_use_embedded_materials,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      ns: msg.ns.to_string(),
      id: msg.id,
      type_: msg.type_,
      action: msg.action,
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
      scale: geometry_msgs::msg::Vector3::from_rmw_message(msg.scale),
      color: std_msgs::msg::ColorRGBA::from_rmw_message(msg.color),
      lifetime: builtin_interfaces::msg::Duration::from_rmw_message(msg.lifetime),
      frame_locked: msg.frame_locked,
      points: msg.points
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      colors: msg.colors
          .into_iter()
          .map(std_msgs::msg::ColorRGBA::from_rmw_message)
          .collect(),
      texture_resource: msg.texture_resource.to_string(),
      texture: sensor_msgs::msg::CompressedImage::from_rmw_message(msg.texture),
      uv_coordinates: msg.uv_coordinates
          .into_iter()
          .map(super::msg::UVCoordinate::from_rmw_message)
          .collect(),
      text: msg.text.to_string(),
      mesh_resource: msg.mesh_resource.to_string(),
      mesh_file: super::msg::MeshFile::from_rmw_message(msg.mesh_file),
      mesh_use_embedded_materials: msg.mesh_use_embedded_materials,
    }
  }
}


// Corresponds to visualization_msgs__msg__MarkerArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MarkerArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub markers: Vec<super::msg::Marker>,

}



impl Default for MarkerArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MarkerArray::default())
  }
}

impl rosidl_runtime_rs::Message for MarkerArray {
  type RmwMsg = super::msg::rmw::MarkerArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        markers: msg.markers
          .into_iter()
          .map(|elem| super::msg::Marker::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        markers: msg.markers
          .iter()
          .map(|elem| super::msg::Marker::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      markers: msg.markers
          .into_iter()
          .map(super::msg::Marker::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to visualization_msgs__msg__MenuEntry
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

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MenuEntry {
    /// ID is a number for each menu entry.  Must be unique within the
    /// control, and should never be 0.
    pub id: u32,

    /// ID of the parent of this menu entry, if it is a submenu.  If this
    /// menu entry is a top-level entry, set parent_id to 0.
    pub parent_id: u32,

    /// menu / entry title
    pub title: std::string::String,

    /// Arguments to command indicated by command_type (below)
    pub command: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MenuEntry::default())
  }
}

impl rosidl_runtime_rs::Message for MenuEntry {
  type RmwMsg = super::msg::rmw::MenuEntry;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        parent_id: msg.parent_id,
        title: msg.title.as_str().into(),
        command: msg.command.as_str().into(),
        command_type: msg.command_type,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      parent_id: msg.parent_id,
        title: msg.title.as_str().into(),
        command: msg.command.as_str().into(),
      command_type: msg.command_type,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      parent_id: msg.parent_id,
      title: msg.title.to_string(),
      command: msg.command.to_string(),
      command_type: msg.command_type,
    }
  }
}


// Corresponds to visualization_msgs__msg__MeshFile
/// Used to send raw mesh files.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MeshFile {
    /// The filename is used for both debug purposes and to provide a file extension
    /// for whatever parser is used.
    pub filename: std::string::String,

    /// This stores the raw text of the mesh file.
    pub data: Vec<u8>,

}



impl Default for MeshFile {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MeshFile::default())
  }
}

impl rosidl_runtime_rs::Message for MeshFile {
  type RmwMsg = super::msg::rmw::MeshFile;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        filename: msg.filename.as_str().into(),
        data: msg.data.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        filename: msg.filename.as_str().into(),
        data: msg.data.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      filename: msg.filename.to_string(),
      data: msg.data.into(),
    }
  }
}


// Corresponds to visualization_msgs__msg__UVCoordinate
/// Location of the pixel as a ratio of the width of a 2D texture.
/// Values should be in range:.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UVCoordinate::default())
  }
}

impl rosidl_runtime_rs::Message for UVCoordinate {
  type RmwMsg = super::msg::rmw::UVCoordinate;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        u: msg.u,
        v: msg.v,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      u: msg.u,
      v: msg.v,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      u: msg.u,
      v: msg.v,
    }
  }
}


