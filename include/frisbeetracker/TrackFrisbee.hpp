#pragma once

#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

namespace TrackFrisbee
{
    // frisbee size found by experimenting
    const int FRISBEE_MAX_AREA = 100;
    const int FRISBEE_MIN_AREA = 25;

    // frisbee HSV bounds found by experimenting
    const int FRIS_LOW_H = 0;
    const int FRIS_HIGH_H = 179;

    const int FRIS_LOW_S = 0; 
    const int FRIS_HIGH_S = 255;

    const int FRIS_LOW_V = 175;
    const int FRIS_HIGH_V = 255;

    typedef std::vector<std::vector<cv::Point>> FrameContours;

    /**
     * @brief Creates a new set of frames with white pixels anywhere the input video
     * matches the color of a frisbee
     * 
     * @param video the input video to be processed
     * @return std::vector<cv::Mat> set of black and white frames
     */
    std::vector<cv::Mat> thresholdFrisbeeHsv(const std::vector<cv::Mat>& video);

    /**
     * @brief Find contours that could be a frisbee based on approximating the
     * polygon, size, and concavity
     * 
     * @param video the video to find the contours in. Video needs to be consist of
     * CV_U8 frames.
     * @return std::vector<FrameContours> containing each of the potential frisbee contours
     */
    std::vector<FrameContours> findFrisbeeContours(const std::vector<cv::Mat>& video);

    /**
     * @brief Draws contours on the frames of an existing video
     * 
     * @param video the video the draw on
     * @param contours the contours to draw. One `FrameContours` is required per frame in 
     * @p video
     * @return std::vector<cv::Mat> the resulting video
     */
    std::vector<cv::Mat> showContours(const std::vector<cv::Mat>& video, const std::vector<FrameContours>& contours);
}