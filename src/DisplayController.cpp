#include "DisplayController.h"
#include <iostream> // TODO: iostream entfernen, wenn Schnittstellen in updateDisplay() ersetzt wurden

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
    std::cout << measurements.temperature << " °C\n";
    std::cout << measurements.humidity << " %\n";
    std::cout << measurements.co << " ppm\n";
    std::cout << convertSystemStateToString(systemState) << "\n";
}