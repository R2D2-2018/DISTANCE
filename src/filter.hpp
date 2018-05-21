#ifndef FILTER_HPP
#define FILTER_HPP
#include "wrap-hwlib.hpp"

/**
 * @class Filter
 * @author Wouter Dijkstra and Kiet van Osnabrugge
 * @date 9-5-2018
 * @file Filter.hpp
 * @brief Class that will contain differnt filter methods for sensor data
 */
class Filter {
    public:

        /**
         * @brief 
         * Returns the median value
         * 
         * @description 
         * Determines the median value of a given array of integers
         * 
         * @return 
         * int : the median value
         */  
        int getMedian(int a[], int size);
};

#endif //FILTER_HPP