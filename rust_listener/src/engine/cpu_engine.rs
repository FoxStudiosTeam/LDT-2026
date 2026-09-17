use crate::engine::types::{Engine, PointCloud};

pub struct CPUEngine<'a,const SIZE: usize> {
    point_cloud : &'a PointCloud<SIZE>
}

impl<'a, const SIZE: usize> CPUEngine<'a,SIZE> {
    pub fn new(point_cloud : &'a PointCloud<SIZE>) -> Self {
        Self {
            point_cloud : point_cloud
        }
    }
}

impl<'a, const SIZE: usize> Engine<SIZE> for CPUEngine<'a,SIZE> {
    fn check(&self) -> Result<bool, anyhow::Error> {



        Ok(false)
    }
}