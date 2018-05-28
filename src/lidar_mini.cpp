#include "lidar_mini.hpp"
#include "uart_protocol.hpp"

/**
 * @file      lidar_mini.cpp
 * @brief     Cpp file for the class LIDARmini which will contain functions to control the LIDARmini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

<<<<<<< HEAD
LIDARmini::LIDARmini() : uart(115200, UARTController::ONE, 1) {
}

std::array<char, 7> LIDARmini::getSensorData() {
    std::array<char, 7> bytes = {};
=======
LIDARmini::LIDARmini(hwlib::target::pin_in RX) : RX(RX) {
}

char *LIDARmini::getDistanceInCm() {
    UARTProtocol uart(RX, 1000);

    for (int i = 0; i < 8; ++i) {
        bytes[i] = uart.getByte();
    }
>>>>>>> parent of 43e1017... Solved merge conflicts

    return bytes.begin();
}
