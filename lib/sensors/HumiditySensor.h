#pragma once
#include <CommonSensorConstants.h>
#include <ISht31SensorDriver.h>

/**
 * @file HumiditySensor.h
 * @class HumiditySensor
 * @brief Kapselt die Verarbeitung von Feuchtigkeitsmesswerten
 * 
 * Der HumiditySensor verwendet einen Sensor-Treiber, um Rohwerte von der
 * Hardware zu lesen, und speichert den aktuell gemessenen Feuchtigkeitswert.
 * 
 * Die Klasse trennt die Sensorlogik (Lesen und Bereitstellen des Werts)
 * vom eigentlichen Hardwarezugriff, der durch den ISht31SensorDriver abstrahiert wird.
 */
class HumiditySensor
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
        HumiditySensor(ISht31SensorDriver& sht31SensorDriver) : sht31SensorDriver(sht31SensorDriver) {}

        /**
         * @brief Gibt den zuletzt gemessenen Feuchtigkeitswert zurück
         * 
         * @return Luftfeuchtigkeit in Prozent
         */
        Humidity getHumidity() const;
};