#include "cameraserver/CameraServer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "sensors/VisionCamera.h"
#include <thread>

using namespace cv;

VisionCamera::VisionCamera()
{
}

void VisionCamera::Start()
{
  std::thread visionThread(VisionThread);
  visionThread.detach();
}

void VisionCamera::VisionThread()
{
  cs::UsbCamera camera = frc::CameraServer::StartAutomaticCapture();
  camera.SetResolution(720, 480);
  camera.SetFPS(30);
  cs::CvSink cvSink = frc::CameraServer::GetVideo();
  cs::CvSource outputStreamStd = frc::CameraServer::PutVideo("Gray", 720, 480);
  cv::Mat source;
  cv::Mat output;
  
  int i = 1;

  while (true)
  {
    if (cvSink.GrabFrame(source) == 0)
    {
      continue;
    }
    outputStreamStd.putVideo(source);

  }
}