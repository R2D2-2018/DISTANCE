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

    // Get current time
    long long int duration = hwlib::now_us();

    // Receive pulse
    bool received = echo_pin.get();

    // If the first pulse hasn't been received yet, wait until first pulse is found.
    if (!received) {
        while (!(received = echo_pin.get()))
            ;
    }
    // While the first pulse has just occurred, keep on looping until echo_pin returns false.
    while ((received = echo_pin.get()))
        ;

    // Calculate distance by converting duration to centiseconds,
    // multiplying with the speed of sound (343m/s) and dividing this roundtrip distance by two.
    duration = hwlib::now_us() - duration;
    int distance = (int)((duration / 29.1) / 2);

    // Return distance, when it exceeds it's maximum range; it returns 400.
    return distance < 400 ? distance : 400;
}