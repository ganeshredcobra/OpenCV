#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Point cent(0,0);
Point perim(0,0);

int sec_angle = 0;
Rect rect1;

int main( int argc, char** argv )
{
/// Read image given by user
    //Mat image = imread("lena.jpg"); // Open and read the image
    /// Create Windows
    namedWindow("Original Image", 1);
    //namedWindow("New Image", 1);
    //int rad = image.cols/2;



    while(true)
    {
        Mat image = imread("lena.jpg"); // Open and read the image

        cent.x = image.cols/2;
        cent.y = image.rows/2;

        rect1.x = 200;
        rect1.y = 100;
        rect1.width = 100;
        rect1.height = 200;

        int rad = rect1.width/2;
        cent.x = rect1.x+(rect1.width/2);
        cent.y = rect1.y+(rect1.height/2);
        rectangle( image, rect1, Scalar( 255, 0, 0 ), 3, 4 );
        //perim.x =  (int)round(cent.x + (rad-5) * cos(sec_angle * CV_PI / 180.0));
        //perim.y =  (int)round(cent.y + (rad-5) * sin(sec_angle * CV_PI / 180.0));

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
