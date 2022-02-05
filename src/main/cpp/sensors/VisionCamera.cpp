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
  cs::UsbCamera camera = frc::CameraServer::StartAutomaticCapture();
  camera.SetResolution(320, 240);
  cs::CvSink cvSink = frc::CameraServer::GetVideo();
  cs::CvSource outputStreamStd = frc::CameraServer::PutVideo("Gray", 320, 240);
  cv::Mat source;
  cv::Mat output;

  while (true)
  {
    if (cvSink.GrabFrame(source) == 0)
    {
      continue;
    }
    cvtColor(source, output, cv::COLOR_BGR2GRAY);
    outputStreamStd.PutFrame(output);
  }
}