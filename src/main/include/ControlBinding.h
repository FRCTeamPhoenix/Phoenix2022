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

    //set controller port namws
    frc::GenericHID m_driveController{0};
    frc::GenericHID m_supportController{1};

    /*get raw axis, generic
    template <typename axis>
    class CheckAxis{
        public:
        double returnAxis();
    }; 
    //get raw button, generic 
    template <typename button>
    class CheckButton{
        public:
        bool returnButton(); 
    };
*/
    double axis(std::string key);
    bool button(std::string key);

    private:

    void setDefaultControls();
    //void getReadings();

}; 
