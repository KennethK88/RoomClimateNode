#pragma once
#include <Measurements.h>

/**
 * @file IMeasurementPublisher.h
 * @brief Interface for publishing measurement values.
 */

/**
 * @brief Abstract interface for components that publish measurement values.
 *
 * This interface decouples the application-level measurement handling from the
 * concrete output technology. Implementations may publish the measurements
 * using MQTT, HTTP or another communication mechanism.
 */
class IMeasurementPublisher
{
    public:

        /**
         * @brief Virtual destructor for polymorphic use.
         */
        virtual ~IMeasurementPublisher() = default;

        /**
         * @brief Publishes the given measurement values.
         *
         * The method returns whether publishing was successfully triggered or
         * completed from the perspective of the concrete implementation. The
         * exact meaning of success depends on the underlying output technology.
         *
         * @param measurements The measurement values to publish.
         * @return true if the measurement values were published successfully,
         *         false otherwise.
         */
        virtual bool publish(const Measurements& measurements) = 0;
};