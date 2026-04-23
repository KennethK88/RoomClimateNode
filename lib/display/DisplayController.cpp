#include <DisplayController.h>
#include <cstdio>
#include <cmath>
#include <cstddef>

namespace
{
    constexpr size_t LINE_SIZE = 25;

    const char* convertSystemStateToString(SystemState systemState)
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
}

void DisplayController::updateDisplay(const Measurements& measurements, SystemState systemState)
{
    char temperatureLine[LINE_SIZE];
    char humidityLine[LINE_SIZE];
    char coLine[LINE_SIZE];
    char statusLine[LINE_SIZE];

    std::snprintf(temperatureLine, LINE_SIZE, "T: %d C", static_cast<int>(std::round(measurements.temperature)));
    std::snprintf(humidityLine, LINE_SIZE, "F: %d %%", static_cast<int>(std::round(measurements.humidity)));
    std::snprintf(coLine, LINE_SIZE, "CO: %d ppm", static_cast<int>(std::round(measurements.co)));
    std::snprintf(statusLine, LINE_SIZE, "Status: %s", convertSystemStateToString(systemState));

    displayOutput.clear();
    displayOutput.writeLine(0, temperatureLine);
    displayOutput.writeLine(1, humidityLine);
    displayOutput.writeLine(2, coLine);
    displayOutput.writeLine(3, statusLine);
    displayOutput.display();
}