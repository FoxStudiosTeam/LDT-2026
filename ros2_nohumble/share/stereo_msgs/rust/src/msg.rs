#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to stereo_msgs__msg__DisparityImage
/// Separate header for compatibility with current TimeSynchronizer.
/// Likely to be removed in a later release, use image.header instead.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DisparityImage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Floating point disparity image. The disparities are pre-adjusted for any
    /// x-offset between the principal points of the two cameras (in the case
    /// that they are verged). That is: d = x_l - x_r - (cx_l - cx_r)
    pub image: sensor_msgs::msg::Image,

    /// Stereo geometry. For disparity d, the depth from the camera is Z = fT/d.
    /// Focal length, pixels
    pub f: f32,

    /// Baseline, world units
    pub t: f32,

    /// Subwindow of (potentially) valid disparity values.
    pub valid_window: sensor_msgs::msg::RegionOfInterest,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DisparityImage::default())
  }
}

impl rosidl_runtime_rs::Message for DisparityImage {
  type RmwMsg = super::msg::rmw::DisparityImage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(msg.image)).into_owned(),
        f: msg.f,
        t: msg.t,
        valid_window: sensor_msgs::msg::RegionOfInterest::into_rmw_message(std::borrow::Cow::Owned(msg.valid_window)).into_owned(),
        min_disparity: msg.min_disparity,
        max_disparity: msg.max_disparity,
        delta_d: msg.delta_d,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(&msg.image)).into_owned(),
      f: msg.f,
      t: msg.t,
        valid_window: sensor_msgs::msg::RegionOfInterest::into_rmw_message(std::borrow::Cow::Borrowed(&msg.valid_window)).into_owned(),
      min_disparity: msg.min_disparity,
      max_disparity: msg.max_disparity,
      delta_d: msg.delta_d,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      image: sensor_msgs::msg::Image::from_rmw_message(msg.image),
      f: msg.f,
      t: msg.t,
      valid_window: sensor_msgs::msg::RegionOfInterest::from_rmw_message(msg.valid_window),
      min_disparity: msg.min_disparity,
      max_disparity: msg.max_disparity,
      delta_d: msg.delta_d,
    }
  }
}


