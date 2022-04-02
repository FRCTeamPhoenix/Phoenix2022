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
    m_intakeSubsystem->SetArmSpeed(m_operatorJoystick.GetRawAxis(WRIST_SLIDER) * INTAKE_ARM_SPEED);

    frc::SmartDashboard::PutNumber("Arm power", m_operatorJoystick.GetRawAxis(WRIST_SLIDER) * INTAKE_ARM_SPEED);
    m_intakeSubsystem->SetIndexerSpeed(m_operatorJoystick.GetRawAxis(INDEXER_SLIDER) * INDEXER_SPEED);
    m_intakeSubsystem->SetIntakeSpeed(m_operatorJoystick.GetRawAxis(INTAKE_SLIDER) * INTAKE_SPEED);
    m_intakeSubsystem->SetShooterSpeed(m_operatorJoystick.GetRawButton(SHOOTER_SWITCH));
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