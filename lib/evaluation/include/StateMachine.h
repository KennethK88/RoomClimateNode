#pragma once
#include <ValidationResults.h>
#include <SystemState.h>

/**
 * @file StateMachine.h
 * @class StateMachine
 * @brief Bestimmt den aktuellen Systemzustand basierend auf Sensorbewertungen
 * 
 * Die StateMachine fasst die Ergebnisse aus Validierung und Schwellenwert-
 * bewertung zusammen und leitet daraus den aktuellen Zustand des Systems ab.
 * 
 * Dabei werden sowohl ungültige Sensordaten als auch kritische Messwerte
 * berücksichtigt, um zwischen verschiedenen Systemzuständen (z. B. Normal,
 * Warning, Error) zu unterscheiden.
 */
class StateMachine
{
    public:

        /**
         * @brief Konstruktor
         */
        StateMachine() = default;

        /**
         * @brief Berechnet den aktuellen Systemzustand
         * 
         * Verwendet die Validierungs- und Schwellenwert-Ergebnisse, um den
         * Systemzustand zu bestimmen.
         * 
         * @param validationResults Validierungsstatus der Sensordaten
         * @param thresholdResult Ergebnis der Schwellenwertbewertung
         * @return Abgeleiteter Systemzustand
         */
        SystemState calculateState(const ValidationResults& validationResults);
};