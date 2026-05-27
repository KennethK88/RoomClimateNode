#pragma once

/**
 * @file ILedOutput.h
 * @class ILedOutput
 * @brief Abstraktes Interface zur Ansteuerung einer LED
 *
 * Das Interface abstrahiert die konkrete Hardwareansteuerung von LEDs
 * und ermöglicht eine entkoppelte Nutzung durch fachliche Komponenten
 * wie den LedController.
 *
 * Implementierungen übernehmen die konkrete Ansteuerung der Hardware,
 * beispielsweise über digitale GPIO-Pins.
 */
class ILedOutput
{
    public:

        /**
         * @brief Virtueller Destruktor
         */
        virtual ~ILedOutput() = default;
        
        /**
         * @brief Initialisiert die LED-Ausgabekomponente
         * 
         * Bereitet die zugrunde liegende Hardware für den Betrieb vor.
         * Die konkrete Initialisierung ist abhängig von der jeweiligen
         * Hardwareimplementierung.
         */
        virtual void init() = 0;

        /**
         * @brief Schaltet die LED ein
         */
        virtual void turnOn() = 0;
        
        /**
         * @brief Schaltet die LED aus
         */
        virtual void turnOff() = 0;
};