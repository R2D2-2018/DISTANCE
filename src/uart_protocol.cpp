#include "uart_protocol.hpp"

/**
 * @file      uart_protocol.cpp
 * @brief     Cpp file for the class UARTProtocol which will contain functions use a UARTProtocol which is needed for the LIDARmini class.
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

UARTProtocol::UARTProtocol(hwlib::target::pin_in& RX, int waitStartByteCycles):
    RX(RX),
    waitStartByteCycles(waitStartByteCycles)
{}


char UARTProtocol::getByte()
{
    int result = 0;
    for (int i = 0; i < 8; ++i)
    {
        result *= 2;
        result += RX.get();
    }
    return result;
}


bool UARTProtocol::waitForStart()
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