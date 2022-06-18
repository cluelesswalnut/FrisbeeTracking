#include <stdio.h>

#include "frisbeetracker/OpenCvTutorial.hpp"
// #include <opencv2/opencv.hpp>

int main()
{
    std::string pic = "1200.jpeg";
    // OpenCvTutorial::showImage(pic);
    std::string vid = "/home/me/Desktop/code/FrisbeeTracking/overheadUltimate.mp4";
    OpenCvTutorial::showVideo(vid);
}