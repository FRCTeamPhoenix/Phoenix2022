#pragma once

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

class FaceTarget : public frc2::CommandHelper<frc2::CommandBase, FaceTarget>{
public:
    FaceTarget(DriveSubsystem* driveSubsystem);
        
    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSubsystem* m_driveSubsystem;
    frc::Timer m_timer;
    units::second_t m_lastExecute;
    units::radian_t m_heading;
};