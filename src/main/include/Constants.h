// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>
#include <units/velocity.h>
#include <units/acceleration.h>
#include <units/time.h>
#include <units/angle.h>
#include <wpi/numbers>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

// settings
enum class Scaling {NONE, ROOT, QUADRATIC, CUBIC};
const Scaling DRIVETRAIN_SCALING = Scaling::ROOT;
const double TURN_PERCENT = 0.6;

// motor ids
const int FALCON_FRONT_LEFT = 1;
const int FALCON_FRONT_RIGHT = 2;
const int FALCON_BACK_LEFT = 3;
const int FALCON_BACK_RIGHT = 4;

const int FALCON_EXTENDING_ARM = 5;
const int TALON_LEFT_ROTATOR = 6;
const int TALON_RIGHT_ROTATOR = 7;

// wheel information
const units::meter_t WHEEL_DIAMETER = 4_in;
const double TICKS_PER_ROTATION = 2048.0;
const double WHEEL_TO_FALCON_RATIO = 12.0;

//16 ft/s and 16 ft/s^2
const units::meters_per_second_t CRUISE_VELOCITY =  8_fps;
const units::meters_per_second_squared_t CRUISE_ACCELERATION = 12_fps / 1_s;

const units::meter_t DISTANCE_THRESHOLD = 2_in;

// PIDF values
const double DRIVETRAIN_DISTANCE_P = 0.55;
const double DRIVETRAIN_DISTANCE_I = 0.0;
const double DRIVETRAIN_DISTANCE_D = 0.0;
const double DRIVETRAIN_DISTANCE_F = 0.0;
const double TURN_P = 0.0;
const double TURN_I = 0.0;
const double TURN_D = 0.0;

// controller
const int DRIVE_JOYSTICK = 0;
const int OPERATOR_JOYSTICK = 1;
const int LEFTSTICK_X = 0;
const int LEFTSTICK_Y = 1;
const int RIGHTSTICK_X = 4;
const int RIGHTSTICK_Y = 5;
const auto TURN_RATE = wpi::numbers::pi * 0.5_rad / 1_s;