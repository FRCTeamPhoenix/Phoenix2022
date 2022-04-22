#include "subsystems/IntakeSubsystem.h"
#include <math.h>

#include <frc/smartdashboard/SmartDashboard.h>

IntakeSubsystem::IntakeSubsystem(){
    // m_encoder = m_intakeArm.GetEncoder();
    // we have to call this every time to use it instead of storing it
    ConfigureDefault();
}

void IntakeSubsystem::ConfigureDefault(){
    m_intakeArm.SelectProfileSlot(0, 0);
    m_intakeArm.Config_kP(0, ARM_P);
    m_intakeArm.Config_kI(0, ARM_I);
    m_intakeArm.Config_kD(0, ARM_D);
    m_intakeArm.Config_kF(0, ARM_F);

    m_intake.ConfigFactoryDefault();
    m_intakeArm.ConfigFactoryDefault();
    m_intakeShooter.ConfigFactoryDefault();
    m_intakeIndexer.ConfigFactoryDefault();

    //choose direction (going right way?)
    m_intake.SetInverted(false);
    m_intakeArm.SetInverted(false);
    m_intakeShooter.SetInverted(true);
    m_intakeIndexer.SetInverted(true);

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

    //current limit
    m_intakeArm.ConfigSupplyCurrentLimit({true, MAX_ARM_CURRENT.to<double>(), 0.0, 0.0});

    //make bot resist motion
    m_intake.SetNeutralMode(NeutralMode::Coast);
    m_intakeArm.SetNeutralMode(NeutralMode::Brake);
    m_intakeShooter.SetNeutralMode(NeutralMode::Coast);
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

void IntakeSubsystem::SetShooterVelocity(double rpm){
    m_intakeShooter.Set(ControlMode::Velocity, rpm);
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
    return 360_deg * ticks / TALON_TICKS_PER_ROTATION / TALON_TO_ARM_RATIO;
}

double IntakeSubsystem::ArmAngleToTicks(units::radian_t angle){
    return angle / (360_deg) * TALON_TICKS_PER_ROTATION * TALON_TO_ARM_RATIO;
}

double IntakeSubsystem::ShooterRPMToTicks(double rpm){
    return rpm * TALON_TICKS_PER_ROTATION * TALON_TO_SHOOTER_RATIO;
}