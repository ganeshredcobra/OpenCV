#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main( int argc, char** argv )
{
    Mat src = imread("lena.jpg",CV_LOAD_IMAGE_COLOR); //load  image

    Mat bgr[3];   //destination array
    split(src,bgr);//split source

    //Note: OpenCV uses BGR color order
    imshow("blue.png",bgr[0]); //blue channel
    imshow("green.png",bgr[1]); //green channel
    imshow("red.png",bgr[2]); //red channel

 /// Wait until user press some key
 waitKey();
 return 0;
}
