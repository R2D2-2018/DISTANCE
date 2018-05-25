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
    hwlib::pin_in &RX;

  public:
    /**
     * @brief Constructor
     */
    explicit LIDARmini(hwlib::pin_in &RX);

    /**
     * @brief
     * wait until the start byte (0x59) has occured twice in a row
     *
     * @description
     * Loop startByteCycles amount of times to check for start bytes
     * Returns true if start byte (0x59) has been detected twice.
     * Returns false if function has looped startByteCycles times without detecting start bytes.
     *
     * @return
     * bool : true or false
     */
    bool waitForStartByte();

    /**
     * @brief
     * Returns an array with all the sensor data
     *
     * @description
     * Returns the full data package, 7 bytes as an array
     *
     * @return
     * std::array : sensor data package
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