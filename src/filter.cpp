#include "filter.hpp"

/**
 * @file      filter.cpp
 * @brief     Cpp file for the class filter which will contain different filters
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

int Median::get(std::array<int> values) {
    /// Sort the array before finding middle value(s)
    std::sort(values.begin(), values.end());
    int length = values.size();
    /// If the length of the array is uneven, return the middle value. Else return the average of the two middle values.
    return (length % 2) ? values[length / 2] : (values[length / 2 - 1] + values[length / 2]) / 2;
}

int Kalman::get(std::array<int> values) {
    /// Dummy functionality:
    return values[0];
}