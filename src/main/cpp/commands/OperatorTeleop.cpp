#include "commands/OperatorTeleop.h"
#include <frc/smartdashboard/SmartDashboard.h>


OperatorTeleop::OperatorTeleop(IntakeSubsystem* IntakeSubsystem):
m_intakeSubsystem(IntakeSubsystem){
    AddRequirements(IntakeSubsystem);
}

void OperatorTeleop::Initialize(){
    m_intakeSubsystem->SetArmSpeed(0.0);
    m_intakeSubsystem->SetShooterSpeed(0.0);
    m_intakeSubsystem->SetIntakeSpeed(0.0);
    m_intakeSubsystem->SetIndexerSpeed(0.0);
}

void OperatorTeleop::Execute(){
    m_intakeSubsystem->SetArmSpeed(-m_operatorJoystick.GetRawAxis(LEFTSTICK_Y) * INTAKE_ARM_SPEED);
    frc::SmartDashboard::PutNumber("Arm power", -m_operatorJoystick.GetRawAxis(LEFTSTICK_Y) * INTAKE_ARM_SPEED);
    m_intakeSubsystem->SetIntakeSpeed((m_operatorJoystick.GetRawButton(BUMPER_L) - m_operatorJoystick.GetRawButton(BUMPER_R)) * INTAKE_SPEED);
    // decide on controls for shooter and indexer
}

void OperatorTeleop::End(bool interrupted){
    m_intakeSubsystem->SetArmSpeed(0.0);
    m_intakeSubsystem->SetShooterSpeed(0.0);
    m_intakeSubsystem->SetIntakeSpeed(0.0);
    m_intakeSubsystem->SetIndexerSpeed(0.0);
}

bool OperatorTeleop::IsFinished(){
    return false;
}