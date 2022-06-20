#include <frisbeetracker/TrackFrisbee.hpp>

namespace TrackFrisbee
{
    std::vector<cv::Mat> thresholdFrisbeeHsv(const std::vector<cv::Mat>& video)
    {
        std::vector<cv::Mat> frisbeeThreshold;
        for (const auto& frame : video)
        {
            cv::Mat imgHSV;

            cv::cvtColor(frame, imgHSV, cv::COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

            cv::Mat imgThresholded;

            cv::inRange(
                    imgHSV,
                    cv::Scalar(FRIS_LOW_H, FRIS_LOW_S, FRIS_LOW_V),
                    cv::Scalar(FRIS_HIGH_H, FRIS_HIGH_S, FRIS_HIGH_V),
                    imgThresholded); //Threshold the image

            // //morphological opening (remove small objects from the foreground)
            // cv::erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)) );
            // cv::dilate( imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)) ); 

            // //morphological closing (fill small holes in the foreground)
            // cv::dilate( imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)) ); 
            // cv::erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)) );

            frisbeeThreshold.push_back(imgThresholded);
        }
        return frisbeeThreshold;
    }

}