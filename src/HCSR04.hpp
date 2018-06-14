#ifndef HCSR04_HPP
#define HCSR04_HPP
#include "wrap-hwlib.hpp"

/**
 * @file      HCSR04.hpp
 * @brief     Hpp file for the class HCSR04 which will contain functions to control the HCSR04 ultrasonic sensor
 * @author    Wouter Dijksta
 * @date      29-5-2018
 * @license   MIT
 */

/**
 * @class HCSR04
 * @brief Class for the HCSR04 ultrasonic sensor
 */
class HCSR04 {
  private:
    hwlib::pin_out &trigger_pin;
    hwlib::pin_in &echo_pin;

  public:
    /**
     * @brief HCSR04 Constructor
     * @param trigger_pin       Pin to send the pulse on
     * @param echo_pin          Pin to listen for the reflection on
     */
    explicit HCSR04(hwlib::pin_out &trigger_pin, hwlib::pin_in &echo_pin);

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
    int getDistance();
};

#endif // HCSR04_HPP