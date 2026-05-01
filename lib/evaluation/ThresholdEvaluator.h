#pragma once
#include <ValidationResults.h>
#include <Measurements.h>
#include <ThresholdResults.h>
#include <CommonSensorConstants.h>

/**
 * @file ThresholdEvaluator.h
 * @class ThresholdEvaluator
 * @brief Bewertet Sensormesswerte anhand definierter Grenzwerte
 * 
 * Der ThresholdEvaluator analysiert gültige Sensormesswerte und prüft,
 * ob diese definierte Grenzwerte überschreiten oder unterschreiten.
 * 
 * Im Gegensatz zur Validierung wird hier nicht die grundsätzliche
 * Plausibilität bewertet, sondern ob ein Messwert als kritisch
 * eingestuft werden muss.
 * 
 * Die Ergebnisse werden in einer separaten Struktur abgelegt und
 * dienen als Grundlage für die spätere Zustandsbestimmung des Systems.
 */
class ThresholdEvaluator
{
    private:

        /**
         * @brief Prüft, ob die Temperatur den oberen Grenzwert überschreitet
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @param thresholdResult Ergebnisstruktur zur Speicherung des Schwellenwertstatus
         */
        void evaluateTemperatureTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);

        /**
         * @brief Prüft, ob die Luftfeuchtigkeit den oberen Grenzwert überschreitet
         *
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @param thresholdResult Ergebnisstruktur zur Speicherung des Schwellenwertstatus
         */
        void evaluateHumidityTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);

        /**
         * @brief Prüft, ob der CO-Wert den oberen Grenzwert überschreitet
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @param thresholdResult Ergebnisstruktur zur Speicherung des Schwellenwertstatus
         */        
        void evaluateCoTooHigh(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);

        /**
         * @brief Prüft, ob die Temperatur den unteren Grenzwert unterschreitet
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @param thresholdResult Ergebnisstruktur zur Speicherung des Schwellenwertstatus
         */
        void evaluateTemperatureTooLow(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);

        /**
         * @brief Prüft, ob die Luftfeuchtigkeit den unteren Grenzwert unterschreitet
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @param thresholdResult Ergebnisstruktur zur Speicherung des Schwellenwertstatus
         */
        void evaluateHumidityTooLow(const Measurements& measurements, const ValidationResults& validationResults, ThresholdResults& thresholdResult);
    
    public:

        /**
         * @brief Konstruktor
         */    
        ThresholdEvaluator() = default;

        /**
         * @brief Bewertet alle Sensormesswerte anhand definierter Grenzwerte
         * 
         * Führt die Schwellenwertprüfung für alle relevanten Sensoren durch
         * und fasst die Ergebnisse in einer gemeinsamen Struktur zusammen.
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @return Struktur mit Schwellenwertbewertungen aller Sensoren
         */        
        ThresholdResults evaluateAllSensors(const Measurements& measurements, const ValidationResults& validationResults);
};