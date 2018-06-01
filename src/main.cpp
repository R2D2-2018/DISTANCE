#include "distance.hpp"
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);

    auto trigger_pin = hwlib::target::pin_out(hwlib::target::pins::d7);
    auto echo_pin = hwlib::target::pin_in(hwlib::target::pins::d6);

    HCSR04 ultrasonic(trigger_pin, echo_pin);
    LIDARmini lidar;
    Distance distance(&lidar, &ultrasonic);

    while (1) {
        hwlib::cout << "Distance: " << distance.getDistance(Distance::SensorType::AUTOMATIC, Distance::Scale::CENTIMETERS)
                    << hwlib::endl;
    }
}
