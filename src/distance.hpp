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
    hwlib::target::pin_out *trigger_pin;
    hwlib::target::pin_in *echo_pin;
    hwlib::target::pin_in *RX;

  public:
    enum class Scale { CENTIMETERS, INCHES };
    enum class Sensor { AUTOMATIC, LIDAR, ULTRASONIC };
    /**
     * @brief Distance Constructor for TF mini LiDAR
     * @param RX       RX pin to use
     */
    explicit Distance(hwlib::target::pin_in &RX);

    /**
     * @brief Distance Constructor for Ultrasonic sensor
     * @param trigger_pin       Pin to send the pulse on
     * @param echo_pin          Pin to listen for the reflection on
     */
    Distance(hwlib::target::pin_out &trigger_pin, hwlib::target::pin_in &echo_pin);

    /**
     * @brief Distance Constructor for TF mini liDAR and Ultrasonic sensor
     * @param trigger_pin       Pin to send the pulse on
     * @param echo_pin          Pin to listen for the reflection on
     * @param RX                RX pin to use
     */
    Distance(hwlib::target::pin_out &trigger_pin, hwlib::target::pin_in &echo_pin, hwlib::target::pin_in &RX);

    /**
     * @brief
     * Get distance in centimers
     *
     * @description
     * Returns the distance to an object in centimeters
     *
     * @return
     * int : distance value
     */
    int getDistance(Distance::Sensor sensor, Distance::Scale scale);

    int convertToInches(int centimeters);
};

#endif // DISTANCE_HPP