#pragma once

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc/controller/PIDController.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>

#include <units/angle.h>

class DriveTeleop : public frc2::CommandHelper<frc2::CommandBase, DriveTeleop>{
public:
    DriveTeleop(DriveSubsystem* driveSubsystem);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSubsystem* m_driveSubsystem;
    frc::Joystick m_driveJoystick{DRIVE_JOYSTICK};

    frc::PIDController m_turnController{TURN_P, TURN_I, TURN_D};

    frc::Timer m_timer;
    units::second_t m_lastExecute;
    units::radian_t m_heading;
};