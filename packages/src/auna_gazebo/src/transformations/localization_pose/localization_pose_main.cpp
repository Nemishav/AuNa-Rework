// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "auna_gazebo/localization_pose.hpp"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  // Set prefix for topic and frame_id, if first argument is non-empty.
  if (argc > 1) {
    rclcpp::spin(std::make_shared<LocalizationPose>(argv[1]));
  } else {
    rclcpp::spin(std::make_shared<LocalizationPose>(""));
  }

  rclcpp::shutdown();
  return 0;
}