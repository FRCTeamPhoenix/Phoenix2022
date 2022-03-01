#include "Lidar.h"
#include <thread>
#include <string>
#include <frc/SerialPort.h>
#include <iostream>

void Lidar::readThread()
{
    int readerToInt;
    char buffer[MAX_BYTE_COUNT];
    frc::SerialPort lidarSerialPort(115200, frc::SerialPort::Port::kMXP);

    while (true)
    {
        // reads lidar code from arduino
        lidarSerialPort.Read(buffer, MAX_BYTE_COUNT);

        std::string bufferToString (buffer);

        readerToInt = std::stoi(bufferToString);  
        std::cout << readerToInt << std::endl;

    }
}

void Lidar::StartLidar()
{
    std::thread lidarThread(readThread);
    lidarThread.detach();
}