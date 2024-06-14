// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "auna_omnet/omnet_receiver.hpp"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<OmnetReceiver>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}