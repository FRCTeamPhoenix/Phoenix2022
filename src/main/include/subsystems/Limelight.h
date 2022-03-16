#pragma once

#include <networktables/NetworkTable.h>

namespace Limelight{
    float getTx();
    float getTy();
    bool seesTarget();
    void disableLight();
    void enableLight();

} 