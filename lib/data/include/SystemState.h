#pragma once

/**
 * @file SystemState.h
 * @brief Definiert die möglichen Systemzustände des Raumklima-Knotens.
 *
 * Der SystemState beschreibt den aktuellen Gesamtzustand des Systems auf Basis
 * der validierten Sensormesswerte. Der Zustand wird von der StateMachine
 * bestimmt und kann von nachgelagerten Komponenten zur weiteren Verarbeitung
 * oder Ausgabe verwendet werden.
 */
enum class SystemState
{
    /**
     * @brief Normalzustand.
     *
     * Alle relevanten Messwerte sind gültig.
     */
    Normal,

    /**
     * @brief Fehlerzustand.
     *
     * Mindestens ein relevanter Messwert ist ungültig oder konnte nicht
     * plausibel ermittelt werden.
     */
    Error
};