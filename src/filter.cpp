#include "filter.hpp"

/**
 * @file      filter.cpp
 * @brief     Cpp file for the class filter which will contain different filters
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

int Median::get(CyclicQueue<int, 10> values) {
    ///< Sort the array before finding middle value(s)
    for (int i = 0; i < values.getCount(); i++) {
        int j = i;
        while (j > 0 && values[j] < values[j - 1]) {
            int temp = values[j];
            values[j] = values[j - 1];
            values[j - 1] = temp;
            j--;
        }
    }
    ///< If the values.getCount() of the array is uneven, return the middle value. Else return the average of the two middle values.
    return (values.getCount() % 2) ? values[values.getCount() / 2]
                                   : (values[values.getCount() / 2 - 1] + values[values.getCount() / 2]) / 2;
}

int Average::get(CyclicQueue<int, 10> values) {
    int sum = 0;
    for (int i = 0; i < values.getCount(); i++) {
        sum += values[i];
    }
    return round((float)sum / values.getCount());
}