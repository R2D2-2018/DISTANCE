#ifndef FILTER_HPP
#define FILTER_HPP
#include "wrap-hwlib.hpp"
#include <array>

/**
 * @file      filter.hpp
 * @brief     Hpp file for the class filter which will contain different filters
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

/**
 * @class Filter
 * @brief Base interface class for all filters
 * All filters shall be derived from this base class.
 */
class Filter {
  public:
    /**
     * @brief
     * Returns a filtered value
     *
     * @description
     * Virtual function which, when given a set of (previous) values, will return a filtered value.
     *
     * @param int[] A pointer to the most recent set of (filtered) values, including the latest raw value.
     * @param int Size of the aforementioned set of values.
     * @return
     * int : The filtered value or error value (-1)
     */
    virtual int get(int *values, const int size) = 0;
};
/**
 * @class Median
 * @brief Median filter derived from base Filter class
 * Implements a median filter as per the interface provided by Filter.
 */
class Median : public Filter {
  public:
    /**
     * @brief
     * Returns a median-filtered value
     *
     * @description
     * Get-function which, when given a set of (previous) values, will return a median-filtered value.
     *
     * @param int[] A pointer to the most recent set of (filtered) values, including the latest raw value.
     * @param int Size of the aforementioned set of values.
     * @return
     * int : The median-filtered value or error value (-1)
     */
    int get(int *values, const int size) override;
};

/**
 * @class Filter
 * @brief Median filter derived from base Filter class
 * Implements a median filter as per the interface provided by Filter.
 */

class Kalman : public Filter {
  public:
    /**
     * @brief
     * Returns a kalman-filtered value
     *
     * @description
     * Get-function which, when given an array containing the latest raw-
     * and filtered value (in that respective order), will return a Kalman-filtered value.
     *
     * @param int[] A pointer to the most recent raw- and filtered value in that respective order.
     * @param int Size of the aforementioned set of values.
     * @return
     * int : The Kalman-filtered value or error value (-1)
     */
    int get(int *values, const int size) override;
};

#endif // FILTER_HPP