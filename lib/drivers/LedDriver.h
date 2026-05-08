#pragma once
#include <ILedOutput.h>

/**
 * @file LedDriver.h
 * @class LedDriver
 * @brief Hardware-Treiber zur Ansteuerung einer einzelnen LED
 *
 * Der LedDriver implementiert das Interface ILedOutput und steuert
 * eine LED über einen digitalen GPIO-Pin an.
 *
 * Die konkrete Pinbelegung wird beim Erstellen des Drivers übergeben,
 * wodurch dieselbe Klasse für unterschiedliche LEDs wiederverwendet
 * werden kann.
 */
class LedDriver : public ILedOutput
{
    private:

        /**
         * @brief GPIO-Pin der LED
         */
        int pinNumber; // aus HardwareConfig

    public:

        /**
         * @brief Konstruktor
         *
         * Erstellt einen LED-Treiber für den angegebenen GPIO-Pin.
         *
         * @param pinNumber GPIO-Pin der LED
         */
        explicit LedDriver(int pinNumber) : pinNumber(pinNumber) {}
        
        /**
         * @brief Initialisiert den LED-Pin als Ausgang
         */
        void init();
        
        /**
         * @brief Schaltet die LED ein
         */
        void turnOn() override;
        
        /**
         * @brief Schaltet die LED aus
         */
        void turnOff() override;
};