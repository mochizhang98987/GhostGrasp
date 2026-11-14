#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "infrared_grasp_backends/mycobot_sim_execute_server.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<infrared_grasp_backends::MyCobotSimExecuteServer>());
  rclcpp::shutdown();
  return 0;
}
