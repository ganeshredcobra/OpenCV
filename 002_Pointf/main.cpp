#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"


using namespace cv;
using namespace std;



Point2f rect_points[4];

Point2f FindValue(Point2f rect_points[4],char Level){

	int HighestX,TempX;
	int LowestY,TempY;
	Point2f HighestPoint;
	Point2f LowestPoint;

	HighestPoint.x = rect_points[0].x;
	HighestPoint.y = rect_points[0].y;
	LowestPoint.x = rect_points[3].x;
	LowestPoint.y = rect_points[3].y;

	for (int i = 0; i < 4; i++)
	{
		if(Level == 'h')
		{
			if(HighestPoint.x > rect_points[i+1].x)
			{
				HighestPoint.x = rect_points[i].x;
			}
			else
			{
				HighestPoint.x = rect_points[i+1].x;
			}
			if(HighestPoint.y > rect_points[i+1].y)
			{
				HighestPoint.y = rect_points[i].y;
			}
			else
			{
				HighestPoint.y = rect_points[i+1].y;
			}
		}
		else if(Level == 'l')
		{

			if(rect_points[i].x < LowestPoint.x )
			{
				LowestPoint.x = rect_points[i].x;
			}
			else
			{
				LowestPoint.x = LowestPoint.x;
			}
			if(rect_points[i].y < LowestPoint.y )
			{
				LowestPoint.y = rect_points[i].y;
			}
			else
			{
				LowestPoint.y = LowestPoint.y;
			}

		}
	}
	if(Level == 'h')
		return HighestPoint;
	else
		return LowestPoint;
}


int main(int argc, char *argv[])
{
    Point2f a(1.3, 2.3), b(0.3, 0.3), c(5.3, 6.3), d(7.3, 8.3) ;
    Point2f Result,Result1;
    rect_points[0] = a;
    rect_points[1] = b;
    rect_points[2] = c;
    rect_points[3] = d;
    //cout<<"Points"<<rect_points[0];
    Result = FindValue(rect_points, 'h');
    cout<<"Result is "<<Result<<endl;
    Result1 = FindValue(rect_points, 'l');
    cout<<"Result is "<<Result1<<endl;
    return 0;
}



