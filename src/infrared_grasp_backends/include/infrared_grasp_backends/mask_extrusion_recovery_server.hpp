#pragma once

#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include "infrared_grasp_interfaces/action/recover_geometry.hpp"
#include "infrared_grasp_interfaces/msg/geometry_hypothesis_array.hpp"

namespace infrared_grasp_backends
{

using RecoverGeometry = infrared_grasp_interfaces::action::RecoverGeometry;

class MaskExtrusionRecoveryServer : public rclcpp::Node
{
public:
  using GoalHandleRecoverGeometry = rclcpp_action::ServerGoalHandle<RecoverGeometry>;

  explicit MaskExtrusionRecoveryServer(
    const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const RecoverGeometry::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleRecoverGeometry> goal_handle);

  void handle_accepted(const std::shared_ptr<GoalHandleRecoverGeometry> goal_handle);
  void execute(const std::shared_ptr<GoalHandleRecoverGeometry> goal_handle);

  bool sleep_cancelable(
    const std::shared_ptr<GoalHandleRecoverGeometry> & goal_handle,
    int delay_ms);

  void publish_feedback(
    const std::shared_ptr<GoalHandleRecoverGeometry> & goal_handle,
    const std::string & stage,
    double progress,
    double current_best_score) const;
  void publish_hypotheses(
    const RecoverGeometry::Goal & goal,
    const std::vector<infrared_grasp_interfaces::msg::GeometryHypothesis> & hypotheses) const;

  rclcpp_action::Server<RecoverGeometry>::SharedPtr action_server_;
  rclcpp::Publisher<infrared_grasp_interfaces::msg::GeometryHypothesisArray>::SharedPtr hypotheses_pub_;
};

}  // namespace infrared_grasp_backends
