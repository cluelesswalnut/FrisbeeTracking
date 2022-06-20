#pragma once

#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

namespace TrackFrisbee
{
        // frisbee HSV found by experimenting
        const int FRIS_LOW_H = 0;
        const int FRIS_HIGH_H = 179;

        const int FRIS_LOW_S = 0; 
        const int FRIS_HIGH_S = 255;

        const int FRIS_LOW_V = 175;
        const int FRIS_HIGH_V = 255;

        // grass HSV found by experimenting
        // int iLowH = 33;
        // int iHighH = 75;

        // int iLowS = 0; 
        // int iHighS = 255;

        // int iLowV = 0;
        // int iHighV = 255;

    std::vector<cv::Mat> thresholdFrisbeeHsv(const std::vector<cv::Mat>& video);
}