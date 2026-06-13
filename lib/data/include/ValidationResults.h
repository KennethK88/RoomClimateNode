#pragma once

/**
 * @file ValidationResults.h
 * @brief Struktur zur Speicherung des Validierungsstatus von Sensormesswerten
 * 
 * Diese Struktur enthält für jeden Sensor ein Flag, das angibt, ob der
 * jeweilige Messwert als gültig oder ungültig bewertet wurde.
 * 
 * Die Werte werden durch den SensorValidator gesetzt und dienen als
 * Grundlage für nachgelagerte Komponenten wie ThresholdEvaluator
 * und StateMachine.
 */
struct ValidationResults
{
    /**
     * @file ValidationResults.h
     * @brief Struktur zur Speicherung des Validierungsstatus von Sensormesswerten
     * 
     * Diese Struktur enthält für jeden Sensor ein Flag, das angibt, ob der
     * jeweilige Messwert als gültig oder ungültig bewertet wurde.
     * 
     * Die Werte werden durch den SensorValidator gesetzt und dienen als
     * Grundlage für nachgelagerte Komponenten wie ThresholdEvaluator
     * und StateMachine.
     */
    bool temperatureValid = false;

    /**
     * @brief Gibt an, ob der Feuchtigkeitswert gültig ist
     */
    bool humidityValid = false;
};