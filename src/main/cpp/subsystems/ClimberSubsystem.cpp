#include "subsystems/ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem(){
    ConfigureDefault();
}

void ClimberSubsystem::Periodic(){

}

void ClimberSubsystem::ConfigureDefault(){
    //reset everything
    m_rightRotator.ConfigFactoryDefault();
    m_leftRotator.ConfigFactoryDefault();
    m_extenderArm.ConfigFactoryDefault();

    //make the left and right side work in tandem
    m_leftRotator.Follow(m_rightRotator);

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
    m_extenderArm.ConfigPeakOutputForward(1.0, 10);
    m_extenderArm.ConfigPeakOutputReverse(-1.0, 10);
    m_rightRotator.ConfigNominalOutputForward(0.0, 10);
    m_rightRotator.ConfigNominalOutputReverse(0.0, 10);
    m_rightRotator.ConfigPeakOutputForward(1.0, 10);
    m_rightRotator.ConfigPeakOutputReverse(-1.0, 10);

    //zero the sensors
    ZeroExtenderEncoders();
}

void ClimberSubsystem::SetExtenderSpeed(double percent){
    m_extenderArm.Set(ControlMode::PercentOutput, percent);
}

void ClimberSubsystem::SetRotatorSpeed(double percent){
    m_rightRotator.Set(ControlMode::PercentOutput, percent);
}

void ClimberSubsystem::ZeroExtenderEncoders(){
    m_extenderArm.SetSelectedSensorPosition(0, 0, 10);
}

void ClimberSubsystem::ZeroRotatorEncoders(){
    m_leftRotator.SetSelectedSensorPosition(0, 0, 10);
    m_rightRotator.SetSelectedSensorPosition(0, 0, 10);
}