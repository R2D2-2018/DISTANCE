#ifndef FILTER_TEST_HPP
#define FILTER_TEST_HPP

#include "catch.hpp"
#include "filter.hpp"
/**
 * @brief Filter base class test
 * @details
 * This test case checks whether or not an instance of a derived Filter class can be accessed
 * by its base class using a pointer.
 */

TEST_CASE("Filter::get()", "[base class]") {
    CyclicQueue<int, 10> values = {9, 6, 3, 4, 7, 1, 8, 2};
    ///< Class instance call
    Median median = Median();
    Filter *filter = &median;
    ///< Since the amount of values is even, it will be the average of 4 and 6.
    REQUIRE(filter->get(values) == 5);        // should pass
    REQUIRE_FALSE(filter->get(values) == -1); // should fail
}

/**
 * @brief Median class test, even
 * @details
 * This test case checks whether the median class returns the correct median value
 * given a random set of integers. The amount of integers is even.
 */

TEST_CASE("Median::get() even", "[median]") {
    CyclicQueue<int, 10> values = {9, 6, 3, 4, 7, 1, 8, 2};
    ///< Class instance call
    Median median = Median();
    ///< Since the amount of values is even, it will be the average of 4 and 6.
    REQUIRE(median.get(values) == 5);        // should pass
    REQUIRE_FALSE(median.get(values) == -1); // should fail
}

/**
 * @brief Median class test, odd
 * @details
 * This test case checks whether the median class returns the correct median value
 * given a random set of integers. The amount of integers is uneven.
 */

TEST_CASE("Median::get() odd", "[median]") {
    CyclicQueue<int, 10> values = {6, 3, 4, 5, 1, 8, 2};
    ///< Class instance call
    Median median = Median();
    ///< Since the amount of values is odd, it will be the middle value (in this case, 4).
    REQUIRE(median.get(values) == 4);        // should pass
    REQUIRE_FALSE(median.get(values) == -1); // should fail
}

/**
 * @brief Average class test
 * @details
 * This test case checks whether the average class returns the correct average value
 * given a random set of integers.
 */

TEST_CASE("Average::get()", "[average]") {
    CyclicQueue<int, 10> values = {6, 3, 4, 5, 1, 8, 2};
    ///< Class instance call
    Average average = Average();
    ///< sum of all values is 29. 29/7 = 4.14, so the average should be 4.
    REQUIRE(average.get(values) == 4);        // should pass
    REQUIRE_FALSE(average.get(values) == -1); // should fail
}

TEST_CASE("FIR::get()", "[FIR]") {
    CyclicQueue<int, 10> values = {1, 2, 3, 4, 5, 10, 2};
    ///< Class instance call
    FIR<-1, 2, -1> fir = FIR<-1, 2, -1>();
    ///< Applying kernel <-1, 2, -1> on the values {x-1, x, x+1} should result in the value 0.
    ///< Doing the same for values {4, 5, 10} and {5, 10, 2} should result in the values
    ///< -4 and 13 respectively. Size parameter is defaulted to the kernel size.
    REQUIRE(fir.get(values) == 0);
    values.dequeue();
    REQUIRE(fir.get(values) == 0);
    values.dequeue();
    hwlib::cout << values.peakNext();
    REQUIRE(fir.get(values) == 0);
    values.dequeue();
    REQUIRE(fir.get(values) == -4);
    values.dequeue();
    REQUIRE(fir.get(values) == 13);
    ///< Testing a different filter.
    FIR<-1, -1, 4, -1, -1> fir2 = FIR<-1, -1, 4, -1, -1>();
    values = {1, 2, 3, 4, 5, 10, 2};
    REQUIRE(fir2.get(values) == 0);
    values.dequeue();
    ///< Applying <-1, -1, 4, -1, -1> on {2, 3, 4, 5, 10} should result in the value -4.
    REQUIRE(fir2.get(values) == -4);
}

#endif ///< FILTER_TEST_HPP