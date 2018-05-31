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

std::array<char, 9> LIDARmini::getWantedRegisters(char registerSetByte) {
    std::array<char, 9> bytes = {};

    // The 100k value is chosen because if it is lower it does not work, we're not quite sure why.
    // But we think it might be related to the BAUDrate
    for (int j = 0; j < 100000; j++) {
        if (uart.available() >= 9) { // 9 is the amound of bytes of the full data package
            // Check if startbyte(0x59) is available.., twice. receive() pops an element of a stack
            if (uart.receive() == 0x59 && uart.receive() == 0x59) {
                int bytesCounter = 0;
                if (registerSetByte >>
                    7) { // registerSetByte is a byte in which every bit corrosponts with a register of the sensor.
                    // in this case the most left bit is checked and if it's 1 then the start byte will be put in the array.
                    bytes[0] = 0x59;
                    bytes[1] = 0x59;
                    bytesCounter = bytesCounter + 2;
                }
                for (int i = 6; i >= 0; i++) { // Loop for 7 more times to fill in the remaining data package in the array.
                    if (((registerSetByte >> (i)) % 2)) { // checks if the array posistion of the check byte is 1.
                        bytes[bytesCounter] = uart.receive();
                        bytesCounter++;
                    } else {
                        uart.receive();
                    }
                }
                return bytes;
            }
        }
    }
    return bytes;
}

int LIDARmini::getDistance() {
    std::array<char, 9> data = this->getWantedRegisters(0x60); // 0110 0000 because we want the 2 dist registers
    int dist_L = data[0];                                      // dist_L is register 2
    int dist_H = data[1];                                      // dist_H is register 3
    return (dist_H << 8) | (dist_L);
}

int LIDARmini::getStrength() {
    std::array<char, 9> data = this->getWantedRegisters(0x18); // 0001 1000 because we want the 2 strength registers
    int strength_L = data[0];                                  // strength_L is register 4
    int strength_H = data[1];                                  // strength_H is register 5
    return (strength_H << 8) | (strength_L);
}

int LIDARmini::getQualityDegree() {
    std::array<char, 9> data = this->getWantedRegisters(0x02);
    return data[0]; // QualityDegree is register 8
}
