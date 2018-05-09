#include "UARTprotocol.hpp"

UARTprotocol::UARTprotocol(hwlib::target::pin_in RX1): 
    RX1(RX1)
{}

int UARTprotocol::ReadByte() {
    unsigned int number = 0;
    for(int i = 0; i < 8; i++) {
        number = number << 1;
        if (RX1.get()){
            number++;
        }
        //- eerste bit
    }
    return number;
}

bool UARTprotocol::WaitForStartByte() {
    unsigned int number = 0;
    while(!IsStartBit(number)){
        number = number << 1;
        if (RX1.get()){
            number++;
        }
        //- meest linker bit
    }
    return true;
}

bool UARTprotocol::IsStartBit(int number) {
        if(number == 59){
            return true;
        } else {
            return false;
        }
}