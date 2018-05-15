#ifndef LIDAR_MINI_HPP
#define LIDAR_MINI_HPP
#include "wrap-hwlib.hpp"
#include "uart_protocol.hpp"

/**
 * @class LIDARmini.h
 * @author Wouter Dijkstra and Kiet van Osnabrugge
 * @date 8-5-2018
 * @file LIDARmini.hpp
 * @brief Class for the TF LIDAR Mini
 */
class LIDARmini {
private:
    hwlib::target::pin_in RX;
public:

    /**
     * @brief Constructor
     */
    LIDARmini(hwlib::target::pin_in RX);

    /**
     * @brief 
     * Returns the distance in cm
     * 
     * @description 
     * Calculates the distance with the uart protocol of the data that comes in over the RX port in cm
     * 
     * @return 
     * int : the distance in cm
     */  
    int GetDistanceInCM();
   
};

#endif //LIDAR_MINI_HPP