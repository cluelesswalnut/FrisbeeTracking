#include <stdio.h>

#include "frisbeetracker/OpenCvTutorial.hpp"
#include "frisbeetracker/TrackFrisbee.hpp"
// #include <opencv2/opencv.hpp>

#include <vector>

int main()
{
    std::string pic = "1200.jpeg";
    // OpenCvTutorial::showImage(pic);
    std::string vid = "/home/me/Desktop/code/FrisbeeTracking/overheadUltimate.mp4";
    // OpenCvTutorial::showVideo(vid);
    // OpenCvTutorial::test(vid);

    std::vector<cv::Mat> video = OpenCvTutorial::readVideo(vid);
    video = TrackFrisbee::thresholdFrisbeeHsv(video);
    video = TrackFrisbee::frisbeeContour(video);

    OpenCvTutorial::showVideo(video);
}