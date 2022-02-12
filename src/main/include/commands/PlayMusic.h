#pragma once

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

class PlayMusic : public frc2::CommandHelper<frc2::CommandBase, PlayMusic>{
public:
    PlayMusic(DriveSubsystem* driveSubsystem, std::string fileName);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSubsystem* m_driveSubsystem;

    int m_loops = 10;
    std::string m_fileName = "";
};