#ifndef ARMORDETECT_H
#define ARMORDETECT_H
#include<opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include<vector>
#include<iostream>
#define T_ANGLE_THRE 10;
#define T_SIZE_THRE 5;
using namespace std;
using namespace cv;

extern Point2f center_point;
void brightAdjust(Mat src, Mat dst, double dContrast, double dBright); //亮度调节函数
void getDiffImage(Mat src1, Mat src2, Mat dst, int nThre); //二值化
vector<RotatedRect> armorDetect(vector<RotatedRect> vEllipse,Mat src); //检测装甲
void drawBox(RotatedRect box, Mat img); //标记装甲
void armor(Mat frame);//检测



#endif // !1