#include "Lidar.h"
#include <thread>
#include <string>
#include <frc/SerialPort.h>

char buffer[MAX_BYTE_COUNT];

void Lidar::readThread() {
    while (true) {
        //reads lidar code from arduino
        lidarSerialPort.Read(buffer, MAX_BYTE_COUNT);

        readerToInt[MAX_BYTE_COUNT] = std::atoi(buffer);
    }
}