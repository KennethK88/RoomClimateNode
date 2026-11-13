#pragma once
#include "Types.h"

/**
 * @file ISht31SensorDriver.h
 * @brief Defines the interface for SHT31 sensor drivers.
 */

/**
 * @brief Abstract interface for temperature and humidity measurement.
 *
 * Defines the contract for SHT31 sensor driver implementations,
 * including sensor initialization, measurement acquisition,
 * and access to the most recently acquired measurements.
 *
 * Decouples application-level sensor components from the concrete
 * hardware implementation, allowing alternative implementations
 * and test doubles to be used.
 */
class ISht31SensorDriver
{
    public:

        /**
         * @brief Virtual destructor for polymorphic use.
         */
        virtual ~ISht31SensorDriver() = default;

        /**
         * @brief Initializes the sensor driver.
         */
        virtual void init() = 0;

        /**
         * @brief Acquires temperature and humidity measurements.
         *
         * Triggers a sensor measurement and updates the internally
         * stored temperature and humidity values.
         */
        virtual void readMeasurements() = 0;

        /**
         * @brief Returns the most recently stored temperature measurement.
         *
         * Does not trigger a new sensor measurement.
         *
         * @return Temperature in degrees Celsius.
         */
        virtual Temperature getTemperature() = 0;
        
        /**
         * @brief Returns the most recently stored relative humidity measurement.
         *
         * Does not trigger a new sensor measurement.
         *
         * @return Relative humidity in percent.
         */
        virtual Humidity getHumidity() = 0;
};