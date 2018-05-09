#include "wrap-hwlib.hpp"
#include "LIDARmini.hpp"
#include "UARTprotocol.hpp"
#include "filter.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!" << hwlib::endl;

    auto pin = hwlib::target::pin_out(hwlib::target::pins::d19);

    LIDARmini lidar(pin);
    lidar.doSomething(50);

    UARTprotocol uart(50);
    uart.func();

    Filter filt(50);
    filt.func();
    
    return 0;
}
