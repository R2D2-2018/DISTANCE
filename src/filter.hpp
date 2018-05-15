#ifndef filter_hpp
#define filter_hpp
#include "wrap-hwlib.hpp"

/**
 * @class Filter.h
 * @author Wouter Dijkstra and Kiet van Osnabrugge
 * @date 9-5-2018
 * @file Filter.hpp
 * @brief Class that will contain differnt filter methods for sensor data
 */
class Filter {
    public:

        int MadainFilterEightBytes(int bytes[8]);//we made the choice to use 8 because 
        //that was what we found enough for a good medain and is still fast enough
};

#endif //x