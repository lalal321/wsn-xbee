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
	struct xbee_conAddress address1;
	struct xbee_conAddress address2;
	
    xbee_setup(&xbee, "xbeeZB", "/dev/serial0", 57600);
    
	memset(&address1, 0, sizeof(address1));
	address1.addr64_enabled = 1;
	address1.addr64[0] = 0x00;
	address1.addr64[1] = 0x13;
	address1.addr64[2] = 0xA2;
	address1.addr64[3] = 0x00;
	address1.addr64[4] = 0x40;
	address1.addr64[5] = 0xAE;
	address1.addr64[6] = 0x9B;
	address1.addr64[7] = 0xFE;
	
	memset(&address2, 0, sizeof(address2));
	address2.addr64_enabled = 1;
	address2.addr64[0] = 0x00;
	address2.addr64[1] = 0x13;
	address2.addr64[2] = 0xA2;
	address2.addr64[3] = 0x00;
	address2.addr64[4] = 0x40;
	address2.addr64[5] = 0xAC;
	address2.addr64[6] = 0xC3;
	address2.addr64[7] = 0x10;
		
	for (;;) {
		/* Conexao com o radio 1 */ 
		xbee_conNew(xbee, &con, "Data", &address1);
		xbee_conTx(con, NULL, "Hello Radio 1");
		usleep(100000);
		xbee_conRx(con, &pkt, NULL);
		std::cout << pkt->data << std::endl;
		xbee_conEnd(con);
		usleep(100000);
		
		/* Conexao com o radio 2 */ 
		xbee_conNew(xbee, &con, "Data", &address2);
		xbee_conTx(con, NULL, "Hello Radio 2");
		usleep(100000);
		xbee_conRx(con, &pkt, NULL);
		std::cout << pkt->data << std::endl;
		xbee_conEnd(con);
		usleep(100000);
	}
	xbee_conEnd(con);
	xbee_shutdown(xbee);
	return 0;
}
