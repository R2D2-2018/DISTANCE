#ifndef UART_TEST_HPP
#define UART_TEST_HPP

#include "lidar_mini.hpp"
#include "uart_test_bench.hpp"

TEST_CASE("Lidar::getDistance()") {
    UARTTestBench<ConstantRx> uart{0x59, 0x59, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};

    LIDARmini lidar(uart);

    std::cout << std::hex << lidar.getDistance() << std::endl;
}

#endif // UART_TEST_HPP