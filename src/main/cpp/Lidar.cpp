#include "Lidar.h"
#include <thread>
#include <SerialPort.h>
#include <string>

// reference https://github.com/Iron-Panthers/FRC-2015/blob/master/src/LidarI2C.cpp

/* 
serial data reader class
port id to plug into board
open serial port with that port number
set baud rate
in separate thread, consistently read lidar measurements
function to access measurements as needed
*/

    char buffer[MAX_BYTE_COUNT];

    serialLidarPort.read(buffer, MAX_BYTE_COUNT);

    void readThread() {
        while (true) {
            Read(buffer, MAX_BYTE_COUNT);

            //char from buffer array to string to ints
            std::string readerToString = "";
            for (int i = 0; i <= MAX_BYTE_COUNT; i++) {
                readerToString += buffer[i];
            }

            for (int i = 0; i <= MAX_BYTE_COUNT; i++) {
                readerToInt[i] = stoi(readerToString[i]);
            }
        }
    }