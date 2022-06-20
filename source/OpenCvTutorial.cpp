#include "frisbeetracker/OpenCvTutorial.hpp"

#include <opencv2/opencv.hpp>

namespace OpenCvTutorial
{

    std::vector<cv::Mat> readVideo(const std::string& vidPath)
    {
        std::vector<cv::Mat> vidFrames;
        cv::VideoCapture video(vidPath); 
        // if not success, exit program
        if (video.isOpened() == false)  
        {
            std::cout << "Cannot open the video file" << std::endl;
            return vidFrames;
        }

        while (true)
        {
            cv::Mat frame;
            bool bSuccess = video.read(frame); // read a new frame from video 

            //Breaking the while loop at the end of the video
            if (bSuccess == false) 
            {
                break;
            }

            vidFrames.push_back(frame);
        }
        return vidFrames;
    }

    void showVideo(const std::vector<cv::Mat>& video)
    {
        for (const auto& i : video)
        {
            cv::imshow("Video Window", i);

            //wait for for 10 ms until any key is pressed.  
            //If the 'Esc' key is pressed, break the while loop.
            //If the any other key is pressed, continue the loop 
            //If any key is not pressed withing 10 ms, continue the loop
            if (cv::waitKey(20) == 27)
            {
                std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
                break;
            }
        }
    }


    void showImage(const std::string& imgPath)
    {
        cv::Mat image(600, 800, CV_8UC3, cv::Scalar(100, 250, 30)); 
        image = cv::imread( imgPath);
        if ( !image.data )
        {
            printf("No image data \n");
            std::cout << imgPath << std::endl;
            return;
        }
        cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
        cv::imshow("Display Image", image);
        cv::waitKey(0);
    }

    void showVideo(const std::string& vidPath)
    {
        cv::VideoCapture video(vidPath); 
        // if not success, exit program
        if (video.isOpened() == false)  
        {
            std::cout << "Cannot open the video file" << std::endl;
            return;
        }

        //Uncomment the following line if you want to start the video in the middle
        //video.set(CAP_PROP_POS_MSEC, 300);

        //get the frames rate of the video
        double fps = video.get(cv::CAP_PROP_FPS);

        std::cout << "Frames per seconds : " << fps << std::endl;

        std::string window_name = "My First Video";

        cv::namedWindow(window_name, cv::WINDOW_NORMAL); //create a window

        while (true)
        {
            cv::Mat frame;
            bool bSuccess = video.read(frame); // read a new frame from video 

            //Breaking the while loop at the end of the video
            if (bSuccess == false) 
            {
                std::cout << "Found the end of the video" << std::endl;
                break;
            }

            //show the frame in the created window
            cv::imshow(window_name, frame);

            //wait for for 10 ms until any key is pressed.  
            //If the 'Esc' key is pressed, break the while loop.
            //If the any other key is pressed, continue the loop 
            //If any key is not pressed withing 10 ms, continue the loop
            if (cv::waitKey(10) == 27)
            {
                std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
                break;
            }
        }
    }
}