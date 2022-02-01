#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/length.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
    public:
        DriveSubsystem();

        void Periodic();

        void Tankdrive(double left, double right);

        void ConfigureDefault();

        void ZeroEncoders();

        bool IsStopped();

        void AdjustSmoothing(int x);

        //average of both wheels in terms of error
        units::meter_t ClosedLoopError();

        //called periodically
        void RunMotionMagic(units::meter_t distance);
    private:
        units::meter_t TicksToDistance(double ticks);
        double DistanceToTicks(units::meter_t distance);

        WPI_TalonFX m_frontLeft{TALON_FRONT_LEFT};
        WPI_TalonFX m_frontRight{TALON_FRONT_RIGHT};
        WPI_TalonFX m_backLeft {VICTOR_BACK_LEFT};
        WPI_TalonFX m_backRight {VICTOR_BACK_RIGHT};

        int smoothing;
};