#pragma once
#include <Types.h>

/**
 * @file ISht31SensorDriver.h
 * @brief Schnittstelle für SHT31-kompatible Sensor-Treiber.
 */

/**
 * @class ISht31SensorDriver
 * @brief Abstrakte Schnittstelle zur Messwerterfassung von Temperatur und Luftfeuchtigkeit.
 *
 * Diese Schnittstelle entkoppelt die fachlichen Sensorkomponenten vom
 * konkreten Hardwaretreiber. Implementierungen übernehmen die Initialisierung,
 * das Auslesen des Sensors und die Bereitstellung der zuletzt ermittelten
 * Temperatur- und Luftfeuchtigkeitswerte.
 */
class ISht31SensorDriver
{
    public:

        /**
         * @brief Virtueller Destruktor für polymorphe Verwendung.
         */
        virtual ~ISht31SensorDriver() = default;

        /**
         * @brief Initialisiert den Sensor-Treiber.
         */
        virtual void init() = 0;

        /**
         * @brief Führt eine Messung durch und aktualisiert die intern gespeicherten Messwerte.
         */
        virtual void readMeasurements() = 0;

        /**
         * @brief Gibt den zuletzt ermittelten Temperaturwert zurück.
         *
         * @return Temperaturwert in °C.
         */
        virtual Temperature getTemperature() = 0;

        /**
         * @brief Gibt den zuletzt ermittelten Luftfeuchtigkeitswert zurück.
         *
         * @return Relative Luftfeuchtigkeit in %.
         */
        virtual Humidity getHumidity() = 0;
};