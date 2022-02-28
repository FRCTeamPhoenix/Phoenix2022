#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/length.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class ClimberSubsystem : public frc2::SubsystemBase {
    public:
        ClimberSubsystem();

        void Periodic();

        void ConfigureDefault();
    
        void SetExtenderSpeed(double percent);

        void SetRotatorSpeed(double percent);

        void ZeroExtenderEncoders();

        void ZeroRotatorEncoders();
    private:
        units::meter_t ExtenderTicksToDistance(double ticks);
        double ExtenderDistanceToTicks(units::meter_t distance);
        units::radian_t RotatorTicksToDegrees(double ticks);
        double RotatorDegreesToTicks(units::radian_t degrees);
        WPI_TalonFX m_extenderArm{FALCON_EXTENDING_ARM};
        WPI_TalonSRX m_leftRotator{TALON_LEFT_ROTATOR};
        WPI_TalonSRX m_rightRotator{TALON_RIGHT_ROTATOR};

};