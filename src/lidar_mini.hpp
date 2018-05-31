#ifndef LIDAR_MINI_HPP
#define LIDAR_MINI_HPP
#include "uart_connection.hpp"
#include "wrap-hwlib.hpp"
#include <array>

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
    explicit LIDARmini();

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
     * registerSetByte : char
     *
     * @return
     * wantedRegisters : std::array
     */
    std::array<char, 9> getWantedRegisters(char registerSetByte);

    /**
     * @brief
     * Get distance in centimers
     *
     * @description
     * Returns the distance to an object in centimeters
     *
     * @return
     * int : distance value
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
     * int : signal strength
     */
    int getStrength();

    /**
     * @brief
     * Returns the signal signal quality degree
     *
     * @description
     * Returns the quelity degree resieved form the quality degree register.
     *
     * @return
     * int : qualityDegree
     */
    int getQualityDegree();
};

#endif // LIDAR_MINI_HPP