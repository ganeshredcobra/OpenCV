#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    Mat src = imread("lena.jpg",CV_LOAD_IMAGE_COLOR); //load  image

   namedWindow("src",1);
   //imshow("src",src);

    // Split the image into different channels
    vector<Mat> rgbChannels(3);
    split(src, rgbChannels);

    // Show individual channels
    Mat g, fin_img;
    g = Mat::zeros(Size(src.cols, src.rows), CV_8UC1);

    // Showing Red Channel
    // G and B channels are kept as zero matrix for visual perception
    {
    vector<Mat> channels;
    channels.push_back(g);
    channels.push_back(g);
    channels.push_back(rgbChannels[2]);

    /// Merge the three channels
    merge(channels, fin_img);
    namedWindow("R",1);imshow("R", fin_img);
    }

    // Showing Green Channel
    {
    vector<Mat> channels;
    channels.push_back(g);
    channels.push_back(rgbChannels[1]);
    channels.push_back(g);
    merge(channels, fin_img);
    namedWindow("G",1);imshow("G", fin_img);
    }

    // Showing Blue Channel
    {
    vector<Mat> channels;
    channels.push_back(rgbChannels[0]);
    channels.push_back(g);
    channels.push_back(g);
    merge(channels, fin_img);
    namedWindow("B",1);imshow("B", fin_img);
    }

    waitKey(0);
    return 0;
}
