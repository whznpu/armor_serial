#ifndef SERIAL_H
#define SERIAL_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include<boost/lexical_cast.hpp>
#include<opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include<string>



using namespace cv;
using namespace std;
using namespace boost::asio;


void send_center(Point2f point);//发送坐标

#endif // !1