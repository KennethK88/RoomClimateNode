#pragma once
#include <ISht31SensorDriver.h>

/**
 * @file HumiditySensor.h
 * @brief Fachliche Sensorkomponente für die Luftfeuchtigkeit.
 */

/**
 * @class HumiditySensor
 * @brief Stellt den aktuellen Luftfeuchtigkeitswert bereit.
 *
 * Der HumiditySensor kapselt den fachlichen Zugriff auf den
 * Luftfeuchtigkeitswert. Der konkrete Hardwarezugriff erfolgt über die
 * ISht31SensorDriver-Schnittstelle und bleibt dadurch von dieser Klasse
 * entkoppelt.
 *
 * Die eigentliche Messung wird vom Sensor-Treiber durchgeführt. Diese Klasse
 * fragt den zuletzt vom Treiber ermittelten Luftfeuchtigkeitswert ab.
 */
class HumiditySensor
{
    private:
        /**
         * @brief Referenz auf den Sensor-Treiber zur Messwertbereitstellung.
         */
        ISht31SensorDriver& sht31SensorDriver;

    public:

        /**
         * @brief Erstellt einen HumiditySensor.
         *
         * @param sht31SensorDriver Sensor-Treiber, der den Luftfeuchtigkeitswert bereitstellt.
         */
        HumiditySensor(ISht31SensorDriver& sht31SensorDriver) : sht31SensorDriver(sht31SensorDriver) {}

        /**
         * @brief Gibt den zuletzt ermittelten Luftfeuchtigkeitswert zurück.
         *
         * @return Relative Luftfeuchtigkeit in %.
         */
        Humidity getHumidity() const;
};