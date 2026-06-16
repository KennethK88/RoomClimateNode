#pragma once
#include <CommonSensorConstants.h>
#include <Measurements.h>
#include <ValidationResults.h>

/**
 * @file SensorValidator.h
 * @brief Validiert Messwerte des Raumklima-Knotens.
 */

/**
 * @class SensorValidator
 * @brief Prüft Messwerte auf Initialisierung, Fehlerwerte und plausible Wertebereiche.
 *
 * Der SensorValidator überprüft die erfassten Messwerte anhand definierter
 * Validierungsregeln und kennzeichnet jeden Wert als gültig oder ungültig.
 *
 * Ziel ist es, nicht initialisierte, fehlerhafte oder physikalisch
 * unplausible Messwerte frühzeitig zu erkennen und nachgelagerten Komponenten
 * in strukturierter Form bereitzustellen.
 */
class SensorValidator
{
    private:

        /**
         * @brief Validiert den Temperaturwert.
         *
         * @param measurements Aktuelle Messwerte.
         * @param validationResults Ergebnisstruktur zur Speicherung des Validierungsstatus.
         */
        void validateTemperature(const Measurements& measurements, ValidationResults& validationResults);

        /**
         * @brief Validiert den Luftfeuchtigkeitswert.
         *
         * @param measurements Aktuelle Messwerte.
         * @param validationResults Ergebnisstruktur zur Speicherung des Validierungsstatus.
         */      
        void validateHumidity(const Measurements& measurements, ValidationResults& validationResults);

        void validateBatteryLevel(const Measurements& measurements, ValidationResults& validationResults);

    public:

        /**
         * @brief Validiert alle enthaltenen Messwerte.
         *
         * Führt die Validierung für die im Measurements-Objekt enthaltenen
         * Messwerte durch und fasst die Ergebnisse in einer gemeinsamen
         * Ergebnisstruktur zusammen.
         *
         * @param measurements Aktuelle Messwerte.
         * @return Struktur mit dem Validierungsstatus der Messwerte.
         */
        ValidationResults validateAllSensors(const Measurements& measurements);
};