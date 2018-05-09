#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("Ô­Ê¼Í¼Ïñ", srcImage);

	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());
	// ½«Í¼Ïñ×ª»»Îª»Ò¶ÈÍ¼Ïñ
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	// ½µÔë
	blur(grayImage, edge, Size(3, 3));

	Canny(edge, edge, 3, 9, 3);

	imshow("±ßÔµ¼ì²â", edge);
	
	waitKey(0);
	return 0;

}