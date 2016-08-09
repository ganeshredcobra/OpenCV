#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int view_x, view_y;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          //cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          //cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          //cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE )
     {
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
          view_x = x;
          view_y = y;

     }
}

bool Check_Boundary(Point2f rect_points[])
{

}


int main(int argc, char *argv[])
{
    Point2f rect_points[4];
    //int view_x = 25;
    //int view_y = 25;
    int view_width = 300;
    int view_height= 200;
    int aPillarAngle = 0;

    Mat img = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);;
    if(img.empty())
       return -1;
    namedWindow( "lena", CV_WINDOW_AUTOSIZE );
    setMouseCallback("lena", CallBackFunc, NULL);
    while(true)
    {

        RotatedRect rRect = RotatedRect(Point2f(view_x, view_y), Size(/*325*/view_width, view_height), aPillarAngle);
        rRect.points(rect_points);
        cout<<"Rect Points  is:"<<rect_points[0]<<" "<<rect_points[1]<<" "<<rect_points[2]<<" "<<rect_points[3]<<endl;
        for (int j = 0; j < 4; j++)
        {
            line(img, rect_points[j], rect_points[(j + 1) % 4], (255, 0, 0), 1, 8);
        }
        imshow("lena", img);
        waitKey(30);
    }
    cout<<"Size is"<<img.size();
    //waitKey(0);
    return 0;
}



