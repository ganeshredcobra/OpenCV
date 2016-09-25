#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    /*Returns an identity matrix of the specified size and type.*/
    Mat E = Mat::eye(10, 10, CV_64F);
    cout << "E = " << endl << " " << E << endl << endl;
    // make a 4x4 diagonal matrix with 0.1's on the diagonal.
    Mat A = Mat::eye(4, 4, CV_32F)*0.1;
    cout << "A = " << endl << " " << A << endl << endl;

    /*Returns an array of all 1’s of the specified size and type.*/
    Mat O = Mat::ones(10, 10, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;
    // make 5x5 matrix filled with 3.
    A = Mat::ones(5, 5, CV_8U)*3;
    cout << "A = " << endl << " " << A << endl << endl;

    /*Returns a zero array of the specified size and type.*/
    Mat Z = Mat::zeros(10,10, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;

    return 0;
}
