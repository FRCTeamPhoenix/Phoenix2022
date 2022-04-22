#pragma once

#include "Constants.h"
#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc/controller/PIDController.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>

class OperatorTeleop : public frc2::CommandHelper<frc2::CommandBase, OperatorTeleop>{
public:
    OperatorTeleop(IntakeSubsystem* intakeSubsystem);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    IntakeSubsystem* m_intakeSubsystem;
    frc::Joystick m_driverJoystick{DRIVE_JOYSTICK};
    frc::Joystick m_operatorJoystick{OPERATOR_JOYSTICK};
    units::radian_t m_armAngle;
};