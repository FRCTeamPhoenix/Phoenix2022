// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/ClimberSubsystem.h"
#include "commands/DriveTeleop.h"
#include "commands/OperatorTeleop.h"
#include "commands/DriveDistance.h"
#include "commands/ClimberState.h"
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

  frc2::Command* GetTeleopCommand();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...

  void ConfigureButtonBindings();
  //subsystems
  DriveSubsystem m_driveSubsystem;
  ClimberSubsystem m_climberSubsystem;
  
  //commands
  //used to sequence both teleop commands at once to not interfere with climber (yuck)
  frc2::ParallelCommandGroup m_teleopCommand{DriveTeleop(&m_driveSubsystem), OperatorTeleop{&m_climberSubsystem}};

  DriveDistance m_driveDistance = DriveDistance(&m_driveSubsystem, -8_ft);
  ClimberState m_climberState = ClimberState(&m_climberSubsystem, 0_in, 0_deg);
  //assume the extender is currently latched on, but the robot is on the floor and the rotators are directly up
  //pull down and move the rotators back
  //move the rotators in place
  //extend slightly to latch rotators
  //rotate forwards (tilts bot backwards)
  //extend to first traversal bar
  //rotate backwards and pull in extender to latch on extender
  //retract extender and rotate backwards
  //move the rotators in place
  //extend slightly to latch rotators
  //rotate forwards (tilts bot backwards)
  //extend to first traversal bar
  //rotate backwards and pull in extender to latch on extender
  //retract extender and rotate backwards
  //move the rotators in place
};
