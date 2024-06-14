// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#ifndef AUNA_MQTT_CALLBACK_HPP
#define AUNA_MQTT_CALLBACK_HPP

#include "mqtt/async_client.h"
#include "nlohmann/json.hpp"
#include "rclcpp/rclcpp.hpp"
// #include "auna_mqtt/mqtt_waypoint_receiver.hpp"

class MQTTWaypointReceiver;
class MqttCallback : public virtual mqtt::callback {
  MQTTWaypointReceiver* m_obj;

 public:
  MqttCallback(MQTTWaypointReceiver* _obj);
  ~MqttCallback() {}

  void message_arrived(mqtt::const_message_ptr msg);
};

#endif