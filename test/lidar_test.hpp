#ifndef UART_TEST_HPP
#define UART_TEST_HPP

#include "lidar_mini.hpp"

TEST_CASE("Lidar::getDistance()") {
    // UARTTestBench<ConstantRx> uart{0x59, 0x59, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
    UARTLib::MockUART connMock(115200, UARTLib::UARTController::ONE);

    LIDARmini lidar(connMock);

    std::cout << std::hex << lidar.getDistance() << std::endl;
}

#endif ///< UART_TEST_HPP