#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
#define WINDOW_NAME "线性混合示例"

const int g_nMAXAlphaValue = 100; // Alpha 最大值
int g_nAlphaValueSlider; // 当前滑动条的值
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat srcimage_1;
Mat srcimage_2;
Mat dstimage;

// 相应滑动条的回掉函数
void on_Tracker(int, void*)
{
	// 求出当前alpha值相对于最大值的比例
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMAXAlphaValue;
	g_dBetaValue = (1 - g_dAlphaValue);
	addWeighted(srcimage_1, g_dAlphaValue, srcimage_2, g_dBetaValue, 0.0, dstimage);

	imshow(WINDOW_NAME, dstimage);
}
int main(int argc, int **argv)
{
	// 加载图像
	srcimage_1 = imread("1.jpg");
	srcimage_2 = imread("1.jpg");
	if (!srcimage_1.data) { printf("读取第一幅图片时有误，请确定指定目录下是否有相应图片存在"); return -1; };
	if (!srcimage_2.data) { printf("读取第二幅图片时有误，请确定制定目录下是否有相应图片存在"); return -1; };
	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);

	// 在窗体中创建一个滑动条空间
	char TrackBarName[50];
	sprintf(TrackBarName, "透明值 %d", g_nAlphaValueSlider);

	createTrackbar(TrackBarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMAXAlphaValue, on_Tracker);
	on_Tracker(g_nAlphaValueSlider, 0);
	waitKey(0);
	return 0;
}