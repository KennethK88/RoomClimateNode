#pragma once
#include <ValidationResults.h>
#include <SystemState.h>

/**
 * @file StateMachine.h
 * @brief Bestimmt den aktuellen Systemzustand des Raumklima-Knotens.
 */

/**
 * @class StateMachine
 * @brief Leitet den Systemzustand aus den Validierungsergebnissen ab.
 *
 * Die StateMachine bewertet den Validierungsstatus der erfassten Messwerte
 * und bestimmt daraus den aktuellen SystemState.
 *
 * Aktuell unterscheidet die StateMachine zwischen einem Normalzustand und
 * einem Fehlerzustand. Ein Fehlerzustand liegt vor, wenn mindestens ein
 * relevanter Messwert ungültig ist.
 */
class StateMachine
{
    public:

        /**
         * @brief Erzeugt eine StateMachine.
         */
        StateMachine() = default;

        /**
         * @brief Berechnet den aktuellen Systemzustand.
         *
         * Verwendet die Validierungsergebnisse der Messwerte, um den
         * Systemzustand zu bestimmen.
         *
         * @param validationResults Validierungsstatus der Messwerte.
         * @return Abgeleiteter Systemzustand.
         */
        SystemState calculateState(const ValidationResults& validationResults);
};