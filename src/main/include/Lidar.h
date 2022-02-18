#pragma once
// https://github.com/Iron-Panthers/FRC-2015/tree/master/src reference
// https://robotpy.readthedocs.io/projects/wpilib/en/latest/wpilib/SerialPort.html 
// https://first.wpi.edu/FRC/roborio/release2015/docs/cpp/classSerialPort.html#a86c989d7946cc35008fe12d5b9976057 

class SerialPort {
    public:     
        SerialPort lidarSerialPort(115200, kOnboard);
        Read lidarRead(buffer, MAX_BYTE_COUNT);
    private: 
        int readerToInt[MAX_BYTE_COUNT];
};