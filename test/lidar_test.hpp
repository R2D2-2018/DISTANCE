#ifndef UART_TEST_HPP
#define UART_TEST_HPP

#include "lidar_mini.hpp"

TEST_CASE("Lidar::getDistance()") {
    UARTLib::MockUART connMock(115200, UARTLib::UARTController::ONE);

    LIDARmini lidar(connMock);
    ///< Seeing as we have a mock UART connection, getDistance() should return zero:
    REQUIRE(lidar.getDistance() == 0);
}

#endif ///< UART_TEST_HPP