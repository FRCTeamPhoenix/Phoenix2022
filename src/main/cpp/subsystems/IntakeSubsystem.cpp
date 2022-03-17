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

    //choose direction (going right way?)
    m_intake.SetInverted(true);
    m_intakeWrist.SetInverted(true);
    m_intakeArm.SetInverted(false);

    //output limits
    m_intake.ConfigNominalOutputForward(0.0, 10);
    m_intake.ConfigNominalOutputReverse(0.0, 10);
    m_intake.ConfigPeakOutputForward(1.0, 10);
    m_intake.ConfigPeakOutputReverse(-1.0, 10);
    m_intakeWrist.ConfigNominalOutputForward(0.0, 10);
    m_intakeWrist.ConfigNominalOutputReverse(0.0, 10);
    m_intakeWrist.ConfigPeakOutputForward(1.0, 10);
    m_intakeWrist.ConfigPeakOutputReverse(-1.0, 10);

    //make bot resist motion
    m_intakeWrist.SetNeutralMode(NeutralMode::Brake);
}

void IntakeSubsystem::SetArmSpeed(double speed){
    m_intakeArm.Set(speed);
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