#ifndef LIDAR_MINI_HPP
#define LIDAR_MINI_HPP
#include "uart_connection.hpp"
#include "uart_protocol.hpp"
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
    LIDARmini(hwlib::pin_in &RX);

    // std::array<char, 7> bytes;

    bool compairBytes(char byte1, char byte2);

    bool waitForStartByte(char startByte, int StartByteCycles);

    /**
     * @brief
     * Returns the distance in cm
     *
     * @description
     * Calculates the distance with the uart protocol of the data that comes in over the RX port in cm.
     * Right now it returns the full package.
     *
     * @return
     * char * : to the first element of the data package
     */
    std::array<char, 7> getDistanceInCm();

    void printByte(char byte[]);
};

#endif // LIDAR_MINI_HPP