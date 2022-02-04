// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>
#include <units/velocity.h>
#include <units/time.h>
#include <units/angle.h>
#include <wpi/math>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

// motor ids
const int TALON_FRONT_LEFT = 1;
const int TALON_FRONT_RIGHT = 2;
const int VICTOR_BACK_LEFT = 3;
const int VICTOR_BACK_RIGHT = 4;

// wheel information
const units::meter_t WHEEL_DIAMETER = 4.5_in;
const double TICKS_PER_ROTATION = 4096; // this is likely the value, but if its going twice as fast as expected then this could be the place to look

// PIDF values
const double DRIVETRAIN_DISTANCE_P = 0.0;
const double DRIVETRAIN_DISTANCE_I = 0.0;
const double DRIVETRAIN_DISTANCE_D = 0.0;
const double DRIVETRAIN_DISTANCE_F = 0.0;
const double TURN_P = 0.0;
const double TURN_I = 0.0;
const double TURN_D = 0.0;

// controller
const double DRIVE_JOYSTICK = 0;
const int LEFTSTICK_X = 0;
const int LEFTSTICK_Y = 1;
const int RIGHTSTICK_X = 4;
const int RIGHTSTICK_Y = 5;
const auto TURN_RATE = wpi::math::pi * 0.5_rad / 1_s;