#ifndef LIDAR_HPP
#define LIDAR_HPP
#include "wrap-hwlib.hpp"
/**
 * @class UARTprotocol
 * @author Wouter Dijkstra and Kiet van Osnabrugge
 * @date 8-5-2018
 * @file UARTprotocl.hpp
 * @brief This class will contain functions for other classes to use the uart protocol.
 */
class UARTprotocol {
    public:
        hwlib::target::pin_in& RX;
        int waitStartByteCycles;

        UARTprotocol(hwlib::target::pin_in& RX, int waitStartByteCycles);

        /**
    	* @brief gets a byte form the RX pin
        *
        * This function gets a byte one bit at a time from the RX pin.
        *
        * @return 
        * char : returns a char (which corrosponds to a byte)
        */
        char getByte();

        /**
        * @brief Waits until the start byte is found
        * 
        * This function loops until two start bytes have been found or until a specified amount of tries has been reached.
        * 
        * @returns boolean value
        */
        bool waitForStart();
    };

#endif // LIDAR_HPP