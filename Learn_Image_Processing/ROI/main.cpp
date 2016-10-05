#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orig_img;

int main(int, char* argv[])
{

    orig_img = imread("lena.jpg"); // Open and read the image
    if (orig_img.empty())
    {
        cout << "Error!!! Image cannot be loaded..." << endl;
        return -1;
    }
    Rect roi(20,20,50,50);
    rectangle(orig_img,roi,Scalar( 100, 155, 25 ));
    Mat NewImg = orig_img(roi).clone();
    imshow("Original",orig_img);
    imshow("ROI",NewImg);
    waitKey(0);
    return 0;
}
