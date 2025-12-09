/**
 * @file Matrix.cppm
 * @brief 矩阵运算
 */

module;

#include <cstddef>

export module rmdev.matrix;

export import rmdev.matrixBase;
import emdevif.concepts;

#ifdef RMDEV_USE_CMSIS_DSP

export import rmdev.armMatrix;

export namespace rmdev {

template<typename Type, std::size_t row, std::size_t col>
    requires emdevif::ArithmeticType<Type>
using Matrix = rmdev::ArmMatrix<Type, row, col>;

}  // namespace rmdev

#endif  // RMDEV_USE_CMSIS_DSP
