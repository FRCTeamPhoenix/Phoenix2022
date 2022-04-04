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

  m_driveSubsystem.SetDefaultCommand(std::move(m_driveTeleop));
  m_intakeSubsystem.SetDefaultCommand(std::move(m_operatorTeleop));

  //add chooser options
  m_autoChooser.SetDefaultOption("Defense Auto", &m_driveDistance);
  m_autoChooser.AddOption("One Ball Auto", &m_oneBallAuto);

  frc::SmartDashboard::PutData(&m_autoChooser);

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_lowerButton.CancelWhenPressed(&m_raiseClimber).CancelWhenPressed(&m_climberRoutine).WhenPressed(&m_defaultClimberState);
  m_raiseButton.CancelWhenPressed(&m_defaultClimberState).CancelWhenPressed(&m_climberRoutine).WhenPressed(&m_raiseClimber);
  m_autoButton.CancelWhenPressed(&m_raiseClimber).CancelWhenPressed(&m_defaultClimberState).WhenPressed(&m_climberRoutine);
  m_cancelAutoButton.CancelWhenPressed(&m_raiseClimber).CancelWhenPressed(&m_defaultClimberState).CancelWhenPressed(&m_climberRoutine);
  m_zeroButton.WhileHeld(&m_zeroHeld).WhenReleased(&m_zeroReleased);
  m_manualMode.CancelWhenPressed(&m_raiseClimber).CancelWhenPressed(&m_climberRoutine).CancelWhenPressed(&m_defaultClimberState).WhileHeld(&m_climberManual);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  //grab the current dashboard values for target height and target angle
  units::meter_t targetHeight = units::inch_t(frc::SmartDashboard::GetNumber("Target Height", 0.0));
  units::radian_t targetAngle = units::degree_t(frc::SmartDashboard::GetNumber("Target Angle", 0.0));
  m_climberState = ClimberState(&m_climberSubsystem, targetHeight, targetAngle);

  //actual auto
  return m_autoChooser.GetSelected();
}
