#include "uart_protocol.hpp"

UARTprotocol::UARTprotocol(hwlib::target::pin_in RX): 
    RX(RX)
{}

int UARTprotocol::ReadByte() {
    unsigned int number = 0;
    for(int i = 0; i < 8; i++) {
        number = number << 1;
        if (RX.get()){
            number++;
        }
    }
    return number;
}

void UARTprotocol::WaitForStartByte(int StartByte) {
    unsigned int number = 0;
    while(!IsStartByte(StartByte, number)){
        number = number << 1;
        if (RX.get()){
            number++;
        }
        if (number > 255){
            if ((number % 2) == 0) {
                number = number / 2;
            } else {
                number = number / 2;
                number++;
            }
        }
    }
    return;
}

bool UARTprotocol::IsStartByte(int StartByte, int number) {
    if(number == StartByte){
        return true;
            } else {
        return false;
    }
}

int UARTprotocol::ReadParityByte(){
    return 50;
}

void UARTprotocol::WaitForStopByte(int stopByte){
    hwlib::wait_ms(50);
    return;
}

bool UARTprotocol::IsStopByte(int stopByte, int number){
    return true;
}