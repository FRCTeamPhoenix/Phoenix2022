#include "commands/DriveTeleop.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <cmath>

DriveTeleop::DriveTeleop(DriveSubsystem* driveSubsystem) :
 m_driveSubsystem(driveSubsystem){
     AddRequirements(m_driveSubsystem);
}

void DriveTeleop::Initialize(){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    m_driveSubsystem->ZeroEncoders();
}

void DriveTeleop::Execute(){
    //Up should be +1 and right should be 1
    double leftStickY = -m_driveJoystick.GetRawAxis(LEFTSTICK_Y) * DRIVETRAIN_SCALING;
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
            leftStickY = std::pow(leftStickY, 3.0) / std::abs(leftStickY);
            rightStickX = std::pow(rightStickX, 3.0) / std::abs(rightStickX);
            break;
        case Scaling::CUBIC:
            // x^3
            leftStickY = std::pow(leftStickY, 3.0);
            rightStickX = std::pow(rightStickX, 3.0);
            break;
        case Scaling::ROOT:
            // x * root x
            leftStickY = leftStickY * std::sqrt(std::abs(leftStickY));
            rightStickX = rightStickX * std::sqrt(std::abs(rightStickX));
            break;
        default:
            break;
    }
        
    rightStickX *= TURN_PERCENT;

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
    m_driveSubsystem->TankDrive(0.0, 0.0);
}

bool DriveTeleop::IsFinished(){
    return false;
}