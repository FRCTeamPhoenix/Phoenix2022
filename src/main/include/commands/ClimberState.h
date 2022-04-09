#pragma once

#include "Constants.h"
#include "subsystems/ClimberSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <units/length.h>
#include <units/angle.h>

class ClimberState : public frc2::CommandHelper<frc2::CommandBase, ClimberState>{
public:
    ClimberState(ClimberSubsystem* climberSubsystem, units::meter_t extenderDistance, units::radian_t rotatorAngle, bool disableArms = false, bool ends = true);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    bool InThreshold();

    ClimberSubsystem* m_climberSubsystem;
    
    units::meter_t m_extenderDistance;
    units::radian_t m_rotatorAngle;
    bool m_disableRotator;
    bool m_ends;
};