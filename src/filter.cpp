#include "filter.hpp"

//Filter::Filter();

int Filter::MadainFilterEightBytes(int bytes[8]) {
    int preByte = 0;
    int totalByte = 0;
    for(int i = 0; i < 8; i++){
            totalByte = preByte + bytes[i];
            preByte = bytes[i];
    }
    return totalByte / 8;
}