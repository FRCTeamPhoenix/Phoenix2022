// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "subsystems/DriveSubsystem.h"
#include "units/length.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  //command must be MOVED to be stored here
  m_driveSubsystem.SetDefaultCommand(std::move(m_driveTeleop));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_playMusic;
}
