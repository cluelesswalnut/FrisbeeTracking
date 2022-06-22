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

    std::vector<FrameContours> findFrisbeeContours(const std::vector<cv::Mat>& video)
    {
        // verify each image is the correct format
        for (const auto& i : video)
            assert(i.type() == CV_8U);

        std::vector<FrameContours> finalContours;
        for (const auto& frame : video)
        {
            // output values for `findContours`
            FrameContours contours;
            FrameContours frisbeeContours;
            std::vector<cv::Vec4i> hierarchy;
            // initialize an image to draw the contours on
            cv::Mat imgWithContours = cv::Mat::zeros( frame.size(), CV_8U );

            // RETR_EXTERNAL - only find the external contours
            cv::findContours( frame, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

            for( size_t i = 0; i< contours.size(); i++ )
            {
                // `approxPoly` is very impactful. It facilitates checking concavity and affects
                // the contour area
                std::vector<cv::Point> poly;
                cv::approxPolyDP(contours[i], contours[i], 0.5, true);

                // verify the object is approximately frisbee sized
                double area = cv::contourArea(contours[i]);
                if (area > FRISBEE_MAX_AREA || area < FRISBEE_MIN_AREA)
                    continue;

                // verify the object is convex. This eliminates many random shapes
                // such as people
                if (!cv::isContourConvex(contours[i]))
                    continue;

                frisbeeContours.push_back(contours[i]);
            }
            finalContours.push_back(frisbeeContours);
        }
        return finalContours;
    }

    std::vector<cv::Mat> showContours(const std::vector<cv::Mat>& video, const std::vector<FrameContours>& contours)
    {
        assert(video.size() == contours.size());
        
        std::vector<cv::Mat> outVideo;
        for (size_t frameIndex = 0; frameIndex < video.size(); ++frameIndex)
        {
            cv::Mat imgWithContours = video[frameIndex].clone();
            FrameContours currFrameContours = contours[frameIndex];
            for( size_t i = 0; i< currFrameContours.size(); i++ )
            {
                cv::Scalar color = cv::Scalar(0, 0, 255);
                cv::drawContours( imgWithContours, currFrameContours, (int)i, color, -1, cv::LINE_8, cv::noArray(), 0 );
            }
            outVideo.push_back(imgWithContours);
        }
        return outVideo;
    }
}