#pragma once
#include <CommonSensorConstants.h>
#include <ISht31SensorDriver.h>

/**
 * @file TemperatureSensor.h
 * @class TemperatureSensor
 * @brief Kapselt die Verarbeitung von Temperaturmesswerten
 * 
 * Der TemperatureSensor verwendet einen Sensor-Treiber, um Rohwerte von der
 * Hardware zu lesen, und speichert den aktuell gemessenen Temperaturwert.
 * 
 * Die Klasse trennt die Sensorlogik (Lesen und Bereitstellen des Werts)
 * vom eigentlichen Hardwarezugriff, der durch den ISht31SensorDriver abstrahiert wird.
 */
class TemperatureSensor
{
    private:
        /**
         * @brief Referenz auf den zugehörigen Sensor-Treiber
         */
        ISht31SensorDriver& sht31SensorDriver;

    public:

        /**
         * @brief Konstruktor
         * 
         * @param sht31SensorDriver Referenz auf den Sensor-Treiber zur Messwertgewinnung
         */
        TemperatureSensor(ISht31SensorDriver& sht31SensorDriver) : sht31SensorDriver(sht31SensorDriver) {}

        /**
         * @brief Gibt den zuletzt gemessenen Temperaturwert zurück
         * 
         * @return Temperatur in Grad Celsius
         */
        Temperature getTemperature() const;
};