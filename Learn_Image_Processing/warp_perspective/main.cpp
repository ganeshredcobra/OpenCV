#include "opencv2/opencv.hpp"
using namespace cv;
int main( int argc, char** argv )
{
// Read the source file
Mat src;
src = imread("../IMG/lena.jpg");

Mat dst;
Point2f src_verts[4];
src_verts[2] = Point(195,140);
src_verts[3] = Point(410,120);
src_verts[1] = Point(220,750);
src_verts[0] = Point(400,750);
Point2f dst_verts[4];
dst_verts[2] = Point(160,100);
dst_verts[3] = Point(530,120);
dst_verts[1] = Point(220,750);
dst_verts[0] = Point(400,750);

// Obtain and Apply the perspective transformation
Mat M = getPerspectiveTransform(src_verts,dst_verts);
warpPerspective(src,dst,M,src.size());
// Show the results
namedWindow( " ORIGINAL ", WINDOW_AUTOSIZE );
imshow( " ORIGINAL ", src );
namedWindow( " PERSPECTIVE ", WINDOW_AUTOSIZE );
imshow( " PERSPECTIVE ", dst );
waitKey();
return 0;
}
