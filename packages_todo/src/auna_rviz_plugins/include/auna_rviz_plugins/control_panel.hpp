// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <rclcpp/rclcpp.hpp>
#include <rviz_common/panel.hpp>
#include <std_srvs/srv/empty.hpp>

namespace auna_rviz_plugins {

class ControlPanel : public rviz_common::Panel {
  Q_OBJECT
 public:
  ControlPanel(QWidget* parent = nullptr);

 public Q_SLOTS:
  void onEmergencyStopClicked();
  void onChangeVelocityClicked();

 private:
  QLineEdit* velocity_input_;
  rclcpp::Node::SharedPtr node_;
};

}  // namespace auna_rviz_plugins
