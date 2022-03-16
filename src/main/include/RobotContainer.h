// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/Joystick.h>

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

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  frc::Joystick m_controlPanel{CONTROL_PANEL_JOYSTICK};
  frc2::JoystickButton m_lowerButton{&m_controlPanel, LOWER_BUTTON};
  frc2::JoystickButton m_raiseButton{&m_controlPanel, RAISE_BUTTON};
  frc2::JoystickButton m_autoButton{&m_controlPanel, START_AUTO_BUTTON};
  frc2::JoystickButton m_cancelAutoButton{&m_controlPanel, CANCEL_AUTO_BUTTON};
  frc2::JoystickButton m_zeroButton{&m_controlPanel, ZERO_CLIMBER_BUTTON};

  void ConfigureButtonBindings();
  //subsystems
  DriveSubsystem m_driveSubsystem;
  ClimberSubsystem m_climberSubsystem;
  
  //commands
  DriveTeleop m_driveTeleop{&m_driveSubsystem};

  DriveDistance m_driveDistance = DriveDistance(&m_driveSubsystem, -8_ft);
  ClimberState m_climberState = ClimberState(&m_climberSubsystem, 0_in, 0_deg);

  //default position
  ClimberState m_defaultClimberState{&m_climberSubsystem, 0_in, 0_deg};
  //height for the starting position is 20 in
  ClimberState m_raiseClimber{&m_climberSubsystem, 20_in, 0_deg};

  //assume the extender is currently latched on, but the robot is on the floor and the rotators are directly up
  frc2::SequentialCommandGroup m_climberRoutine{
    //pull down and move the rotators back
    ClimberState(&m_climberSubsystem, 0_in, 30_deg),
    //move the rotators in place
    ClimberState(&m_climberSubsystem, 0_in, 35_deg),
    //extend slightly to latch rotators -- FIRST RUNG LATCHED --
    ClimberState(&m_climberSubsystem, 2.5_in, 35_deg),
    //rotate forwards (tilts bot backwards)
    ClimberState(&m_climberSubsystem, 2.5_in, 64_deg),
    //extend to first traversal bar
    ClimberState(&m_climberSubsystem, 24.5_in, 64_deg),
    //rotate backwards
    ClimberState(&m_climberSubsystem, 24.5_in, 54_deg),
    //latch extender
    ClimberState(&m_climberSubsystem, 4.5_in, 54_deg, true),
    //rotate backwards
    ClimberState(&m_climberSubsystem, 4.5_in, 30_deg),
    //retract extender
    ClimberState(&m_climberSubsystem, 0_in, 30_deg),
    //move the rotators in place
    ClimberState(&m_climberSubsystem, 0_in, 35_deg),
    //extend slightly to latch rotators -- SECOND RUNG LATCHED --
    ClimberState(&m_climberSubsystem, 2.5_in, 35_deg),
    //rotate forwards (tilts bot backwards)
    ClimberState(&m_climberSubsystem, 2.5_in, 64_deg),
    //extend to third traversal bar
    ClimberState(&m_climberSubsystem, 24.5_in, 64_deg),
    //rotate backward
    ClimberState(&m_climberSubsystem, 24.5_in, 54_deg),
    //latch extender
    ClimberState(&m_climberSubsystem, 4.5_in, 54_deg, true),
    //rotate backwards
    ClimberState(&m_climberSubsystem, 4.5_in, 30_deg),
    //retract extender
    ClimberState(&m_climberSubsystem, 0_in, 30_deg),
    //move the rotators in place
    ClimberState(&m_climberSubsystem, 0_in, 35_deg),
    //extend slightly to latch rotators -- THIRD RUNG LATCHED --
    ClimberState(&m_climberSubsystem, 2.5_in, 35_deg)
  };

  //inline commands for some of the buttons
  frc2::FunctionalCommand m_zeroClimber{
    [this] {},
    [this] { m_climberSubsystem.SetExtenderSpeed(-0.2); },
    [this] (bool interrupted) { m_climberSubsystem.ZeroRotatorEncoders(); m_climberSubsystem.ZeroExtenderEncoders();},
    [this] {return m_climberSubsystem.GetBottomExtenderLimit();},
    {&m_climberSubsystem}
  };
};
