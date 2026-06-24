/**
 * @file matrix.hpp
 * @brief
 */

#pragma once
#ifndef RMDEV_MATRIX_HPP
    #define RMDEV_MATRIX_HPP

    #include "rmdev/matrix/matrix_base.hpp"

    #ifdef RMDEV_USE_CMSIS_DSP
        #include "matrix/detail/arm_matrix.hpp"
namespace rmdev {

template<typename Type, std::size_t row, std::size_t col>
    requires emdevif::ArithmeticType<Type>
using Matrix = rmdev::ArmMatrix<Type, row, col>;

}  // namespace rmdev

    #endif  // RMDEV_USE_CMSIS_DSP

#endif      // !RMDEV_MATRIX_HPP
