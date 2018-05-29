#ifndef LIDAR_MINI_HPP
#define LIDAR_MINI_HPP
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"
#include <array>

/**
 * @file      lidar_mini.hpp
 * @brief     Hpp file for the class LIDARmini which will contain functions to control the TF LIDAR mini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

/**
 * @class LIDARmini
 * @brief Class for the TF LIDAR Mini
 */
class LIDARmini {
  private:
    UARTConnection uart;

  public:
    /**
     * @brief Constructor
     */
    explicit LIDARmini();

    /**
     * @brief
     * Returns an array with all the sensor data
     *
     * @description
     * If the two startbytes are found returns the data package minus the 2 startbytes, 7 bytes as an array.
     * If no startbytes are found with in a set amound of try's (100000) an empty array will be returned.
     * The amound of try's has been determent by tests and 100000 works correctly. We suspect the reason why the amound is so high
     * is because of the function needing to get in sick with the baudrate.
     *
     * @return
     * std::array : bytes
     */
    std::array<char, 7> getSensorData();

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

#endif // LIDAR_MINI_HPP