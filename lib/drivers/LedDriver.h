#pragma once
#include <ILedOutput.h>
#include <gpio.h>

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
         * @brief GPIO-Pin, über den die LED angesteuert wird.
         */
        const GpioPin gpioPin;

    public:

        /**
         * @brief Konstruktor
         *
         * Erstellt einen LED-Treiber für den angegebenen GPIO-Pin.
         *
         * @param gpioPin GPIO-Pin der LED
         */
        explicit LedDriver(GpioPin gpioPin) : gpioPin(gpioPin) {}
        
        /**
         * @brief Initialisiert den LED-Pin als Ausgang
         */
        void init() override;
        
        /**
         * @brief Schaltet die LED ein
         */
        void turnOn() override;
        
        /**
         * @brief Schaltet die LED aus
         */
        void turnOff() override;
};