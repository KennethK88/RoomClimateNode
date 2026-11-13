#pragma once
#include "ISht31SensorDriver.h"

/**
 * @file TemperatureSensor.h
 * @brief Defines the application-level temperature sensor component.
 */

/**
 * @brief Provides access to temperature measurements.
 *
 * Encapsulates application-level access to temperature measurements
 * through the ISht31SensorDriver interface.
 *
 * The actual sensor communication and measurement acquisition are
 * handled by the underlying driver. This class retrieves the most
 * recently stored temperature value without triggering a new measurement.
 */
class TemperatureSensor
{
    private:

        /**
         * @brief Reference to the underlying SHT31 sensor driver.
         */
        ISht31SensorDriver& sht31SensorDriver;

    public:

        /**
         * @brief Constructs a temperature sensor.
         *
         * @param sht31SensorDriver Sensor driver providing temperature measurements.
         */
        TemperatureSensor(ISht31SensorDriver& sht31SensorDriver) : sht31SensorDriver(sht31SensorDriver) {}

        /**
         * @brief Returns the most recently stored temperature measurement.
         *
         * Does not trigger a new sensor measurement.
         *
         * @return Temperature in degrees Celsius, or the corresponding
         *         initialization or measurement error value.
         */
        Temperature getTemperature() const;
};