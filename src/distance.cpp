#include "distance.hpp"

/**
 * @file      distance.cpp
 * @brief     Cpp file for the class distance
 * @author    Wouter Dijksta
 * @date      31-5-2018
 * @license   MIT
 */

Distance::Distance(hwlib::target::pin_in &RX) : RX(&RX) {
}

Distance::Distance(hwlib::target::pin_out &trigger_pin, hwlib::target::pin_in &echo_pin)
    : trigger_pin(&trigger_pin), echo_pin(&echo_pin) {
}

Distance::Distance(hwlib::target::pin_out &trigger_pin, hwlib::target::pin_in &echo_pin, hwlib::target::pin_in &RX)
    : trigger_pin(&trigger_pin), echo_pin(&echo_pin), RX(&RX) {
}

int Distance::getDistance(Distance::Sensor sensor, Distance::Scale scale) {
    // Test
    if (sensor == Sensor::LIDAR) {
        return 1;
    } else if (sensor == Sensor::ULTRASONIC) {
        return 2;
    } else if (sensor == Sensor::AUTOMATIC) {
        return 3;
    }
    return 0;
}

int Distance::convertToInches(int centimeters) {
    return 1;
}