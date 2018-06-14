#ifndef DISTANCE_HPP
#define DISTANCE_HPP
#include "HCSR04.hpp"
#include "lidar_mini.hpp"
#include "wrap-hwlib.hpp"

/**
 * @file      distance.hpp
 * @brief     Hpp file for the class distance
 * @author    Wouter Dijksta
 * @date      31-5-2018
 * @license   MIT
 */

/**
 * @class distance
 * @brief Class for the distance
 */
class Distance {
  private:
    LIDARmini &lidar;
    HCSR04 &ultrasonic;

  public:
    enum class Scale { CENTIMETERS, INCHES };
    enum class SensorType { AUTOMATIC, LIDAR, ULTRASONIC };
    enum class Filter { KALMAN, MEDIAN };

  private:
    Scale unit;
    SensorType sensorType;
    Filter filter;

  public:
    Distance(LIDARmini &lidarm, HCSR04 &ultrasonic);

    /**
     * @brief Get distance in centimeters
     *
     * @details
     * Returns the distance to an object in centimeters
     *
     * @return        distance
     */
    int getDistance();

    /**
     * @brief Sets the sensor attribute to sensorType
     *
     * @details
     * Sets the sensor specifier to the sensor specified in the parameter.
     *
     * @param [in]sensorType
     */
    void setSensor(const SensorType sensorType);

    /**
     * @brief Does nothing
     *
     * @details
     * Does nothing
     *
     * @param[in] unit
     */
    void setUnit(const Scale unit);

    /**
     * @brief Does nothing
     *
     * @details
     * Does nothing
     *
     * @param[in] filter Filter type
     * @param[in] size Size of the filter
     */
    void setFilter(const Filter filter, const int size);

    /**
     * @brief Converts centimeters to inches
     *
     * Converts a given centimeter value to inches
     *
     * @param[in]     int                   Centimeters to convert
     * @param[in]     Distance::Scale       The scale in which the distance has to be returned
     * @return        inches
     */
    static int convertToInches(int centimeters);
};

#endif // DISTANCE_HPP