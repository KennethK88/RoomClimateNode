#pragma once
#include <SystemState.h>
#include <IAlarmOutput.h>

/**
 * @file AlarmController.h
 * @class AlarmController
 * @brief Steuert die Alarm-Ausgabe basierend auf dem Systemzustand
 * 
 * Der AlarmController ist verantwortlich für die Aktivierung und
 * Deaktivierung von Alarmen in Abhängigkeit vom aktuellen Systemzustand.
 * 
 * Im Gegensatz zum DisplayController verwaltet diese Klasse intern
 * einen Zustand, um unnötige oder wiederholte Aktivierungen zu vermeiden.
 * 
 * Die konkrete Ansteuerung der Hardware erfolgt über das IAlarmOutput-Interface.
 */
class AlarmController
{
    private:

        /**
         * @brief Gibt an, ob der Alarm aktuell aktiv ist
         */
        bool alarmActive = false;

        /**
         * @brief Referenz auf das Alarm-Output-Interface
         */
        IAlarmOutput& alarmOutput;

    public:

        /**
         * @brief Konstruktor
         * 
         * @param alarmOutput Referenz auf das Alarm-Interface zur Ausgabe
         */
        AlarmController(IAlarmOutput& alarmOutput) : alarmOutput(alarmOutput) {};

        /**
         * @brief Aktualisiert den Alarmzustand
         * 
         * Aktiviert oder deaktiviert den Alarm abhängig vom aktuellen
         * Systemzustand.
         * 
         * @param systemState Aktueller Systemzustand
         */
        void updateAlarm(SystemState systemState);

        /**
         * @brief Gibt zurück, ob der Alarm aktuell aktiv ist
         * 
         * @return true Alarm ist aktiv
         * @return false Alarm ist inaktiv
         */
        bool isAlarmActive() const;
};