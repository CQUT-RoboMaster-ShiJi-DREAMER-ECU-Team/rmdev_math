/**
 * @file Matrix.cppm
 * @brief 矩阵运算
 */

module;

#include <cstddef>
#include <cstdint>
#include <cstring>

#include <initializer_list>
#include <array>
#include <type_traits>

#include "arm_math.h"

#define EMDEVIF_MODULE_INTERFACE_UNIT

export module rmdev.matrix;

import emdevif.core.concepts;
import rmdev.math;

#ifdef __clang__
    #pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
#endif

#include "rmdev/matrix.hpp"
