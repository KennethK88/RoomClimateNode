#pragma once

/**
 * @file ValidationResults.h
 * @brief Datenstruktur für den Validierungsstatus der Messwerte.
 *
 * Diese Struktur enthält für jeden relevanten Messwert ein Flag, das angibt,
 * ob der jeweilige Wert als gültig bewertet wurde.
 *
 * Die Werte werden durch den SensorValidator gesetzt und dienen als Grundlage
 * für die Berechnung des Systemzustands durch die StateMachine.
 */
struct ValidationResults
{
    /**
     * @brief Gibt an, ob der Temperaturwert gültig ist.
     */
    bool temperatureValid = false;

    /**
     * @brief Gibt an, ob der Luftfeuchtigkeitswert gültig ist.
     */
    bool humidityValid = false;

    bool batteryLevelValid = false;
};