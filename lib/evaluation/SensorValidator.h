#pragma once
#include <CommonSensorConstants.h>
#include <Measurements.h>
#include <ValidationResults.h>

/**
 * @file SensorValidator.h
 * @class SensorValidator
 * @brief Validiert Sensormesswerte auf Plausibilität
 * 
 * Der SensorValidator überprüft die Messwerte aller Sensoren anhand
 * definierter Grenzwerte und Regeln und kennzeichnet diese als gültig
 * oder ungültig.
 * 
 * Ziel ist es, fehlerhafte, nicht initialisierte oder physikalisch
 * unplausible Werte frühzeitig zu erkennen und für nachgelagerte
 * Komponenten transparent zu machen.
 */
class SensorValidator
{
    private:

        /**
         * @brief Validiert den Temperaturwert
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Ergebnisstruktur zur Speicherung des Validierungsstatus
         */
        void validateTemperature(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validiert den Feuchtigkeitswert
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Ergebnisstruktur zur Speicherung des Validierungsstatus
         */       
        void validateHumidity(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validiert den CO-Wert
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Ergebnisstruktur zur Speicherung des Validierungsstatus
         */
        void validateCo(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validiert den Distanzwert
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Ergebnisstruktur zur Speicherung des Validierungsstatus
         * 
         * @note Ein Distanzwert von 0 wird als "kein Objekt erkannt" interpretiert
         * und kann dennoch als gültig betrachtet werden.
         */
        void validateDistance(const Measurements& measurements, ValidationResults& validationResults);

    public:

        /**
         * @brief Konstruktor
         */
        SensorValidator() = default;

        /**
         * @brief Validiert alle Sensormesswerte
         * 
         * Führt die Validierung für alle Sensoren durch und fasst die
         * Ergebnisse in einer gemeinsamen Struktur zusammen.
         * 
         * @param measurements Aktuelle Sensordaten
         * @return Struktur mit Validierungsstatus aller Sensoren
         */
        ValidationResults validateAllSensors(const Measurements& measurements);
};