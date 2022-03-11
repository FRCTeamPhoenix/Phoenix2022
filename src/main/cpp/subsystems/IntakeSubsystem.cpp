#include "subsystems/IntakeSubsystem.h"
#include <math.h>

IntakeSubsystem::IntakeSubsystem(){
    // m_encoder = m_intakeArm.GetEncoder();
    // we have to call this every time to use it instead of storing it
    ConfigureDefault();
}

void IntakeSubsystem::ConfigureDefault(){
    m_intake.ConfigFactoryDefault();
    m_intakeWrist.ConfigFactoryDefault();
}

void IntakeSubsystem::SetArmSpeed(double speed){
    m_intake.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetWristSpeed(double speed){
    m_intakeWrist.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetIntakeSpeed(double speed){
    m_intake.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetArmAngle(units::radian_t angle){

}

void IntakeSubsystem::SetWristAngle(units::radian_t angle){
    m_intakeWrist.Set(ControlMode::Position, WristAngleToTicks(angle));
}

void IntakeSubsystem::ZeroArmEncoders(){
    m_intake.SetSelectedSensorPosition(0, 0);
}

void IntakeSubsystem::ZeroIntakeWrist(){
    m_intakeWrist.SetSelectedSensorPosition(0, 0);
}

units::radian_t IntakeSubsystem::GetArmAngle(){
    return ArmTicksToAngle(m_intakeArm.GetEncoder().GetPosition());
}

units::radian_t IntakeSubsystem::GetWristAngle(){
    return WristTicksToAngle(m_intakeWrist.GetSelectedSensorPosition(0));
}

units::radian_t IntakeSubsystem::ArmTicksToAngle(double ticks){
    return 2_rad * M_PI * ticks / TALON_TICKS_PER_ROTATION / TALON_TO_ARM_RATIO;
}

double IntakeSubsystem::ArmAngleToTicks(units::radian_t angle){
    return angle / (2_rad * M_PI) * TALON_TICKS_PER_ROTATION * TALON_TO_ARM_RATIO;
}

units::radian_t IntakeSubsystem::WristTicksToAngle(double ticks){
    return 2_rad * M_PI * ticks / TALON_TICKS_PER_ROTATION;
}

double IntakeSubsystem::WristAngleToTicks(units::radian_t angle){
    return angle / (2_rad * M_PI) * TALON_TICKS_PER_ROTATION;
}