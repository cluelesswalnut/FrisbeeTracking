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

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;
    void test(const std::string& vidPath)
    {

        cv::VideoCapture cap(vidPath); 

        if ( !cap.isOpened() )  // if not success, exit program
        {
                cout << "Cannot open the web cam" << endl;
                return;
        }

        namedWindow("Control", WINDOW_AUTOSIZE); //create a window called "Control"

        // frisbee
        int iLowH = 0;
        int iHighH = 179;

        int iLowS = 0; 
        int iHighS = 255;

        int iLowV = 175;
        int iHighV = 255;

        // // kinda green
        // int iLowH = 33;
        // int iHighH = 75;

        // int iLowS = 0; 
        // int iHighS = 255;

        // int iLowV = 0;
        // int iHighV = 255;

        //Create trackbars in "Control" window
        createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
        createTrackbar("HighH", "Control", &iHighH, 179);

        createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
        createTrackbar("HighS", "Control", &iHighS, 255);

        createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
        createTrackbar("HighV", "Control", &iHighV, 255);

        while (true)
        {
            Mat imgOriginal;
            // cap.set(CAP_PROP_POS_MSEC, 25000);

            bool bSuccess = cap.read(imgOriginal); // read a new frame from video

                if (!bSuccess) //if not success, break loop
            {
                    cout << "Cannot read a frame from video stream" << endl;
                    cap.set(CAP_PROP_POS_MSEC, 0);
                    continue;
                    // break;
            }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
            
        // //morphological opening (remove small objects from the foreground)
        // erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        // dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

        // //morphological closing (fill small holes in the foreground)
        // dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
        // erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        imshow("Thresholded Image", imgThresholded); //show the thresholded image
        imshow("Original", imgOriginal); //show the original image

            if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
            {
                cout << "esc key is pressed by user" << endl;
                break; 
            }
        }
    }
}