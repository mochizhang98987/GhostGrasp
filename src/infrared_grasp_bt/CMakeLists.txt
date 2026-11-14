cmake_minimum_required(VERSION 3.16)
project(infrared_grasp_bt)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(infrared_grasp_interfaces REQUIRED)
find_package(infrared_grasp_core REQUIRED)

add_library(infrared_grasp_bt_nodes
  src/backend_registry.cpp
  src/trial_logger.cpp
  src/select_next_hypothesis_node.cpp
  src/start_trial_node.cpp
  src/report_trial_node.cpp
  src/recover_geometry_action_node.cpp
  src/execute_grasp_action_node.cpp
  src/register_nodes.cpp
)
target_include_directories(infrared_grasp_bt_nodes PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(infrared_grasp_bt_nodes PUBLIC cxx_std_17)
target_link_libraries(infrared_grasp_bt_nodes
  behaviortree_cpp::behaviortree_cpp
  yaml-cpp::yaml-cpp
)
ament_target_dependencies(infrared_grasp_bt_nodes
  rclcpp
  rclcpp_action
  ament_index_cpp
  infrared_grasp_interfaces
  infrared_grasp_core
)

add_executable(bt_runner_node src/bt_runner_node.cpp)
target_link_libraries(bt_runner_node infrared_grasp_bt_nodes)
ament_target_dependencies(bt_runner_node rclcpp ament_index_cpp)

install(TARGETS infrared_grasp_bt_nodes bt_runner_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY include/
  DESTINATION include
)
install(DIRECTORY trees config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(test_backend_registry test/test_backend_registry.cpp)
  target_link_libraries(test_backend_registry infrared_grasp_bt_nodes)

  ament_add_gtest(test_select_next_hypothesis test/test_select_next_hypothesis.cpp)
  target_link_libraries(test_select_next_hypothesis infrared_grasp_bt_nodes)

  ament_add_gtest(test_trial_logger test/test_trial_logger.cpp)
  target_link_libraries(test_trial_logger infrared_grasp_bt_nodes)

  ament_add_gtest(test_bt_contracts test/test_bt_contracts.cpp)
  target_link_libraries(test_bt_contracts infrared_grasp_bt_nodes)
  target_compile_definitions(test_bt_contracts PRIVATE
    INFRARED_GRASP_BT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
  )
endif()

ament_package()
