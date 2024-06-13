// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "rclcpp/rclcpp.hpp"
#include "gazebo_msgs/msg/model_states.hpp"
#include "auna_msgs/msg/string_array.hpp"

class GazeboModels : public rclcpp::Node
{
    public:
        GazeboModels();
    private:
        void model_state_callback(const gazebo_msgs::msg::ModelStates::SharedPtr msg);
        
        rclcpp::Subscription<gazebo_msgs::msg::ModelStates>::SharedPtr subscription_;
        rclcpp::Publisher<auna_msgs::msg::StringArray>::SharedPtr publisher_;
};
