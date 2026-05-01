#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

/**
 * @file COSensor.h
 * @class COSensor
 * @brief Kapselt die Verarbeitung von CO-Messwerten
 * 
 * Der COSensor verwendet einen Sensor-Treiber, um Rohwerte von der
 * Hardware zu lesen, und speichert den aktuell gemessenen CO-Wert.
 * 
 * Die Klasse trennt die Sensorlogik (Lesen und Bereitstellen des Werts)
 * vom eigentlichen Hardwarezugriff, der durch den ISensorDriver abstrahiert wird.
 */
class COSensor
{
    private:

        /**
         * @brief Aktuell gespeicherter CO-Wert
         */
        float currentCO = SensorConstants::CO_NOT_INITIALIZED;

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
        COSensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}

        /**
         * @brief Liest den aktuellen CO-Wert vom Sensor
         * 
         * Ruft den Sensor-Treiber auf, um einen neuen Messwert zu erhalten,
         * und speichert diesen intern.
         */
        void readCO();

        /**
         * @brief Gibt den zuletzt gemessenen CO-Wert zurück
         * 
         * @return CO-Konzentration in ppm
         */
        float getCO() const;
};