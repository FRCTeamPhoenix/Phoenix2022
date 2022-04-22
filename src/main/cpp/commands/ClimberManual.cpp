#include "commands/ClimberManual.h"

ClimberManual::ClimberManual(ClimberSubsystem* climberSubsystem):
m_climberSubsystem(climberSubsystem){
    AddRequirements(climberSubsystem);
}

void ClimberManual::Initialize(){
    m_climberSubsystem->ConfigureManualPID();
}

void ClimberManual::Execute(){
    //make it follow the current position of the dial and sider
    //make sure to scale input to be from 0 to 1
    m_climberSubsystem->SetExtenderDistanceNoMM((m_operatorJoystick.GetRawAxis(EXTENDER_SLIDER) * 0.5 + 0.5) * MAX_EXTENDER_HEIGHT);
    m_climberSubsystem->SetRotatorAngleNoMM(m_operatorJoystick.GetRawAxis(ROTATOR_DIAL) * MAX_ROTATOR_ANGLE);
}

void ClimberManual::End(bool interrupted){
    //maintain current position
    m_climberSubsystem->ConfigureAutoPID();
    m_climberSubsystem->SetExtenderDistanceNoMM(m_climberSubsystem->GetExtenderDistance());
    m_climberSubsystem->SetRotatorAngleNoMM(m_climberSubsystem->GetLeftRotatorAngle());
}

bool ClimberManual::IsFinished(){
    return !m_operatorJoystick.GetRawButton(MANUAL_SWITCH);
}