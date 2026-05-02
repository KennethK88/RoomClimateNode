#pragma once
#include <ISensorDriver.h>

/**
 * @file CODriver.h
 * @class CODriver
 * @brief Treiber zur Messung der CO-Konzentration
 * 
 * Der CODriver implementiert das ISensorDriver-Interface und dient zur
 * Erfassung der CO-Konzentration über einen entsprechenden Gassensor.
 * 
 * Die Klasse kapselt den Zugriff auf die zugrunde liegende Hardware und
 * stellt den Messwert in standardisierter Form bereit.
 * 
 * @note Die konkrete Implementierung ist abhängig vom verwendeten Sensor
 * und kann je nach Sensortyp variieren (z. B. analoger oder digitaler Sensor).
 */
class CODriver : public ISensorDriver
{
    private:
        // Aktuell keine internen Hilfsfunktionen definiert
    
    public:

        /**
         * @brief Konstruktor
         */
        CODriver() = default;

        /**
         * @brief Initialisiert den CO-Sensor
         * 
         * Führt notwendige Initialisierungsschritte für die verwendete
         * Hardware durch.
         */
        void init() override;

        /**
         * @brief Liefert die aktuell gemessene CO-Konzentration
         * 
         * Führt eine Messung durch und gibt den aktuellen Wert zurück.
         * 
         * @return CO-Konzentration in ppm
         * 
         * @note Kann abhängig vom Sensorrauschen oder Messfehlern
         * ungenaue Werte liefern
         */
        float getValue() override;
};