// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "subsystems/DriveSubsystem.h"
#include <units/angle.h>
#include <units/length.h>
#include <frc/smartdashboard/SmartDashboard.h>

RobotContainer::RobotContainer() {
  //set default auto paramaters
  frc::SmartDashboard::SetDefaultNumber("Target Height", 0.0);
  frc::SmartDashboard::SetDefaultNumber("Target Angle", 0.0);

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
  //grab the current dashboard values for target height and target angle
  units::meter_t targetHeight = units::inch_t(frc::SmartDashboard::GetNumber("Target Height", 0.0));
  units::radian_t targetAngle = units::degree_t(frc::SmartDashboard::GetNumber("Target Angle", 0.0));
  m_climberState = ClimberState(&m_climberSubsystem, targetHeight, targetAngle);
  return &m_climberRoutine;
}
