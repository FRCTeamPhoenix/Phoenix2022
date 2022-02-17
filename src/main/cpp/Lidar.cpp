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
    SerialPort lidarSerialPort(115200, kOnboard);

    int maxByteCount = 256;
    char reader[maxByteCount];
    Read lidarRead(reader, maxByteCount);
    Write lidarWrite(reader, maxByteCount);

    //char from reader array to ints
    string readerToString = reader;
    int readerToInt[maxByteCount];
    for (int i = 0; i <= maxByteCount; i++) {
        readerToInt[i] = readerToString[i];
    }

