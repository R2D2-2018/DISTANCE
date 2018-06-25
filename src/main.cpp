#include "distance.hpp"
#include "lidar_mini.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);

    target::pin_out trigger_pin = target::pin_out(target::pins::d7);
    target::pin_in echo_pin = target::pin_in(target::pins::d6);
    HCSR04 ultrasonic = HCSR04(trigger_pin, echo_pin);

    UARTLib::HardwareUART uart = UARTLib::HardwareUART(115200);
    LIDARmini lidar = LIDARmini(uart);

    Distance d = Distance(lidar, ultrasonic);
    d.setSensor(Distance::SensorType::ULTRASONIC);
    d.setFilter(d.average);
    while (1) {
        hwlib::cout << d.getDistance() << "\r\n";
        hwlib::wait_ms(100);
    }
}
