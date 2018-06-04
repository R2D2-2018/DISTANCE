#include "distance.hpp"

/**
 * @file      distance.cpp
 * @brief     Cpp file for the class distance
 * @author    Wouter Dijksta
 * @date      31-5-2018
 * @license   MIT
 */

Distance::Distance(LIDARmini *lidar) : lidar(lidar), ultrasonic(nullptr) {
}

Distance::Distance(HCSR04 *ultrasonic) : lidar(nullptr), ultrasonic(ultrasonic) {
}

Distance::Distance(LIDARmini *lidar, HCSR04 *ultrasonic) : lidar(lidar), ultrasonic(ultrasonic) {
}

int Distance::getDistance(Distance::SensorType sensorType, Distance::Scale scale) {
    if (sensorType == SensorType::LIDAR && lidar != nullptr) {
        return lidar->getDistance();
    } else if (sensorType == SensorType::ULTRASONIC && ultrasonic != nullptr) {
        return ultrasonic->getDistance();
    } else if (sensorType == SensorType::AUTOMATIC && lidar != nullptr && ultrasonic != nullptr) {
        int lidar_distance = lidar->getDistance();
        return lidar_distance > 35 ? lidar_distance : ultrasonic->getDistance();
    }
    return 1234;
}

int Distance::convertToInches(int centimeters) {
    return 0.3937 * centimeters;
}