#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

// #include "../src/filter.hpp"
// #include "../src/UARTprotocol.hpp"
// #include "../src/LIDARmini.hpp"

// UARTprotocol uart(1);
// Filter filter;
// LIDARmini lidar(1);

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

// TEST_CASE( "Filter::getMedian" ) {    
//     int a[] = {1, 2, 3, 4, 5, 6, 8, 9};
//     int size = sizeof(a)/sizeof(int);

//     REQUIRE(filter.getMedian(a, size) == 4); // should pass
//     REQUIRE(filter.getMedian(a, size) == 9); // should fail
// }

// TEST_CASE( "UARTprotocol::IsStartByte" ) {
//     REQUIRE(uart.IsStartByte(5, 5) == true); // should pass
//     REQUIRE(uart.IsStartByte(1, 2) == true); // should fail
// }

// TEST_CASE( "UARTprotocol::ReadParityByte" ) {
//     REQUIRE(uart.ReadParityByte() == 50); // should pass
//     REQUIRE(uart.ReadParityByte() != 50); // should fail
// }