Library provides a function named replaceBackground which takes two parameters of `Mat` type and returns an object of `Mat` type. Here is the prototype of the function:
	Mat replaceBackground(Mat frame, Mat videoFrame)
Mat Type:
	The object `Mat` is short for matrix and is found in opencv libraries. 
Parameters of the Function:
	To explain the parameters of the function first we need to understand what is a video stream. Basically a video stream is an array of images (in opencv they are referred as frames, I will be using frame instead of images from now on) changing at a high speed. We can get a frame (image) out of a stream at any point in time and that frame is stored in `Mat` data type, which our function takes. Background of the first frame will be replaced with the second frame passed to the function. And a frame with replaced background will be returned which can be displayed to the user or written to a file.
Here is a C++ function that calls the function and displays its result:
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
This example code uses Opencv library that is used for image processing.
