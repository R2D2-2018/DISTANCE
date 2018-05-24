#include "filter.hpp"
#include "lidar_mini.hpp"
#include "uart_connection.hpp"
#include "uart_protocol.hpp"
#include "wrap-hwlib.hpp"
#include <array>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    auto RX1 = target::pin_in(target::pins::d19);

    hwlib::wait_ms(1000);
    // std::array<char, 7> bytes;

    LIDARmini lidar(RX1);
    while (1) {
        hwlib::wait_ms(500);
        // char* bytes;
        auto bytes = lidar.getDistanceInCm();
        // Print array
        hwlib::cout << "array2: " << int(bytes[0]) << " ";
        /*for (int i = 0; i<7; i++) {
            hwlib::cout << "array" << i << ":" << (int) bytes[i] << " ";
        }*/
    }

    /*while (1) {
        // hwlib::wait_ms(500);
        

        if (uart.available() >= 9) { // Atleast 9 bytes need to be available, as our data package in total contains 9 bytes.
        




            if (uart.receive() == 0x59 && uart.receive() == 0x59) { // Check if startbyte is available.., twice.
                    for (int i = 0; i < 7; i++) { // Loop for 7 more times to print the remaining data package.
                        char rc = uart.receive();
                        hwlib::cout << "Byte " << i << ": " << (int) rc << " ";
                        bytes[i] = rc;
                    }

                    //Print array
                    for (int i = 0; i<7; i++) {
                        hwlib::cout << "array" << i << ":" << (int) bytes[i] << " ";
                    }

                    hwlib::cout << hwlib::endl;
                    hwlib::wait_ms(2500);
            }
        }
    }*/
}
