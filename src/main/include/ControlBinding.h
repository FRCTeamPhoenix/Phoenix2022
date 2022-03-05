#pragma once

#include <frc/Joystick.h> 
#include <frc/Preferences.h>
#include <frc2/command/button/Trigger.h> 
#include <frc/XboxController.h>
#include <frc/GenericHID.h>


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

    frc::GenericHID m_driveController{0};
    frc::GenericHID m_supportController{1};

    private:

    void setDefaultControls();
    void getReadings();
}; 
