#include "uart_protocol.hpp"

/**
 * @file      uart_protocol.cpp
 * @brief     Cpp file for the class UARTProtocol which will contain functions use a UARTProtocol which is needed for the LIDARmini
 * class.
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

enum class uartEnum { startByte = 59, sizeDataPackage = 8 };

UARTProtocol::UARTProtocol(hwlib::pin_in &RX, int waitStartByteCycles) : RX(RX), waitStartByteCycles(waitStartByteCycles) {
}

char UARTProtocol::getByte() {
    int result = 0;
    for (int i = 0; i < 8; ++i) // 8 is size of a byte
    {
        result *= 2; // 2 to make the binary number one digit bigger
        result += RX.get();
    }
    return result;
}

bool UARTProtocol::waitForStart() {
    char buffer = 0;
    for (int t = 0; t < waitStartByteCycles; ++t) {
        buffer <<= 1;
        buffer = buffer | RX.get();
        if (buffer == char(uartEnum::startByte)) {
            for (int i = 0; i < int(uartEnum::sizeDataPackage); ++i) {
                buffer = buffer | RX.get();
            }
            if (buffer == char(uartEnum::startByte)) {
                return true;
            }
        }
    }
    return false;
}