#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**)
{
    ocl::setUseOpenCL(true);
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat RotateMatrix;
    UMat frame;
    UMat cropimage,imgRotated;
    int angle = 0;
    for(;;)
    {
        clock_t tic = clock();

        cap >> cropimage; // get a new frame from camera
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
