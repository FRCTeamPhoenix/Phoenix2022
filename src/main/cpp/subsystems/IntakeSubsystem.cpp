#include "subsystems/IntakeSubsystem.h"
#include <math.h>

IntakeSubsystem::IntakeSubsystem(){
    // m_encoder = m_intakeArm.GetEncoder();
    // we have to call this every time to use it instead of storing it
    ConfigureDefault();
}

void IntakeSubsystem::ConfigureDefault(){
    m_intake.ConfigFactoryDefault();
    m_intakeArm.ConfigFactoryDefault();
    m_intakeShooter.ConfigFactoryDefault();
    m_intakeIndexer.ConfigFactoryDefault();

    //choose direction (going right way?)
    m_intake.SetInverted(false);
    m_intakeArm.SetInverted(false);
    m_intakeShooter.SetInverted(false);
    m_intakeIndexer.SetInverted(false);

    //output limits
    m_intake.ConfigNominalOutputForward(0.0, 10);
    m_intake.ConfigNominalOutputReverse(0.0, 10);
    m_intake.ConfigPeakOutputForward(1.0, 10);
    m_intake.ConfigPeakOutputReverse(-1.0, 10);
    m_intakeArm.ConfigNominalOutputForward(0.0, 10);
    m_intakeArm.ConfigNominalOutputReverse(0.0, 10);
    m_intakeArm.ConfigPeakOutputForward(1.0, 10);
    m_intakeArm.ConfigPeakOutputReverse(-1.0, 10);
    m_intakeShooter.ConfigNominalOutputForward(0.0, 10);
    m_intakeShooter.ConfigNominalOutputReverse(0.0, 10);
    m_intakeShooter.ConfigPeakOutputForward(1.0, 10);
    m_intakeShooter.ConfigPeakOutputReverse(-1.0, 10);
    m_intakeIndexer.ConfigNominalOutputForward(0.0, 10);
    m_intakeIndexer.ConfigNominalOutputReverse(0.0, 10);
    m_intakeIndexer.ConfigPeakOutputForward(1.0, 10);
    m_intakeIndexer.ConfigPeakOutputReverse(-1.0, 10);

    //make bot resist motion
    m_intake.SetNeutralMode(NeutralMode::Brake);
    m_intakeArm.SetNeutralMode(NeutralMode::Brake);
    m_intakeShooter.SetNeutralMode(NeutralMode::Brake);
    m_intakeIndexer.SetNeutralMode(NeutralMode::Brake);
}

void IntakeSubsystem::SetIntakeSpeed(double speed){
    m_intake.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetArmSpeed(double speed){
    m_intakeArm.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetArmAngle(units::radian_t angle){
    m_intakeArm.Set(ControlMode::MotionMagic, ArmAngleToTicks(angle));
}

void IntakeSubsystem::SetShooterSpeed(double speed){
    m_intakeShooter.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetIndexerSpeed(double speed){
    m_intakeIndexer.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::ZeroArmEncoders(){
    m_intake.SetSelectedSensorPosition(0, 0);
}

units::radian_t IntakeSubsystem::GetArmAngle(){
    return ArmTicksToAngle(m_intakeArm.GetSelectedSensorPosition(0));
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