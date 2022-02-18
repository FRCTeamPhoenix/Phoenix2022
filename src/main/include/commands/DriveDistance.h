#pragma once

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <units/length.h>

class DriveDistance : public frc2::CommandHelper<frc2::CommandBase, DriveDistance>{
public:
    DriveDistance(DriveSubsystem* driveSubsystem, units::meter_t distance);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSubsystem* m_driveSubsystem;
    units::meter_t m_distance;

};