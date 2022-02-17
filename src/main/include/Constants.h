// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#include <units/length.h>

//talons

const int TALON_FRONT_LEFT = 1;
const int TALON_FRONT_RIGHT = 2;
const int VICTOR_BACK_LEFT = 3;
const int VICTOR_BACK_RIGHT = 4;

//wheel stuff
const units::meter_t WHEEL_DIAMETER = 6_in;
const double TICKS_PER_ROTATION = 4096;

//controls

const int DRIVE_JOYSTICK = 0;
const int OPERATOR_JOYSTICK = 1;

const int LEFTSTICK_X = 0;
const int LEFTSTICK_Y = 1;
const int RIGHTSTICK_X = 4;
const int RIGHTSTICK_Y = 5;

const double DRIVETRAIN_DISTANCE_P = 0.0;
const double DRIVETRAIN_DISTANCE_I = 0.0;
const double DRIVETRAIN_DISTANCE_D = 0.0;
const double DRIVETRAIN_DISTANCE_F = 0.0;

//control binding
static constexpr std::string_view LeftKey = "Left";
static constexpr std::string_view RightKey = "Right";
static constexpr std::string_view ClimberUpKey = "ClimberUp";