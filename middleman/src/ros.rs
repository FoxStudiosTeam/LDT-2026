//! ros.rs — ROS2 DDS-discovery + subscribe + parse для large_processor.

use ros2_client::{
    Context, ContextOptions, MessageTypeName, Name, Node, NodeName, NodeOptions, Subscription,
    rustdds::{DomainParticipantStatusEvent, QosPolicies},
};
use ros2_interfaces_jazzy_serde::sensor_msgs::msg::PointCloud2;
use tracing::*;

use shared::error::{AppError, ErrCtx, ErrorType};

// ─── Discovered topic ─────────────────────────────────────────────────────────

#[derive(Debug, Clone)]
pub struct DiscoveredTopic {
    pub name: String,
    pub msg_type: MessageTypeName,
    pub qos: QosPolicies,
}

fn find_pointcloud_topic(event: DomainParticipantStatusEvent) -> Option<DiscoveredTopic> {
    match event {
        DomainParticipantStatusEvent::WriterDetected { writer }
            if writer.type_name.contains("PointCloud2") =>
        {
            let mut parts = writer.type_name.split("::");
            let topic_name = writer.topic_name.strip_prefix("rt")?;
            Some(DiscoveredTopic {
                name: topic_name.to_owned(),
                msg_type: MessageTypeName::new(parts.next()?, parts.last()?.trim_end_matches('_')),
                qos: writer.qos,
            })
        }
        _ => None,
    }
}

// ─── ROS2-нода (без спиннера — запускается позже) ─────────────────────────────

pub struct Ros {
    // Context должен жить столько же сколько Node
    _context: Context,
    pub node: Node,
}

impl Ros {
    pub fn new(domain_id: u16) -> Result<Self, AppError> {
        let opt = ContextOptions::new().domain_id(domain_id);
        let context = Context::with_options(opt).app_error()?;

        let node_name = NodeName::new("/", "large_processor")
            .map_err(|_| ErrorType::InvalidName("Invalid node name"))?;
        let node = context
            .new_node(node_name, NodeOptions::new())
            .app_error()?;

        // Спиннер НЕ запускаем здесь — нужно сначала взять status_receiver,
        // иначе события переполнят канал до того, как мы начнём их читать.
        Ok(Self {
            _context: context,
            node,
        })
    }

    /// Запустить спиннер. Вызывать ПОСЛЕ того, как взят status_receiver.
    pub fn start_spinner(&mut self) -> Result<(), AppError> {
        let spinner = self.node.spinner().app_error()?;
        tokio::spawn(async move {
            if let Err(e) = spinner.spin().await {
                error!("ROS2 spinner error: {e}");
            }
        });
        Ok(())
    }
}

// ─── DDS-discovery ────────────────────────────────────────────────────────────

/// Ждём PointCloud2-издателя в DDS-сети.
///
/// Порядок критичен:
///  1. запускаем спиннер
///  2. СРАЗУ берём receiver (bounded(8) — канал маленький!)
///  3. читаем события
pub async fn discover_pointcloud(ros: &mut Ros) -> Result<DiscoveredTopic, AppError> {
    let receiver = ros.node.status_receiver();

    info!("[ROS2] Ожидание PointCloud2 в DDS-сети...");

    // 3. Читаем события
    while let Ok(msg) = receiver.recv().await {
        if let ros2_client::NodeEvent::DDS(dds_event) = msg {
            if let Some(topic) = find_pointcloud_topic(dds_event) {
                info!("[ROS2] Найден топик: {}", topic.name);
                return Ok(topic);
            }
        }
    }

    ErrorType::message("DDS receiver closed before PointCloud2 was found").err()
}

// ─── Subscribe ────────────────────────────────────────────────────────────────

pub fn subscribe(
    node: &mut Node,
    topic: DiscoveredTopic,
) -> Result<Subscription<PointCloud2>, AppError> {
    let t = node
        .create_topic(
            &Name::parse(topic.name.as_str())
                .map_err(|_| ErrorType::InvalidName("Invalid topic name"))?,
            topic.msg_type,
            &topic.qos,
        )
        .app_error()?;
    // let qos = QosPolicies::builder().reliability().build();

    node.create_subscription::<PointCloud2>(&t, None)
        .app_error()
}

pub fn subscribe_empty(
    node: &mut Node,
    topic: DiscoveredTopic,
) -> Result<Subscription<()>, AppError> {
    let t = node
        .create_topic(
            &Name::parse(topic.name.as_str())
                .map_err(|_| ErrorType::InvalidName("Invalid topic name"))?,
            topic.msg_type,
            &topic.qos,
        )
        .app_error()?;

    // let qos = QosPolicies::builder()
    //     .reliability(ros2_client::rustdds::policy::Reliability::BestEffort)
    //     .build();

    node.create_subscription::<()>(&t, None).app_error()
}

// ─── Parse ────────────────────────────────────────────────────────────────────

#[derive(Debug, Clone, Copy)]
pub struct PointLayout {
    pub x: usize,
    pub y: usize,
    pub z: usize,
    pub intensity: usize,
    pub point_step: usize,
    pub is_bigendian: bool,
}

impl PointLayout {
    pub fn from_cloud(cloud: &PointCloud2) -> Result<Self, AppError> {
        let find = |name: &'static str| -> Result<usize, AppError> {
            cloud
                .fields
                .iter()
                .find(|f| f.name == name)
                .map(|f| f.offset as usize)
                .ok_or_else(|| AppError::from(ErrorType::NoneError(name)))
        };
        Ok(Self {
            x: find("x")?,
            y: find("y")?,
            z: find("z")?,
            intensity: find("intensity")?,
            point_step: cloud.point_step as usize,
            is_bigendian: cloud.is_bigendian,
        })
    }

    #[inline(always)]
    fn read_f32(&self, buf: &[u8], off: usize) -> f32 {
        let raw = unsafe { *(buf.as_ptr().add(off) as *const u32) };
        let bits = if self.is_bigendian {
            u32::from_be(raw)
        } else {
            u32::from_le(raw)
        };
        f32::from_bits(bits)
    }
}

/// Извлекаем конечные точки из кадра.
pub fn parse_cloud(cloud: &PointCloud2, layout: &PointLayout) -> (Vec<[f32; 3]>, Vec<f32>) {
    let total = cloud.width as usize * cloud.height as usize;
    let mut pts = Vec::with_capacity(total);
    let mut intensities = Vec::with_capacity(total);

    for chunk in cloud.data.chunks_exact(layout.point_step).take(total) {
        let x = layout.read_f32(chunk, layout.x);
        let y = layout.read_f32(chunk, layout.y);
        let z = layout.read_f32(chunk, layout.z);
        let i = layout.read_f32(chunk, layout.intensity);
        if x.is_finite() && y.is_finite() && z.is_finite() {
            pts.push([x, y, z]);
            intensities.push(i);
        }
    }

    (pts, intensities)
}
