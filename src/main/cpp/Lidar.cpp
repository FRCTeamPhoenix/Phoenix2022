#include "Lidar.h"
#include <thread>
#include <string>
#include <frc/SerialPort.h>
#include <iostream>



void Lidar::readThread() {
    while (true) {
        //reads lidar code from arduino
        int readerToInt;
        frc::SerialPort::Port kOnboard;
        char buffer[MAX_BYTE_COUNT];

        frc::SerialPort lidarSerialPort(115200, kOnboard);

        lidarSerialPort.Read(buffer, MAX_BYTE_COUNT);

        readerToInt = std::atoi(buffer);
        
        std::cout << readerToInt;
    }
}

void Lidar::StartLidar() {
    std::thread lidarThread(readThread);
}

