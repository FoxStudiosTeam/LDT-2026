mod parser;

use crate::error::Error;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;

#[derive(Debug, Clone)]
pub struct PointCloud {
    pub header: Header,
    pub width: u32,
    pub height: u32,
    pub points: Box<[Point]>,
    pub is_dense: bool,
}

#[derive(Debug, Clone)]
pub struct Header {
    pub stamp: Time,
    pub frame_id: String,
}

#[derive(Debug, Clone, Copy)]
pub struct Time {
    pub sec: i32,
    pub nanosec: u32,
}

#[derive(Debug, Clone)]
pub struct Field {
    pub name: String,
    pub offset: u32,
    pub datatype: u8,
    pub count: u32,
}

#[derive(Debug, Clone, Default)]
pub struct Point {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub intensity: f32,
    pub ring: Option<u16>,
    pub timestamp: Option<f64>,
}

pub fn new(message: PointCloud2) -> Result<PointCloud, Error> {
    parser::parse_pointcloud(message)
}