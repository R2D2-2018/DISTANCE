#include "LIDARmini.hpp"

LIDARmini::LIDARmini(hwlib::target::pin_in RX):
    RX(RX)
{}
      
int LIDARmini::GetDistanceInCM() {
    int distance[8];
    UARTprotocol UARTprotocol(RX); //needs to be moved
    UARTprotocol.WaitForStartByte(59);
    for(int i = 0; i < 8; i++){
        distance[i] = UARTprotocol.ReadByte();
    }
    return distance[0];//temporarily
}