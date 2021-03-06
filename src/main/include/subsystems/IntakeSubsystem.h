#pragma once

#include <frc/motorcontrol/Spark.h>
#include <frc2/command/SubsystemBase.h>
#include <units/length.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase {
    public:
        IntakeSubsystem();

        void ConfigureDefault();

        void SetIntakeSpeed(double speed);

        void SetArmSpeed(double speed);

        void SetArmAngle(units::radian_t angle);
        
        void SetShooterSpeed(double speed);

        void SetShooterVelocity(double rpm);

        void SetIndexerSpeed(double speed);

        void ZeroArmEncoders();

        units::radian_t GetArmAngle();

    private:
        units::radian_t ArmTicksToAngle(double ticks);
        double ArmAngleToTicks(units::radian_t angle);
        double ShooterRPMToTicks(double rpm);
        
        WPI_TalonSRX m_intakeArm{TALON_ARM};
        WPI_TalonSRX m_intakeShooter{TALON_SHOOTER};
        WPI_VictorSPX m_intake{VICTOR_INTAKE};
        WPI_VictorSPX m_intakeIndexer{VICTOR_INDEXER}; // the big wheel that holds the ball
};