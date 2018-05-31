#include "distance.hpp"
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);

    auto trigger_pin = hwlib::target::pin_out(hwlib::target::pins::d7);
    auto echo_pin = hwlib::target::pin_in(hwlib::target::pins::d6);

    Distance distance(trigger_pin, echo_pin);

    hwlib::cout << "Distance: " << distance.getDistance(Distance::Sensor::AUTOMATIC, Distance::Scale::CENTIMETERS) << hwlib::endl;
}
