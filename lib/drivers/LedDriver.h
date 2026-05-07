#pragma once
#include <IAlarmOutput.h>

/**
 * @file LedDriver.h
 * @class LedDriver
 * @brief Treiber zur Ansteuerung einer LED
 * 
 * Der LedDriver implementiert das IAlarmOutput-Interface und ermöglicht
 * die Aktivierung und Deaktivierung eines visuellen Alarmsignals.
 * 
 * Die Klasse kapselt den direkten Hardwarezugriff und wird typischerweise
 * über den AlarmController bzw. CompositeAlarmOutput angesteuert.
 */
class LedDriver : public IAlarmOutput
{
    public:

        /**
         * @brief Konstruktor
         */
        LedDriver() = default;

        /**
         * @brief Initialisiert die LED-Hardware
         * 
         * Konfiguriert den zugehörigen Pin als Ausgang.
         */
        void init();

        /**
         * @brief Aktiviert die LED
         * 
         * Schaltet die LED ein.
         */
        void activate() override;

        /**
         * @brief Deaktiviert die LED
         * 
         * Schaltet die LED aus.
         */
        void deactivate() override;
};