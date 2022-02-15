#include "commands/DriveDistance.h"
#include <units/length.h>
#include <iostream>

DriveDistance::DriveDistance(DriveSubsystem* driveSubsystem, units::meter_t distance):
m_driveSubsystem(driveSubsystem),
m_distance(distance){
    AddRequirements(driveSubsystem);
}

void DriveDistance::Initialize(){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    m_driveSubsystem->ZeroEncoders();
    std::cout << "started moving with distance: " << m_distance.to<double>() << std::endl;
}

void DriveDistance::Execute(){
    m_driveSubsystem->RunMotionMagic(m_distance);
}

void DriveDistance::End(bool interrupted){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    std::cout << "finished drive distance" << std::endl;
}

bool DriveDistance::IsFinished(){
    return m_driveSubsystem->IsStopped() && (m_distance - m_driveSubsystem->GetAverageDistance() < DISTANCE_THRESHOLD);
}