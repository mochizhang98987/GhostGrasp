#pragma once

#include <memory>
#include <string>

#include <behaviortree_cpp/bt_factory.h>
#include <rclcpp/rclcpp.hpp>

#include "infrared_grasp_bt/backend_registry.hpp"
#include "infrared_grasp_bt/trial_logger.hpp"

namespace infrared_grasp_bt
{
void register_m0_nodes(
  BT::BehaviorTreeFactory & factory,
  rclcpp::Node::SharedPtr node,
  std::shared_ptr<BackendRegistry> registry,
  std::shared_ptr<TrialLogger> logger,
  const std::string & executor_name);
}  // namespace infrared_grasp_bt
