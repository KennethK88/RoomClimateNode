#pragma once
#include <ThermistorDriver.h>
#include <HumidityDriver.h>
#include <CODriver.h>
#include <DistanceDriver.h>
#include <BuzzerDriver.h>
#include <LedDriver.h>
#include <OledDriver.h>
#include <HardwareConfig.h>
#include <AirMonitorController.h>

class AirMonitorFactory
{
    private:
        ThermistorDriver thermistorDriver;
        HumidityDriver humidityDriver;
        CODriver coDriver;
        DistanceDriver distanceDriver;
        BuzzerDriver buzzerDriver;
        LedDriver ledDriverNormal{HardwareConfig::LED_NORMAL_DIGITAL_PIN};
        LedDriver ledDriverWarning{HardwareConfig::LED_WARNING_DIGITAL_PIN};
        LedDriver ledDriverError{HardwareConfig::LED_ERROR_DIGITAL_PIN};
        OledDriver oledDriver;
        AirMonitorController airMonitorController{thermistorDriver, humidityDriver, coDriver, distanceDriver, buzzerDriver, ledDriverNormal, ledDriverWarning, ledDriverError, oledDriver};

    public:
        AirMonitorController& getAirMonitorController();
};