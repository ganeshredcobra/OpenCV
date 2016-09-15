#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

bool Run_FLAG = false;
static int Cnt = 0;
std::vector<cv::Point2f> pSrc,pDst;
Mat src;
Mat result1;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

        pSrc[Cnt] = CvPoint( x, y );
        circle(src, pSrc[Cnt], 5, cv::Scalar(0,255,0),-1);
        if(Cnt == 3)
        {
            Cnt = 0;
            Run_FLAG = true;
        }
        else
            Cnt++;

    }

}

int main()
{
    namedWindow("SRC_Image", WINDOW_AUTOSIZE );
    namedWindow("Dst_Image", WINDOW_AUTOSIZE );

    src = imread("Input.png");
    int h = src.cols;
    int w = src.rows;
    int channesl = src.channels();

    setMouseCallback("SRC_Image", CallBackFunc, NULL);
    /*
    pSrc.push_back(CvPoint( 100, 60 ));
    pSrc.push_back(CvPoint( 260, 60 ));
    pSrc.push_back(CvPoint( 100, 300));
    pSrc.push_back(CvPoint( 260, 300 ));

    pDst.push_back(CvPoint( 20, 60 ));
    pDst.push_back(CvPoint( 340, 60 ));
    pDst.push_back(CvPoint(100, 300 ));
    pDst.push_back(CvPoint( 260, 300 ));

    */
    pSrc.push_back(CvPoint( 63, 64 ));
    pSrc.push_back(CvPoint( 306, 60 ));
    pSrc.push_back(CvPoint( 226, 303));
    pSrc.push_back(CvPoint( 145, 304 ));

    pDst.push_back(CvPoint( 36, 0 ));
    pDst.push_back(CvPoint( 327, 0 ));
    pDst.push_back(CvPoint(363, 363 ));
    pDst.push_back(CvPoint( 0, 363 ));

    Run_FLAG = true;

    while(true)
    {
        if(Run_FLAG)
        {
            cv::Mat H = findHomography(pSrc, pDst, CV_LMEDS);
            cout << "Homography is " << H << endl;
            for(unsigned int i=0; i<pSrc.size(); ++i)
            {
                cv::circle(src, pSrc[i], 5, cv::Scalar(255,0,0),-1);
            }
            src.copyTo(result1);
            cv::warpPerspective(src, result1, H, cv::Size(src.cols, src.rows));

            Run_FLAG = false;
        }
        cv::imshow("SRC_Image",src);
        cv::imshow("Dst_Image",result1);
        cv::waitKey(30);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
