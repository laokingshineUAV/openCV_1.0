#include <iostream>
#include <opencv2/core/core.hpp> 
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture(0);
	Mat edges;
	while (1)
	{
		Mat frame;
		char a;
		capture >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		blur(edges, edges, Size(3, 3));
		Canny(edges, edges, 0, 30, 3);
		imshow("ÊÓÆµÁ÷", edges);
		if(waitKey(30) >= 0) break;
	}

	return 0;
}