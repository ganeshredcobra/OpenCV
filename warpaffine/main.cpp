#include "opencv2/opencv.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat RotateMatrix;
    Mat frame;
    Mat cropimage,imgRotated;
    int angle = 0;
    for(;;)
    {
        clock_t tic = clock();

        cap >> frame; // get a new frame from camera
        cropimage = frame;
        RotateMatrix = getRotationMatrix2D(Point2f(cropimage.cols/2, cropimage.rows/2), angle, 1.0);
        warpAffine(cropimage, imgRotated, RotateMatrix, cropimage.size(), cv::INTER_LINEAR);
        imshow("Image Rotated",imgRotated);
        angle++;
        if(angle == 360)
            angle = 0;
        if(waitKey(30) >= 0) break;
        clock_t toc = clock();
		//cout << "    Process FPS: " << CLOCKS_PER_SEC / (toc - tic) << endl;
    }
    return 0;
}
