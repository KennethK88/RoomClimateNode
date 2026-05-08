#pragma once
#include <ILedOutput.h>
#include <SystemState.h>

/**
 * @file LedController.h
 * @class LedController
 * @brief Steuert die Status-LEDs basierend auf dem aktuellen Systemzustand
 *
 * Der LedController bildet den aktuellen SystemState auf die
 * entsprechenden Status-LEDs ab.
 *
 * Dabei gilt:
 * - Normal  -> grüne LED
 * - Warning -> gelbe LED
 * - Error   -> rote LED
 *
 * Die Klasse arbeitet ausschließlich mit dem abstrakten Interface
 * ILedOutput und ist dadurch von konkreter Hardware entkoppelt.
 */
class LedController
{
    private:
        ILedOutput& normalLed;
        ILedOutput& warningLed;
        ILedOutput& errorLed;

    public:

        /**
         * @brief Konstruktor
         *
         * Verdrahtet die LEDs für die verschiedenen Systemzustände.
         *
         * @param normalLed LED für den Zustand Normal
         * @param warningLed LED für den Zustand Warning
         * @param errorLed LED für den Zustand Error
         */
        LedController(ILedOutput& normalLed, ILedOutput& warningLed, ILedOutput& errorLed) :    normalLed(normalLed),
                                                                                                warningLed(warningLed),
                                                                                                errorLed(errorLed) {}
        
        /**
         * @brief Aktualisiert die Status-LEDs entsprechend des Systemzustands
         *
         * Aktiviert genau die LED, die dem aktuellen SystemState entspricht,
         * und deaktiviert alle anderen LEDs.
         *
         * @param systemState Aktueller Zustand des Systems
         */
        void updateLeds(SystemState systemState);
};