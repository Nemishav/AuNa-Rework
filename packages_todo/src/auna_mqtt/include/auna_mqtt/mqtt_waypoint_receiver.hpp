// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#ifndef AUNA_MQTT_WAYPOINT_RECEIVER_HPP
#define AUNA_MQTT_WAYPOINT_RECEIVER_HPP

#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <vector>
#include "auna_mqtt/mqtt_callback.hpp"
#include "nav2_msgs/action/navigate_through_poses.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

using NavigateThroughPoses = nav2_msgs::action::NavigateThroughPoses;
using GoalHandleNavigateThroughPoses =
    rclcpp_action::ClientGoalHandle<NavigateThroughPoses>;

class MQTTWaypointReceiver : public rclcpp::Node {
 public:
  MQTTWaypointReceiver();

  void mqtt_callback(nlohmann::json data);

 private:
  // create a namespace variable
  std::string namespace_;

  // create a buffer and listener for tf2
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;

  // create a timer
  rclcpp::TimerBase::SharedPtr timer_;

  // create a timer callback
  void timer_callback();

  // create a client for the action
  rclcpp_action::Client<nav2_msgs::action::NavigateThroughPoses>::SharedPtr
      client_ptr_;

  // create a goal response callback
  void goal_response_callback(
      std::shared_future<rclcpp_action::ClientGoalHandle<
          nav2_msgs::action::NavigateThroughPoses>::SharedPtr>
          future);

  // create a feedback callback
  void feedback_callback(
      GoalHandleNavigateThroughPoses::SharedPtr,
      const std::shared_ptr<const NavigateThroughPoses::Feedback> feedback);

  // create a result callback
  void result_callback(
      const GoalHandleNavigateThroughPoses::WrappedResult& result);

  // m_mqttClient
  mqtt::async_client* m_mqttClient;

  // pose vector
  std::vector<geometry_msgs::msg::PoseStamped> poses_;
};

#endif