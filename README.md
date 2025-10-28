# rmdev_math

属于 [rmdev](https://github.com/CQUT-RoboMaster-ShiJi-DREAMER-ECU-Team/rmdev.git) 的一个子模块，包含数学运算库。

## 配置

* CMake 变量 `RMDEV_MATH_USE_CMSIS_DSP`: 是否使用 CMSIS-DSP 库。启用了后，依赖 `CMSISDSP`。默认值是 `ON`。
* 宏 `RMDEV_FLOAT_EQU_DEFAULT_ERROR_VALUE`: 默认的浮点数等于比较误差值（当两个浮点数的绝对值之差小于这个值时，认为二者相等），默认值是
  `0.001f`。
