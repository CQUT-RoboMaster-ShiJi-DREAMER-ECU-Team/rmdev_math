/**
 * @file math.cppm
 * @brief 数学相关函数
 */

module;

#ifdef RMDEV_USE_CMSIS_DSP
    #include "arm_math.h"
#endif

#include "rmdev/math.hpp"

export module rmdev.math;

export namespace rmdev::num {
    using ::rmdev::num::e;
    using ::rmdev::num::log2_e;
    using ::rmdev::num::lge;
    using ::rmdev::num::ln2;
    using ::rmdev::num::ln10;
    using ::rmdev::num::pi;
    using ::rmdev::num::pi_inv2;
    using ::rmdev::num::pi_inv4;
    using ::rmdev::num::invPi;
    using ::rmdev::num::invPi_2;
    using ::rmdev::num::invSqrtPi_2;
    using ::rmdev::num::sqrt2;
    using ::rmdev::num::invSqrt2;
}
export namespace rmdev {
    using ::rmdev::sgn;
    using ::rmdev::weakEqu;
    using ::rmdev::bitUintMax;
    using ::rmdev::integerBits;
    using ::rmdev::limitMinMax;
    using ::rmdev::limitInRange;
    using ::rmdev::angleToRad;
    using ::rmdev::radToAngle;
    using ::rmdev::sin;
    using ::rmdev::cos;
    using ::rmdev::sin_cos;
}
