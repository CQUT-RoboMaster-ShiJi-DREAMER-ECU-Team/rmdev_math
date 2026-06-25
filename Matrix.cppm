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
#include "rmdev/matrix.hpp"

export module rmdev.matrix;

export namespace rmdev {
using ::rmdev::MatrixBase;
using ::rmdev::MatrixCouldMultiplied;
using ::rmdev::SquareMatrix;
}  // namespace rmdev

#ifdef RMDEV_USE_CMSIS_DSP
export namespace rmdev {
using ::rmdev::ArmMatrix;
using ::rmdev::Matrix;
}  // namespace rmdev
#endif
