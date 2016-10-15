#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orig_img;
Mat res_img;

int main(int, char* argv[])
{

    orig_img = imread("lena.jpg"); // Open and read the image
    if (orig_img.empty())
    {
        cout << "Error!!! Image cannot be loaded..." << endl;
        return -1;
    }

    imshow("Original Image",orig_img);
    cv::resize(orig_img, res_img, Size(), 0.5, 0.5);
    imshow("Result Image",res_img);
    waitKey(0);
    return 0;
}
