#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/*
 when the destination matrix and the source matrix have the same type and size,
copyTo will not change the address of the destination matrix,
while clone will always allocate a new address for the destination matrix.
*/

int main()
{
    Mat mat1 = Mat::ones(1, 5, CV_32F);
    Mat mat2 = mat1;
    Mat mat3 = Mat::zeros(1, 5, CV_32F);
    mat3.copyTo(mat1);
    cout << "Output of copyTo" << endl;
    cout << mat1 << endl;
    cout << mat2 << endl;

    mat1 = Mat::ones(1, 5, CV_32F);
    mat2 = mat1;
    mat3 = Mat::zeros(1, 5, CV_32F);
    mat1 = mat3.clone();
    cout << "Output of clone" << endl;
    cout << mat1 << endl;
    cout << mat2 << endl;

    return 0;
}
