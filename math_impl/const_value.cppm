/**
 * @file const_value.cppm
 * @brief 数学常用常量
 */

module;

#include <numbers>

#ifndef RMDEV_FLOAT_EQU_DEFAULT_ERROR_VALUE

/// 默认的浮点数等于比较误差值（当两个浮点数的绝对值之差小于这个值时，认为二者相等）
/// @note 这个值可以通过编译参数定义宏 RMDEV_FLOAT_EQU_DEFAULT_ERROR_VALUE 来修改。
///       如果没有定义，则使用默认值 0.001f
#define RMDEV_FLOAT_EQU_DEFAULT_ERROR_VALUE 0.001f

#endif

export module rmdev.math:constantValue;

export namespace rmdev::num {

namespace internal {

/// rmdev 中，默认的浮点数等于比较误差值
constexpr auto float_equ_default_error_value = RMDEV_FLOAT_EQU_DEFAULT_ERROR_VALUE;

}  // namespace internal

constexpr auto e = std::numbers::e;                   ///< e
constexpr auto log2_e = std::numbers::log2e;          ///< log2(e)
constexpr auto lge = std::numbers::log10e;            ///< log10(e)
constexpr auto ln2 = std::numbers::ln2;               ///< ln(2)
constexpr auto ln10 = std::numbers::ln10;             ///< ln(10)
constexpr auto pi = std::numbers::pi;                 ///< pi
constexpr auto pi_inv2 = 1.57079632679489661923;      ///< pi/2
constexpr auto pi_inv4 = 0.785398163397448309616;     ///< pi/4
constexpr auto invPi = std::numbers::inv_pi;          ///< 1/pi
constexpr auto invPi_2 = 0.636619772367581343076;     ///< 2/pi
constexpr auto invSqrtPi_2 = 1.12837916709551257390;  ///< 2/sqrt(pi)
constexpr auto sqrt2 = std::numbers::sqrt2;           ///< sqrt(2)
constexpr auto invSqrt2 = 0.707106781186547524401;    ///< 1/sqrt(2)

}  // namespace rmdev::num
