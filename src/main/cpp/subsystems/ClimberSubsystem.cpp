#include "subsystems/ClimberSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

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
}

void ClimberSubsystem::ConfigureDefault(){
    //put a boolean value on the smartdashboard for zeroing
    frc::SmartDashboard::SetDefaultBoolean("Zero Rotators", false);
    frc::SmartDashboard::SetDefaultBoolean("Zero Extenders", false);

    //reset everything
    m_rightRotator.ConfigFactoryDefault();
    m_leftRotator.ConfigFactoryDefault();
    m_extenderArm.ConfigFactoryDefault();

    //make the left and right side work in tandem
    m_leftRotator.Follow(m_rightRotator, FollowerType::FollowerType_AuxOutput1);

    //invert to make go right direction
    m_leftRotator.SetInverted(InvertType::OpposeMaster);
    m_rightRotator.SetInverted(false);
    m_extenderArm.SetInverted(false);

    //configure the sensor
    m_extenderArm.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
    m_rightRotator.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 10);
    m_leftRotator.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 10);

    //10 ms period for PID
    m_extenderArm.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
    m_rightRotator.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
    m_extenderArm.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    m_rightRotator.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);

    //nominal = default, peak = maximum
    m_extenderArm.ConfigNominalOutputForward(0.0, 10);
    m_extenderArm.ConfigNominalOutputReverse(0.0, 10);
    m_extenderArm.ConfigPeakOutputForward(MAX_EXTENDER_OUTPUT, 10);
    m_extenderArm.ConfigPeakOutputReverse(-MAX_EXTENDER_OUTPUT, 10);
    m_rightRotator.ConfigNominalOutputForward(0.0, 10);
    m_rightRotator.ConfigNominalOutputReverse(0.0, 10);
    m_rightRotator.ConfigPeakOutputForward(MAX_ROTATOR_OUTPUT, 10);
    m_rightRotator.ConfigPeakOutputReverse(-MAX_ROTATOR_OUTPUT, 10);

    //configure PID values
    m_extenderArm.Config_kP(0, EXTENDER_P);
    m_extenderArm.Config_kI(0, EXTENDER_I);
    m_extenderArm.Config_kD(0, EXTENDER_D);
    m_extenderArm.Config_kF(0, EXTENDER_F);

    m_rightRotator.Config_kP(0, ROTATOR_P);
    m_rightRotator.Config_kI(0, ROTATOR_I);
    m_rightRotator.Config_kD(0, ROTATOR_D);
    m_rightRotator.Config_kF(0, ROTATOR_F);
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
    //set it to double the ticks since it is using sum mode
    m_rightRotator.Set(ControlMode::MotionMagic, RotatorDegreesToTicks(angle) * 2.0);
}


void ClimberSubsystem::ZeroExtenderEncoders(){
    m_extenderArm.SetSelectedSensorPosition(0, 0, 10);
}

void ClimberSubsystem::ZeroRotatorEncoders(){
    m_leftRotator.SetSelectedSensorPosition(0, 0, 10);
    m_rightRotator.SetSelectedSensorPosition(0, 0, 10);
}

units::meter_t ClimberSubsystem::GetExtenderDistance(){
    return ExtenderTicksToDistance(m_extenderArm.GetSelectedSensorPosition(0));
}

units::radian_t ClimberSubsystem::GetRotatorAngle(){
    return RotatorTicksToDegrees(m_rightRotator.GetSelectedSensorPosition(0));
}

units::meter_t ClimberSubsystem::ExtenderTicksToDistance(double ticks){
    return ticks / FALCON_TICKS_PER_ROTATION / FALCON_TO_EXTENDER_RATIO * DISTANCE_PER_EXTENDER_REVOLUTION;
}

double ClimberSubsystem::ExtenderDistanceToTicks(units::meter_t distance){
    return distance / DISTANCE_PER_EXTENDER_REVOLUTION * FALCON_TO_EXTENDER_RATIO * FALCON_TICKS_PER_ROTATION;
}

units::radian_t ClimberSubsystem::RotatorTicksToDegrees(double ticks){
    return ticks / TALON_TICKS_PER_ROTATION / TALON_TO_ROTATOR_RATIO * 360_deg;
}

double ClimberSubsystem::RotatorDegreesToTicks(units::radian_t degrees){
    return degrees / 360_deg * TALON_TICKS_PER_ROTATION * TALON_TO_ROTATOR_RATIO;   
}