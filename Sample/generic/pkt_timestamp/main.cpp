#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xbee.h>
#include <string>
#include <sstream>

int main() {
		
	struct xbee *xbee;
	struct xbee_con *con;
	struct xbee_pkt *pkt;
	struct xbee_conAddress address;
	
    xbee_setup(&xbee, "xbeeZB", "/dev/serial0", 57600);
    
	memset(&address, 0, sizeof(address));
	address.addr64_enabled = 1;
	address.addr64[0] = 0x00;
	address.addr64[1] = 0x13;
	address.addr64[2] = 0xA2;
	address.addr64[3] = 0x00;
	address.addr64[4] = 0x40;
	address.addr64[5] = 0xAE;
	address.addr64[6] = 0x9B;
	address.addr64[7] = 0xFE;
	
	xbee_conNew(xbee, &con, "Data", &address);
	
	for (;;) {
		
		xbee_conTx(con, NULL, "HelloTest");
		
		usleep(100000);

		xbee_conRx(con, &pkt, NULL);
		
		//cout << pkt->data << endl;
		
		printf("Time: %d \n", pkt->timestamp);
		
		usleep(100000);
		
	}
	
	xbee_conEnd(con);
	xbee_shutdown(xbee);
	
	return 0;
}
