#[[
链接 CMSIS-DSP 库

:param target_name: 要链接 CMSIS-DSP 库的目标名称
:param is_use_stm32cubemx: 是否使用 STM32CUBEMX 生成的 CMSIS-DSP 库
]]
macro(linkCmsisDsp target_name is_use_stm32cubemx)
    if (${is_use_stm32cubemx})
        if (NOT EMDEVIF_USE_STM32CUBEMX)
            message(FATAL_ERROR "Let ${target_name} to use stm32cubemx requires to set EMDEVIF_USE_STM32CUBEMX equal to ON")
        endif ()

        target_link_libraries(${target_name} PUBLIC emdevif_stm32cubemx_support)
    else ()
        target_link_libraries(${target_name} PUBLIC rmdev_cmsis_dsp_support)
    endif ()
endmacro()
