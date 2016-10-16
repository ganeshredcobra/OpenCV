#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orig_img;
Mat Hori_img;
Mat vert_img;
Mat Both_img;

int main(int, char* argv[])
{

    orig_img = imread("lena.jpg"); // Open and read the image
    if (orig_img.empty())
    {
        cout << "Error!!! Image cannot be loaded..." << endl;
        return -1;
    }

    cv::flip(orig_img,vert_img,0);
    cv::flip(orig_img,Hori_img,1);
    cv::flip(orig_img,Both_img,-1);

    imshow("Original Image",orig_img);
    imshow("vert_img",vert_img);
    imshow("Hori_img",Hori_img);
    imshow("Both_img",Both_img);

    waitKey(0);
    return 0;
}
