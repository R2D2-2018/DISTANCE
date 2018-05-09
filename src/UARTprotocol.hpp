#ifndef UARTprotocol_hpp
#define UARTprotocol_hpp
#include "wrap-hwlib.hpp"

class UARTprotocol {
    private:
        hwlib::target::pin_in RX1;
    public:
        UARTprotocol(hwlib::target::pin_in RX1);

        int ReadByte();

        bool WaitForStartByte();

        bool IsStartBit(int number);
};
#endif //x