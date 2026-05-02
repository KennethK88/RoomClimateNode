#pragma once
#include <DHT.h>
#include "utils/HardwareConfig.h"
#include <ISensorDriver.h>

/**
 * @file HumidityDriver.h
 * @class HumidityDriver
 * @brief Treiber zur Messung der Luftfeuchtigkeit über einen DHT-Sensor
 * 
 * Der HumidityDriver implementiert das ISensorDriver-Interface und nutzt
 * die DHT-Bibliothek zur Erfassung der relativen Luftfeuchtigkeit.
 * 
 * Die Klasse kapselt den Zugriff auf die externe DHT-Library sowie die
 * zugehörige Hardwarekonfiguration und stellt den Messwert in einheitlicher
 * Form bereit.
 */
class HumidityDriver : public ISensorDriver
{
    private:

        /**
         * @brief Instanz des DHT-Sensors
         * 
         * Initialisiert mit den in HardwareConfig definierten Parametern.
         */   
        DHT dht{HardwareConfig::HUMIDITY_DRIVER_PIN, HardwareConfig::HUMIDITY_DRIVER_TYPE};

    public:

        /**
         * @brief Konstruktor
         */
        HumidityDriver() = default;

        /**
         * @brief Initialisiert den DHT-Sensor
         * 
         * Führt die notwendige Initialisierung der DHT-Bibliothek durch.
         */
        void init() override;

        /**
         * @brief Liefert die aktuell gemessene Luftfeuchtigkeit
         * 
         * Führt eine Messung über die DHT-Library durch.
         * 
         * @return Luftfeuchtigkeit in Prozent
         * 
         * @note Kann bei fehlerhafter Messung NaN zurückgeben
         */
        float getValue() override;
};