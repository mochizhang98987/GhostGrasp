#include "infrared_grasp_bt/register_nodes.hpp"

#include "infrared_grasp_bt/execute_grasp_action_node.hpp"
#include "infrared_grasp_bt/recover_geometry_action_node.hpp"
#include "infrared_grasp_bt/report_trial_node.hpp"
#include "infrared_grasp_bt/select_next_hypothesis_node.hpp"
#include "infrared_grasp_bt/start_trial_node.hpp"

namespace infrared_grasp_bt
{
void register_m0_nodes(
  BT::BehaviorTreeFactory & factory,
  rclcpp::Node::SharedPtr node,
  std::shared_ptr<BackendRegistry> registry,
  std::shared_ptr<TrialLogger> logger,
  const std::string & executor_name)
{
  factory.registerNodeType<StartTrialNode>("StartTrial");
  factory.registerNodeType<SelectNextHypothesis>("SelectNextHypothesis");

  factory.registerBuilder<RecoverGeometryActionNode>(
    "RecoverGeometry",
    [node, registry](const std::string & name, const BT::NodeConfig & config) {
      return std::make_unique<RecoverGeometryActionNode>(name, config, node, registry);
    });

  factory.registerBuilder<ExecuteGraspActionNode>(
    "ExecuteGrasp",
    [node, registry, executor_name](const std::string & name, const BT::NodeConfig & config) {
      return std::make_unique<ExecuteGraspActionNode>(
        name, config, node, registry, executor_name);
    });

  factory.registerBuilder<ReportTrialNode>(
    "ReportTrial",
    [logger](const std::string & name, const BT::NodeConfig & config) {
      return std::make_unique<ReportTrialNode>(name, config, logger);
    });
}
}  // namespace infrared_grasp_bt
