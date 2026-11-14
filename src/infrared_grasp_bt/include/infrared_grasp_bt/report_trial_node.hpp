#pragma once

#include <memory>
#include <string>
#include <vector>

#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/basic_types.h>

#include "infrared_grasp_bt/trial_logger.hpp"
#include "infrared_grasp_interfaces/msg/geometry_hypothesis.hpp"

namespace infrared_grasp_bt
{

class ReportTrialNode : public BT::SyncActionNode
{
public:
  ReportTrialNode(
    const std::string & name,
    const BT::NodeConfig & config,
    std::shared_ptr<TrialLogger> logger);

  static BT::PortsList providedPorts();

private:
  BT::NodeStatus tick() override;

  std::shared_ptr<TrialLogger> logger_;
};

}  // namespace infrared_grasp_bt
