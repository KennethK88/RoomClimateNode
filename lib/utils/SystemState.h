#pragma once

/**
 * @file SystemState.h
 * @brief Definiert die möglichen Zustände des Systems
 * 
 * Der SystemState beschreibt den aktuellen Gesamtzustand des
 * Luftüberwachungssystems basierend auf validierten und bewerteten
 * Sensormesswerten.
 * 
 * Die Zustände werden von der StateMachine bestimmt und von
 * nachgelagerten Komponenten wie DisplayController und
 * AlarmController verwendet.
 */
enum class SystemState
{
    /**
     * @brief Normalzustand
     * 
     * Alle Sensormesswerte sind gültig und befinden sich innerhalb
     * der definierten Grenzwerte.
     */
    Normal,

    /**
     * @brief Fehlerzustand
     * 
     * Mindestens ein Sensormesswert ist ungültig oder weist auf
     * einen kritischen Zustand hin.
     */
    Error
};