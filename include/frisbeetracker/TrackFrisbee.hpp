#pragma once

#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

namespace TrackFrisbee
{
        // frisbee HSV bounds found by experimenting
        const int FRIS_LOW_H = 0;
        const int FRIS_HIGH_H = 179;

        const int FRIS_LOW_S = 0; 
        const int FRIS_HIGH_S = 255;

        const int FRIS_LOW_V = 175;
        const int FRIS_HIGH_V = 255;

        // grass HSV bounds found by experimenting
        // int iLowH = 33;
        // int iHighH = 75;

        // int iLowS = 0; 
        // int iHighS = 255;

        // int iLowV = 0;
        // int iHighV = 255;

    /**
     * @brief Creates a new set of frames with white pixels anywhere the input video
     * matches the color of a frisbee
     * 
     * @param video the input video to be processed
     * @return std::vector<cv::Mat> set of black and white frames
     */
    std::vector<cv::Mat> thresholdFrisbeeHsv(const std::vector<cv::Mat>& video);

    /**
     * @brief WIP
     * 
     * @param video 
     * @return std::vector<cv::Mat> 
     */
    std::vector<cv::Mat> frisbeeContour(const std::vector<cv::Mat>& video);
}