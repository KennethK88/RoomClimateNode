#pragma once
#include <Measurements.h>
#include <ValidationResults.h>
#include <CommonSensorConstants.h>

/**
 * @file DisplayPolicy.h
 * @class DisplayPolicy
 * @brief Entscheidet, ob das Display aktiv sein soll
 * 
 * Die DisplayPolicy wertet Sensordaten und deren Validierungsstatus aus,
 * um zu bestimmen, ob das Display eingeschaltet oder ausgeschaltet wird.
 * 
 * Entscheidungslogik:
 * - Ungültige Distanzwerte &rarr; Display bleibt aktiv (Fail-Safe)
 * - Kein Objekt erkannt (Distanzwert = 0) &rarr; Display wird deaktiviert
 * - Objekt innerhalb des Schwellwerts &rarr; Display aktiv
 * - Objekt außerhalb des Schwellwerts &rarr; Display deaktiviert
*/
class DisplayPolicy
{
    private:

        /**
         * @brief Interne Entscheidungslogik für den Displayzustand
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @return true Display soll aktiv sein
         * @return false Display soll deaktiviert sein
         */ 
        bool evaluateDisplayState(const Measurements& measurements, const ValidationResults& validationResults);

    public:
        DisplayPolicy() = default;

        /**
         * @brief Bestimmt, ob das Display aktiv sein soll
         * 
         * @param measurements Aktuelle Sensordaten
         * @param validationResults Validierungsstatus der Sensordaten
         * @return true Display aktiv
         * @return false Display inaktiv
         */
        bool isDisplayActive(const Measurements& measurements, const ValidationResults& validationResults);
};