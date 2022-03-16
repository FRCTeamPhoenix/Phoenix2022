
#include "cameraserver/CameraServer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "sensors/VisionCamera.h"
#include <thread>

VisionCamera::VisionCamera(){
}

void VisionCamera::Start(){
  std::thread visionThread(VisionThread);
  visionThread.detach();
}

void VisionCamera::VisionThread(){
  cs::UsbCamera camera1 = frc::CameraServer::StartAutomaticCapture();
  cs::UsbCamera camera2 = frc::CameraServer::StartAutomaticCapture();

  camera1.SetConnectionStrategy(cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);
  camera2.SetConnectionStrategy(cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);

  camera1.SetResolution(160, 120); 
  camera1.SetFPS(30);
  camera2.SetResolution(160, 120); 
  camera2.SetFPS(30);
}