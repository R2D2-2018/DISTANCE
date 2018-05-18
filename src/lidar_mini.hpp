#ifndef LIDAR_MINI_HPP
#define LIDAR_MINI_HPP
#include "wrap-hwlib.hpp"
#include "uart_protocol.hpp"
#include <array>
/**
 * @class LIDARmini
 * @author Wouter Dijkstra and Kiet van Osnabrugge
 * @date 8-5-2018
 * @file lidar_mini.hpp
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

    std::array<char, 7> bytes;

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
    char * getDistance();
   
};

#endif //LIDAR_MINI_HPP