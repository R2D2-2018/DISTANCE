#include "filter.hpp"
#include "lidar_mini.hpp"
#include "uart_protocol.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    auto RX1 = target::pin_in(target::pins::d19);

    hwlib::wait_ms(1000);

    LIDARmini lidar(RX1);

    lidar.getDistanceInCm();
}
