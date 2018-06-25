#ifndef FILTER_HPP
#define FILTER_HPP

#include "cyclic_queue.hpp"
#include "wrap-hwlib.hpp"
#include <array>
#include <math.h>

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
     * @param CyclicQueue<int, 10> The most recent set of (filtered) values, including the latest raw value.
     * @return
     * int : The filtered value or an error value (-1)
     */
    virtual int get(CyclicQueue<int, 10> values) = 0;
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
     * @param CyclicQueue<int, 10> The most recent set of (filtered) values, including the latest raw value.
     * @return
     * int : The median-filtered value or an error value (-1)
     */
    int get(CyclicQueue<int, 10> values) override;
};

/**
 * @class Average
 * @brief Average filter derived from base Filter class
 * Implements an average filter as per the interface provided by Filter.
 */

class Average : public Filter {
  public:
    /**
     * @brief
     * Returns an average-filtered value
     *
     * @description
     * Get-function which, when given an array containing any amount of values,
     * will return an average value.
     *
     * @param CyclicQueue<int, 10> The most recent set of (filtered) values, including the latest raw value.
     * @return
     * int : The average value or an error value (-1)
     */
    int get(CyclicQueue<int, 10> values) override;
};

/**
 * @class FIR
 * @brief FIR filter derived from base Filter class
 * Implements an FIR filter as per the interface provided by Filter.
 * The kernel is specified by a parameter pack of integers.
 *
 * @tparam int... A list of integers which are stored inside a vector at construction.
 */

template <int... Is>
class FIR : public Filter {
  private:
    std::array<int, sizeof...(Is)> kernel{{Is...}};

  public:
    /**
     * @brief
     * Returns an FIR-filtered value
     *
     * @description
     * Get-function which, when given an array containing any amount of values,
     * will return an FIR-filtered value based on the template kernel.
     * The size parameter is defaulted to the kernel size and should not be overridden,
     * lest you dare invoke the wrath of std::vector's error handling.
     * The reason the entire function is defined here is because it is dependent on the template call.
     * Defining the function in the .cpp file requires us to call the template again.
     *
     * @param CyclicQueue<int, 10> The most recent set of (filtered) values, including the latest raw value.
     * @return
     * int : The FIR-filtered value or an error value (-1)
     */
    int get(CyclicQueue<int, 10> values) override {
        int return_value = 0;
        for (unsigned int i = 0; i < sizeof...(Is); i++) {
            return_value += values[i] * kernel[i];
        }
        return return_value;
    }
};

#endif // FILTER_HPP