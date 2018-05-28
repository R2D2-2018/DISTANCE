<<<<<<< HEAD
#include "filter.hpp"
#include "lidar_mini.hpp"
#include "uart_protocol.hpp"
=======
#include "lidar_mini.hpp"
#include "uart_connection.hpp"
>>>>>>> feature-Use_uart_Lib
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    hwlib::wait_ms(1000);
<<<<<<< HEAD

    LIDARmini lidar(RX1);

    lidar.getDistanceInCm();
=======
>>>>>>> feature-Use_uart_Lib
}
