#pragma once
#include <ISensorDriver.h>

/**
 * @file ThermistorDriver.h
 * @class ThermistorDriver
 * @brief Treiber zur Temperaturmessung über einen Thermistor
 * 
 * Der ThermistorDriver implementiert das ISensorDriver-Interface und ermöglicht
 * die Erfassung von Temperaturwerten über einen analogen Thermistor.
 * 
 * Der Treiber liest Rohwerte vom ADC und wandelt diese in eine Temperatur
 * in Grad Celsius um.
 * 
 * Die Klasse kapselt den direkten Hardwarezugriff sowie die Umrechnung
 * der Messwerte und stellt diese in standardisierter Form bereit.
 */
class ThermistorDriver : public ISensorDriver
{
    private:

        /**
         * @brief Liest den Rohwert vom analogen Eingang
         * 
         * @return ADC-Rohwert
         */
        int readRawValue();

        /**
         * @brief Wandelt einen ADC-Rohwert in eine Temperatur um
         * 
         * @param rawValue ADC-Rohwert
         * @return Temperatur in Grad Celsius
         */
        float convertRawValueToTemperature(int rawValue);
    
    public:

        /**
         * @brief Konstruktor
         */
        ThermistorDriver() = default;

        /**
         * @brief Initialisiert den Thermistor
         * 
         * Konfiguriert den zugehörigen analogen Eingang.
         */
        void init() override;

        /**
         * @brief Liefert die aktuell gemessene Temperatur
         * 
         * Führt eine Messung durch und gibt die berechnete Temperatur zurück.
         * 
         * @return Temperatur in Grad Celsius
         */
        float getValue() override;
};