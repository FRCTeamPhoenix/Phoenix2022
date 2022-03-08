// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "subsystems/DriveSubsystem.h"
#include "units/length.h"

RobotContainer::RobotContainer() {
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetTeleopCommand(){
  return &m_teleopCommand;
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return &m_climberState;
}
