#include <frisbeetracker/TrackFrisbee.hpp>

namespace TrackFrisbee
{
    std::vector<cv::Mat> thresholdFrisbeeHsv(const std::vector<cv::Mat>& video)
    {
        std::vector<cv::Mat> frisbeeThreshold;
        for (const auto& frame : video)
        {
            cv::Mat imgHSV;
            // Convert the captured frame from BGR to HSV because HSV is more suitable for color segmentation
            cv::cvtColor(frame, imgHSV, cv::COLOR_BGR2HSV);

            // create a new image with white anywhere a pixel matches the color range for a frisbee
            cv::Mat imgThresholded;
            cv::inRange(
                    imgHSV,
                    cv::Scalar(FRIS_LOW_H, FRIS_LOW_S, FRIS_LOW_V),
                    cv::Scalar(FRIS_HIGH_H, FRIS_HIGH_S, FRIS_HIGH_V),
                    imgThresholded);

            frisbeeThreshold.push_back(imgThresholded);
        }
        return frisbeeThreshold;
    }

    std::vector<cv::Mat> frisbeeContour(const std::vector<cv::Mat>& video)
    {
        std::vector<cv::Mat> frisbeeThreshold;
        for (const auto& frame : video)
        {
            // output values for `findContours`
            std::vector<std::vector<cv::Point> > contours;
            std::vector<cv::Vec4i> hierarchy;
            // initialize an image to draw the contours on
            cv::Mat imgWithContours = cv::Mat::zeros( frame.size(), CV_8U );

            // RETR_EXTERNAL - only find the external contours
            cv::findContours( frame, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

            for( size_t i = 0; i< contours.size(); i++ )
            {
                cv::Scalar color = cv::Scalar(255);
                cv::drawContours( imgWithContours, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0 );
            }
            frisbeeThreshold.push_back(imgWithContours);
        }
        return frisbeeThreshold;
    }

}