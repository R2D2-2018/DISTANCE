#include "HCSR04.hpp"

/**
 * @file      HCSR04.cpp
 * @brief     CPP file for the class HCSR04 which will contain functions to control the HCSR04 ultrasonic sensor
 * @author    Wouter Dijksta
 * @date      29-5-2018
 * @license   MIT
 */

HCSR04::HCSR04(hwlib::pin_out &trigger_pin, hwlib::pin_in &echo_pin) : trigger_pin(trigger_pin), echo_pin(echo_pin) {
}

int HCSR04::getDistance() {
    trigger_pin.set(0);
    trigger_pin.set(1);
    hwlib::wait_us(10);
    trigger_pin.set(0);
    /// Wait for first signal from echo pin
    while (!echo_pin.get()) {
    }
    /// Get current time
    long long int duration = hwlib::now_us();
    /// While the first pulse has just occurred, keep on looping until echo_pin returns false.
    while (echo_pin.get()) {
    }
    /// Calculate distance by calculating the delta duration
    duration = hwlib::now_us() - duration;
    int distance = (int)(duration / 58);

    /// Return distance, when it exceeds it's maximum range; it returns 400.
    return distance < 400 ? distance : 400;
}