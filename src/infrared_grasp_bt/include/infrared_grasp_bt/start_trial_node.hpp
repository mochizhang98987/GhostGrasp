#pragma once

#include <string>

#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/basic_types.h>

namespace infrared_grasp_bt
{

class StartTrialNode : public BT::SyncActionNode
{
public:
  StartTrialNode(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

private:
  BT::NodeStatus tick() override;
};

}  // namespace infrared_grasp_bt
