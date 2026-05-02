#pragma once

/**
 * @file ISensorDriver.h
 * @class ISensorDriver
 * @brief Interface für Sensor-Treiber
 * 
 * Dieses Interface definiert die grundlegenden Operationen für alle Sensor-Treiber
 * im System. Konkrete Implementierungen kapseln den Zugriff auf die jeweilige
 * Hardware und stellen Messwerte in einheitlicher Form bereit.
 * 
 * Ziel ist eine Entkopplung zwischen Sensorlogik und Hardwarezugriff, sodass
 * Sensoren unabhängig von ihrer konkreten Implementierung verwendet und getestet
 * werden können.
 */
class ISensorDriver
{
    public:

        /**
         * @brief Virtueller Destruktor
         */    
        virtual ~ISensorDriver() = default;

        /**
         * @brief Initialisiert die Hardware des Sensors
         * 
         * Führt notwendige Initialisierungsschritte aus, z. B.:
         * - Konfiguration von Pins
         * - Initialisierung externer Bibliotheken
         * - Vorbereitung interner Zustände
         */
        virtual void init() = 0;

        /**
         * @brief Liefert den aktuellen Messwert des Sensors
         * 
         * @return Messwert des Sensors als float
         * 
         * @note Die Einheit und Interpretation des Rückgabewerts hängt
         * von der konkreten Implementierung ab (z. B. °C, %, ppm, cm).
         */
        virtual float getValue() = 0;
};