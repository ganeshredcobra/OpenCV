#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat frame,img1;

int main()
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    cap >> frame; // get a new frame from camera
    cvtColor( frame, img1, CV_BGR2GRAY );
    imshow("Original", img1);
// Original
// Create mask image
    Mat mask(img1.rows, img1.cols, CV_8UC1, Scalar(0,0,0));
    circle(mask, Point(img1.rows/2,img1.cols/2), 150, 255, -1);
    imshow("Mask",mask);
// perform AND
    Mat r;
    bitwise_and(img1,mask,r);
// fill outside with white
    const uchar white = 255;
    for(int i = 0; i < r.rows; i++)
        for(int j = 0; j < r.cols; j++)
            if (!mask.at<uchar>(i,j))
                r.at<uchar>(i,j)=white;
    imshow("Result",r);
    Mat New;
    cvtColor( r, New, CV_GRAY2BGR );
    imshow("Result1",New);
    waitKey(0);
    return 0;
}
