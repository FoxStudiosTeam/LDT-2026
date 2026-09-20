use rerun::Points3D;
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use shared::error::{AppError, ErrCtx, ErrorType};
use tokio::time::Instant;
use tracing::*;
use tracing_subscriber::EnvFilter;

use crate::sandbox::rerun_enshured;

mod diag;
mod ros;
mod sandbox;
mod types;

shared::env_config! {
    "" => pub ENV = pub Env {
        rerun_url : String = "rerun+http://192.168.0.100:9876/proxy".to_string(),
        ROS_DOMAIN_ID : u16 = 0
    }
}

#[tokio::main]
async fn main() -> Result<(), AppError> {
    let filter =
        EnvFilter::try_from_default_env().unwrap_or_else(|_| EnvFilter::new("info,rustdds=error"));
    tracing_subscriber::fmt().with_env_filter(filter).init();

    info!("ROS_DOMAIN_ID = {}", ENV.ROS_DOMAIN_ID);
    info!("Rerun URL     = {}", ENV.rerun_url);
    let mut ros = ros::Ros::new(ENV.ROS_DOMAIN_ID)?;

    ros.start_spinner()?;

    let topic = ros::discover_pointcloud(&mut ros).await?;
    let subscription = ros::subscribe(&mut ros.node, topic)?;
    let rerun = rerun_enshured().await?;
    info!("[INIT] Подписка установлена, запуск основного цикла.");

    let mut last = Instant::now();
    while let Ok((pc, _msg)) = subscription.async_take().await {
        let now = Instant::now();
        info!("{}ms", now.duration_since(last).as_millis());
        last = now;
        // let parsed = parse_coords(&pc).app_error()?;
        // rerun
        //     .log("points", &rerun::Points3D::new(&parsed))
        //     .app_error()?;
    }

    Ok(())
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Point {
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub intensity: f32,
}

impl From<&Point> for rerun::Position3D {
    #[inline]
    fn from(p: &Point) -> Self {
        rerun::Position3D::new(p.x, p.y, p.z)
    }
}

pub fn parse_coords(pc: &PointCloud2) -> Result<Vec<Point>, AppError> {
    let width = pc.width as usize;
    let height = pc.height as usize;
    let point_step = pc.point_step as usize;

    let total_points = width.checked_mul(height).ok_or_else(|| {
        ErrorType::message(format!(
            "Overflow calculating total points: {}x{}",
            width, height
        ))
    })?;

    // Поиск смещений полей
    let x_field = pc
        .fields
        .iter()
        .find(|f| f.name == "x")
        .ok_or(ErrorType::NoneError("field 'x' not found"))?;
    let y_field = pc
        .fields
        .iter()
        .find(|f| f.name == "y")
        .ok_or(ErrorType::NoneError("field 'y' not found"))?;
    let z_field = pc
        .fields
        .iter()
        .find(|f| f.name == "z")
        .ok_or(ErrorType::NoneError("field 'z' not found"))?;
    let i_field = pc
        .fields
        .iter()
        .find(|f| f.name == "intensity")
        .ok_or(ErrorType::NoneError("field 'intensity' not found"))?;

    let x_off = x_field.offset as usize;
    let y_off = y_field.offset as usize;
    let z_off = z_field.offset as usize;
    let i_off = i_field.offset as usize;

    // Валидация: смещения полей должны умещаться в размер одной точки (4 байта на f32)
    if x_off + 4 > point_step
        || y_off + 4 > point_step
        || z_off + 4 > point_step
        || i_off + 4 > point_step
    {
        return Err(
            ErrorType::message("Field offset is out of point_step bounds".to_string()).into(),
        );
    }

    let is_bigendian = pc.is_bigendian;
    let mut result = Vec::with_capacity(total_points);

    // Функция чтения f32 с учетом endianness и возможной невыровненности памяти
    #[inline(always)]
    unsafe fn read_f32_unaligned(ptr: *const u8, offset: usize, is_bigendian: bool) -> f32 {
        let raw_bytes = std::ptr::read_unaligned(ptr.add(offset) as *const u32);
        let bits = if is_bigendian {
            u32::from_be(raw_bytes)
        } else {
            u32::from_le(raw_bytes)
        };
        f32::from_bits(bits)
    }

    let point_chunks = pc.data.chunks_exact(point_step).take(total_points);

    for point_buf in point_chunks {
        let ptr = point_buf.as_ptr();

        let (x, y, z, intensity) = unsafe {
            (
                read_f32_unaligned(ptr, x_off, is_bigendian),
                read_f32_unaligned(ptr, y_off, is_bigendian),
                read_f32_unaligned(ptr, z_off, is_bigendian),
                read_f32_unaligned(ptr, i_off, is_bigendian),
            )
        };

        // Игнорируем точки с NaN (если точка «пустая»)
        if pc.is_dense || (!x.is_nan() && !y.is_nan() && !z.is_nan()) {
            result.push(Point { x, y, z, intensity });
        }
    }

    Ok(result)
}
