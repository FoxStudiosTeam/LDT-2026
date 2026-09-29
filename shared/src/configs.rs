use crate::rail_detection::{LidarGeometry, RailTrackDetector};

use crate as shared;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Default, serde::Serialize, serde::Deserialize)]
pub enum DetectionPreset {
    #[default]
    Default,
    StrictRail,
    Anchored,
    Quiet,
    QuietPlus,
}

impl From<DetectionPreset> for RailTrackDetector {
    fn from(preset: DetectionPreset) -> Self {
        let geo = LidarGeometry::default();
        match preset {
            DetectionPreset::Default => {
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
                detector.obstacle_config.temporal_tracking_enabled = true;
                detector.obstacle_config.min_hits_for_critical = 2;
                detector.obstacle_config.max_missed_frames = 1;
                detector.obstacle_config.track_match_dist_m = 2.50;
                detector.obstacle_config.track_match_lateral_m = 0.80;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.25;
                detector.max_outlier_frames = 4;
                detector.far_anchor_enabled = true;
                detector
            }
            DetectionPreset::StrictRail => {
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
                detector.obstacle_config.temporal_tracking_enabled = true;
                detector.obstacle_config.min_hits_for_critical = 2;
                detector.obstacle_config.max_missed_frames = 1;
                detector.obstacle_config.track_match_dist_m = 2.50;
                detector.obstacle_config.track_match_lateral_m = 0.80;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.25;
                detector.max_outlier_frames = 4;
                detector.far_anchor_enabled = true;
                detector
            }
            DetectionPreset::Anchored => {
                // Tuned RailTrackDetector Config
                let mut detector = RailTrackDetector::new(geo);
                detector.depth_step_thresh = 0.100;
                detector.max_depth_step_thresh = 1.100;
                detector.nominal_gauge = 1.300;
                detector.min_gauge = 1.600;
                detector.max_gauge = 2.100;
                detector.row_start_pct = 0.960;
                detector.row_end_pct = 0.380;
                detector.max_lateral_jump = 0.300;
                detector.max_lateral_rail_jump = 0.020;
                detector.extrapolate_m = 21.0;
                detector.smooth_n = 1;
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
                detector.obstacle_config.clearance_narrowing_width = 0.0080;
                detector.obstacle_config.clearance_narrowing_height = 0.0060;
                detector.obstacle_config.cluster_depth_thresh = 0.20;
                detector.obstacle_config.temporal_tracking_enabled = true;
                detector.obstacle_config.min_hits_for_critical = 2;
                detector.obstacle_config.max_missed_frames = 1;
                detector.obstacle_config.track_match_dist_m = 2.50;
                detector.obstacle_config.track_match_lateral_m = 0.80;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.250;
                detector.max_outlier_frames = 4;
                detector.far_anchor_enabled = false;
                detector
            }
            DetectionPreset::Quiet => {
                // Tuned RailTrackDetector Config
                let mut detector = RailTrackDetector::new(geo);
                detector.depth_step_thresh = 0.100;
                detector.max_depth_step_thresh = 1.100;
                detector.nominal_gauge = 1.550;
                detector.min_gauge = 1.500;
                detector.max_gauge = 1.400;
                detector.row_start_pct = 0.670;
                detector.row_end_pct = 0.400;
                detector.max_lateral_jump = 0.200;
                detector.max_lateral_rail_jump = 0.020;
                detector.extrapolate_m = 5.0;
                detector.smooth_n = 1;
                detector.contrast_depth = 195.0;
                detector.contrast_intensity = 5.0;
                detector.blend = 1.00;
                detector.obstacle_config.enabled = true;
                detector.obstacle_config.mode =
                    shared::rail_detection::ObstacleDetectionMode::Boxcast3D;
                detector.obstacle_config.clearance_width = 2.40;
                detector.obstacle_config.min_height_above_rail = 0.17;
                detector.obstacle_config.max_height_above_rail = 3.30;
                detector.obstacle_config.min_points = 12;
                detector.obstacle_config.max_distance_m = 50.0;
                detector.obstacle_config.depth_diff_thresh = 0.25;
                detector.obstacle_config.upward_curvature = 0.00200;
                detector.obstacle_config.clearance_narrowing_width = 0.0060;
                detector.obstacle_config.clearance_narrowing_height = 0.0090;
                detector.obstacle_config.clearance_height_end_shift = -0.200;
                detector.obstacle_config.clearance_start_offset = 2.000;
                detector.obstacle_config.cluster_depth_thresh = 0.20;
                detector.obstacle_config.temporal_tracking_enabled = true;
                detector.obstacle_config.min_hits_for_critical = 2;
                detector.obstacle_config.max_missed_frames = 1;
                detector.obstacle_config.track_match_dist_m = 2.50;
                detector.obstacle_config.track_match_lateral_m = 0.80;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.250;
                detector.max_outlier_frames = 3;
                detector.far_anchor_enabled = false;
                detector
            }
            DetectionPreset::QuietPlus => {
                // Tuned RailTrackDetector Config
                let mut detector = RailTrackDetector::new(geo);
                detector.depth_step_thresh = 0.100;
                detector.max_depth_step_thresh = 1.100;
                detector.nominal_gauge = 1.550;
                detector.min_gauge = 1.500;
                detector.max_gauge = 1.400;
                detector.row_start_pct = 0.670;
                detector.row_end_pct = 0.400;
                detector.max_lateral_jump = 0.200;
                detector.max_lateral_rail_jump = 0.020;
                detector.extrapolate_m = 5.0;
                detector.smooth_n = 1;
                detector.contrast_depth = 195.0;
                detector.contrast_intensity = 5.0;
                detector.blend = 1.00;
                detector.obstacle_config.enabled = true;
                detector.obstacle_config.mode =
                    shared::rail_detection::ObstacleDetectionMode::Boxcast3D;
                detector.obstacle_config.clearance_width = 2.40;
                detector.obstacle_config.min_height_above_rail = 0.17;
                detector.obstacle_config.max_height_above_rail = 3.30;
                detector.obstacle_config.min_points = 12;
                detector.obstacle_config.max_distance_m = 58.0;
                detector.obstacle_config.depth_diff_thresh = 0.25;
                detector.obstacle_config.upward_curvature = 0.00200;
                detector.obstacle_config.clearance_narrowing_width = 0.0060;
                detector.obstacle_config.clearance_narrowing_height = 0.0090;
                detector.obstacle_config.clearance_height_end_shift = -0.200;
                detector.obstacle_config.clearance_start_offset = 2.000;
                detector.obstacle_config.cluster_depth_thresh = 0.20;
                detector.obstacle_config.temporal_tracking_enabled = true;
                detector.obstacle_config.min_hits_for_critical = 2;
                detector.obstacle_config.max_missed_frames = 1;
                detector.obstacle_config.track_match_dist_m = 2.50;
                detector.obstacle_config.track_match_lateral_m = 0.80;
                detector.temporal_jump_reject_enabled = true;
                detector.max_interframe_jump_m = 0.250;
                detector.max_outlier_frames = 3;
                detector.far_anchor_enabled = false;
                detector
            }
        }
    }
}

impl std::str::FromStr for DetectionPreset {
    type Err = String;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let clean = s.trim().to_lowercase().replace(['_', '-'], "");
        match clean.as_str() {
            "default" => Ok(DetectionPreset::Default),
            "strictrail" | "strict" => Ok(DetectionPreset::StrictRail),
            "anchored" | "anchor" => Ok(DetectionPreset::Anchored),
            "quietplus" | "quiet+" => Ok(DetectionPreset::QuietPlus),
            "quiet" => Ok(DetectionPreset::Quiet),
            _ => Err(format!(
                "Unknown DetectionPreset '{}'. Available: Default, StrictRail, Anchored, Quiet, QuietPlus",
                s
            )),
        }
    }
}

impl std::fmt::Display for DetectionPreset {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Default => write!(f, "Default"),
            Self::StrictRail => write!(f, "StrictRail"),
            Self::Anchored => write!(f, "Anchored"),
            Self::Quiet => write!(f, "Quiet"),
            Self::QuietPlus => write!(f, "QuietPlus"),
        }
    }
}

impl DetectionPreset {
    pub fn current() -> Self {
        DetectionPreset::Quiet
    }

    /// Загружает пресет из .env или переменной окружения `DETECTION_PRESET`,
    /// с дефолтом `DetectionPreset::current()`.
    pub fn from_env() -> Self {
        let _ = dotenvy::dotenv();
        std::env::var("DETECTION_PRESET")
            .ok()
            .and_then(|val| val.parse().ok())
            .unwrap_or_else(Self::current)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_detection_preset_from_str() {
        assert_eq!(
            "Default".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::Default
        );
        assert_eq!(
            "default".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::Default
        );
        assert_eq!(
            "StrictRail".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::StrictRail
        );
        assert_eq!(
            "strict_rail".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::StrictRail
        );
        assert_eq!(
            "strict".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::StrictRail
        );
        assert_eq!(
            "Anchored".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::Anchored
        );
        assert_eq!(
            "Quiet".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::Quiet
        );
        assert_eq!(
            "quiet".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::Quiet
        );
        assert_eq!(
            "QuietPlus".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::QuietPlus
        );
        assert_eq!(
            "quiet_plus".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::QuietPlus
        );
        assert_eq!(
            "quiet+".parse::<DetectionPreset>().unwrap(),
            DetectionPreset::QuietPlus
        );
        assert!("unknown_preset".parse::<DetectionPreset>().is_err());
    }

    #[test]
    fn test_detection_preset_default_fallback() {
        assert_eq!(DetectionPreset::current(), DetectionPreset::Quiet);
    }
}
