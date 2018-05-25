#include "lidar_mini.hpp"
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);

    auto RX1 = target::pin_in(target::pins::d19);
    LIDARmini lidar(RX1);

    while (1) {
        hwlib::wait_ms(500);
        hwlib::cout << "Distance(CM): " << lidar.getDistance() << hwlib::endl;
    }
}
