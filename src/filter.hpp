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

        int MadainFilterEightBytes(int bytes[8]);
};

#endif //x