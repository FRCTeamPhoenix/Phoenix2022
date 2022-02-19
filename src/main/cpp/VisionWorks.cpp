#include "cameraserver/CameraServer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
class Robot: public IterativeRobot
{
private:
  static void VisionThread()
  {
    cs::UsbCamera camera = frc::CameraServer::StartAutomaticCapture();
    camera.SetResolution(640, 480);
    cs::CvSink cvSink = frc::CameraServer::GetVideo();
    cs::CvSource outputStreamStd = frc::CameraServer::PutVideo("Gray", 640, 480);
    cv::Mat source;
    cv::Mat output;
    while(true) {
      if (cvSink.GrabFrame(source) == 0) {
        continue;
      }
      cvtColor(source, output, cv::COLOR_BGR2GRAY);
      outputStreamStd.PutFrame(output);
    }
  }
  void RobotInit()
  {
    std::thread visionThread(VisionThread);
    visionThread.detach();
  }
};
START_ROBOT_CLASS(Robot)