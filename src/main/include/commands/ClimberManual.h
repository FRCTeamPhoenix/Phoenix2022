#pragma once

#include "Constants.h"
#include "subsystems/ClimberSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc/controller/PIDController.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>

class ClimberManual : public frc2::CommandHelper<frc2::CommandBase, ClimberManual>{
public:
    ClimberManual(ClimberSubsystem* climberSubsystem);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    ClimberSubsystem* m_climberSubsystem;
    frc::Joystick m_operatorJoystick{OPERATOR_JOYSTICK};
};