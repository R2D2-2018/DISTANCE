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
    hwlib::wait_ms(2);
    trigger_pin.set(1);
    hwlib::wait_ms(10);
    trigger_pin.set(0);

    // Receive pulse
    bool received = echo_pin.get();

    // Get current time
    int duration = (int)hwlib::now_us();

    while (!received) {
        received = echo_pin.get();
    }
    while (received) {
        received = echo_pin.get();
    }

    // Calculate distance
    duration = (int)((hwlib::now_us() - duration) - 400);
    int distance = (int)((duration / 2) / 29.1);

    // Return distance, when it exceeds it's maximum range; it returns 400.
    return distance < 400 ? distance : 400;
}