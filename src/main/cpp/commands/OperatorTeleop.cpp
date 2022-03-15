#include "commands/OperatorTeleop.h"
#include <iostream>

OperatorTeleop::OperatorTeleop(){
}

void OperatorTeleop::Initialize(){
    std::cout << "Started operator teleop" << std::endl;
}

void OperatorTeleop::Execute(){
}

void OperatorTeleop::End(bool interrupted){
    std::cout << "Ended operator teleop" << std::endl;
}

bool OperatorTeleop::IsFinished(){
    return false;
}