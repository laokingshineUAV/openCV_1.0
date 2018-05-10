#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
#define WINDOW_NAME "���Ի��ʾ��"

const int g_nMAXAlphaValue = 100; // Alpha ���ֵ
int g_nAlphaValueSlider; // ��ǰ��������ֵ
double g_dAlphaValue;
double g_dBetaValue;

//�����洢ͼ��ı���
Mat srcimage_1;
Mat srcimage_2;
Mat dstimage;

// ��Ӧ�������Ļص�����
void on_Tracker(int, void*)
{
	// �����ǰalphaֵ��������ֵ�ı���
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMAXAlphaValue;
	g_dBetaValue = (1 - g_dAlphaValue);
	addWeighted(srcimage_1, g_dAlphaValue, srcimage_2, g_dBetaValue, 0.0, dstimage);

	imshow(WINDOW_NAME, dstimage);
}
int main(int argc, int **argv)
{
	// ����ͼ��
	srcimage_1 = imread("1.jpg");
	srcimage_2 = imread("1.jpg");
	if (!srcimage_1.data) { printf("��ȡ��һ��ͼƬʱ������ȷ��ָ��Ŀ¼���Ƿ�����ӦͼƬ����"); return -1; };
	if (!srcimage_2.data) { printf("��ȡ�ڶ���ͼƬʱ������ȷ���ƶ�Ŀ¼���Ƿ�����ӦͼƬ����"); return -1; };
	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);

	// �ڴ����д���һ���������ռ�
	char TrackBarName[50];
	sprintf(TrackBarName, "͸��ֵ %d", g_nAlphaValueSlider);

	createTrackbar(TrackBarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMAXAlphaValue, on_Tracker);
	on_Tracker(g_nAlphaValueSlider, 0);
	waitKey(0);
	return 0;
}