#pragma once

#include "Constants.h"
#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc/controller/PIDController.h>
#include <units/length.h>
#include <units/angle.h>

class IntakeState : public frc2::CommandHelper<frc2::CommandBase, IntakeState>{
public:
    IntakeState(IntakeSubsystem* IntakeSubsystem, units::radian_t angle);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    IntakeSubsystem* m_intakeSubsystem;
    units::radian_t angle;

    frc2::PIDController m_pidController{ARM_P, ARM_I, ARM_D};
};