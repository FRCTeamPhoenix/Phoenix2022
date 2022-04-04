#include "commands/FaceTarget.h"
#include <units/length.h>
#include <iostream>
#include <wpi/numbers>

FaceTarget::FaceTarget(DriveSubsystem* driveSubsystem)
{
    
}

void FaceTarget::Initialize(){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    m_driveSubsystem->ZeroEncoders();
}

void FaceTarget::Execute(){
    //Do Stuff to make sure we face the target;
}

void FaceTarget::End(bool interrupted){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    std::cout << "finished drive distance" << std::endl;
}

bool FaceTarget::IsFinished(){
    return false;  //Need to figure out if we are facing the target then return true.
}