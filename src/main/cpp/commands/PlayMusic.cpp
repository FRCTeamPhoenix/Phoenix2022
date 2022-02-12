#include "commands/PlayMusic.h"

PlayMusic::PlayMusic(DriveSubsystem* driveSubsystem, std::string fileName):
m_driveSubsystem(driveSubsystem),
m_fileName(fileName){
    AddRequirements(m_driveSubsystem);
}

void PlayMusic::Initialize(){
    m_driveSubsystem->LoadSong(m_fileName);
    m_loops = 10;
}

void PlayMusic::Execute(){
    if(m_loops > 0){
        m_loops--;
        if(m_loops == 0)
            m_driveSubsystem->PlaySong();
    }
}

void PlayMusic::End(bool interrupted){
    m_driveSubsystem->StopSong();
}

bool PlayMusic::IsFinished(){
    return false;
}