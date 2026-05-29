#pragma once
#include <IAlarmOutput.h>

/**
 * @file BuzzerDriver.h
 * @class BuzzerDriver
 * @brief Treiber zur Ansteuerung eines Buzzers
 * 
 * Der BuzzerDriver implementiert das IAlarmOutput-Interface und ermöglicht
 * die Aktivierung und Deaktivierung eines akustischen Alarmsignals.
 * 
 * Die Klasse kapselt den direkten Hardwarezugriff und wird typischerweise
 * über den AlarmController angesteuert.
 */
class BuzzerDriver : public IAlarmOutput
{
    public:

        /**
         * @brief Konstruktor
         */
        BuzzerDriver() = default;

        /**
         * @brief Initialisiert die Hardware des Buzzers
         * 
         * Konfiguriert den zugehörigen Pin als Ausgang.
         */
        void init() override;

        /**
         * @brief Aktiviert den Buzzer
         * 
         * Schaltet das akustische Signal ein.
         */
        void activate() override;

        /**
         * @brief Deaktiviert den Buzzer
         * 
         * Schaltet das akustische Signal aus.
         */
        void deactivate() override;
};