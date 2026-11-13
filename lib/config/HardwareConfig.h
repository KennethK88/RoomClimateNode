#pragma once

/**
 * @file HardwareConfig.h
 * @brief Selects the hardware configuration for the target ESP32 platform.
 *
 * Includes the appropriate hardware configuration based on the ESP-IDF
 * target definitions.
 *
 * Supported platforms:
 * - ESP32 (LOLIN D32)
 * - ESP32-C3 (LOLIN C3 Pico)
 *
 * Compilation fails if multiple or unsupported target platforms are defined.
 */

#if defined(CONFIG_IDF_TARGET_ESP32) && defined(CONFIG_IDF_TARGET_ESP32C3)
    #error "Multiple hardware platforms defined"
#elif defined(CONFIG_IDF_TARGET_ESP32)
    #include "HardwareConfigD32.h"
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
    #include "HardwareConfigC3Pico.h"
#else
    #error "Unsupported hardware platform"
#endif