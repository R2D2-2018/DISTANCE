#include "lidar_mini.hpp"

/**
 * @file      lidar_mini.cpp
 * @brief     Cpp file for the class LIDARmini which will contain functions to control the LIDARmini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */
LIDARmini::LIDARmini(HardwareUART &uart) : uart(uart) {
}

std::array<char, 9> LIDARmini::getWantedRegisters(LidarMiniRegisters registerSetByte) {
    return getWantedRegisters(static_cast<char>(registerSetByte));
}

std::array<char, 9> LIDARmini::getWantedRegisters(char registerSetByte) {
    std::array<char, 9> wantedRegisters = {};

    // The 100k value is chosen because if it is lower it does not work, we're not quite sure why.
    // But we think it might be related to the BAUDrate
    for (int j = 0; j < 100000; j++) {
        char c;
        uart >> c;

        if (c == 0x59) {
            char dat[8];

            for (int i = 0; i < 8; i++) {
                uart >> dat[i];
            }

            if (dat[0] == 0x59) {
                int registerCounter = 0;

                if (registerSetByte >> 7) {
                    wantedRegisters[0] = 0x59;
                    wantedRegisters[1] = 0x59;
                    registerCounter += 2;
                }
                for (int i = 6; i >= 0; i--) { // Loop for 7 more times to fill in the remaining data package in the array.
                    if (((registerSetByte >> (i)) % 2)) { // checks if the array posistion of the check byte is 1.
                        wantedRegisters[registerCounter] = uart.receive();
                        registerCounter++;
                    }
                }
                return wantedRegisters;
            }
        }
    }
    return wantedRegisters;
}

int LIDARmini::getDistance() {
    std::array<char, 9> distanceRegisters =
        this->getWantedRegisters(LidarMiniRegisters::Distance); // 0110 0000 because we want the 2 dist registers
    int dist_L = distanceRegisters[0];                          // dist_L is register 2
    int dist_H = distanceRegisters[1];                          // dist_H is register 3
    return (dist_H << 8) | (dist_L);
}

int LIDARmini::getStrength() {
    std::array<char, 9> strengthRegisters =
        this->getWantedRegisters(LidarMiniRegisters::Strength); // 0001 1000 because we want the 2 strength registers
    int strength_L = strengthRegisters[0];                      // strength_L is register 4
    int strength_H = strengthRegisters[1];                      // strength_H is register 5
    return (strength_H << 8) | (strength_L);
}

int LIDARmini::getQualityDegree() {
    std::array<char, 9> qualityDegreeRegister =
        this->getWantedRegisters(LidarMiniRegisters::QualityDegree); // 0000 0010 because we want the quality register
    return qualityDegreeRegister[0];                                 // QualityDegree is register 8
}

int LIDARmini::getPerityByte() {
    std::array<char, 9> perityRegister =
        this->getWantedRegisters(LidarMiniRegisters::PerityByte); // 0000 0001 because we want the perity register
    return perityRegister[0];                                     // perity is register 9
}
