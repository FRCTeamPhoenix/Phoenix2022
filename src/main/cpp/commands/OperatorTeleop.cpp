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
    frc::SmartDashboard::PutNumber("Arm Scale", arm_scale);
    frc::SmartDashboard::PutNumber("Wrist Scale", wrist_scale);
    frc::SmartDashboard::PutBoolean("Invert Arm", invert_arm);
    frc::SmartDashboard::PutBoolean("Invert Arm", invert_arm);
    frc::SmartDashboard::PutBoolean("Invert Intake", invert_intake);
    m_intakeSubsystem->SetArmSpeed(m_operatorJoystick.GetRawAxis(LEFTSTICK_Y) * arm_scale * (invert_arm ? -1 : 1));
    m_intakeSubsystem->SetWristSpeed(m_operatorJoystick.GetRawAxis(RIGHTSTICK_Y) * wrist_scale * (invert_wrist ? -1 : 1));
    m_intakeSubsystem->SetIntakeSpeed((m_operatorJoystick.GetRawButton(BUMPER_L) - m_operatorJoystick.GetRawButton(BUMPER_R)) * (invert_intake ? -1 : 1));
}

void OperatorTeleop::End(bool interrupted){
    m_intakeSubsystem->SetArmSpeed(0.0);
    m_intakeSubsystem->SetWristSpeed(0.0);
    m_intakeSubsystem->SetIntakeSpeed(0.0);
}

bool OperatorTeleop::IsFinished(){
    return false;
}