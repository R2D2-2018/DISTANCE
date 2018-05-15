#include "lidar_mini.hpp"

enum LiDarminiEnum{
    startByte = 59,
    dataPackageSize = 8
};

LIDARmini::LIDARmini(hwlib::target::pin_in RX):
    RX(RX)
{}
      
int LIDARmini::GetDistanceInCM() {
    int distance[dataPackageSize];
    UARTprotocol UARTprotocol(RX); //needs to be moved
    UARTprotocol.WaitForStartByte(startByte);
    for(int i = 0; i < dataPackageSize; i++){
        distance[i] = UARTprotocol.ReadByte();
    }
    return distance[0];//temporarily
}