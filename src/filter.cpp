#include "filter.hpp"

/**
 * @file      filter.cpp
 * @brief     Cpp file for the class filter which will contain different filters
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

// TODO: Change to use C++ array
int Filter::getMedian(int list[], int length) {
    int i = 1;
    // TODO: Change to use for loop instead of while
    while (i < length) {
        for (int j = i; list[j - 1] > list[j]; j--) {
            int temp = list[j];
            list[j] = list[j - 1];
            list[j - 1] = temp;
        }
        i++;
    }

    return length % 2 ? list[length / 2] : (list[length / 2 - 1] + list[length / 2]) / 2;
}