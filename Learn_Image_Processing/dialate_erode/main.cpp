#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
// Read the source file
    Mat src;
    src = imread("coins.jpg"); // Open and read the image
// Apply the filters
    Mat dst, dst2, dst3;
    inRange(src, Scalar(0, 0, 100), Scalar(40, 30, 255), dst);
    Mat element = getStructuringElement(MORPH_ELLIPSE,Size(15,15));
    dilate(dst, dst2, element);
    erode(dst2, dst3, element);
// Show the results
    namedWindow( " ORIGINAL ", WINDOW_AUTOSIZE );
    imshow( " ORIGINAL ", src );
    namedWindow( " SEGMENTED ", WINDOW_AUTOSIZE );
    imshow( " SEGMENTED ", dst );
    namedWindow( " DILATION ", WINDOW_AUTOSIZE );
    imshow( " DILATION ", dst2 );
    namedWindow( " EROSION ", WINDOW_AUTOSIZE );
    imshow( " EROSION ", dst3 );
    waitKey();
    return 0;
}
