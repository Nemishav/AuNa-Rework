// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "auna_cacc/cacc_controller.hpp"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CaccController>());
  rclcpp::shutdown();
  return 0;
}