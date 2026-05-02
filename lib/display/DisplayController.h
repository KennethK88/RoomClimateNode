#pragma once
#include <Measurements.h>
#include <SystemState.h>
#include <IDisplayOutput.h>

/**
 * @file DisplayController.h
 * @class DisplayController
 * @brief Steuert die Anzeige des Displays
 * 
 * Der DisplayController ist verantwortlich für die Darstellung der aktuellen
 * Sensordaten und des Systemzustands auf dem Display.
 * 
 * Die Klasse selbst trifft keine fachlichen Entscheidungen, sondern setzt
 * lediglich die vorgegebenen Zustände um:
 * - Anzeige von Messwerten und Systemzustand
 * - Aktivieren oder Deaktivieren des Displays
 * 
 * Die konkrete Ansteuerung der Hardware erfolgt über das IDisplayOutput-Interface.
 */
class DisplayController
{
    private:

        /**
         * @brief Referenz auf das Display-Output-Interface
         */
        IDisplayOutput& displayOutput;
    
    public:

        /**
         * @brief Konstruktor
         * 
         * @param displayOutput Referenz auf das Display-Interface zur Ausgabe
         */
        DisplayController(IDisplayOutput& displayOutput) : displayOutput(displayOutput) {}

        /**
         * @brief Aktualisiert die Anzeige des Displays
         * 
         * Stellt die aktuellen Sensordaten sowie den Systemzustand dar
         * oder deaktiviert das Display abhängig vom übergebenen Zustand.
         * 
         * @param measurements Aktuelle Sensordaten
         * @param systemState Aktueller Systemzustand
         * @param displayActive Gibt an, ob das Display aktiv sein soll
         */
        void updateDisplay(const Measurements& measurements, SystemState systemState, bool displayActive);
};