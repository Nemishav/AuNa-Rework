// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "rclcpp/rclcpp.hpp"

#include "auna_its_msgs/msg/cam.hpp"
#include "gazebo_msgs/msg/entity_state.hpp"
#include "gazebo_msgs/msg/model_states.hpp"
#include "gazebo_msgs/srv/get_entity_state.hpp"
#include "std_msgs/msg/header.hpp"

#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Scalar.h>

class SimulationPose : public rclcpp::Node {
 public:
  SimulationPose(std::string name);

 private:
  void service_timer_callback();
  void model_srv_callback(
      const rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedFuture
          future);

  rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedPtr modelClient_;
  rclcpp::Subscription<gazebo_msgs::msg::ModelStates>::SharedPtr subscription_;
  rclcpp::Publisher<auna_its_msgs::msg::CAM>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr service_timer_;

  std::string name_;
  double speed_;
  int publish_milliseconds_ = 100;
  double scale_factor_ = 10;
};