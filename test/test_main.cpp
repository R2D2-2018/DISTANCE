#define CATCH_CONFIG_MAIN ///< This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "filter.hpp"
#include "hcsr04_test.hpp"
#include "lidar_mini.hpp"
#include "lidar_test.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("Filter::get()", "[base class]") {
    const int size = 8;
    int values[size] = {9, 6, 3, 4, 7, 1, 8, 2};
    /// Class instance call
    Median median = Median();
    Filter *filter = &median;
    /// Since the amount of values is even, it will be the average of 4 and 6.
    REQUIRE(filter->get(values, size) == 5);        // should pass
    REQUIRE_FALSE(filter->get(values, size) == -1); // should fail
}

TEST_CASE("Median::get() even", "[median]") {
    const int size = 8;
    int values[size] = {9, 6, 3, 4, 7, 1, 8, 2};
    /// Class instance call
    Median median = Median();
    /// Since the amount of values is even, it will be the average of 4 and 6.
    REQUIRE(median.get(values, size) == 5);        // should pass
    REQUIRE_FALSE(median.get(values, size) == -1); // should fail
}

TEST_CASE("Median::get() odd", "[median]") {
    const int size = 7;
    int values[size] = {6, 3, 4, 5, 1, 8, 2};
    /// Class instance call
    Median median = Median();
    /// Since the amount of values is odd, it will be the middle value (in this case, 4).
    REQUIRE(median.get(values, size) == 4);        // should pass
    REQUIRE_FALSE(median.get(values, size) == -1); // should fail
}

TEST_CASE("Kalman::get()", "[kalman]") {
    /// Kalman filter is still dummy code which returns the first element of the array.
    const int size = 2;
    int values[size] = {6, 5};
    /// Class instance call
    Kalman kalman = Kalman();
    REQUIRE(kalman.get(values, size) == 6);
    REQUIRE_FALSE(kalman.get(values, size) == -1);
}
