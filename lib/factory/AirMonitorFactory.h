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

/**
 * @file AirMonitorFactory.h
 * @class AirMonitorFactory
 * @brief Factory zur Erstellung und Verdrahtung des Luftüberwachungssystems
 *
 * Die AirMonitorFactory erzeugt die konkreten Hardwarekomponenten des
 * Luftüberwachungssystems und verdrahtet diese mit dem
 * AirMonitorController.
 *
 * Die Factory kapselt die konkrete Hardwarekonfiguration und trennt
 * den Systemaufbau bewusst von der fachlichen Logik.
 *
 * Verantwortlichkeiten:
 * - Erzeugung konkreter Hardware-Treiber
 * - Konfiguration hardwareabhängiger Komponenten
 * - Verdrahtung des vollständigen Systems
 * - Bereitstellung eines fertig initialisierten
 *   AirMonitorController-Objekts
 *
 * @note Durch die Nutzung einer Factory bleibt der
 * AirMonitorController hardwareunabhängig und testbar.
 */
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
        /**
         * @brief Liefert den verdrahteten AirMonitorController
         *
         * @return Referenz auf den vollständig aufgebauten
         * AirMonitorController
         */
        AirMonitorController& getAirMonitorController();
};