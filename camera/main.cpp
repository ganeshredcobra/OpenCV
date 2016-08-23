#include "opencv2/core/ocl.hpp"
#include "opencv2/opencv.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**)
{
    ocl::setUseOpenCL(true);
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    UMat edges;
    Mat frame;
    namedWindow("edges",1);
    for(;;)
    {
        clock_t tic = clock();

        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
       // GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
        clock_t toc = clock();
		cout << "    Process FPS: " << CLOCKS_PER_SEC / (toc - tic) << endl;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
