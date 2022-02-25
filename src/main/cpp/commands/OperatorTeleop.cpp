#include "commands/OperatorTeleop.h"

OperatorTeleop::OperatorTeleop(ClimberSubsystem* climberSubsystem):
m_climberSubsystem(climberSubsystem){
    AddRequirements({m_climberSubsystem});
}

void OperatorTeleop::Initialize(){
    m_climberSubsystem->SetExtenderSpeed(0.0);
    m_climberSubsystem->SetRotatorSpeed(0.0);
}

void OperatorTeleop::Execute(){
    //extend with the left stick
    m_climberSubsystem->SetExtenderSpeed(m_operatorJoystick.GetRawAxis(LEFTSTICK_Y));
    m_climberSubsystem->SetRotatorSpeed(m_operatorJoystick.GetRawAxis(RIGHTSTICK_Y));
}

void OperatorTeleop::End(bool interrupted){
    m_climberSubsystem->SetExtenderSpeed(0.0);
    m_climberSubsystem->SetRotatorSpeed(0.0);
}

bool OperatorTeleop::IsFinished(){
    return false;
}