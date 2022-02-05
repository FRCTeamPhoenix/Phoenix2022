#pragma once
#include "cameraserver/CameraServer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class VisionCamera{
    public:
        VisionCamera();
        void Start();

    private:
        static void VisionThread();
};