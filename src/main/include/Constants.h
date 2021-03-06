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
#include <units/current.h>

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
const double DRIVETRAIN_SPEED_MULTIPLIER = 0.6;
const double TURN_PERCENT = 0.6;

// motor ids
const int FALCON_FRONT_LEFT = 1;
const int FALCON_FRONT_RIGHT = 2;
const int FALCON_BACK_LEFT = 3;
const int FALCON_BACK_RIGHT = 4;

const int FALCON_EXTENDING_ARM = 5;
const int TALON_LEFT_ROTATOR = 6;
const int TALON_RIGHT_ROTATOR = 7;

const int TALON_ARM = 8;
const int VICTOR_INDEXER = 9;
const int TALON_SHOOTER = 10;
const int VICTOR_INTAKE = 11;

// wheel information
const units::meter_t WHEEL_DIAMETER = 4_in;
const double FALCON_TICKS_PER_ROTATION = 2048.0;
const double WHEEL_TO_FALCON_RATIO = 12.0;

//16 ft/s and 16 ft/s^2
const units::meters_per_second_t CRUISE_VELOCITY =  8_fps;
const units::meters_per_second_squared_t CRUISE_ACCELERATION = 8_fps / 1_s;

const units::meter_t DISTANCE_THRESHOLD = 2_in;

// PIDF drivetrain values
const double DRIVETRAIN_DISTANCE_P = 0.55;
const double DRIVETRAIN_DISTANCE_I = 0.0;
const double DRIVETRAIN_DISTANCE_D = 0.0;
const double DRIVETRAIN_DISTANCE_F = 0.0;
const double TURN_P = 0.0;
const double TURN_I = 0.0;
const double TURN_D = 0.0;

//Extender PIDF
const double EXTENDER_P = 0.8;
const double EXTENDER_I = 0.0;
const double EXTENDER_D = 1.0;
const double EXTENDER_F = 0.05;

const double EXTENDER_MANUAL_P = 0.25;
const double EXTENDER_MANUAL_I = 0.0;
const double EXTENDER_MANUAL_D = 1.0;
const double EXTENDER_MANUAL_F = 0.05;

const units::meter_t EXTENDER_POSITION_THRESHOLD = 0.9_in;
const double EXTENDER_VELOCITY_THRESHOLD = 1500;
const units::meter_t MAX_EXTENDER_HEIGHT = 25_in;

//Rotator PIDF
const double ROTATOR_LEFT_P = 3.0;
const double ROTATOR_LEFT_I = 0.0;
const double ROTATOR_LEFT_D = 0.0;
const double ROTATOR_LEFT_F = 0.0;

const double ROTATOR_RIGHT_P = 3.0;
const double ROTATOR_RIGHT_I = 0.0;
const double ROTATOR_RIGHT_D = 0.0;
const double ROTATOR_RIGHT_F = 0.0;

const units::radian_t ROTATOR_POSITION_THRESHOLD = 3.0_deg;
const units::radian_t MAX_ROTATOR_ANGLE = 70_deg;
const double ROTATOR_VELOCITY_THRESHOLD = 10.0;

// controller
const int DRIVE_JOYSTICK = 0;
const int LEFTSTICK_X = 0;
const int LEFTSTICK_Y = 1;
const int RIGHTSTICK_X = 4;
const int RIGHTSTICK_Y = 5;
const int BUMPER_L = 5;
const int BUMPER_R = 6;
const auto TURN_RATE = wpi::numbers::pi * 0.7_rad / 1_s;

//control panel
const int OPERATOR_JOYSTICK = 1;
const int LOWER_BUTTON = 4;
const int RAISE_BUTTON = 3;
const int START_AUTO_BUTTON = 7;
const int CANCEL_AUTO_BUTTON = 5;
const int ZERO_CLIMBER_BUTTON = 6;
const int MANUAL_SWITCH = 2;
const int SHOOTER_SWITCH = 1;

const int INTAKE_SLIDER = 0;
const int WRIST_SLIDER = 5;
const int INDEXER_SLIDER = 4;
const int EXTENDER_SLIDER = 1;
const int ROTATOR_DIAL = 2;

// intake
const units::ampere_t MAX_ARM_CURRENT = units::ampere_t(20.0);
const double TALON_TO_ARM_RATIO = 1;
const double TALON_TO_SHOOTER_RATIO = 1;
const double ARM_VELOCITY_MAX = 1500; // in ticks per hundred milliseconds, default from example
const double ARM_ACCEL_MAX = 1500;
const double ARM_P = 0;
const double ARM_I = 0;
const double ARM_D = 0;
const double ARM_F = 0;
const double INTAKE_WRIST_SPEED = 0.5;
const double INTAKE_SPEED = 1.0;
const double INDEXER_SPEED = 0.6;
const double SHOOTER_SPEED = 0.5;
const double SHOOTER_AUTO_SPEED = 0.4;

// climber
const units::ampere_t MAX_EXTENDER_CURRENT = units::ampere_t(60.0);
const double MAX_EXTENDER_FORWARD_OUTPUT = 1.0;
const double MAX_EXTENDER_REVERSE_OUTPUT = -1.0;
const double MAX_ROTATOR_OUTPUT = 1.0;
const units::meter_t EXTENDER_SPROCKET_DIAMETER = 1.79_in;
const double TALON_TICKS_PER_ROTATION = 4096.0;
const double FALCON_TO_EXTENDER_RATIO = 36.0;
const double TALON_TO_ROTATOR_RATIO = 44.0 / 15.0;
const units::radian_t MIN_ROTATION = 0_deg;
const units::radian_t MAX_ROTATION = 170_deg;
const units::meter_t MIN_EXTEND = 0_in;
const units::meter_t MAX_EXTEND = 15_in;
const units::meters_per_second_t EXTENDER_VELOCITY = 8_fps;
const units::meters_per_second_squared_t EXTENDER_ACCELERATION = 4_fps / 1_s;
const auto ROTATOR_VELOCITY = 90_deg / 1_s;
const auto ROTATOR_ACCELERATION = 90_deg / 1_s / 1_s;

