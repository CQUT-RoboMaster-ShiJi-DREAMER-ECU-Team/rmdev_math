/**
 * @file matrix_base.hpp
 * @brief 矩阵基本声明
 */

#pragma once

#include <cstdint>

#include <algorithm>
#include <span>

namespace rmdev {

/**
 * 特殊矩阵标签
 */
enum class SpecialMatrixTag : uint8_t {
    Normal = 0U,  ///< 普通矩阵
    E,            ///< 单位矩阵（必须是方阵才有意义，否则无效）
    One,          ///< 每个元素全是 1 的矩阵
    Zero          ///< 每个元素全是 0 的矩阵
};  // todo 可以考虑实现：上、下三角矩阵

/**
 * 通过特殊矩阵标签初始化矩阵
 * @tparam Type 类型
 * @param[out] data 矩阵数据
 * @param row 行数
 * @param col 列数
 * @param tag 特殊矩阵标签
 */
template<typename Type>
constexpr void initSpecialMatrix(std::span<Type> data,
                                 const std::size_t row,
                                 const std::size_t col,
                                 const SpecialMatrixTag tag) noexcept
{
    if (row == col) {
        switch (tag) {
        case SpecialMatrixTag::E:
            for (std::size_t i = 0; i < row; ++i) {
                data[i * col + i] = static_cast<Type>(1);
            }
            break;
        case SpecialMatrixTag::One:
            std::ranges::fill(data, static_cast<Type>(1));
            break;
        default:
            break;
        }
    }
    else {
        switch (tag) {
        case SpecialMatrixTag::One:
            std::ranges::fill(data, static_cast<Type>(1));
            break;
        default:
            break;
        }
    }
}

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
