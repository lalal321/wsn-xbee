#include <iostream>
#include <unistd.h>
#include "wsn-xbee.h"

using namespace std;

int main(){
	
	cout << "Initialized!" << endl;
	
	WSNXbee *w = new WSNXbee("/dev/serial0", 57600);
	
	w->send(2, "This is a test!!!");
	
	cout << w->receive(2);
	
	//cout << w->receiveForAll();
	//w->sendForAll("Observer");

	return 0;
	
}
