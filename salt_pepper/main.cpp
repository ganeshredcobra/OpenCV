#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;

void salt(cv::Mat &image, int n)
{
    for (int k=0; k<n; k++)
    {
        // rand() is the MFC random number generator
        // try qrand() with Qt
        int i= rand()%image.cols;
        int j= rand()%image.rows;
        if (image.channels() == 1)   // gray-level image
        {
            image.at<uchar>(j,i)= 255;
        }
        else if (image.channels() == 3)     // color image
        {
            image.at<cv::Vec3b>(j,i)[0]= 255;
            image.at<cv::Vec3b>(j,i)[1]= 255;
            image.at<cv::Vec3b>(j,i)[2]= 255;
        }
    }
}

int main()
{
    // open the image
    cv::Mat image= cv::imread("lena.jpg");
    // call function to add noise
    salt(image,3000);
    // display image
    cv::namedWindow("Image");
    cv::imshow("Image",image);
    cv::waitKey(0);
}
