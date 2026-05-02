#pragma once
#include <CommonSensorConstants.h>
#include <ISensorDriver.h>

/**
 * @file DistanceSensor.h
 * @class DistanceSensor
 * @brief Kapselt die Verarbeitung von Distanzmesswerten
 * 
 * Der DistanceSensor verwendet einen Sensor-Treiber, um Rohwerte von der
 * Hardware zu lesen, und speichert die aktuell gemessene Distanz.
 * 
 * Die Klasse trennt die Sensorlogik (Lesen und Bereitstellen des Werts)
 * vom eigentlichen Hardwarezugriff, der durch den ISensorDriver abstrahiert wird.
 * 
 * @note Ein Distanzwert von 0 wird als "kein Objekt erkannt" interpretiert.
 */
class DistanceSensor
{
    private:

        /**
         * @brief Aktuell gespeicherter Distanzwert
         */
        float currentDistance = SensorConstants::DISTANCE_NOT_INITIALIZED;

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
        DistanceSensor(ISensorDriver& sensorDriver) : sensorDriver(sensorDriver) {}

        /**
         * @brief Liest die aktuelle Distanz vom Sensor
         * 
         * Ruft den Sensor-Treiber auf, um einen neuen Messwert zu erhalten,
         * und speichert diesen intern.
         */
        void readDistance();

        /**
         * @brief Gibt die zuletzt gemessene Distanz zurück
         * 
         * @return Distanz in Zentimetern
         * 
         * @note Ein Rückgabewert von 0 bedeutet, dass kein Objekt erkannt wurde.
         */
        float getDistance() const;
};