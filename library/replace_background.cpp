#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat replaceBackground(Mat frame, Mat videoFrame)
{
    Mat frame_bgra = Mat::zeros(3, 3, CV_8UC1);

    int b_lower = 0, b_higher = 40;
    int g_lower = 170, g_higher = 220;
    int r_lower = 100, r_higher = 150;

    if (!frame.empty() && !videoFrame.empty())
    {
        cvtColor(frame, frame_bgra, CV_BGR2BGRA);
        cvtColor(videoFrame, videoFrame, CV_BGR2BGRA);

        for (int x = 0; x < frame_bgra.rows; ++x)
        {
            for (int y = 0; y < frame_bgra.cols; ++y)
            {
                Vec4b &pixel = frame_bgra.at<cv::Vec4b>(x, y);
                if (videoFrame.rows > x && videoFrame.cols > y)
                {
                    Vec4b &pixel_image = videoFrame.at<cv::Vec4b>(x, y);
                    if (pixel[0] >= b_lower && pixel[0] <= b_higher && pixel[1] >= g_lower && pixel[1] <= g_higher && pixel[2] >= r_lower && pixel[2] <= r_higher)
                    {
                        pixel[0] = pixel_image[0];
                        pixel[1] = pixel_image[1];
                        pixel[2] = pixel_image[1];
                    }
                }
            }
        }
    }
    else if(!frame.empty())
    {
        return frame;
    }
    return frame_bgra;
}