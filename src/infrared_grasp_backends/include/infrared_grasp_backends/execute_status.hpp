#pragma once

#include <cstdint>

namespace infrared_grasp_backends
{

constexpr std::uint8_t kExecuteStatusSucceeded = 1;
constexpr std::uint8_t kExecuteStatusFailed = 2;
constexpr std::uint8_t kExecuteStatusTimeout = 3;
constexpr std::uint8_t kExecuteStatusCanceled = 4;

}  // namespace infrared_grasp_backends
