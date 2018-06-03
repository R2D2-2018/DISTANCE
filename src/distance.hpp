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
    LIDARmini *lidar;
    HCSR04 *ultrasonic;

  public:
    enum class Scale { CENTIMETERS, INCHES };
    enum class SensorType { AUTOMATIC, LIDAR, ULTRASONIC };
    /**
     * @brief Distance constructor for the TF mini LiDAR distance sensor
     *
     * @param[in]     LIDARmini     LIDARmini object
     */
    explicit Distance(LIDARmini *lidar);

    /**
     * @brief Distance constructor for the HCSR04 Ultrasonic distance sensor
     *
     * @param[in]     HCSR04     HCSR04 object
     */
    explicit Distance(HCSR04 *ultrasonic);

    /**
     * @brief Distance constructor for the TF mini LiDAR and HCSR04 Ultrasonic distance sensors
     *
     * @param[in]     LIDARmini     LIDARmini object
     * @param[in]     HCSR04        HCSR04 object
     */
    Distance(LIDARmini *lidar, HCSR04 *ultrasonic);

    /**
     * @brief Get distance in centimeters
     *
     * Returns the distance to an object in centimeters
     *
     * @param[in]     Distance::SensorType  The sensor that should be used
     * @param[in]     Distance::Scale       The scale in which the distance has to be returned
     * @return        distance
     */
    int getDistance(Distance::SensorType sensorType, Distance::Scale scale);

    /**
     * @brief Converts centimeters to inches
     *
     * Converts a given centimeter value to inches
     *
     * @param[in]     int                   Centimeters to convert
     * @param[in]     Distance::Scale       The scale in which the distance has to be returned
     * @return        inches
     */
    int convertToInches(int centimeters);
};

#endif // DISTANCE_HPP