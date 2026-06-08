#pragma once
#include <ThermistorDriver.h>
#include <HumidityDriver.h>
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
        AirMonitorController airMonitorController{thermistorDriver, humidityDriver};

    public:
        /**
         * @brief Liefert den verdrahteten AirMonitorController
         *
         * @return Referenz auf den vollständig aufgebauten
         * AirMonitorController
         */
        AirMonitorController& getAirMonitorController();
};