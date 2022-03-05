#pragma once

#include <frc/Joystick.h> 
#include <frc/Preferences.h>
#include <frc2/command/button/Trigger.h> 
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <string>


#include "Constants.h" 


class ControlBinding {
    public:

    static ControlBinding* getInstance() {
            static ControlBinding instance;
            return &instance;
        }

    ControlBinding(ControlBinding const&) = delete;
    void operator = (ControlBinding const&) = delete;    
    ControlBinding();
    void initialize();	

    //set controller port names
    frc::GenericHID m_driveController{0};
    frc::GenericHID m_supportController{1};


    double axis(std::string key);
    bool button(std::string key);

    private:

    void setDefaultControls();

}; 
