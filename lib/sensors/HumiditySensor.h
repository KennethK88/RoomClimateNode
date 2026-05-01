#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

/**
 * @file HumiditySensor.h
 * @class HumiditySensor
 * @brief Kapselt die Verarbeitung von Feuchtigkeitsmesswerten
 * 
 * Der HumiditySensor verwendet einen Sensor-Treiber, um Rohwerte von der
 * Hardware zu lesen, und speichert den aktuell gemessenen Feuchtigkeitswert.
 * 
 * Die Klasse trennt die Sensorlogik (Lesen und Bereitstellen des Werts)
 * vom eigentlichen Hardwarezugriff, der durch den ISensorDriver abstrahiert wird.
 */
class HumiditySensor
{
    private:

        /**
         * @brief Aktuell gespeicherter Feuchtigkeitswert
         */
        float currentHumidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;

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
        HumiditySensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}

        /**
         * @brief Liest die aktuelle Luftfeuchtigkeit vom Sensor
         * 
         * Ruft den Sensor-Treiber auf, um einen neuen Messwert zu erhalten,
         * und speichert diesen intern.
         */
        void readHumidity();

        /**
         * @brief Gibt den zuletzt gemessenen Feuchtigkeitswert zurück
         * 
         * @return Luftfeuchtigkeit in Prozent
         */
        float getHumidity() const;
};