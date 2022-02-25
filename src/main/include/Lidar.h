#pragma once
#include "Constants.h"
#include <frc/SerialPort.h>
// https://first.wpi.edu/FRC/roborio/release2015/docs/cpp/classSerialPort.html#a86c989d7946cc35008fe12d5b9976057 

class Lidar {   
    public: 
        void StartLidar();
    private: 
        static void readThread();
};