#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem(){

}

void IntakeSubsystem::ConfigureDefault(){

}

void IntakeSubsystem::SetLiftSpeed(double speed){

}

void IntakeSubsystem::SetPivotSpeed(double speed){

}

void IntakeSubsystem::SetIntakeSpeed(double speed){

}

void IntakeSubsystem::SetLiftAngle(units::radian_t angle){

}

void IntakeSubsystem::SetPivotAngle(units::radian_t angle){

}

void IntakeSubsystem::ZeroLiftEncoders(){
    m_intakeLift.SetSelectedSensorPosition(0, 0);
}

void IntakeSubsystem::ZeroIntakePivot(){
    m_intakePivot.SetSelectedSensorPosition(0, 0);
}

units::radian_t IntakeSubsystem::GetLiftAngle(){
    return LiftTicksToAngle(m_intakeLift.GetSelectedSensorPosition(0));
}

units::radian_t IntakeSubsystem::GetPivotAngle(){
    return PivotTicksToAngle(m_intakePivot.GetSelectedSensorPosition(0));
}

units::radian_t IntakeSubsystem::LiftTicksToAngle(double ticks){
    
}

double IntakeSubsystem::LiftAngleToTicks(units::radian_t angle){
    
}

units::radian_t IntakeSubsystem::PivotTicksToAngle(double ticks){
    
}

double IntakeSubsystem::PivotAngleToTicks(units::radian_t angle){
    
}