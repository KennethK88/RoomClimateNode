#pragma once
#include <vector>
#include <IAlarmOutput.h>

/**
 * @file CompositeAlarmOutput.h
 * @class CompositeAlarmOutput
 * @brief Kombiniert mehrere Alarm-Ausgabekomponenten zu einer Einheit
 * 
 * Der CompositeAlarmOutput implementiert das Composite-Pattern und ermöglicht
 * es, mehrere Alarm-Ausgabekomponenten (z. B. Buzzer, LED) gemeinsam zu steuern.
 * 
 * Aufrufe von activate() und deactivate() werden an alle enthaltenen
 * IAlarmOutput-Instanzen weitergeleitet.
 * 
 * Dadurch kann der AlarmController mehrere Ausgabegeräte gleichzeitig
 * ansprechen, ohne deren konkrete Anzahl oder Implementierung zu kennen.
 */
class CompositeAlarmOutput : public IAlarmOutput
{
    private:
            
        /**
         * @brief Sammlung aller angebundenen Alarm-Ausgabekomponenten
         */
        std::vector<IAlarmOutput*> alarmOutputs;

    public:

        /**
         * @brief Konstruktor
         */
        CompositeAlarmOutput() = default;

        /**
         * @brief Fügt eine Alarm-Ausgabekomponente hinzu
         * 
         * @param alarmOutput Zeiger auf eine Implementierung von IAlarmOutput
         */
        void add(IAlarmOutput* alarmOutput);

        /**
         * @brief Aktiviert alle enthaltenen Alarm-Ausgabekomponenten
         * 
         * Leitet den Aktivierungsaufruf an alle registrierten Outputs weiter.
         */
        void activate() override;

        /**
         * @brief Deaktiviert alle enthaltenen Alarm-Ausgabekomponenten
         * 
         * Leitet den Deaktivierungsaufruf an alle registrierten Outputs weiter.
         */
        void deactivate() override;
};