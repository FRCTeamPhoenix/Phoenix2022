#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/length.h>
#include <ctre/Phoenix.h> 

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
    public:
        DriveSubsystem();

        void Periodic();

        void TankDrive(double left, double right);

        void ConfigureDefault();

        void ZeroEncoders();

        bool IsStopped();

        //(Changes how 'smooth' motion magic operates) call this wherever input is being handled, perhaps using bumpers to increase/decrease
        void AdjustSmoothing(int x);

        //average of both wheels in terms of error
        units::meter_t ClosedLoopError();

        //called periodically
        void RunMotionMagic(units::meter_t distance);

        units::meter_t GetAverageDistance();

    private:
        units::meter_t TicksToDistance(double ticks);
        double DistanceToTicks(units::meter_t distance);

        WPI_TalonFX m_frontLeft{FALCON_FRONT_LEFT};
        WPI_TalonFX m_frontRight{FALCON_FRONT_RIGHT};
        WPI_TalonFX m_backLeft {FALCON_BACK_LEFT};
        WPI_TalonFX m_backRight {FALCON_BACK_RIGHT};

        int smoothing;
};
