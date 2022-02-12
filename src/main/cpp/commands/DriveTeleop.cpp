#include "commands/DriveTeleop.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <cmath>

DriveTeleop::DriveTeleop(DriveSubsystem* driveSubsystem) :
 m_driveSubsystem(driveSubsystem),
 m_heading(0_rad){
     AddRequirements(m_driveSubsystem);
}

void DriveTeleop::Initialize(){
    m_heading = 0_deg;
    m_driveSubsystem->TankDrive(0.0, 0.0);
    m_timer.Start();
    m_driveSubsystem->ZeroEncoders();
    m_lastExecute = m_timer.Get();
}

void DriveTeleop::Execute(){
    //calculate delta time
    units::second_t currentTime = m_timer.Get();
    units::second_t deltaTime = currentTime - m_lastExecute;
    m_lastExecute = currentTime;

    //Up should be +1 and right should be 1
    double leftStickY = -m_driveJoystick.GetRawAxis(LEFTSTICK_Y);
    double rightStickX = -m_driveJoystick.GetRawAxis(RIGHTSTICK_X);

    //deadzones
    if(std::abs(leftStickY) <= 0.0001){
        leftStickY = 0.0;
    }

    if(std::abs(rightStickX) <= 0.0001){
        rightStickX = 0.0;
    }

    //scale input based on enum
    switch(DRIVETRAIN_SCALING){
        case Scaling::QUADRATIC:
            //(sign) x^2
            leftStickY = std::pow(leftStickY, 3) / std::abs(leftStickY);
            rightStickX = std::pow(rightStickX, 3) / std::abs(rightStickX);
            break;
        case Scaling::CUBIC:
            // x^3
            leftStickY = std::pow(leftStickY, 3);
            rightStickX = std::pow(rightStickX, 3);
            break;
        case Scaling::ROOT:
            // x * root x
            leftStickY = leftStickY * std::sqrt(std::abs(leftStickY));
            rightStickX = rightStickX * std::sqrt(std::abs(rightStickX));
            break;
    }
        

    //update heading (use if gyro mounted)
    m_heading += rightStickX * TURN_RATE * deltaTime;

    double leftSide = leftStickY - rightStickX;
    double rightSide = leftStickY + rightStickX;
    //prevent from going out of -1 to 1 range
    if(rightSide > 1.0){
        double delta = rightSide - 1.0;
        leftSide -= delta;
        rightSide -= delta;
    }else if(leftSide < -1.0){
        double delta = leftSide + 1.0;
        leftSide += delta;
        rightSide += delta;
    }

    m_driveSubsystem->TankDrive(leftSide, rightSide);
}

void DriveTeleop::End(bool interrupted){
    m_timer.Stop();
    m_driveSubsystem->TankDrive(0.0, 0.0);
}

bool DriveTeleop::IsFinished(){
    return false;
}