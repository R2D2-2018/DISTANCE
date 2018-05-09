#include "UARTprotocol.hpp"

UARTprotocol::UARTprotocol(int value): 
    value(value)
{}

void UARTprotocol::func() {
    hwlib::cout << "UART: " << value << hwlib::endl;
}