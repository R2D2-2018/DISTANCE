#include "distance.hpp"

/**
 * @file      distance.cpp
 * @brief     Cpp file for the class distance
 * @author    Wouter Dijksta
 * @date      31-5-2018
 * @license   MIT
 */

Distance::Distance(LIDARmini &lidar, HCSR04 &ultrasonic)
    : lidar(lidar), ultrasonic(ultrasonic), unit(Scale::CENTIMETERS), sensorType(SensorType::AUTOMATIC), filter(average) {
}

int Distance::getDistance() {
    int distance = -1;
    if (sensorType == SensorType::LIDAR) {
        distance = lidar.getDistance();
    } else if (sensorType == SensorType::ULTRASONIC) {
        distance = ultrasonic.getDistance();
    } else if (sensorType == SensorType::AUTOMATIC) {
        int ultrasonic_distance = ultrasonic.getDistance();
        distance = (ultrasonic_distance <= 30 ? ultrasonic_distance : lidar.getDistance());
    }
    values.enqueue(distance);
    int filtered_distance = filter.get(values);
    values.pop();
    values.enqueue(filtered_distance);
    return filtered_distance;
}

void Distance::setSensor(const Distance::SensorType sensorType) {
    this->sensorType = sensorType;
}

void Distance::setUnit(const Distance::Scale unit) {
    this->unit = unit;
}

void Distance::setFilter(const Filter &filter) {
    this->filter = filter;
}

int Distance::convertToInches(int centimeters) {
    return 0.3937 * centimeters;
}