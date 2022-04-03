#include "commands/ClimberState.h"

#include <iostream>

ClimberState::ClimberState(ClimberSubsystem* climberSubsystem, units::meter_t extenderDistance, units::radian_t rotatorAngle, bool disableArms, bool ends):
m_climberSubsystem(climberSubsystem),
m_extenderDistance(extenderDistance),
m_rotatorAngle(rotatorAngle),
m_disableRotator(disableArms),
m_ends()
{
    AddRequirements(climberSubsystem);
}

void ClimberState::Initialize(){
    m_climberSubsystem->ConfigureAutoPID();
    //Do NOT zero motor speed here as that would cause the mechanism to drop
    std::cout << "Setting climber state: " << m_extenderDistance.to<double>() << " m and " << m_rotatorAngle.to<double>() << " rad" << std::endl;
    std::cout << "Extender (ticks): " << m_climberSubsystem->ExtenderDistanceToTicks(m_extenderDistance) << " Rotator (ticks):" << m_climberSubsystem->RotatorDegreesToTicks(m_rotatorAngle) << std::endl;
}

void ClimberState::Execute(){
    m_climberSubsystem->SetExtenderDistance(m_extenderDistance);
    if(!m_disableRotator)
        m_climberSubsystem->SetRotatorAngle(m_rotatorAngle);
    else
        m_climberSubsystem->SetRotatorSpeed(0.0);
}

void ClimberState::End(bool interrupted){
    //Once again, do NOT modify the output as a constant motor speed must be applied to overcome gravity (adjust _F value in Constants)
    if(interrupted){
        //this command was most likely emergency stopped, try maintaining current position
        m_climberSubsystem->SetRotatorAngle((m_climberSubsystem->GetLeftRotatorAngle() + m_climberSubsystem->GetRightRotatorAngle()) / 2.0);
        m_climberSubsystem->SetExtenderDistance(m_climberSubsystem->GetExtenderDistance());
    }
    std::cout << "Climber state complete" << std::endl;
}

bool ClimberState::IsFinished(){
    //normally, check if both mechanisms are stopped and within a set target range
    bool rotatorVelocityStopped = m_climberSubsystem->IsRotatorStopped();
    bool extenderVelocityStopped = m_climberSubsystem->IsExtenderStopped();
    bool rotatorPositionStopped = std::abs(m_climberSubsystem->GetLeftRotatorAngle().to<double>() - m_rotatorAngle.to<double>()) < ROTATOR_POSITION_THRESHOLD.to<double>()
    && std::abs(m_climberSubsystem->GetRightRotatorAngle().to<double>() - m_rotatorAngle.to<double>()) < ROTATOR_POSITION_THRESHOLD.to<double>();
    bool extenderPositionStopped = std::abs(m_climberSubsystem->GetExtenderDistance().to<double>() - m_extenderDistance.to<double>()) < EXTENDER_POSITION_THRESHOLD.to<double>();
    return extenderVelocityStopped && extenderPositionStopped 
    && ((rotatorVelocityStopped && rotatorPositionStopped) || m_disableRotator) && m_ends;
}