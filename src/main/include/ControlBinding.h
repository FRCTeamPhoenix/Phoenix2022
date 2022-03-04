#pragma once

#include <frc/Joystick.h> 
#include <frc/Preferences.h>
#include <frc2/command/button/Trigger.h> 
#include <frc/XboxController.h>
#include <frc/GenericHID.h>

#include "Constants.h" 

enum class JoystickType {
    DRIVER, OPERATOR
};

enum class ControlType {
    AXIS, BUTTON
};

struct ControlData {
    JoystickType driver;
    ControlType control;
    int id;
};

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

    frc::GenericHID controller{0};

    private:
    frc::Joystick m_driverJoystick{DRIVE_JOYSTICK};

    void setDefaultControls();
    //void displayControlBindings();
    //void setControls();

    bool bOne = false;
    double left_x = 0.0;
    double left_y = 0.0;
}; 