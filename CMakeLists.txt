cmake_minimum_required(VERSION 3.28...4.0.2)

project(rmdev_math CXX)

option(RMDEV_MATH_USE_CMSIS_DSP "Will link CMSIS-DSP to rmdev_math" ON)

if (EMDEVIF_USE_CPP_MODULES)
    add_library(${PROJECT_NAME} STATIC)

    target_link_libraries(${PROJECT_NAME}
        PUBLIC emdevif_core
        PRIVATE emdevif_compile_options
    )

    target_include_directories(${PROJECT_NAME} PUBLIC inc)
    target_sources(${PROJECT_NAME} PUBLIC FILE_SET rmdev_math_modules
        TYPE CXX_MODULES FILES math.cppm
    )
else ()
    add_library(${PROJECT_NAME} INTERFACE)
    target_link_libraries(${PROJECT_NAME} INTERFACE emdevif_core
        emdevif_compile_options
    )
    target_include_directories(${PROJECT_NAME} INTERFACE inc)
endif ()

if (RMDEV_MATH_USE_CMSIS_DSP)
    enable_language(C)

    if (EMDEVIF_USE_CPP_MODULES)
        target_link_libraries(${PROJECT_NAME} PUBLIC CMSISDSP)
        target_compile_definitions(${PROJECT_NAME} PUBLIC RMDEV_USE_CMSIS_DSP=1)

        target_sources(${PROJECT_NAME} PUBLIC
            FILE_SET rmdev_matrix_modules TYPE CXX_MODULES FILES Matrix.cppm
        )
    else ()
        target_link_libraries(${PROJECT_NAME} INTERFACE CMSISDSP)
        target_compile_definitions(${PROJECT_NAME} INTERFACE RMDEV_USE_CMSIS_DSP=1)
    endif ()
endif ()
