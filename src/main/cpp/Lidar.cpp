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
    int lidarDistances[5] = {0, 0, 0, 0, 0};
    int lidarAverageDivision;
    double averageLidarDistance;

    while (true)
    { 
        // reads lidar code from arduino
        lidarSerialPort.Read(buffer, MAX_BYTE_COUNT);

        std::string bufferToString (buffer);

        readerToInt = std::stoi(bufferToString);

        //stores 5 most recent distances
        if (lidarDistances[0] = 0) {
            lidarDistances[0] = readerToInt;

            lidarAverageDivision = 1;
        } else if (lidarDistances[1] = 0) {
            lidarDistances[1] = readerToInt;

            lidarAverageDivision = 2;
        } else if (lidarDistances[2] = 0) {
            lidarDistances[2] = readerToInt;

            lidarAverageDivision = 3;
        } else if (lidarDistances[3] = 0) {
            lidarDistances[3] = readerToInt;

            lidarAverageDivision = 4;
        } else if (lidarDistances[4] = 0) {
            lidarDistances[4] = readerToInt;
            
            lidarAverageDivision = 5;
        } else if ((lidarDistances[0] != 0) && (lidarDistances[1] != 0) && (lidarDistances[2] != 0) && (lidarDistances[3] != 0) && (lidarDistances[4] != 0)) {
            lidarDistances[0] = lidarDistances[1];
            lidarDistances[1] = lidarDistances[2];
            lidarDistances[2] = lidarDistances[3];
            lidarDistances[3] = lidarDistances[4];
            lidarDistances[4] = readerToInt;

            lidarAverageDivision = 5;
        }

        //calculates the distance and prints it
        averageLidarDistance = (lidarDistances[0] + lidarDistances[1] + lidarDistances[2] + lidarDistances[3] + lidarDistances[4]) / lidarAverageDivision;
        std::cout << averageLidarDistance << std::endl;
    }
}

void Lidar::StartLidar()
{
    std::thread lidarThread(readThread);
    lidarThread.detach();
}