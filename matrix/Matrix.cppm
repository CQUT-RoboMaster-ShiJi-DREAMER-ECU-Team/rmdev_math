/**
 * @file Matrix.cppm
 * @author 杜以成
 * @date 2025-06-02
 * @brief 矩阵运算
 */

module;

#include "emdevif/concepts.hpp"

export module rmdev.matrix;

export import rmdev.matrixType;

#ifdef RMDEV_USE_CMSIS_DSP

export import rmdev.armMatrix;

export namespace rmdev {

template<typename Type, std::size_t row, std::size_t col>
    requires emdevif::ArithmeticType<Type>
using Matrix = rmdev::ArmMatrix<Type, row, col>;

}  // namespace rmdev

#endif  // RMDEV_USE_CMSIS_DSP
