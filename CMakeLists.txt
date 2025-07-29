cmake_minimum_required(VERSION 3.28)

project(rmdev_math CXX)

option(RMDEV_MATH_USE_CMSIS_DSP "Will link CMSIS-DSP to rmdev_math" ON)
option(RMDEV_MATH_CMSIS_DSP_USE_STM32CUBEMX "Will use stm32cubemx generated CMSIS-DSP lib" ON)

add_library(${PROJECT_NAME} OBJECT)

target_link_libraries(${PROJECT_NAME} PUBLIC emdevif_core)

file(GLOB RMDEV_MATH_IMPL_MODULES "math_impl/*.cppm")
target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET rmdev_math_modules TYPE CXX_MODULES FILES
        math.cppm
        ${RMDEV_MATH_IMPL_MODULES}
)

include("cmake/config_use_cmsis_dsp.cmake")

if (RMDEV_MATH_USE_CMSIS_DSP)
    enable_language(C)
    linkCmsisDsp(${PROJECT_NAME} RMDEV_MATH_CMSIS_DSP_USE_STM32CUBEMX)
    target_compile_definitions(${PROJECT_NAME} PUBLIC RMDEV_USE_CMSIS_DSP=1)
endif ()

# ============================================================================
# For matrix

target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET rmdev_matrix_modules TYPE CXX_MODULES FILES
        matrix/Matrix.cppm
        matrix/MatrixType.cppm
)

if (RMDEV_MATH_USE_CMSIS_DSP)
    target_sources(${PROJECT_NAME} PUBLIC
        FILE_SET rmdev__arm_matrix_modules TYPE CXX_MODULES FILES
            matrix/ArmMatrix/ArmMatrix.cppm
            matrix/ArmMatrix/ArmMatrix_interface.cppm
            matrix/ArmMatrix/ArmMatrix_implements.cppm
            matrix/ArmMatrix/ArmMatrix_traits.cppm
    )
endif ()
