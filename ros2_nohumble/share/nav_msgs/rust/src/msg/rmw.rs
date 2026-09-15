#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Goals() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__Goals__init(msg: *mut Goals) -> bool;
    fn nav_msgs__msg__Goals__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Goals>, size: usize) -> bool;
    fn nav_msgs__msg__Goals__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Goals>);
    fn nav_msgs__msg__Goals__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Goals>, out_seq: *mut rosidl_runtime_rs::Sequence<Goals>) -> bool;
}

// Corresponds to nav_msgs__msg__Goals
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// An array of navigation goals

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Goals {
    /// This header will store the time at which the poses were computed (not to be confused with the stamps of the poses themselves)
    /// In the case that individual poses do not have their frame_id set or their timetamp set they will use the default value here.
    pub header: std_msgs::msg::rmw::Header,

    /// An array of goals to for navigation to achieve.
    /// The goals should be executed in the order of the array.
    /// The header and stamp are intended to be used for computing the position of the goals.
    /// They may vary to support cases of goals that are moving with respect to the robot.
    pub goals: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::PoseStamped>,

}



impl Default for Goals {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__Goals__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__Goals__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Goals {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Goals__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Goals__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Goals__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Goals {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Goals where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/Goals";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Goals() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__GridCells() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__GridCells__init(msg: *mut GridCells) -> bool;
    fn nav_msgs__msg__GridCells__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GridCells>, size: usize) -> bool;
    fn nav_msgs__msg__GridCells__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GridCells>);
    fn nav_msgs__msg__GridCells__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GridCells>, out_seq: *mut rosidl_runtime_rs::Sequence<GridCells>) -> bool;
}

// Corresponds to nav_msgs__msg__GridCells
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// An array of cells in a 2D grid

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GridCells {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Width of each cell
    pub cell_width: f32,

    /// Height of each cell
    pub cell_height: f32,

    /// Each cell is represented by the Point at the center of the cell
    pub cells: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,

}



impl Default for GridCells {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__GridCells__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__GridCells__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GridCells {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__GridCells__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__GridCells__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__GridCells__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GridCells {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GridCells where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/GridCells";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__GridCells() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__MapMetaData() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__MapMetaData__init(msg: *mut MapMetaData) -> bool;
    fn nav_msgs__msg__MapMetaData__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MapMetaData>, size: usize) -> bool;
    fn nav_msgs__msg__MapMetaData__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MapMetaData>);
    fn nav_msgs__msg__MapMetaData__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MapMetaData>, out_seq: *mut rosidl_runtime_rs::Sequence<MapMetaData>) -> bool;
}

// Corresponds to nav_msgs__msg__MapMetaData
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This hold basic information about the characteristics of the OccupancyGrid

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MapMetaData {
    /// The time at which the map was loaded
    pub map_load_time: builtin_interfaces::msg::rmw::Time,

    /// The map resolution
    pub resolution: f32,

    /// Map width
    pub width: u32,

    /// Map height
    pub height: u32,

    /// The origin of the map [m, m, rad].  This is the real-world pose of the
    /// bottom left corner of cell (0,0) in the map.
    pub origin: geometry_msgs::msg::rmw::Pose,

}



impl Default for MapMetaData {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__MapMetaData__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__MapMetaData__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MapMetaData {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__MapMetaData__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__MapMetaData__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__MapMetaData__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MapMetaData {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MapMetaData where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/MapMetaData";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__MapMetaData() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__OccupancyGrid() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__OccupancyGrid__init(msg: *mut OccupancyGrid) -> bool;
    fn nav_msgs__msg__OccupancyGrid__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OccupancyGrid>, size: usize) -> bool;
    fn nav_msgs__msg__OccupancyGrid__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OccupancyGrid>);
    fn nav_msgs__msg__OccupancyGrid__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OccupancyGrid>, out_seq: *mut rosidl_runtime_rs::Sequence<OccupancyGrid>) -> bool;
}

// Corresponds to nav_msgs__msg__OccupancyGrid
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This represents a 2-D grid map

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OccupancyGrid {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// MetaData for the map
    pub info: super::super::msg::rmw::MapMetaData,

    /// The map data, in row-major order, starting with (0,0).
    /// Cell (1, 0) will be listed second, representing the next cell in the x direction.
    /// Cell (0, 1) will be at the index equal to info.width, followed by (1, 1).
    /// The values inside are application dependent, but frequently,
    /// 0 represents unoccupied, 1 represents definitely occupied, and
    /// -1 represents unknown.
    pub data: rosidl_runtime_rs::Sequence<i8>,

}



impl Default for OccupancyGrid {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__OccupancyGrid__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__OccupancyGrid__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OccupancyGrid {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__OccupancyGrid__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__OccupancyGrid__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__OccupancyGrid__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OccupancyGrid {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OccupancyGrid where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/OccupancyGrid";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__OccupancyGrid() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Odometry() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__Odometry__init(msg: *mut Odometry) -> bool;
    fn nav_msgs__msg__Odometry__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Odometry>, size: usize) -> bool;
    fn nav_msgs__msg__Odometry__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Odometry>);
    fn nav_msgs__msg__Odometry__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Odometry>, out_seq: *mut rosidl_runtime_rs::Sequence<Odometry>) -> bool;
}

// Corresponds to nav_msgs__msg__Odometry
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This represents an estimate of a position and velocity in free space.
/// The pose in this message should be specified in the coordinate frame given by header.frame_id
/// The twist in this message should be specified in the coordinate frame given by the child_frame_id

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Odometry {
    /// Includes the frame id of the pose parent.
    pub header: std_msgs::msg::rmw::Header,

    /// Frame id the pose points to. The twist is in this coordinate frame.
    pub child_frame_id: rosidl_runtime_rs::String,

    /// Estimated pose that is typically relative to a fixed world frame.
    pub pose: geometry_msgs::msg::rmw::PoseWithCovariance,

    /// Estimated linear and angular velocity relative to child_frame_id.
    pub twist: geometry_msgs::msg::rmw::TwistWithCovariance,

}



impl Default for Odometry {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__Odometry__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__Odometry__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Odometry {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Odometry__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Odometry__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Odometry__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Odometry {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Odometry where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/Odometry";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Odometry() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Path() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__Path__init(msg: *mut Path) -> bool;
    fn nav_msgs__msg__Path__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Path>, size: usize) -> bool;
    fn nav_msgs__msg__Path__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Path>);
    fn nav_msgs__msg__Path__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Path>, out_seq: *mut rosidl_runtime_rs::Sequence<Path>) -> bool;
}

// Corresponds to nav_msgs__msg__Path
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// An array of poses that represents a Path for a robot to follow.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Path {
    /// Indicates the frame_id of the path.
    pub header: std_msgs::msg::rmw::Header,

    /// Array of poses to follow.
    pub poses: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::PoseStamped>,

}



impl Default for Path {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__Path__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__Path__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Path {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Path__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Path__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Path__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Path {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Path where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/Path";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Path() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Trajectory() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__Trajectory__init(msg: *mut Trajectory) -> bool;
    fn nav_msgs__msg__Trajectory__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Trajectory>, size: usize) -> bool;
    fn nav_msgs__msg__Trajectory__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Trajectory>);
    fn nav_msgs__msg__Trajectory__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Trajectory>, out_seq: *mut rosidl_runtime_rs::Sequence<Trajectory>) -> bool;
}

// Corresponds to nav_msgs__msg__Trajectory
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// An array of trajectory points that represents a trajectory for a robot to follow.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory {
    /// Indicates the frame_id in which the planner ran and timestamp represents when the trajectory was generated.
    pub header: std_msgs::msg::rmw::Header,

    /// Array of trajectory points to follow.
    pub points: rosidl_runtime_rs::Sequence<super::super::msg::rmw::TrajectoryPoint>,

}



impl Default for Trajectory {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__Trajectory__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__Trajectory__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Trajectory {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Trajectory__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Trajectory__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__Trajectory__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Trajectory {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Trajectory where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/Trajectory";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__Trajectory() }
  }
}


#[link(name = "nav_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__TrajectoryPoint() -> *const std::ffi::c_void;
}

#[link(name = "nav_msgs__rosidl_generator_c")]
extern "C" {
    fn nav_msgs__msg__TrajectoryPoint__init(msg: *mut TrajectoryPoint) -> bool;
    fn nav_msgs__msg__TrajectoryPoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrajectoryPoint>, size: usize) -> bool;
    fn nav_msgs__msg__TrajectoryPoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrajectoryPoint>);
    fn nav_msgs__msg__TrajectoryPoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrajectoryPoint>, out_seq: *mut rosidl_runtime_rs::Sequence<TrajectoryPoint>) -> bool;
}

// Corresponds to nav_msgs__msg__TrajectoryPoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Trajectory point state

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrajectoryPoint {
    /// Absolute time and frame of reference of the point along a trajectory
    pub header: std_msgs::msg::rmw::Header,

    /// Pose of the trajectory sample.
    pub pose: geometry_msgs::msg::rmw::Pose,

    /// Velocity of the trajectory sample.
    pub velocity: geometry_msgs::msg::rmw::Twist,

    /// Acceleration of the trajectory (optional, linear.x component is NaN if not set).
    pub acceleration: geometry_msgs::msg::rmw::Accel,

    /// Force/Torque to apply at trajectory sample (optional, force.x component is NaN if not set).
    pub effort: geometry_msgs::msg::rmw::Wrench,

}



impl Default for TrajectoryPoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_msgs__msg__TrajectoryPoint__init(&mut msg as *mut _) {
        panic!("Call to nav_msgs__msg__TrajectoryPoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrajectoryPoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__TrajectoryPoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__TrajectoryPoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_msgs__msg__TrajectoryPoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrajectoryPoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrajectoryPoint where Self: Sized {
  const TYPE_NAME: &'static str = "nav_msgs/msg/TrajectoryPoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_msgs__msg__TrajectoryPoint() }
  }
}


