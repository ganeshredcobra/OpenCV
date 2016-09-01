#include "opencv2/opencv.hpp"

#include <iostream>
#include <chrono>
#include <unistd.h>

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

    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;

    for(;;)
    {
        clock_t tic = clock();

        cap >> frame; // get a new frame from camera
        cropimage = frame;
        RotateMatrix = getRotationMatrix2D(Point2f(cropimage.cols/2, cropimage.rows/2), angle, 1.0);
        auto t0 = Time::now();
        warpAffine(cropimage, imgRotated, RotateMatrix, cropimage.size(), cv::INTER_LINEAR);
        auto t1 = Time::now();
        fsec fs = t1 - t0;
        ms d = std::chrono::duration_cast<ms>(fs);
        //std::cout << fs.count() << "s\n";
        std::cout << d.count() << "ms\n";
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
