#pragma once

#include "Constants.h"
#include "subsystems/ClimberSubsystem.h"
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
    ClimberSubsystem* m_climberSubsystem;
    frc::Joystick m_operatorJoystick{OPERATOR_JOYSTICK};
    IntakeSubsystem* m_intakeSubsystem;
    frc::Joystick m_operatorJoystick{OPERATOR_JOYSTICK};
    int arm_scale = 1;
    int wrist_scale = 1;
    bool invert_arm = false;
    bool invert_wrist = true;
    bool invert_intake = true;
};