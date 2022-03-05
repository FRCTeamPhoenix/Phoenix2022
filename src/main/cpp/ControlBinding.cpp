 #include "ControlBinding.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/GenericHID.h> 

ControlBinding::ControlBinding(){}

void ControlBinding::initialize() {
    setDefaultControls();
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
//finds axis of named key
double ControlBinding::axis(std::string key){
  double axis = -m_driveController.GetRawAxis(frc::Preferences::GetInt(key, 0));
  return axis;
}

//finds if button is pushed of named key
bool ControlBinding::button(std::string key){
  bool button = -m_supportController.GetRawButtonPressed(frc::Preferences::GetInt(key,0));
  return button;
}