#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem(){

}

void IntakeSubsystem::ConfigureDefault(){

}

void IntakeSubsystem::SetArmSpeed(double speed){

}

void IntakeSubsystem::SetWristSpeed(double speed){

}

void IntakeSubsystem::SetIntakeSpeed(double speed){

}

void IntakeSubsystem::SetArmAngle(units::radian_t angle){

}

void IntakeSubsystem::SetWristAngle(units::radian_t angle){

}

void IntakeSubsystem::ZeroArmEncoders(){
}

void IntakeSubsystem::ZeroIntakeWrist(){
    m_intakeWrist.SetSelectedSensorPosition(0, 0);
}

units::radian_t IntakeSubsystem::GetArmAngle(){
    return ArmTicksToAngle(m_intakeArm);
}

units::radian_t IntakeSubsystem::GetWristAngle(){
    return WristTicksToAngle(m_intakeWrist.GetSelectedSensorPosition(0));
}

units::radian_t IntakeSubsystem::ArmTicksToAngle(double ticks){
    
}

double IntakeSubsystem::ArmAngleToTicks(units::radian_t angle){
    
}

units::radian_t IntakeSubsystem::WristTicksToAngle(double ticks){
    
}

double IntakeSubsystem::WristAngleToTicks(units::radian_t angle){
    
}