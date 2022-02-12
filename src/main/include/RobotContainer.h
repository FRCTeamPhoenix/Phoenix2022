// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include "subsystems/DriveSubsystem.h"
#include "commands/DriveTeleop.h"
#include "commands/DriveDistance.h"
#include <units/length.h>


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...

  void ConfigureButtonBindings();
  //subsystems
  DriveSubsystem m_driveSubsystem;
  
  //commands
  DriveTeleop m_driveTeleop{&m_driveSubsystem};
  DriveDistance m_driveDistance = DriveDistance(&m_driveSubsystem, 1_m);
};
