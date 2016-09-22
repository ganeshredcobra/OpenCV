#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
// Callback functions declarations
void cbMouse(int event, int x, int y, int flags, void*);

// Global definitions and variables
Mat orig_img, tmp_img;
const char main_win[]="main_win";
Rect rect1;

int main(int, char* argv[])
{

    orig_img = imread("lena.jpg"); // Open and read the image
    if (orig_img.empty())
    {
        cout << "Error!!! Image cannot be loaded..." << endl;
        return -1;
    }
    namedWindow(main_win); // Creates main window
    // Creates a font for adding text to the image
    QtFont font = fontQt("Arial", 20, Scalar(255,0,0,0),
                         QT_FONT_BLACK, QT_STYLE_NORMAL);
    // Creation of CallBack functions
    setMouseCallback(main_win, cbMouse, NULL);

    rect1.x = 28;
    rect1.y = 27;
    rect1.width = 100;
    rect1.height = 100;

    rectangle( orig_img, rect1, Scalar( 0, 55, 255 ), +1, 4 );


    imshow(main_win, orig_img); // Shows original image
    cout << "Press any key to exit..." << endl;
    waitKey(); // Infinite loop with handle for events
    return 0;
}

void cbMouse(int event, int x, int y, int flags, void*)
{
    cv::Point P(x,y);
    if  ( event == EVENT_LBUTTONDOWN )
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    if(P.inside(rect1))
        cout<<"Inside Rectangle"<<endl;
}

