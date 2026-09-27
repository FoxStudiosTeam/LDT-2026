use crate::rail_detection::{LidarGeometry, RailTrackDetector};

use crate as shared;

#[derive(Default)]
pub enum DetectionPreset {
    #[default]
    Default,
    StrictRail,
}

impl Into<RailTrackDetector> for DetectionPreset {
    fn into(self) -> RailTrackDetector {
        let geo = LidarGeometry::default();
        match self {
            Self::Default => {
                let mut detector = RailTrackDetector::new(geo);
                detector.depth_step_thresh = 0.100;
                detector.max_depth_step_thresh = 1.100;
                detector.nominal_gauge = 1.580;
                detector.min_gauge = 1.515;
                detector.max_gauge = 1.560;
                detector.row_start_pct = 0.880;
                detector.row_end_pct = 0.050;
                detector.max_lateral_jump = 0.300;
                detector.max_lateral_rail_jump = 0.100;
                detector.extrapolate_m = 24.0;
                detector.smooth_n = 3;
                detector.contrast_depth = 195.0;
                detector.contrast_intensity = 5.0;
                detector.blend = 1.00;
                detector.obstacle_config.enabled = true;
                detector.obstacle_config.mode =
                    shared::rail_detection::ObstacleDetectionMode::Boxcast3D;
                detector.obstacle_config.clearance_width = 2.50;
                detector.obstacle_config.min_height_above_rail = 0.15;
                detector.obstacle_config.max_height_above_rail = 3.20;
                detector.obstacle_config.min_points = 8;
                detector.obstacle_config.max_distance_m = 100.0;
                detector.obstacle_config.depth_diff_thresh = 0.25;
                detector.obstacle_config.upward_curvature = 0.00200;
                detector.obstacle_config.cluster_depth_thresh = 1.20;
                detector.obstacle_config.clearance_narrowing_width = 0.003;
                detector.obstacle_config.clearance_narrowing_height = 0.003;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.25;
                detector.max_outlier_frames = 4;
                detector.far_anchor_enabled = true;
                detector
            }
            Self::StrictRail => {
                // Tuned RailTrackDetector Config
                let mut detector = RailTrackDetector::new(geo);
                detector.depth_step_thresh = 0.100;
                detector.max_depth_step_thresh = 1.100;
                detector.nominal_gauge = 1.700;
                detector.min_gauge = 1.600;
                detector.max_gauge = 1.400;
                detector.row_start_pct = 0.880;
                detector.row_end_pct = 0.350;
                detector.max_lateral_jump = 0.300;
                detector.max_lateral_rail_jump = 0.020;
                detector.extrapolate_m = 24.0;
                detector.smooth_n = 1;
                detector.contrast_depth = 195.0;
                detector.contrast_intensity = 5.0;
                detector.blend = 1.00;
                detector.obstacle_config.enabled = false;
                detector.obstacle_config.mode =
                    shared::rail_detection::ObstacleDetectionMode::Boxcast3D;
                detector.obstacle_config.clearance_width = 2.50;
                detector.obstacle_config.min_height_above_rail = 0.15;
                detector.obstacle_config.max_height_above_rail = 3.20;
                detector.obstacle_config.min_points = 8;
                detector.obstacle_config.max_distance_m = 100.0;
                detector.obstacle_config.depth_diff_thresh = 0.25;
                detector.obstacle_config.upward_curvature = 0.00200;
                detector.obstacle_config.clearance_narrowing_width = 0.0030;
                detector.obstacle_config.clearance_narrowing_height = 0.0030;
                detector.obstacle_config.cluster_depth_thresh = 1.20;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.25;
                detector.max_outlier_frames = 4;
                detector.far_anchor_enabled = true;
                detector
            }
        }
    }
}

impl DetectionPreset {
    pub fn current() -> Self {
        DetectionPreset::StrictRail
    }
}
