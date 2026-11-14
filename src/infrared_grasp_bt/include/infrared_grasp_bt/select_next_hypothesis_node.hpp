#pragma once

#include <string>
#include <vector>

#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/basic_types.h>

#include "infrared_grasp_interfaces/msg/geometry_hypothesis.hpp"

namespace infrared_grasp_bt
{

class SelectNextHypothesis : public BT::SyncActionNode
{
public:
  SelectNextHypothesis(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

private:
  BT::NodeStatus tick() override;
};

}  // namespace infrared_grasp_bt
