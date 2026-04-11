#include "DisplayController.h"
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

static void formatLine(float value, signed char width, unsigned char precision, char* bufferValue, char* bufferLine, size_t bufferLineSize, const char* formatText)
{
    dtostrf(value, width, precision, bufferValue);
    snprintf(bufferLine, bufferLineSize, formatText, bufferValue);
}

void DisplayController::updateDisplay(const Measurements& measurements, SystemState systemState)
{
    // TODO: char Größen optimieren
    char temperature[10];
    char temperatureLine[20];

    char humidity[10];
    char humidityLine[20];

    char co[10];
    char coLine[20];

    char statusLine[20];

    formatLine(measurements.temperature, 6, 1, temperature, temperatureLine, sizeof(temperatureLine), "T: %s C");
    formatLine(measurements.humidity, 5, 0, humidity, humidityLine, sizeof(humidityLine), "F: %s %%");
    formatLine(measurements.co, 4, 0, co, coLine, sizeof(coLine), "CO: %s ppm");
    snprintf(statusLine, sizeof(statusLine), "Status: %s", convertSystemStateToString(systemState));

    displayOutput.clear();
    displayOutput.writeLine(0, temperatureLine);
    displayOutput.writeLine(1, humidityLine);
    displayOutput.writeLine(2, coLine);
    displayOutput.writeLine(3, statusLine);
    displayOutput.display();
}