#include "lidar_mini.hpp"
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);

    LIDARmini lidar;

    // lidar.setRegisterSetByte(0xFF);
    std::array<char, 9> bytes2 = lidar.getWantedRegisters(0x98);
    for (int i = 0; i < 9; i++) {
        hwlib::cout << "Byte: " << int(bytes2[i]) << "\r" << hwlib::endl;
    }

    hwlib::cout << lidar.getDistance() << "\r" << hwlib::endl;
    hwlib::cout << lidar.getStrength() << "\r" << hwlib::endl;
    hwlib::cout << lidar.getQualityDegree() << "\r" << hwlib::endl;
}
