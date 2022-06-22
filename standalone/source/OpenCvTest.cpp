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
    std::vector<cv::Mat> videoEdit = TrackFrisbee::thresholdFrisbeeHsv(video);

    std::vector<TrackFrisbee::FrameContours> contours = TrackFrisbee::findFrisbeeContours(videoEdit);
    videoEdit = TrackFrisbee::showContours(video, contours);

    OpenCvTutorial::showVideo(videoEdit);
}