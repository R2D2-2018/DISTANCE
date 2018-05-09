#include "wrap-hwlib.hpp"
#include "LIDARmini.hpp"
#include "UARTprotocol.hpp"
#include "filter.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

   // auto TX1 = target::pin_oc(target::pins::d18);
    auto RX1 = target::pin_in(target::pins::d19);

    hwlib::wait_ms(1000);
    
    UARTprotocol UARTprotocol(RX1);

}
