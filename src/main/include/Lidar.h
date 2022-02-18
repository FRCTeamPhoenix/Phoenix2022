#pragma once
#include "Constants.h"
#include <frc/SerialPort.h>
// https://first.wpi.edu/FRC/roborio/release2015/docs/cpp/classSerialPort.html#a86c989d7946cc35008fe12d5b9976057 

class Lidar {   
    private: 
        int readerToInt[MAX_BYTE_COUNT];
        frc::SerialPort lidarSerialPort{115200, kOnboard};
        void readThread();
};