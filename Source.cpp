#include <iostream>
#include <opencv2/opencv.hpp>
#include "replaceBackground.h"
using namespace std;
using namespace cv;

void printScreenPixels(Mat frame)
{
    int a1 = 0, b1 = 0, c1 = 0, a2 = 255, b2 = 255, c2 = 255;
    cvtColor(frame, frame, CV_BGR2BGRA);
    for (int x = 0; x < 5; ++x)
    {
        for (int y = 0; y < 5; ++y)
        {
            Vec4b &pixel_image = frame.at<cv::Vec4b>(x, y);
            if (pixel_image[0] > a1)
                a1 = pixel_image[0];

            if (pixel_image[0] < a2)
                a2 = pixel_image[0];

            if (pixel_image[1] > b1)
                b1 = pixel_image[1];

            if (pixel_image[1] < b2)
                b2 = pixel_image[1];

            if (pixel_image[2] > c1)
                c1 = pixel_image[2];

            if (pixel_image[2] < c2)
                c2 = pixel_image[2];
        }
    }
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    while (cv::waitKey(15) != 'q')
    {
    }
}

int main()
{
    string filename = "The.mkv";
    VideoCapture cam(0);
    VideoCapture video(filename);
    Mat frame, video_frame, result;

    while (cv::waitKey(15) != 'q')
    {
        cam >> frame;
        video >> video_frame;
        result = replaceVideo(frame, video_frame);
        imshow("video", result);
    }

    cam.release();
    video.release();
    return 0;
}