#include <utility>
#include <thread>
#include <chrono>
#include <X11/Xlib.h>
#include <functional>
#include <atomic>
#include "armorDetect/armorDetect.h"
#include "serial/serial.h"


int main()
{
    VideoCapture cap0("1.mp4");
    Mat frame0;
    cap0 >> frame0;
    double fps = cap0.get(CV_CAP_PROP_FPS); 
    namedWindow("Raw");
    while(1)
    {
        if (cap0.read(frame0)){

                std::thread t1(armor,frame0);
                
                std::thread t2(send_center,center_point);

                t1.detach();

                t2.detach();
                 char c=waitKey(1000/fps);
                  if (c == 27) {
            break;}
        }
        else
        {
            break;
        }
        imshow("Raw", frame0);
          
            
    }

    
    cap0.release();
    
    
    return 0;
}