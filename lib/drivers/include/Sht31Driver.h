#pragma once
#include "ISht31SensorDriver.h"
#include "Types.h"
#include <cstdint>
#include "CommonSensorConstants.h"

/**
 * @file Sht31Driver.h
 * @brief Konkreter Treiber für den SHT31-Temperatur- und Feuchtigkeitssensor.
 */

/**
 * @brief Liest Temperatur- und Luftfeuchtigkeitswerte vom SHT31-Sensor aus.
 *
 * Diese Klasse implementiert die ISht31SensorDriver-Schnittstelle und kapselt
 * die hardwarenahe Kommunikation mit dem SHT31-Sensor. Die Messwerte werden
 * durch readMeasurements() aktualisiert und anschließend zwischengespeichert,
 * sodass sie über getTemperature() und getHumidity() abgefragt werden können.
 */
class Sht31Driver : public ISht31SensorDriver
{
    private:
        uint8_t data[6] = {0};
        Temperature temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
        Humidity humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
        
    public:

        /**
         * @brief Erzeugt einen SHT31-Treiber.
         */
        Sht31Driver() = default;

        /**
         * @brief Initialisiert die Kommunikation mit dem SHT31-Sensor.
         */
        void init() override;

        /**
         * @brief Liest die aktuellen Messwerte vom SHT31-Sensor.
         *
         * Die gelesenen Rohdaten werden in Temperatur und Luftfeuchtigkeit
         * umgerechnet und intern gespeichert.
         */
        void readMeasurements() override;

        /**
         * @brief Gibt den zuletzt gelesenen Temperaturwert zurück.
         *
         * @return Temperaturwert in °C.
         */
        Temperature getTemperature() override;

         /**
         * @brief Gibt den zuletzt gelesenen Luftfeuchtigkeitswert zurück.
         *
         * @return Relative Luftfeuchtigkeit in %.
         */
        Humidity getHumidity() override;
};