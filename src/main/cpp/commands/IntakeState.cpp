#include "commands/IntakeState.h"

IntakeState::IntakeState(IntakeSubsystem* IntakeSubsystem):
m_intakeSubsystem(IntakeSubsystem)
{
    AddRequirements(IntakeSubsystem);
}

void IntakeState::Initialize(){

}

void IntakeState::Execute(){

}

void IntakeState::End(bool interrupted){

}

bool IntakeState::IsFinished(){
    return false;
}