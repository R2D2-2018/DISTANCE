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

int LIDARmini::getDistance() {
    std::array<char, 8> data = this->getWantedRegisters();
    int dist_L = data[1];
    int dist_H = data[2];
    return (dist_H << 8) | (dist_L);
}

std::array<char, 8> LIDARmini::getWantedRegisters() {
    std::array<char, 8> bytes = {};

    // The 100k value is chosen because if it is lower it does not work, we're not quite sure why.
    // But we think it might be related to the BAUDrate
    for (int j = 0; j < 100000; j++) {
        if (uart.available() >= 9) { // 9 is the amound of bytes of the full data package
            // Check if startbyte(0x59) is available.., twice. receive() pops an element of a stack
            if (uart.receive() == 0x59 && uart.receive() == 0x59) {
                if (registerSetByte >>
                    7) { // registerSetByte is a byte in which every bit corrosponts with a register of the sensor.
                    // in this case the most left bit is checked and if it's 1 then the start byte will be put in the array.
                    bytes[0] = 0x59;
                }
                for (int i = 1; i < 8; i++) { // Loop for 7 more times to fill in the remaining data package in the array.
                    if (((registerSetByte >> (7 - i)) % 2)) { // checks if the array posistion of the check byte is 1.
                        bytes[i] = uart.receive();
                    } else {
                        uart.receive();
                        bytes[i] = 0;
                    }
                }
                return bytes;
            }
        }
    }
    return bytes;
}

void LIDARmini::setRegisterSetByte(char newByte) {
    registerSetByte = newByte;
}