#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "stereo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__stereo_msgs__msg__DisparityImage() -> *const std::ffi::c_void;
}

#[link(name = "stereo_msgs__rosidl_generator_c")]
extern "C" {
    fn stereo_msgs__msg__DisparityImage__init(msg: *mut DisparityImage) -> bool;
    fn stereo_msgs__msg__DisparityImage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DisparityImage>, size: usize) -> bool;
    fn stereo_msgs__msg__DisparityImage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DisparityImage>);
    fn stereo_msgs__msg__DisparityImage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DisparityImage>, out_seq: *mut rosidl_runtime_rs::Sequence<DisparityImage>) -> bool;
}

// Corresponds to stereo_msgs__msg__DisparityImage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Separate header for compatibility with current TimeSynchronizer.
/// Likely to be removed in a later release, use image.header instead.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DisparityImage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Floating point disparity image. The disparities are pre-adjusted for any
    /// x-offset between the principal points of the two cameras (in the case
    /// that they are verged). That is: d = x_l - x_r - (cx_l - cx_r)
    pub image: sensor_msgs::msg::rmw::Image,

    /// Stereo geometry. For disparity d, the depth from the camera is Z = fT/d.
    /// Focal length, pixels
    pub f: f32,

    /// Baseline, world units
    pub t: f32,

    /// Subwindow of (potentially) valid disparity values.
    pub valid_window: sensor_msgs::msg::rmw::RegionOfInterest,

    /// The range of disparities searched.
    /// In the disparity image, any disparity less than min_disparity is invalid.
    /// The disparity search range defines the horopter, or 3D volume that the
    /// stereo algorithm can "see". Points with Z outside of:
    ///     Z_min = fT / max_disparity
    ///     Z_max = fT / min_disparity
    /// could not be found.
    pub min_disparity: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_disparity: f32,

    /// Smallest allowed disparity increment. The smallest achievable depth range
    /// resolution is delta_Z = (Z^2/fT)*delta_d.
    pub delta_d: f32,

}



impl Default for DisparityImage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !stereo_msgs__msg__DisparityImage__init(&mut msg as *mut _) {
        panic!("Call to stereo_msgs__msg__DisparityImage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DisparityImage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { stereo_msgs__msg__DisparityImage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { stereo_msgs__msg__DisparityImage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { stereo_msgs__msg__DisparityImage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DisparityImage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DisparityImage where Self: Sized {
  const TYPE_NAME: &'static str = "stereo_msgs/msg/DisparityImage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__stereo_msgs__msg__DisparityImage() }
  }
}


