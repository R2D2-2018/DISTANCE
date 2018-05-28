#ifndef LIDAR_HPP
#define LIDAR_HPP
#include "wrap-hwlib.hpp"

/**
 * @file      uart_protocol.cpp
 * @brief     Hpp file for the class UARTProtocol which will contain functions use a UARTProtocol which is needed for the LIDARmini
 * class.
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

/**
 * @class UARTProtocol
 * @brief This class will contain functions for other classes to use the uart protocol.
 */
class UARTProtocol {
  public:
    hwlib::target::pin_in &RX; // RX is a pin on the arduino if you didn't know :D
    int waitStartByteCycles;

    UARTProtocol(hwlib::target::pin_in &RX, int waitStartByteCycles);

    /**
     * @brief gets a byte form the RX pin
     *
     * This function gets a byte one bit at a time from the RX pin.
     *
     * @return
     * char : returns a char (which corresponds to a byte)
     */
    char getByte();

    /**
     * @brief Waits until the start byte is found
     *
     * This function loops until two start bytes have been found or until a specified amount of tries has been reached.
     *
     * @returns boolean value
     */
    bool waitForStart();
};

#endif // LIDAR_HPP