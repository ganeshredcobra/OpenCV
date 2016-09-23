#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orig_img;

void Process_image(void)
{
    Rect rect1;

    rect1.x = 28;
    rect1.y = 27;
    rect1.width = 100;
    rect1.height = 100;

    rectangle( orig_img, rect1, Scalar( 0, 55, 255 ), +1, 4 );
}

int main(int, char* argv[])
{

    orig_img = imread("lena.jpg"); // Open and read the image
    if (orig_img.empty())
    {
        cout << "Error!!! Image cannot be loaded..." << endl;
        return -1;
    }
    while(true)
    {
        double t0 = (double)getTickCount();
        Process_image();
        double elapsed = ((double)getTickCount()-t0)/getTickFrequency();
        imshow("Image",orig_img);
        waitKey(30);
        cout<<"Elapased time is "<<elapsed<<" seconds"<<endl;
    }
    return 0;
}
