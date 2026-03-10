/**
 * @file math.cppm
 * @brief 数学相关函数
 */

module;

#include <cstddef>
#include <cmath>

#include <numbers>
#include <algorithm>
#include <utility>
#include <tuple>

#ifdef RMDEV_USE_CMSIS_DSP
    #include "arm_math.h"
#endif

#define EMDEVIF_MODULE_INTERFACE_UNIT

export module rmdev.math;

import emdevif.core.concepts;

#ifdef __clang__
    #pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
#endif

#include "rmdev/math.hpp"
