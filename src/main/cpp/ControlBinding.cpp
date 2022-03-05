 #include "ControlBinding.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/GenericHID.h> 

ControlBinding::ControlBinding(){}

void ControlBinding::initialize() {
    setDefaultControls();
    //getReadings();
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

double ControlBinding::axis(std::string key){
  double axis = -m_driveController.GetRawAxis(frc::Preferences::GetInt(key, 0));
  return axis;
}

bool ControlBinding::button(std::string key){
  bool button = -m_supportController.GetRawButtonPressed(frc::Preferences::GetInt(key,0));
  return button;
}

/*void ControlBinding::getReadings(){
    
  //double leftStick = -m_driveController.GetRawAxis(frc::Preferences::GetInt(LEFTKEY, 0));
  //double rightStick = -m_driveController.GetRawAxis(frc::Preferences::GetInt(RIGHTKEY, 0));
  //bool climberUp = -m_supportController.GetRawButtonPressed(frc::Preferences::GetInt(CLIMBERUPKEY,0));
}*/

/*template<typename axis>
double ControlBinding::CheckAxis<axis>::returnAxis(){
  return -m_driveController.GetRawAxis(frc::Preferences::GetInt(axis, 0));
}
template<typename button>
bool ControlBinding::CheckButton<button>::returnButton(){
  return -m_supportController.GetRawButtonPressed(frc::Preferences::GetInt(button,0));
}
*/