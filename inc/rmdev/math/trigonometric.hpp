/**
 * @file trigonometric.hpp
 * @brief 三角学相关函数
 */

#pragma once

#include "rmdev/math/const_value.hpp"

    #include <cmath>

    #include <utility>
    #include <tuple>

    #ifdef RMDEV_USE_CMSIS_DSP
        #include "arm_math.h"
    #endif

    #include "emdevif/core/concepts.hpp"
namespace rmdev {

/**
 * 角度转弧度
 * @tparam Type: 数据类型
 * @param angle: 角度值
 * @return 弧度值
 */
template<emdevif::ArithmeticType Type>
constexpr float angleToRad(const Type angle) noexcept
{
    return angle * Type(num::pi) / Type(180);
}

/**
 * 弧度转角度
 * @tparam Type: 数据类型
 * @param rad: 弧度值
 * @return 角度值
 */
template<emdevif::ArithmeticType Type>
constexpr float radToAngle(const Type rad) noexcept
{
    return rad * Type(180) / Type(num::pi);
}

/**
 * 计算正弦值
 * @tparam Type 数据类型
 * @param x 弧度
 * @return 计算结果
 */
template<emdevif::ArithmeticType Type>
Type sin(const Type x)
{
#ifdef RMDEV_USE_CMSIS_DSP
    if constexpr (std::is_same_v<Type, float32_t>) {
        return arm_sin_f32(x);
    }
    else if constexpr (std::is_same_v<Type, q31_t>) {
        return arm_sin_q31(x);
    }
    else if constexpr (std::is_same_v<Type, q15_t>) {
        return arm_sin_q15(x);
    }
    else {
        return std::sin(x);
    }
#else
    return std::sin(x);
#endif
}

/**
 * 计算余弦值
 * @tparam Type 数据类型
 * @param x 弧度
 * @return 计算结果
 */
template<emdevif::ArithmeticType Type>
Type cos(const Type x) noexcept
{
#ifdef RMDEV_USE_CMSIS_DSP
    if constexpr (std::is_same_v<Type, float32_t>) {
        return arm_cos_f32(x);
    }
    else if constexpr (std::is_same_v<Type, q31_t>) {
        return arm_cos_q31(x);
    }
    else if constexpr (std::is_same_v<Type, q15_t>) {
        return arm_cos_q15(x);
    }
    else {
        return std::cos(x);
    }
#else
    return std::cos(x);
#endif
}

/**
 * 计算正弦和余弦值
 * @tparam Type 数据类型
 * @param x 弧度制
 * @return 返回一对值，分别为正弦计算结果和余弦计算结果
 */
template<emdevif::ArithmeticType Type>
auto sin_cos(const Type x) noexcept
{
    std::remove_cvref_t<Type> sin_out, cos_out;

#ifdef RMDEV_USE_CMSIS_DSP
    if constexpr (std::is_same_v<Type, float32_t>) {
        arm_sin_cos_f32(x, &sin_out, &cos_out);
    }
    else if constexpr (std::is_same_v<Type, q31_t>) {
        arm_sin_cos_q31(x, &sin_out, &cos_out);
    }
    else {
        sin_out = std::sin(x);
        cos_out = std::cos(x);
    }
#else
    sin_out = std::sin(x);
    cos_out = std::cos(x);
#endif

    return std::make_pair(sin_out, cos_out);
}

/**
 * 计算正弦和余弦值
 * @tparam Type 数据类型
 * @param x 弧度制
 * @param[out] sin_out 正弦计算结果
 * @param[out] cos_out 余弦计算结果
 */
template<emdevif::ArithmeticType Type>
void sin_cos(const Type x, Type& sin_out, Type& cos_out) noexcept
{
    std::tie(sin_out, cos_out) = sin_cos(x);
}

}  // namespace rmdev
