#pragma once

#include <opencv2/opencv.hpp>

#include <string>

namespace OpenCvTutorial
{
    void showImage(const std::string& imgPath);

    void showVideo(const std::string& vidPath);

    std::vector<cv::Mat> readVideo(const std::string& vidPath);

    void showVideo(const std::vector<cv::Mat>& video);

    void test(const std::string& vidPath);
}