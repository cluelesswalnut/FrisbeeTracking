#pragma once

#include <opencv2/opencv.hpp>

#include <string>

namespace OpenCvTutorial
{
    /**
     * @brief Shows a provided image
     * 
     * @param imgPath path to the image
     */
    void showImage(const std::string& imgPath);

    /**
     * @brief Shows a provided video
     * 
     * @param vidPath path to the video
     */
    void showVideo(const std::string& vidPath);

    /**
     * @brief Reads a video and stores it as a vector of frames
     * 
     * @param vidPath path to the video
     * @return std::vector<cv::Mat> each frame of the video
     */
    std::vector<cv::Mat> readVideo(const std::string& vidPath);

    /**
     * @brief Shows a video
     * 
     * @param video frames of the video
     */
    void showVideo(const std::vector<cv::Mat>& video);
}