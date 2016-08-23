#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int view_x = 200;
int view_y =250;
int Point_x, Point_y;
int Screen_width = 400;
int Screen_height= 400;

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
          //cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
          Point_x = x;
          Point_y = y;
     }
}

bool Check_Boundary(Point2f rect_points[])
{
    bool Xval = false;
    bool Yval = false;

    if((rect_points[0].x >0 && rect_points[1].x > 0 && rect_points[2].x > 0 && rect_points[3].x > 0) && (rect_points[0].x < Screen_width && rect_points[1].x < Screen_width && rect_points[2].x < Screen_width && rect_points[3].x < Screen_width))
    {
        Xval = true;
    }
    else
    {
       //cout<<"Rect Points  is:"<<rect_points[0]<<" "<<rect_points[1]<<" "<<rect_points[2]<<" "<<rect_points[3]<<endl;
       Xval = false;
    }
    if((rect_points[0].y >0 && rect_points[1].y > 0 && rect_points[2].y > 0 && rect_points[3].y > 0) && (rect_points[0].y < Screen_height && rect_points[1].y < Screen_height && rect_points[2].y < Screen_height && rect_points[3].y < Screen_height))
    {

        Yval = true;
    }
    else
    {
       //cout<<"Rect Points  is:"<<rect_points[0]<<" "<<rect_points[1]<<" "<<rect_points[2]<<" "<<rect_points[3]<<endl;
       Yval = false;
    }
    if(Xval == true && Yval == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main(int argc, char *argv[])
{
    Point2f rect_points[4];
    Point2f lastrect_points[4];
    int last_view_x,last_view_y;
    int view_width = 200;
    int view_height= 100;
    int aPillarAngle = 0;
    bool CB;
    bool Check1 = false;
    bool Check2 = false;
    bool Check3 = false;

    Mat img = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
    Mat dimg = imread("draw.jpg", CV_LOAD_IMAGE_COLOR);;
    if(img.empty())
       return -1;
    namedWindow( "lena", CV_WINDOW_AUTOSIZE );
    namedWindow( "draw", CV_WINDOW_AUTOSIZE );
    setMouseCallback("draw", CallBackFunc, NULL);
    imshow("draw", dimg);
    while(true)
    {
        img = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
        if(!Check1)
        {
            view_x = Point_x;
            view_y = Point_y;
        }
        RotatedRect rRect = RotatedRect(Point2f(view_x, view_y), Size(/*325*/view_width, view_height), aPillarAngle);
        rRect.points(rect_points);
        CB=Check_Boundary(rect_points);
        //cout<<CB<<endl;
        if(CB)
        {
            //cout<<"Rect Points  is:"<<rect_points[0]<<" "<<rect_points[1]<<" "<<rect_points[2]<<" "<<rect_points[3]<<endl;
            if(Check1 == true || Check2 == true || Check3 == true)
            {
                Check1 = false;
                Check2 = false;
                Check3 = false;
            }
            last_view_x = view_x;
            last_view_y = view_y;
            memcpy(lastrect_points, rect_points, sizeof(lastrect_points));
            for (int j = 0; j < 4; j++)
            {
                line(img, rect_points[j], rect_points[(j + 1) % 4], (255, 0, 0), 1, 8);
            }
        }
        else
        {
            //cout<<"Rect Points  is:"<<rect_points[0]<<" "<<rect_points[1]<<" "<<rect_points[2]<<" "<<rect_points[3]<<endl;
            //cout<<"Last Rect Points  is:"<<lastrect_points[0]<<" "<<lastrect_points[1]<<" "<<lastrect_points[2]<<" "<<lastrect_points[3]<<endl;
            view_x = last_view_x;
            view_y = last_view_y;
            for (int j = 0; j < 4; j++)
            {
                line(img, lastrect_points[j], lastrect_points[(j + 1) % 4], (255, 0, 0), 1, 8);
            }
            if((Point_x > view_x+20) && (view_x+20 < Screen_width))
            {
                view_x = view_x+20;
            }
            else if((Point_x > view_x+10) && (view_x+10 < Screen_width))
            {
                view_x = view_x+10;
            }
            else if((Point_x > view_x) && (view_x < Screen_width))
            {
                view_x++;
            }
            else if((Point_x < view_x-20) && (view_x - 20 > 0))
            {
                view_x = view_x-20;
            }
            else if((Point_x < view_x-10) && (view_x-10 > 0))
            {
                view_x = view_x-10;
            }
            else if((Point_x < view_x) && (view_x > 0))
            {
                view_x = view_x--;
            }

            /*******************************************/

            if((Point_y > view_y+20) && (view_y+20 < Screen_height))
            {
                view_y = view_y+20;
            }
            else if((Point_y > view_y+10) && (view_y+10 < Screen_height))
            {
                view_y = view_y+10;
            }
            else if((Point_y > view_y) && (view_y < Screen_height))
            {
                view_y++;
            }
            else if((Point_y < view_y-20) && (view_y - 20 > 0))
            {
                view_y = view_y-20;
            }
            else if((Point_y < view_y-10) && (view_y-10 > 0))
            {
                view_y = view_y-10;
            }
            else if((Point_y < view_y) && (view_y > 0))
            {
                view_y = view_y--;
            }


            cout<<"view_x is: "<<view_x<<endl;
        }
        imshow("lena", img);
        waitKey(30);
    }
    cout<<"Size is"<<img.size();
    //waitKey(0);
    return 0;
}



