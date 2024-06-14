// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "auna_mqtt/mqtt_callback.hpp"
#include "auna_mqtt/mqtt_waypoint_receiver.hpp"

MqttCallback::MqttCallback(MQTTWaypointReceiver* _obj) { m_obj = _obj; }

void MqttCallback::message_arrived(mqtt::const_message_ptr msg) {
  nlohmann::json data = nlohmann::json::parse(msg->get_payload_str());
  m_obj->mqtt_callback(data);
}
