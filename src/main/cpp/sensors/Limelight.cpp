#include "sensors/Limelight.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableValue.h>

    Limelight::Limelight(){

    }
    float Limelight::getTx() { 
        auto inst = nt::NetworkTableInstance::GetDefault();
    return inst.GetTable("limelight")->GetNumber("tx", 0.0);
    } //-27 to 27 degrees

    float Limelight::getTy() { 
        auto inst = nt::NetworkTableInstance::GetDefault();
        return inst.GetTable("limelight")->GetNumber("ty", 0.0);} //-20.5 to 20.5 degrees
    
    bool Limelight::seesTarget() { 
        auto inst = nt::NetworkTableInstance::GetDefault();
        return (int)inst.GetTable("limelight")->GetNumber("tv", 0.0) == 0 ? false : true;}

    void Limelight::disableLight() { 
        auto inst = nt::NetworkTableInstance::GetDefault();
        inst.GetTable("limelight")->PutNumber("ledMode", 1);}

    void Limelight::enableLight() { 
        auto inst = nt::NetworkTableInstance::GetDefault();
        inst.GetTable("limelight")->PutNumber("ledMode", 3);}

    void Limelight::alignToTarget() {
        //This function will take the Tx and Ty from the limelight and rotate the robot to be aligned
        //If no target found, robot will slowly spinn counterclockwise until a target is found
    }
