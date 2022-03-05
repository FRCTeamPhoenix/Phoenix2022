#pragma once

#include <frc/motorcontrol/Spark.h>
#include <frc2/command/SubsystemBase.h>
#include <units/length.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase {
    public:
        IntakeSubsystem();

        void ConfigureDefault();

        void SetLiftSpeed(double speed);
        
        void SetPivotSpeed(double speed);

        void SetIntakeSpeed(double speed);

        void SetLiftAngle(units::radian_t angle);

        void SetPivotAngle(units::radian_t angle);

        void ZeroLiftEncoders();

        void ZeroIntakePivot();

        units::radian_t GetLiftAngle();

        units::radian_t GetPivotAngle();
    private:
        units::radian_t LiftTicksToAngle(double ticks);
        double LiftAngleToTicks(units::radian_t angle);
        units::radian_t PivotTicksToAngle(double ticks);
        double PivotAngleToTicks(units::radian_t angle);

        WPI_TalonSRX m_intakeLift{TALON_INTAKE_LIFT};
        WPI_TalonSRX m_intakePivot{TALON_INTAKE_PIVOT};
        frc::Spark m_intake{SPARK_INTAKE};
};