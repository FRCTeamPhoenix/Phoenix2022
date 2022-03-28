#include "subsystems/ClimberSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include <iostream>
#include <string>

ClimberSubsystem::ClimberSubsystem(){
    ConfigureDefault();
}

void ClimberSubsystem::Periodic(){
    if(frc::SmartDashboard::GetBoolean("Zero Rotators", false)){
        ZeroRotatorEncoders();
        frc::SmartDashboard::PutBoolean("Zero Rotators", false);
    }

    if(frc::SmartDashboard::GetBoolean("Zero Extenders", false)){
        ZeroExtenderEncoders();
        frc::SmartDashboard::PutBoolean("Zero Extenders", false);
    }

    //display the current angles and extender height
    units::degree_t angle = (GetLeftRotatorAngle() + GetRightRotatorAngle()) / 2.0;
    frc::SmartDashboard::PutString("Rotator Angle", std::to_string(angle.to<double>()) + " deg");
    units::inch_t height = GetExtenderDistance();
    frc::SmartDashboard::PutString("Extender Height", std::to_string(height.to<double>()) + " in");
}

void ClimberSubsystem::ConfigureDefault(){
    //put a boolean value on the smartdashboard for zeroing
    frc::SmartDashboard::PutBoolean("Zero Rotators", false);
    frc::SmartDashboard::PutBoolean("Zero Extenders", false);

    //reset everything
    m_rightRotator.ConfigFactoryDefault();
    m_leftRotator.ConfigFactoryDefault();
    m_extenderArm.ConfigFactoryDefault();

    //make all three motors break mode
    m_rightRotator.SetNeutralMode(NeutralMode::Brake);
    m_leftRotator.SetNeutralMode(NeutralMode::Brake);
    m_extenderArm.SetNeutralMode(NeutralMode::Brake);

    //invert to make go right direction
    m_leftRotator.SetInverted(true);
    m_rightRotator.SetInverted(false);
    m_extenderArm.SetInverted(false);

    //configure the sensors
    m_extenderArm.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
    //set the sensors to be relative sensors
    m_rightRotator.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    m_leftRotator.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
    m_rightRotator.SetSensorPhase(false);
    m_leftRotator.SetSensorPhase(false);

    //configure the limit switches to be closed by default
    m_extenderArm.ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyClosed, 10);
    m_extenderArm.ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyClosed, 10);

    //10 ms period for PID
    m_extenderArm.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
    m_rightRotator.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
    m_leftRotator.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
    m_extenderArm.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    m_rightRotator.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    m_leftRotator.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);

    //nominal = default, peak = maximum
    m_extenderArm.ConfigNominalOutputForward(0.0, 10);
    m_extenderArm.ConfigNominalOutputReverse(0.0, 10);
    m_extenderArm.ConfigPeakOutputForward(MAX_EXTENDER_FORWARD_OUTPUT, 10);
    m_extenderArm.ConfigPeakOutputReverse(MAX_EXTENDER_REVERSE_OUTPUT, 10);
    m_rightRotator.ConfigNominalOutputForward(0.0, 10);
    m_rightRotator.ConfigNominalOutputReverse(0.0, 10);
    m_rightRotator.ConfigPeakOutputForward(MAX_ROTATOR_OUTPUT, 10);
    m_rightRotator.ConfigPeakOutputReverse(-MAX_ROTATOR_OUTPUT, 10);
    m_leftRotator.ConfigNominalOutputForward(0.0, 10);
    m_leftRotator.ConfigNominalOutputReverse(0.0, 10);
    m_leftRotator.ConfigPeakOutputForward(MAX_ROTATOR_OUTPUT, 10);
    m_leftRotator.ConfigPeakOutputReverse(-MAX_ROTATOR_OUTPUT, 10);

    //configure PID values
    m_extenderArm.Config_kP(0, EXTENDER_P);
    m_extenderArm.Config_kI(0, EXTENDER_I);
    m_extenderArm.Config_kD(0, EXTENDER_D);
    m_extenderArm.Config_kF(0, EXTENDER_F);

    m_rightRotator.Config_kP(0, ROTATOR_RIGHT_P);
    m_rightRotator.Config_kI(0, ROTATOR_RIGHT_I);
    m_rightRotator.Config_kD(0, ROTATOR_RIGHT_D);
    m_rightRotator.Config_kF(0, ROTATOR_RIGHT_F);

    m_leftRotator.Config_kP(0, ROTATOR_LEFT_P);
    m_leftRotator.Config_kI(0, ROTATOR_LEFT_I);
    m_leftRotator.Config_kD(0, ROTATOR_LEFT_D);
    m_leftRotator.Config_kF(0, ROTATOR_LEFT_F);

    //set the proper pid slots
    m_rightRotator.SelectProfileSlot(0, 0);
    m_leftRotator.SelectProfileSlot(0, 0);

    //set motion magic cruise velocity and acceleration
    m_rightRotator.ConfigMotionCruiseVelocity(RotatorDegreesToTicks(ROTATOR_VELOCITY * 100_ms), 10);
    m_rightRotator.ConfigMotionAcceleration(RotatorDegreesToTicks(ROTATOR_ACCELERATION * 1_s * 100_ms), 10);
    m_leftRotator.ConfigMotionCruiseVelocity(RotatorDegreesToTicks(ROTATOR_VELOCITY * 100_ms), 10);
    m_leftRotator.ConfigMotionAcceleration(RotatorDegreesToTicks(ROTATOR_ACCELERATION * 1_s * 100_ms), 10);
    m_extenderArm.ConfigMotionCruiseVelocity(ExtenderDistanceToTicks(EXTENDER_VELOCITY * 100_ms), 10);
    m_extenderArm.ConfigMotionAcceleration(ExtenderDistanceToTicks(EXTENDER_ACCELERATION  * 1_s * 100_ms), 10);
    
    //cap the extender current draw to 60 amp
    m_extenderArm.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, MAX_CLIMBER_CURRENT.to<double>(), 0.0, 0.0), 10);
}

void ClimberSubsystem::SetExtenderSpeed(double percent){
    m_extenderArm.Set(ControlMode::PercentOutput, percent);
}

void ClimberSubsystem::SetRotatorSpeed(double percent){
    m_leftRotator.Set(ControlMode::PercentOutput, percent);
    m_rightRotator.Set(ControlMode::PercentOutput, percent);
}

void ClimberSubsystem::SetExtenderDistance(units::meter_t distance){
    m_extenderArm.Set(ControlMode::MotionMagic, ExtenderDistanceToTicks(distance));
}

void ClimberSubsystem::SetRotatorAngle(units::radian_t angle){
    //go to the target angle
    m_rightRotator.Set(ControlMode::MotionMagic, RotatorDegreesToTicks(angle));
    m_leftRotator.Set(ControlMode::MotionMagic, RotatorDegreesToTicks(angle));
}


void ClimberSubsystem::ZeroExtenderEncoders(){
    std::cout << "Zeroed the extender encoders" << std::endl;
    m_extenderArm.SetSelectedSensorPosition(0, 0);
}

void ClimberSubsystem::ZeroRotatorEncoders(){
    std::cout << "Zeroed the rotator encoders" << std::endl;
    m_leftRotator.SetSelectedSensorPosition(0, 0);
    m_rightRotator.SetSelectedSensorPosition(0, 0);
}

units::meter_t ClimberSubsystem::GetExtenderDistance(){
    return ExtenderTicksToDistance(m_extenderArm.GetSelectedSensorPosition(0));
}

units::radian_t ClimberSubsystem::GetRightRotatorAngle(){
    return RotatorTicksToDegrees(m_rightRotator.GetSelectedSensorPosition(0));
}

units::radian_t ClimberSubsystem::GetLeftRotatorAngle(){
    return RotatorTicksToDegrees(m_leftRotator.GetSelectedSensorPosition(0));
}

bool ClimberSubsystem::IsRotatorStopped(){
    return std::abs(m_leftRotator.GetSelectedSensorVelocity(0)) < ROTATOR_VELOCITY_THRESHOLD
    && std::abs(m_rightRotator.GetSelectedSensorVelocity(0)) < ROTATOR_VELOCITY_THRESHOLD;
}

bool ClimberSubsystem::IsExtenderStopped(){
    return std::abs(m_extenderArm.GetSelectedSensorVelocity(0)) < EXTENDER_VELOCITY_THRESHOLD;
}

units::meter_t ClimberSubsystem::ExtenderTicksToDistance(double ticks){
    return ticks / FALCON_TICKS_PER_ROTATION / FALCON_TO_EXTENDER_RATIO * EXTENDER_SPROCKET_DIAMETER * wpi::numbers::pi;
}

double ClimberSubsystem::ExtenderDistanceToTicks(units::meter_t distance){
    return distance / EXTENDER_SPROCKET_DIAMETER / wpi::numbers::pi * FALCON_TO_EXTENDER_RATIO * FALCON_TICKS_PER_ROTATION;
}

units::radian_t ClimberSubsystem::RotatorTicksToDegrees(double ticks){
    return ticks / TALON_TICKS_PER_ROTATION / TALON_TO_ROTATOR_RATIO * 360_deg;
}

double ClimberSubsystem::RotatorDegreesToTicks(units::radian_t degrees){
    return degrees / 360_deg * TALON_TICKS_PER_ROTATION * TALON_TO_ROTATOR_RATIO;   
}

bool ClimberSubsystem::GetBottomExtenderLimit(){
    //normally closed so if open its triggered
    return (!m_extenderArm.IsRevLimitSwitchClosed());
}

bool ClimberSubsystem::GetTopExtenderLimit(){
    //normally closed so if open its triggered
    return (!m_extenderArm.IsFwdLimitSwitchClosed());
}