#include <iostream>
#include <unistd.h>
#include "wsn-xbee.h"

using namespace std;

int main(){
	
	
	WSNXbee *w = new WSNXbee("/dev/serial0", 57600);
	
	w->send(2, "Observer");
	
	cout << w->receive(2);
	
	//cout << w->receive(2);

	return 0;
	
}
