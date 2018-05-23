#include "lidar_mini.hpp"

/**
 * @file      lidar_mini.cpp
 * @brief     Cpp file for the class LIDARmini which will contain functions to control the LIDARmini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

LIDARmini::LIDARmini(hwlib::pin_in& RX):
    RX(RX)
{}

bool LIDARmini::compairBytes(char byte1, char byte2){
    if(byte1 = byte2){
        return true;
    }
    return false;
}

bool LIDARmini::waitForStartByte(char startByte, int StartByteCycles){
    UARTConnection uart(115200, UARTController::ONE, 1);
    for(int i = 0; i < StartByteCycles; ++i){
        char receivedByte = uart.receive();
        if(compairBytes(receivedByte, startByte)){
            return true;
        }
    }
    return false;
}

char * LIDARmini::getDistanceInCm(char startByte) {
    UARTConnection uart(115200, UARTController::ONE, 1);//115200 is the bautrate
    char bytes[8] = {};
    if(waitForStartByte(startByte, 18)){  //18 is the size of 2 full data packages
        for (int i = 0; i < 8; ++i) {          
            bytes[i] = uart.receive();
        }
    }
    return bytes;
}

void LIDARmini::printByte(char bytes[8]){
    for(int i = 0; i < 8; ++i){
        hwlib::cout<<bytes[i]<<" ";
    }
    hwlib::cout<<hwlib::endl;
}
