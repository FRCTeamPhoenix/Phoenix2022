#pragma once

#include "Constants.h"
#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc/controller/PIDController.h>
#include <units/length.h>
#include <units/angle.h>
#include <frc/Joystick.h>

class IntakeState : public frc2::CommandHelper<frc2::CommandBase, IntakeState>{
public:
    IntakeState(IntakeSubsystem* IntakeSubsystem);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    IntakeSubsystem* m_intakeSubsystem;
    frc::Joystick m_operatorJoystick{OPERATOR_JOYSTICK};
    int arm_scale = 1;
    int wrist_scale = 1;
    bool invert_arm = false;
    bool invert_wrist = false;
    bool invert_intake = false;
    // units::radian_t angle;
    // frc2::PIDController m_pidController{ARM_P, ARM_I, ARM_D};
};