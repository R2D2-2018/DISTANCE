#include "uart_protocol.hpp"


UARTprotocol::UARTprotocol(hwlib::target::pin_in& RX, int waitStartByteCycles):
    RX(RX),
    waitStartByteCycles(waitStartByteCycles)
{}


char UARTprotocol::getByte()
{
    int result = 0;
    for (int i = 0; i < 8; ++i)
    {
        result *= 2;
        result += RX.get();
    }
    return result;
}


bool UARTprotocol::waitForStart()
{
    char buffer = 0;
    for (int t = 0; t < waitStartByteCycles; ++t)
    {
        buffer <<= 1;
        buffer = buffer | RX.get();
        if (buffer == 59)
        {
            for (int i = 0; i < 8; ++i)
            {
                buffer = buffer | RX.get();
            }
            if (buffer == 59)
            {
                return true;
            }
        }
    }
    //hwlib::cout << "Tried " << waitStartByteCycles << " times." << hwlib::endl;
    return false;
}