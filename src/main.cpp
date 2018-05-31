#include "lidar_mini.hpp"
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);

    LIDARmini lidar;
    hwlib::cout << lidar.getDistance() << "\r" << hwlib::endl;

    std::array<char, 9> registers = lidar.getWantedRegisters(0b01100000);
    hwlib::cout << int(registers[0]) << "\r" << hwlib::endl;

    std::array<char, 9> registers2 = lidar.getWantedRegisters(LidarMiniRegisters::Distance);
    hwlib::cout << int(registers2[0]) << "\r" << hwlib::endl;
}
