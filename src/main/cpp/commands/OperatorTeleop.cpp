#include "commands/OperatorTeleop.h"
#include <frc/smartdashboard/SmartDashboard.h>


OperatorTeleop::OperatorTeleop(IntakeSubsystem* IntakeSubsystem):
m_intakeSubsystem(IntakeSubsystem){
    AddRequirements(IntakeSubsystem);
}

void OperatorTeleop::Initialize(){
    m_intakeSubsystem->SetArmSpeed(0.0);
    m_intakeSubsystem->SetWristSpeed(0.0);
    m_intakeSubsystem->SetIntakeSpeed(0.0);
}

void OperatorTeleop::Execute(){
    m_intakeSubsystem->SetArmSpeed(-m_operatorJoystick.GetRawAxis(LEFTSTICK_Y) * INTAKE_ARM_SPEED);
    m_intakeSubsystem->SetWristSpeed(-m_operatorJoystick.GetRawAxis(RIGHTSTICK_Y) * INTAKE_WRIST_SPEED);
    m_intakeSubsystem->SetIntakeSpeed((m_operatorJoystick.GetRawButton(BUMPER_L) - m_operatorJoystick.GetRawButton(BUMPER_R)) * INTAKE_SPEED);
}

void OperatorTeleop::End(bool interrupted){
    m_intakeSubsystem->SetArmSpeed(0.0);
    m_intakeSubsystem->SetWristSpeed(0.0);
    m_intakeSubsystem->SetIntakeSpeed(0.0);
}

bool OperatorTeleop::IsFinished(){
    return false;
}