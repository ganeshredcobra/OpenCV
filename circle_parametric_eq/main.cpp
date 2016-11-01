#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Point cent(320,320);
Point perim(320,0);

int sec_angle = 0;

int main( int argc, char** argv )
{
/// Read image given by user
    Mat image = imread("lena.jpg"); // Open and read the image
    Mat new_image = Mat::zeros( image.size(), image.type() );
    /// Create Windows
    namedWindow("Original Image", 1);
    //namedWindow("New Image", 1);
    int rad = image.cols/2;
    cent.x = image.cols/2;
    cent.y = image.rows/2;

    while(true)
    {

        perim.x =  (int)round(cent.x + (rad-5) * cos(sec_angle * CV_PI / 180.0));
        perim.y =  (int)round(cent.y + (rad-5) * sin(sec_angle * CV_PI / 180.0));

        sec_angle++;
        circle(image,perim,1,Scalar(0,255,0,0),5,CV_AA,0);
        /// Show stuff
        imshow("Original Image", image);
        //imshow("New Image", new_image);
        /// Wait until user press some key
        waitKey(30);
    }

    return 0;
}
