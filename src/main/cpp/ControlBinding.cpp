 #include "ControlBinding.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/GenericHID.h> 

ControlBinding::ControlBinding(){}

void ControlBinding::initialize() {
    setDefaultControls();
    //displayControlBindings();
}

void ControlBinding::setDefaultControls(){
    // set prefrences and defult values
  if (!frc::Preferences::ContainsKey(LEFTKEY)) {
      frc::Preferences::SetInt(LEFTKEY, 1);
    }
  if (!frc::Preferences::ContainsKey(RIGHTKEY)) {
      frc::Preferences::SetInt(RIGHTKEY, 2);
    }
  if (!frc::Preferences::ContainsKey(CLIMBERUPKEY)) {
      frc::Preferences::SetInt(CLIMBERUPKEY, 7);
    }  
}

void ControlBinding::getReadings(){
    
    double leftStick = -m_driverJoystick.GetRawAxis(frc::Preferences::GetInt(LEFTKEY, 1));
    double rightStick = -m_driverJoystick.GetRawAxis(frc::Preferences::GetInt(RIGHTKEY, 4));
    bool climberUp = -m_driverJoystick.GetRawButtonPressed(frc::Preferences::GetInt(CLIMBERUPKEY,7));
}
/*
void ControlBinding::setControls(){
    //prefrences
}
*/