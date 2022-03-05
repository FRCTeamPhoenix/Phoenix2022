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

        void SetArmSpeed(double speed);
        
        void SetWristSpeed(double speed);

        void SetIntakeSpeed(double speed);

        void SetArmAngle(units::radian_t angle);

        void SetWristAngle(units::radian_t angle);

        void ZeroArmEncoders();

        void ZeroIntakeWrist();

        units::radian_t GetArmAngle();

        units::radian_t GetWristAngle();
    private:
        units::radian_t ArmTicksToAngle(double ticks);
        double ArmAngleToTicks(units::radian_t angle);
        units::radian_t WristTicksToAngle(double ticks);
        double WristAngleToTicks(units::radian_t angle);

        frc::Spark m_intakeArm{SPARK_ARM};
        WPI_TalonSRX m_intakeWrist{TALON_WRIST};
        WPI_TalonSRX m_intake{TALON_INTAKE};
};