#include "DisplayController.h"
#include <iostream> // TODO: iostream entfernen, wenn Schnittstellen in updateDisplay() ersetzt wurden
#include <Arduino.h>

static const char* convertSystemStateToString(SystemState systemState)
{
    switch(systemState)
    {
        case SystemState::Normal:
            return "Normal";
        case SystemState::Warning:
            return "Warning";
        case SystemState::Error:
            return "Error";
        default:
            return "Unknown";
    }
}

void DisplayController::updateDisplay(const Measurements& measurements, SystemState systemState)
{
    // TODO: std::cout durch Schnittstellen ersetzen
    Serial.println(measurements.temperature);
    Serial.println(measurements.humidity);
    Serial.println(measurements.co);
    Serial.println(convertSystemStateToString(systemState));
}