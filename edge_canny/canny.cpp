#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("ԭʼͼ��", srcImage);

	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());
	// ��ͼ��ת��Ϊ�Ҷ�ͼ��
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	// ����
	blur(grayImage, edge, Size(3, 3));

	Canny(edge, edge, 3, 9, 3);

	imshow("��Ե���", edge);
	
	waitKey(0);
	return 0;

}