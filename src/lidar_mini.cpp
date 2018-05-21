#include "lidar_mini.hpp"
#include "uart_protocol.hpp"


LIDARmini::LIDARmini(hwlib::target::pin_in RX):
    RX(RX)
{}

char * LIDARmini::getDistance() 
{
    UARTprotocol uart(RX, 1000);

    //uart.waitForStart();
 
    for (int i = 0; i < 8; ++i) {          
         bytes[i] = uart.getByte();
    }

    return bytes.begin();
}
