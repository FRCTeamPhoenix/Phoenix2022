#include "ControlBinding.h"
#include <frc/smartdashboard/SmartDashboard.h>

ControlBinding::ControlBinding(){}

void ControlBinding::initialize() {
    setDefaultControls();
    //displayControlBindings();
}

void ControlBinding::setDefaultControls(){
    // set prefrences and defult values
    frc::Preferences::SetInt(LeftKey, 1);
    frc::Preferences::SetInt(RightKey, 2);
    frc::Preferences::SetInt(ClimberUpKey, 7);
}
/*void ControlBinding::displayControlBindings(){
    //widgets

}
void ControlBinding::setControls(){
    //prefrences
}
*/