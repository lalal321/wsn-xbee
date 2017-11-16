#include <iostream>
#include <unistd.h>
#include "lib/Socket/client.hpp"
#include "wsn-xbee.h"

int main(){
	TCPClient *c = new TCPClient();
	c->conn("localhost",7000);
	float x=0, y=0, z=0;
		
    std::cout.setf(std::ios::unitbuf);

	std::cout << "Initialized!\n";

	WSNXbee *w = new WSNXbee("/dev/serial0", 57600);

	for(;;){
		w->send(1, "Estou enviando para 1!!!");
		usleep(1000000);
		std::string data;
		w->receive(1, data);
		if (!data.empty()) {
            std::cout << data << "\n";
        }
		usleep(1000000);

		w->send(2, "Estou enviando para 2!!!");
		usleep(1000000);
		w->receive(2, data);
		if (!data.empty()) {
            std::cout << data << "\n";
        }
		usleep(1000000);
		
		w->send(4, "Para todos!!!");
		usleep(1000000);
		w->receive(4, data);
		if (!data.empty()) {
            std::cout << data << "\n";
        }
		usleep(1000000);
		
		std::ostringstream sx;
		std::ostringstream sy;
		std::ostringstream sz;
		sx << x;
		sy << y;
		sz << z;
		//c->sendData("{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}");
		std::cout << "{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}" << std::endl;

	}
	return 0;

}
