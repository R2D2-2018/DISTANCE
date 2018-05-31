#include "lidar_mini.hpp"

/**
 * @file      lidar_mini.cpp
 * @brief     Cpp file for the class LIDARmini which will contain functions to control the LIDARmini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

LIDARmini::LIDARmini() : uart(115200, UARTController::ONE, 1) {
}

std::array<char, 7> LIDARmini::getSensorData() {
    std::array<char, 7> bytes = {};

    // The 100k value is chosen because if it is lower it does not work, we're not quite sure why.
    // But we think it might be related to the BAUDrate
    for (int j = 0; j < 100000; j++) {
        if (uart.available() >= 9) { // 9 is the amound of bytes of the full data package
            // Check if startbyte is available.., twice. receive() pops an element of a stack
            if (uart.receive() == 0x59 && uart.receive() == 0x59) {
                for (int i = 0; i < 7; i++) {  // Loop for 7 more times to print the remaining data package.
                    bytes[i] = uart.receive(); // Fill the bytes array
                }
                break;
            }
        }
    }
    return bytes;
}

int LIDARmini::getDistance() {
    std::array<char, 7> data = this->getSensorData();
    return static_cast<int>(data[0]);
}