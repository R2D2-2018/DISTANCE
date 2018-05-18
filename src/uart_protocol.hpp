#ifndef LIDAR_HPP
#define LIDAR_HPP
#include "wrap-hwlib.hpp"

class UARTprotocol {
    public:
        hwlib::target::pin_in& RX;
        int waitStartByteCycles;

        UARTprotocol(hwlib::target::pin_in& RX, int waitStartByteCycles=5000);

        char getByte();
        bool waitForStart();
    };

#endif // LIDAR_HPP