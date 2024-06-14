// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "rclcpp/rclcpp.hpp"

#include "gazebo_msgs/msg/entity_state.hpp"
#include "gazebo_msgs/msg/model_states.hpp"
#include "gazebo_msgs/srv/get_entity_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "std_msgs/msg/header.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp" /*  .h chnaged to .hpp  */

#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Scalar.h>

#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"

class GazeboPose : public rclcpp::Node {
 public:
  GazeboPose(std::string name);

 private:
  void service_timer_callback();
  void model_srv_callback(
      const rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedFuture
          future);

  tf2_ros::Buffer buffer_;
  tf2_ros::TransformListener listener_;
  tf2_ros::TransformBroadcaster broadcaster_;

  rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedPtr modelClient_;
  rclcpp::TimerBase::SharedPtr service_timer_;

  std::string name_;
  double speed_;
  int publish_milliseconds_ = 100;
};