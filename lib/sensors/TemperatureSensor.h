#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

/**
 * @file TemperatureSensor.h
 * @class TemperatureSensor
 * @brief Kapselt die Verarbeitung von Temperaturmesswerten
 * 
 * Der TemperatureSensor verwendet einen Sensor-Treiber, um Rohwerte von der
 * Hardware zu lesen, und speichert den aktuell gemessenen Temperaturwert.
 * 
 * Die Klasse trennt die Sensorlogik (Lesen und Bereitstellen des Werts)
 * vom eigentlichen Hardwarezugriff, der durch den ISensorDriver abstrahiert wird.
 */
class TemperatureSensor
{
    private:

        /**
         * @brief Aktuell gespeicherter Temperaturwert
         */
        float currentTemperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;

        /**
         * @brief Referenz auf den zugehörigen Sensor-Treiber
         */
        ISensorDriver& sensorDriver;

    public:

        /**
         * @brief Konstruktor
         * 
         * @param sensorDriver Referenz auf den Sensor-Treiber zur Messwertgewinnung
         */
        TemperatureSensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}

        /**
         * @brief Liest die aktuelle Temperatur vom Sensor
         * 
         * Ruft den Sensor-Treiber auf, um einen neuen Messwert zu erhalten,
         * und speichert diesen intern.
         */
        void readTemperature();

        /**
         * @brief Gibt den zuletzt gemessenen Temperaturwert zurück
         * 
         * @return Temperatur in Grad Celsius
         */
        float getTemperature() const;
};