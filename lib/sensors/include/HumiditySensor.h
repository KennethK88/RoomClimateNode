#pragma once

#include "ISht31SensorDriver.h"

/**
 * @file HumiditySensor.h
 * @brief Defines the application-level humidity sensor component.
 */

/**
 * @brief Provides access to relative humidity measurements.
 *
 * Encapsulates application-level access to humidity measurements
 * through the ISht31SensorDriver interface.
 *
 * The actual sensor communication and measurement acquisition are
 * handled by the underlying driver. This class retrieves the most
 * recently stored humidity value without triggering a new measurement.
 */
class HumiditySensor
{
    private:

        /**
         * @brief Reference to the underlying SHT31 sensor driver.
         */
        ISht31SensorDriver& sht31SensorDriver;

    public:

        /**
         * @brief Constructs a humidity sensor.
         *
         * @param sht31SensorDriver Sensor driver providing humidity measurements.
         */
        HumiditySensor(ISht31SensorDriver& sht31SensorDriver) : sht31SensorDriver(sht31SensorDriver) {}

        /**
         * @brief Returns the most recently stored relative humidity measurement.
         *
         * Does not trigger a new sensor measurement.
         *
         * @return Relative humidity in percent, or the corresponding
         *         initialization or measurement error value.
         */
        Humidity getHumidity() const;
};