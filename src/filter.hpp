#ifndef FILTER_HPP
#define FILTER_HPP
#include "wrap-hwlib.hpp"

/**
 * @file      filter.hpp
 * @brief     Hpp file for the class filter which will contain differnet filters
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

/**
 * @class Filter
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