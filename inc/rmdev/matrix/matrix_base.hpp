/**
 * @file matrix_base.hpp
 * @brief 矩阵基本声明
 */

#pragma once

#include "emdevif/core/detail/config.hpp"

#ifndef EMDEVIF_MODULE_INTERFACE_UNIT
    #include <cstdint>
#endif

EMDEVIF_MODULE_EXPORT
namespace rmdev {

/**
 * 特殊矩阵类型
 */
enum class MatrixBase : uint8_t {
    Normal = 0U,  ///< 普通矩阵
    E,            ///< 单位矩阵（必须是方阵才有意义，否则无效）
    One,          ///< 每个元素全是 1 的矩阵
    Zero          ///< 每个元素全是 0 的矩阵
};  // todo 可以考虑实现：上、下三角矩阵

/**
 * 矩阵可以相乘的概念
 * @tparam row1 乘号左边的矩阵的行数
 * @tparam col1 乘号左边的矩阵的列数
 * @tparam row2 乘号右边的矩阵的行数
 * @tparam col2 乘号右边的矩阵的列数
 */
template<std::size_t row1, std::size_t col1, std::size_t row2, std::size_t col2>
concept MatrixCouldMultiplied = (col1 == row2);

/**
 * 方阵概念
 * @tparam row 矩阵的行数
 * @tparam col 矩阵的列数
 */
template<std::size_t row, std::size_t col>
concept SquareMatrix = (row == col);

}  // namespace rmdev
