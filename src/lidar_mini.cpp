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
    auto distanceRegisters = getWantedRegisters<LidarMiniRegisters::Distance>(); // 0110 0000 because we want the 2 dist registers
    int dist_L = distanceRegisters[0];                                           // dist_L is register 2
    int dist_H = distanceRegisters[1];                                           // dist_H is register 3
    return (dist_H << 8) | (dist_L);
}

int LIDARmini::getStrength() {
    auto strengthRegisters =
        getWantedRegisters<LidarMiniRegisters::Strength>(); // 0001 1000 because we want the 2 strength registers
    int strength_L = strengthRegisters[0];                  // strength_L is register 4
    int strength_H = strengthRegisters[1];                  // strength_H is register 5
    return (strength_H << 8) | (strength_L);
}

int LIDARmini::getQualityDegree() {
    auto qualityDegreeRegister =
        getWantedRegisters<LidarMiniRegisters::QualityDegree>(); // 0000 0010 because we want the quality register
    return qualityDegreeRegister[0];                             // QualityDegree is register 8
}

int LIDARmini::getPerityByte() {
    auto perityRegister = getWantedRegisters<LidarMiniRegisters::PerityByte>(); // 0000 0001 because we want the perity register
    return perityRegister[0];                                                   // perity is register 9
}
