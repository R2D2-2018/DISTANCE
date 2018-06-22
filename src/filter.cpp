#include "filter.hpp"

/**
 * @file      filter.cpp
 * @brief     Cpp file for the class filter which will contain different filters
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

int Median::get(int *values, const int size) {
    /// Sort the array before finding middle value(s)
    int j, temp;
    for (int i = 0; i < size; i++) {
        j = i;
        while (j > 0 && values[j] < values[j - 1]) {
            temp = values[j];
            values[j] = values[j - 1];
            values[j - 1] = temp;
            j--;
        }
    }
    /// If the size of the array is uneven, return the middle value. Else return the average of the two middle values.
    return (size % 2) ? values[size / 2] : (values[size / 2 - 1] + values[size / 2]) / 2;
}

int Kalman::get(int *values, const int size) {
    /// Dummy functionality, returns first value in array:
    return values[0];
}