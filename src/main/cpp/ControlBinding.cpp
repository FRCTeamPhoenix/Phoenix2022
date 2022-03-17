#include "ControlBinding.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/GenericHID.h>

ControlBinding::ControlBinding() {}

void ControlBinding::Initialize()
{
  SetDefaultControls();
}

void ControlBinding::SetDefaultControls()
{
  // set prefrences and defult values
  if (!frc::Preferences::ContainsKey(controls::FORWARDAXIS))
  {
    frc::Preferences::SetInt(controls::FORWARDAXIS, LEFTSTICK_Y);
  }

  if (!frc::Preferences::ContainsKey(controls::TURNAXIS))
  {
    frc::Preferences::SetInt(controls::TURNAXIS, RIGHTSTICK_X);
  }

  const std::string ARMAXIS = "ARM";
  const std::string WRISTAXIS = "WRIST";
  const std::string INTAKEINBUTTON = "INTAKEIN";
  const std::string INTAKEOUTBUTTOn = "INTAKEOUT";
}

// finds axis of named key
double ControlBinding::GetAxis(std::string key, bool opController)
{
  if (opController)
    return m_supportController.GetRawAxis(frc::Preferences::GetInt(key, 0));
  else
    return m_driveController.GetRawAxis(frc::Preferences::GetInt(key, 0));
}

// finds if button is pushed of named key
bool ControlBinding::GetButton(std::string key, bool opController)
{
  if (opController)
    return m_supportController.GetRawButtonPressed(frc::Preferences::GetInt(key, 0));
  else
    return m_driveController.GetRawButtonPressed(frc::Preferences::GetInt(key, 0));
}