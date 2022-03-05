#include "commands/ClimberState.h"

ClimberState::ClimberState(ClimberSubsystem* climberSubsystem, units::meter_t extenderDistance, units::radian_t rotatorAngle):
m_climberSubsystem(climberSubsystem),
m_extenderDistance(extenderDistance),
m_rotatorAngle(rotatorAngle)
{
    AddRequirements(climberSubsystem);
}

void ClimberState::Initialize(){
    //Do NOT zero motor speed here as that would cause the mechanism to drop
}

void ClimberState::Execute(){
    m_climberSubsystem->SetExtenderDistance(m_extenderDistance);
    m_climberSubsystem->SetRotatorAngle(m_rotatorAngle);
}

void ClimberState::End(bool interrupted){
    //Once again, do NOT modify the output as a constant motor speed must be applied to overcome gravity (adjust _F value in Constants)
}

bool ClimberState::IsFinished(){
    //normally, check if both mechanisms are stopped and within a set target range
    return false;
}