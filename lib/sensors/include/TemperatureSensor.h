#pragma once
#include "ISht31SensorDriver.h"

/**
 * @file TemperatureSensor.h
 * @brief Fachliche Sensorkomponente für die Temperatur.
 */

/**
 * @class TemperatureSensor
 * @brief Stellt den aktuellen Temperaturwert bereit.
 *
 * Der TemperatureSensor kapselt den fachlichen Zugriff auf den Temperaturwert.
 * Der konkrete Hardwarezugriff erfolgt über die ISht31SensorDriver-Schnittstelle
 * und bleibt dadurch von dieser Klasse entkoppelt.
 *
 * Die eigentliche Messung wird vom Sensor-Treiber durchgeführt. Diese Klasse
 * fragt den zuletzt vom Treiber ermittelten Temperaturwert ab.
 */
class TemperatureSensor
{
    private:
        /**
         * @brief Referenz auf den Sensor-Treiber zur Messwertbereitstellung.
         */
        ISht31SensorDriver& sht31SensorDriver;

    public:

        /**
         * @brief Erstellt einen TemperatureSensor.
         *
         * @param sht31SensorDriver Sensor-Treiber, der den Temperaturwert bereitstellt.
         */
        TemperatureSensor(ISht31SensorDriver& sht31SensorDriver) : sht31SensorDriver(sht31SensorDriver) {}

        /**
         * @brief Gibt den zuletzt ermittelten Temperaturwert zurück.
         *
         * @return Temperaturwert in °C.
         */
        Temperature getTemperature() const;
};