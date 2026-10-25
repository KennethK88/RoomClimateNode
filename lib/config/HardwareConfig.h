#pragma once
#if defined(CONFIG_IDF_TARGET_ESP32) && defined(CONFIG_IDF_TARGET_ESP32C3)
    #error "Multiple hardware platforms defined"
#elif defined(CONFIG_IDF_TARGET_ESP32)
    #include "HardwareConfigD32.h"
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
    #include "HardwareConfigC3Pico.h"
#else
    #error "Unsupported hardware platform"
#endif