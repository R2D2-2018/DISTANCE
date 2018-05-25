#include "lidar_mini.hpp"

/**
 * @file      lidar_mini.cpp
 * @brief     Cpp file for the class LIDARmini which will contain functions to control the LIDARmini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

LIDARmini::LIDARmini(hwlib::pin_in &RX) : RX(RX) {
}

bool LIDARmini::waitForStartByte(char startByte) {
    //
}

std::array<char, 7> LIDARmini::getSensorData() {
    UARTConnection uart(115200, UARTController::ONE, 1);

    std::array<char, 7> bytes;

    while (1) {
        if (uart.available() >= 9) {
            if (uart.receive() == 0x59 && uart.receive() == 0x59) { // Check if startbyte is available.., twice.
                for (int i = 0; i < 7; i++) {                       // Loop for 7 more times to print the remaining data package.
                    bytes[i] = uart.receive();                      // Fill the bytes array
                }
                return bytes;
            }
        }
    }
}

int LIDARmini::getDistance() {
    std::array<char, 7> data = this->getSensorData();
    return static_cast<int>(data[0]);
}