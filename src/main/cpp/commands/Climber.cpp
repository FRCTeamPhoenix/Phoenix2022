// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Climber.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>
#include <frc/XboxController.h>

TalonSRX _talon0 = TalonSRX(0); // Change '0' to match device ID in Tuner.  Use VictorSPX for Victor SPXs
frc::Joystick _joystick{0};

Climber::Climber(){
}

// Called just before this Command runs the first time
void Climber::Initialize() {
    //set motor values to 0
}

// Called repeatedly when this Command is scheduled to run
void Climber::Execute() {
    double stick = _joystick.GetRawAxis(1);
    _talon0.Set(ControlMode.PercentOutput, stick);
}

// Make this return true when this Command no longer needs to run execute()
bool Climber::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Climber::End(bool interrupted) {
    // set motor values to 0
}

bool Climber::RunsWhenDisabled() const {
    return false;
}