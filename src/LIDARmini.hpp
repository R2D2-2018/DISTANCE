#ifndef LIDARmini_hpp
#define LIDARmini_hpp
#include "wrap-hwlib.hpp"

/**
 * @class LIDARmini.h
 * @author Wouter Dijkstra
 * @date 8-5-2018
 * @file LIDARmini.hpp
 * @brief Class for the TF LIDAR Mini
 */
class LIDARmini {
private:
    hwlib::target::pin_in pin;
public:

    /**
     * @brief Constructor
     */
    LIDARmini(hwlib::target::pin_in pin);

    void doSomething(int x);
   
};

#endif //LIDARmini_hpp