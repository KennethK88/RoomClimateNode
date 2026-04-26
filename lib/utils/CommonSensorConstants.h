#pragma once

namespace SensorConstants
{
// Temperature °C
constexpr float TEMPERATURE_NOT_INITIALIZED = -100.0f;
constexpr float TEMPERATURE_MIN_VALID = -20.0f;
constexpr float TEMPERATURE_MAX_VALID = 40.0f;
constexpr float TEMPERATURE_MIN_THRESHOLD = 18.0f;
constexpr float TEMPERATURE_MAX_THRESHOLD = 25.0f;
constexpr float TEMPERATURE_DUMMY_VALID = 20.0f;

// Humidity %
constexpr float HUMIDITY_NOT_INITIALIZED = -100.0f;
constexpr float HUMIDITY_MIN_VALID = 0.0f;
constexpr float HUMIDITY_MAX_VALID = 100.0f;
constexpr float HUMIDITY_MIN_THRESHOLD = 30.0f;
constexpr float HUMIDITY_MAX_THRESHOLD = 70.0f;
constexpr float HUMIDITY_DUMMY_VALID = 35.0f;

// CO ppm
constexpr float CO_NOT_INITIALIZED = -100.0f;
constexpr float CO_MIN_VALID = 0.0f;
constexpr float CO_MAX_VALID = 1000.0f;
constexpr float CO_MAX_THRESHOLD = 200.0f;
constexpr float CO_DUMMY_VALID = 50.0f;

// Distance cm
constexpr float DISTANCE_NOT_INITIALIZED = -100.0f;
constexpr float DISTANCE_MIN_VALID = 0.0f;
constexpr float DISTANCE_MAX_VALID = 300.0f;
constexpr float DISTANCE_ON_OFF_THRESHOLD = 75.0f;
constexpr float DISTANCE_DUMMY_VALID = 50.0f;
}