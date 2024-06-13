// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.


#include "rclcpp/rclcpp.hpp"

#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"

class VescStart : public rclcpp::Node
{
    public:
        VescStart();
    private:
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_subscription;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher;
        rclcpp::TimerBase::SharedPtr timer;

        void timer_callback();
        void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
};