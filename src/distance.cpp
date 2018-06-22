#include "distance.hpp"

/**
 * @file      distance.cpp
 * @brief     Cpp file for the class distance
 * @author    Wouter Dijksta
 * @date      31-5-2018
 * @license   MIT
 */

Distance::Distance(LIDARmini &lidar, HCSR04 &ultrasonic)
    : lidar(lidar), ultrasonic(ultrasonic), unit(Scale::CENTIMETERS), sensorType(SensorType::AUTOMATIC), filter(Filter::KALMAN) {
}

int Distance::getDistance() {
    if (sensorType == SensorType::LIDAR) {
        return lidar.getDistance();
    } else if (sensorType == SensorType::ULTRASONIC) {
        return ultrasonic.getDistance();
    } else if (sensorType == SensorType::AUTOMATIC) {
        int lidar_distance = lidar.getDistance();
        return lidar_distance > 35 ? lidar_distance : ultrasonic.getDistance();
    }

    return -1;
}

void Distance::setSensor(const Distance::SensorType sensorType) {
    this->sensorType = sensorType;
}

void Distance::setUnit(const Distance::Scale unit) {
    this->unit = unit;
}

void Distance::setFilter(const Distance::Filter filter, const int size) {
    this->filter = filter;
}

int Distance::convertToInches(int centimeters) {
    return 0.3937 * centimeters;
}