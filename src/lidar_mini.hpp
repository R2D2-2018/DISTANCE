#ifndef LIDAR_MINI_HPP
#define LIDAR_MINI_HPP
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"
#include <array>

enum class LidarMiniRegisters { Distance = 0b01100000, Strength = 0b00011000, QualityDegree = 0b00000010, PerityByte = 0b00000001 };

/**
 * @file      lidar_mini.hpp
 * @brief     Hpp file for the class LIDARmini which will contain functions to control the TF LIDAR mini sensor
 * @author    Wouter Dijksta and Kiet van Osnabrugge
 * @date      21-5-2018
 * @license   MIT
 */

/**
 * @class LIDARmini
 * @brief Class for the TF LIDAR Mini
 */
class LIDARmini {
  private:
    UARTConnection uart;

  public:
    /**
     * @brief Constructor
     */
    LIDARmini();

    static constexpr int countHighBits(char c) {
        int highBits = 0;

        for (int i = 0; i < 8; i++) {
            if (c >> i == 1) {
                highBits++;
            }
        }

        return highBits;
    }

    /**
     * @brief
     * Returns an array with the wanted register data. You can tell the functions which register you want with the registerSetByte
     *
     * @description
     * The function will start looking for two startbytes that comes in trough the arduino RX1 pin.
     * If no startbytes are found with in a set amound of try's (100000) an empty array will be returned.
     * The amound of try's has been determent by tests and 100000 works correctly. We suspect the reason why the amound is so high
     * is because of the function needing to get in sick with the baudrate.
     *
     * After the function has detected two startbytes.
     * The function will check which posistions of the registerSetByte have a one and if so it will return those registers in an
     * array. The bytes of the registerSetByte corrospont with the registers of the lidar mini.
     *
     * registerSetByte bits and the corrosponding lidarmini register
     * 1 : StartBytes (register 1 and 2 are the same and both contain the startbyte)
     * 2 : dist_L (the low range distance data)
     * 3 : dist_H (the high range distance data)
     * 4 : strength_L (the low range strength data)
     * 5 : strength_H (the high range strength data)
     * 6 : reserved register
     * 7 : signal quality degree
     * 8 : perity register (sum of all registers minus the perity register itself ofcourse)
     *
     * So if registerSetByte = 10100100 the function will return the 2 startbytes, the dist_H and the reserved register.
     * The function puts these registers in a 9 byte big array this is because there will never be more the 9 registers to get the
     * data from
     *
     * @param
     * A char which is used as a binary byte and the bits corrosponts to the registers as explained in the discription.
     *
     * @return
     * A array with the requested register data.
     */
    template <char registerSetByte>
    auto getWantedRegisters() {
        std::array<char, countHighBits(registerSetByte)> wantedRegisters = {};

        // The 100k value is chosen because if it is lower it does not work, we're not quite sure why.
        // But we think it might be related to the BAUDrate
        for (int j = 0; j < 100000; j++) {
            if (uart.available() >= 9) { // 9 is the amound of bytes of the full data package
                if (uart.receive() == 0x59 &&
                    uart.receive() ==
                        0x59) { // Check if startbyte(0x59) is available.., twice. receive() pops an element of a stack
                    int registerCounter = 0;
                    if (registerSetByte >>
                        7) { // registerSetByte is a byte in which every bit corrosponts with a register of the sensor.
                        // in this case the most left bit is checked and if it's 1 then the start byte will be put in the array.
                        wantedRegisters[0] = 0x59;
                        wantedRegisters[1] = 0x59;
                        registerCounter = registerCounter + 2;
                    }
                    for (int i = 6; i >= 0; i--) { // Loop for 7 more times to fill in the remaining data package in the array.
                        if (((registerSetByte >> i) & 1) == 1) { // checks if the array posistion of the check byte is 1.
                            wantedRegisters[registerCounter] = uart.receive();
                            registerCounter++;
                        } else {
                            uart.receive();
                        }
                    }
                    break;
                }
            }
        }
        return wantedRegisters;
    }

    /**
     * @brief
     * Makes it so getwantedRegister accepts enums
     *
     * @description
     * This function gets in the enum which is a byte and the casts the byte to a char
     * and puts that into the getwantedregister function that uses chars.
     * After that the function will return the array it gets form the getWantedRegisters(char) function
     *
     * @param
     * A enum that is a byte which corrosponts to the registers of the sensor.
     *
     * @return
     * A array which contains the requested registers form the function.
     */
    template <LidarMiniRegisters registerSetByte>
    auto getWantedRegisters() {
        return getWantedRegisters<static_cast<char>(registerSetByte)>();
    }

    /**
     * @brief
     * Get distance in centimers
     *
     * @description
     * Returns the distance to an object in centimeters.
     * centimeters is the devalt scale of the sensor.
     *
     * @return
     * The distance value
     */
    int getDistance();

    /**
     * @brief
     * Returns the signal strength value
     *
     * @description
     * Returns the distance value that is made by merging two hex numbers (strength_L and strength_H register) and converting them
     * to integers.
     *
     * @return
     * The signal strength
     */
    int getStrength();

    /**
     * @brief
     * Returns the signal quality degree
     *
     * @description
     * Returns the quelity degree resieved form the quality degree register.
     *
     * @return
     * The queality degree
     */
    int getQualityDegree();

    /**
     * @brief
     * Returns the perity byte.
     *
     * @description
     * Returns the perity byte which is the sum of register 1 to 8.
     * This register only contains the lower byte.
     *
     * @return
     * The lower byte of the perity register
     */
    int getPerityByte();
};

#endif // LIDAR_MINI_HPP