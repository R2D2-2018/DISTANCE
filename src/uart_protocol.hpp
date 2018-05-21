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
    	* @brief gets a bite form the RX pin
        *
        * This function gets a bite a bit at a time form the RX pin.
        *
        * @return 
        * Char : result a byte
        */
        char getByte();

        /**
        * @brief Short description of foo
        * [BLANK]
        * description of foo
        * [BLANK]
        * @param[in]     a    What is the input for the function
        * @return What will the function return
        */
        bool waitForStart();
    };

#endif // LIDAR_HPP