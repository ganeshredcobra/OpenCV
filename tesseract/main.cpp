#include <iostream>


#include "TesseractOCR.h"
using namespace std;

cv::Mat orig_img;
//cv::Mat gray;


int main()
{
    TesseractOCR iOCR;

    orig_img = imread("data.png"); // Open and read the image
    if (orig_img.empty())
    {
        cout << "Error!!! Image cannot be loaded..." << endl;
        return -1;
    }
    char *Text = iOCR.ReadOCR(orig_img);
    //char *Text = ReadOCR(orig_img);

    cout << "Text is :"<< Text << endl;
    cout << "Hello world!" << endl;
    return 0;
}
