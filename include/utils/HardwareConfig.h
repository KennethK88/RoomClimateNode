#include <Arduino.h>

/**
 * @file HardwareConfig.h
 * @brief Zentrale Definition der Hardware-Pinbelegung
 * 
 * Dieses Namespace enthält alle Hardware-spezifischen Konfigurationen
 * wie Pinbelegungen und Sensortypen.
 * 
 * Ziel ist es, die Abhängigkeit zur konkreten Hardware an einer Stelle
 * zu bündeln, sodass Anpassungen ohne Änderungen an der Systemlogik
 * möglich sind.
 */
namespace HardwareConfig
{
    /**
     * @brief Digitaler Ausgangspin für den Buzzer
     */
    constexpr int BUZZER_DIGITAL_PIN = PIN_D2;

    /**
     * @brief Digitaler Ausgangspin für die LED
     */
    constexpr int LED_DIGITAL_PIN = PIN_D4;

    /**
     * @brief Analoger Eingangspin für den Thermistor
     */
    constexpr int THERMISTOR_ANALOG_PIN = PIN_A0;

    /**
     * @brief Digitaler Eingangspin für den Feuchtigkeitssensor
     */
    constexpr int HUMIDITY_DRIVER_PIN = PIN_D7;

    /**
     * @brief Typ des verwendeten Feuchtigkeitssensors
     * 
     * Entspricht dem DHT-Sensortyp (z. B. DHT11).
     */
    constexpr int HUMIDITY_DRIVER_TYPE = 11;

    /**
     * @brief Trigger-Pin für den Ultraschallsensor
     */
    constexpr int DISTANCE_DRIVER_TRIGGER_PIN = PIN_D9;

    /**
     * @brief Echo-Pin für den Ultraschallsensor
     */
    constexpr int DISTANCE_DRIVER_ECHO_PIN = PIN_D10;
}