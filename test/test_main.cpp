#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

//#include "../src/filter.cpp"
#include "../src/uart_protocol.cpp"
#include "../src/lidar_mini.cpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

/*TEST_CASE( "Filter::getMedian" ) {   
    Filter filter; 
    int a[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = sizeof(a)/sizeof(int);

    REQUIRE(filter.getMedian(a, size) == 4); // should pass
    REQUIRE_FALSE(filter.getMedian(a, size) == 9); // should fail
}*/

TEST_CASE("UARTprotocol::getByte") {// this tests is representing a hardware test but needs to be fixted by the leads.
    hwlib::test::pin_in<8>pin_in{1,0,1,0,1,0,1,0};
    UARTprotocol uart(pin_in);
    uart.getByte();
    REQUIRE(uart.getByte() = 170);
}

TEST_CASE("LIDARmini::getDistance") {
    hwlib::test::pin_in<8* 8>pin_in{
    0,0,0,0,0,0,0,1,
    0,0,0,0,0,0,1,0,
    0,0,0,0,0,1,0,0,
    0,0,0,0,1,0,0,0,
    0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,0,
    0,1,0,0,0,0,0,0,
    1,0,0,0,0,0,0,0
    };

    LIDARmini lidar(pin_in);
    lidar.getgetDistance();
    REQUIRE(lidar.getDistance() = 1)//returns a pointer to the first element and i dont know how to put that in a test with this test pin
    //functronality made by the leads
}

/*TEST_CASE( "UARTprotocol::IsStartByte" ) {
    REQUIRE(uart.IsStartByte(5, 5) == true); // should pass
    REQUIRE(uart.IsStartByte(1, 2) == true); // should fail
}*/

// TEST_CASE( "UARTprotocol::ReadParityByte" ) {
//     REQUIRE(uart.ReadParityByte() == 50); // should pass
//     REQUIRE(uart.ReadParityByte() != 50); // should fail
// }