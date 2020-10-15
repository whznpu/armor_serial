
#include "serial.h"
#include <string>

void send_center(Point2f point)
{
    io_service iosev;
    //python virtual com
        //cout<< "start to set port No" << endl;

        serial_port sp(iosev,"/dev/pts/3");

       //cout << "port created "<< endl;

         //设置参数

       sp.set_option(serial_port::baud_rate(115200));

       sp.set_option(serial_port::flow_control(serial_port::flow_control::none));

       sp.set_option(serial_port::parity(serial_port::parity::none));

       sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));

       sp.set_option(serial_port::character_size(8));

         //cout<< "port parameter setup" << endl;

       // 向串口写数据
       
       string x = boost::lexical_cast <string> (point.x);
       string y=boost::lexical_cast<string> (point.y);
       string place=x+" "+y;
       //cout<<point.x<<" "<<point.y<<endl;
       //cout<<x<<"   "<<y<<endl;

       write(sp, buffer(place, place.size()));
}