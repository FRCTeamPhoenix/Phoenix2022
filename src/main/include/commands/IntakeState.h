#pragma once

#include "Constants.h"
#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <units/length.h>
#include <units/angle.h>

class IntakeState : public frc2::CommandHelper<frc2::CommandBase, IntakeState>{
public:
    IntakeState(IntakeSubsystem* IntakeSubsystem);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    IntakeSubsystem* m_intakeSubsystem;
};