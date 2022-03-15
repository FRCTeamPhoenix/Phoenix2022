
#include "cameraserver/CameraServer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "sensors/VisionCamera.h"
#include <thread>
frc::Joystick joy1(0);

VisionCamera::VisionCamera(){
}

void VisionCamera::Start(){
  std::thread visionThreadinit(VisionThreadInitial);
  visionThreadinit.detach();
  std::thread BallDetection(BallDetection);
  BallDetection.detach();
}

void VisionCamera::VisionThreadInitial(){
  // Starting Camera Capture for the Top Camera, Camera 2
  cs::UsbCamera camera2 = frc::CameraServer::StartAutomaticCapture(1);

  // Creating an open Camera Server Stream that stays open
  server = frc::CameraServer::GetServer();

  camera2.SetConnectionStrategy(cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);

  // Setting Camera 2 Resolution and Framerate
  camera2.SetResolution(160, 120);
  camera2.SetFPS(30);
}

void VisionCamera::BallDetection(){
  // Setting up Camera 1 (Front)
  cs::UsbCamera camera1 = frc::CameraServer::StartAutomaticCapture(0);
  camera1.SetConnectionStrategy(cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);
  // Setting Camera 1 Resolution and Framerate
  camera1.SetResolution(160, 120); 
  camera1.SetFPS(30);


  // Get Mats from Camera 1
  cs::CvSink cvSink = camera1::GetVideo();

  cs::CvSource outputStream = frc::CameraServer::PutVideo("Processed Vision Feed", 640, 480);


  // All Mat, Moment, and doubles declarations
  cv:: Mat OriginalImg;
  cv:: Mat HSVimg;
  cv:: Mat Thresholded;
  cv:: Mat ImgLines = Mat::zeros(cvSink.GrabFrame().size(), CV_8UC3);
  cv:: Moments oMoments;
  double dM01;
  double dM10;
  double dArea;
  int PosX;
  int PosY;
  int LastX;
  int LastY;


  // ADD A TOGGLE SETTING HERE FOR THE TWO COLORS (DASHBOARD)
  int iLowH = 86;
  int iHighH = 142;

  int iLowS = 101;
  int iHighS = 255;

  int iLowV = 0;
  int iHighV = 255;



  while (true){

    // Error Checking and Frame Grabbing
    if (cvSink.GrabFrame(mat) == 0){
      outputStream.NotifyError(cvSink.GetError());
      continue;
    }

    // Getting and HSV copy of the current Frame
    cvtColor(OriginalImg, HSVimg, cv::COLOR_BGR2HSV);

    // Limiting the Threshold to a specific HSV Color Range
    cv::inRange(HSVimg, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), Thresholded);

    // Morphological opening (removing noise and smaller objects in the frame)
    errode(Thresholded, Thresholded, 4, cv::Point(-1, -1), 0, 3);

    // Getting the Moments of the Thresholded Image
    oMoments = moments(Thresholded);

    dM01 = oMoments.m01;
    dM10 = oMoments.m10;
    dArea = oMoments.m00;

    // If the Area is less than 1000, then there is no Object, so the following code is skipped
    // Otherwise, this determines the center point of the detected object
    if (dArea > 1000){

      PosX = dM10 / dArea;
      PosY = dM01 / dArea;

      if (LastX >= 0 && LastY >= 0 && PosX >= 0 && PosY >= 0){
        
        // Makes the ImgLines Mat completely black (RESET)
        ImgLines = Scalar(0, 0, 0);
        // Creates a line which has continuous data of the path of the object if the reset is not performed, otherwise, it has the points of center of the object
        line(ImgLines, Point(PosX, PosY), Point(LastX, LastY), Scalar(100, 100, 255), 8);

      }

      // Resetting Last X and Y
      LastX = PosX;
      LastY = PosY;

    }
    OriginalImg = OriginalImg + ImgLines;
    outputStream.PutFrame(OriginalImg);
  }
}