#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Point p_min, p_max;
    double m, M;

    // make a 4x4 diagonal matrix with 0.1's on the diagonal.
    Mat A = Mat::eye(4, 4, CV_32F)*10;
    A.at<float>(0,0) = 3;
    A.at<float>(0,3) = 31;

    cout << "A = " << endl << " " << A << endl << endl;

    cv::minMaxLoc(A, &m, &M, &p_min, &p_max,cv::Mat());
    cout << "min: " << m << " at " << p_min << endl;
    cout << "max: " << M << " at " << p_max << endl;

    return 0;
}
