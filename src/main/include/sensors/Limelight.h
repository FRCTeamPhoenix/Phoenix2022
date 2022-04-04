#pragma once

#include <networktables/NetworkTable.h>

class Limelight{
    public:
        Limelight();
            float getTx();
            float getTy();
            bool seesTarget();
            void disableLight();
            void enableLight();
            void alignToTarget();

}; 