#pragma once

/**
 * @file IAlarmOutput.h
 * @class IAlarmOutput
 * @brief Interface zur Ansteuerung von Alarm-Ausgabekomponenten
 * 
 * Dieses Interface definiert die grundlegenden Operationen zur Aktivierung
 * und Deaktivierung eines Alarms.
 * 
 * Konkrete Implementierungen kapseln den Zugriff auf die jeweilige Hardware
 * (z. B. Buzzer, LED) und ermöglichen eine einheitliche Nutzung durch den
 * AlarmController.
 * 
 * Ziel ist die Entkopplung der Alarmsteuerung von der konkreten Hardware.
 */
class IAlarmOutput
{
    public:

        /**
         * @brief Virtueller Destruktor
         */
        virtual ~IAlarmOutput() = default;

        virtual void init() = 0;

        /**
         * @brief Aktiviert den Alarm
         * 
         * Schaltet die zugehörige Hardwarekomponente ein.
         */        
        virtual void activate() = 0;

        /**
         * @brief Deaktiviert den Alarm
         * 
         * Schaltet die zugehörige Hardwarekomponente aus.
         */        
        virtual void deactivate() = 0;
};