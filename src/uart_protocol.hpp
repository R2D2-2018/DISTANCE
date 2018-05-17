#ifndef UARTprotocol_hpp
#define UARTprotocol_hpp
#include "wrap-hwlib.hpp"

/**
 * @class UARTprotocol.h
 * @author Wouter Dijkstra and Kiet van Osnabrugge
 * @date 9-5-2018
 * @file UARTprotocol.hpp
 * @brief Class that can be used to use the UARTprotocol
 */
class UARTprotocol {
    private:
        hwlib::target::pin_in RX;
    public:
        UARTprotocol(hwlib::target::pin_in RX);

        /**
         * @brief 
         * Returns a byte 
         * 
         * @description 
         * Returns the byte that commes in form the RX port
         * 
         * @return 
         * int number : a byte
         */
        int ReadByte();

        /**
         * @brief 
         * Waits for start byte
         *
         * @description 
         * Waits till the startbyte commes in over the RX port
         *
         * @param
         * Int StartByte : The start byte that needs to be waited for
         */
        void WaitForStartByte(int startByte);

        /**
         * @brief Compares StartByte to a byte
         * 
         * @description 
         * If the startByte is the same as Byte the function will retun true
         *
         * @param
         * int StartByte : The StartByte that will be compaired with
         * int number : The Byte that the StartByte will be compaired with
         * 
         * @return
         * Bool : True or False
         */
        bool IsStartByte(int startByte, int number);

        /**
         * @brief 
         * Returns the paritybyte;
         * 
         * @description 
         * Returns the paritybyte that commes in form the RX port and knows if the sending of the data was correct
         * 
         * @return 
         * int number : paritybyte
         */
        int ReadParityByte();

        /**
         * @brief 
         * Waits for stop byte
         *
         * @description 
         * Waits till the stopbyte commes in over the RX port
         *
         * @param
         * Int StopByte : The stopbyte that needs to be waited for
         */
        void WaitForStopByte(int stopByte);

        /**
         * @brief Compares stopbyte to a byte
         * 
         * @description 
         * If the stopByte is the same as Byte the function will retun true
         *
         * @param
         * int stopByte : The stopByte that will be compaired with
         * int number : The Byte that the StopByte will be compaired with
         * 
         * @return
         * Bool : True or False
         */
        bool IsStopByte(int stopByte, int number);
};
#endif //UARTprotocol
