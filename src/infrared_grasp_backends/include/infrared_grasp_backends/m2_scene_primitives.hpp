#pragma once

#include <cstddef>
#include <vector>

#include "infrared_grasp_interfaces/msg/geometry_hypothesis.hpp"

namespace infrared_grasp_backends
{

using GeometryHypothesis = infrared_grasp_interfaces::msg::GeometryHypothesis;

std::vector<GeometryHypothesis> make_m2_mask_extrusion_hypotheses(std::size_t max_hypotheses);

}  // namespace infrared_grasp_backends
