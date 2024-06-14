// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "rclcpp/rclcpp.hpp"

#include "auna_its_msgs/msg/cam.hpp"
#include "etsi_its_msgs/msg/cam.hpp"

class OmnetReceiver : public rclcpp::Node {
 public:
  OmnetReceiver();

 private:
  void cam_callback(const etsi_its_msgs::msg::CAM::SharedPtr msg);

  rclcpp::Publisher<auna_its_msgs::msg::CAM>::SharedPtr cam_publisher_;
  rclcpp::Subscription<etsi_its_msgs::msg::CAM>::SharedPtr omnet_subscriber_;
  double scale_factor_ = 10;
};