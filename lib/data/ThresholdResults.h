#pragma once

/**
 * @file ThresholdResults.h
 * @brief Struktur zur Speicherung von Grenzwertverletzungen
 * 
 * Diese Struktur enthält für jeden relevanten Sensor Flags, die anzeigen,
 * ob definierte Schwellenwerte über- oder unterschritten wurden.
 * 
 * Im Gegensatz zu ValidationResults wird hier nicht die grundsätzliche
 * Gültigkeit eines Messwerts bewertet, sondern ob ein Wert als kritisch
 * einzustufen ist.
 * 
 * Die Werte werden durch den ThresholdEvaluator gesetzt und dienen
 * als Grundlage für die Zustandsbestimmung in der StateMachine.
 */
struct ThresholdResults
{
        /**
        * @brief Temperatur überschreitet oberen Grenzwert
        */
        bool temperatureTooHigh = false;

        /**
         * @brief Luftfeuchtigkeit überschreitet oberen Grenzwert
         */
        bool humidityTooHigh = false;

        /**
         * @brief CO-Konzentration überschreitet oberen Grenzwert
         */
        bool coTooHigh = false;

        /**
        * @brief Temperatur unterschreitet unteren Grenzwert
         */
        bool temperatureTooLow = false;

        /**
         * @brief Luftfeuchtigkeit unterschreitet unteren Grenzwert
         */
        bool humidityTooLow = false;
};