#include "filter.hpp"

enum Enumfilter {
    amoundOfBytes = 8//we made the choice to use 8 because 
    //that was what we found enough for a good medain and is still fast enough
};

int Filter::MadainFilterEightBytes(int bytes[amoundOfBytes]) {
    int preByte = 0;
    int totalByte = 0;
    for(int i = 0; i < amoundOfBytes; i++){
            totalByte = preByte + bytes[i];
            preByte = bytes[i];
    }
    return totalByte / amoundOfBytes;
}