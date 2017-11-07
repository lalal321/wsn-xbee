#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xbee.h>
#include <string>
#include <sstream> 

using namespace std;

string data;

class WSNXbee{
  public:
    WSNXbee(string port, int baudrate);
    ~WSNXbee();
    void send(int numberOfXbee, string data);
    string receive(int numberOfXbee);
    
 private:
	struct xbee_conAddress address;
    struct xbee *xbee;
	struct xbee_con *con;
	void selectRadio(int n);
};

// constructor
WSNXbee::WSNXbee(string port, int baudrate){
	xbee_setup(&this->xbee, "xbeeZB", port, baudrate);
}

// destructor
WSNXbee::~WSNXbee(){
	/* close the connection */
	xbee_conEnd(this->con);

	/* shutdown libxbee */
	xbee_shutdown(this->xbee);
}

void myCB(struct xbee *xbee, struct xbee_con *con, struct xbee_pkt **pkt, void **data) {
	
	if ((*pkt)->dataLen > 0) {
				
		std::stringstream ss;
		ss << (*pkt)->data;
		string dd;
		ss >> data;
				
	}
	
}

void WSNXbee::selectRadio(int n){
	
	/* close the connection */
	xbee_conEnd(this->con);
	
	int status = 0;
	
	if(n == 1){
		memset(&this->address, 0, sizeof(this->address));
		this->address.addr64_enabled = 1;
		this->address.addr64[0] = 0x00;
		this->address.addr64[1] = 0x13;
		this->address.addr64[2] = 0xA2;
		this->address.addr64[3] = 0x00;
		this->address.addr64[4] = 0x40;
		this->address.addr64[5] = 0xAE;
		this->address.addr64[6] = 0x9B;
		this->address.addr64[7] = 0xFE;
		status = 1;
	}
	else if(n == 2){
		memset(&this->address, 0, sizeof(this->address));
		this->address.addr64_enabled = 1;
		this->address.addr64[0] = 0x00;
		this->address.addr64[1] = 0x13;
		this->address.addr64[2] = 0xA2;
		this->address.addr64[3] = 0x00;
		this->address.addr64[4] = 0x40;
		this->address.addr64[5] = 0xAC;
		this->address.addr64[6] = 0xC3;
		this->address.addr64[7] = 0x10;
		status = 1;
	}
	else if(n == 3){
		memset(&this->address, 0, sizeof(this->address));
		this->address.addr64_enabled = 1;
		this->address.addr64[0] = 0x00;
		this->address.addr64[1] = 0x13;
		this->address.addr64[2] = 0xA2;
		this->address.addr64[3] = 0x00;
		this->address.addr64[4] = 0x40;
		this->address.addr64[5] = 0xAE;
		this->address.addr64[6] = 0x9C;
		this->address.addr64[7] = 0xB0;
		status = 1;
	}
	else{
		cout << "Xbee not found!" << endl;
		return;
	}
	
	if(status == 1){
	
		/* create a 64-bit data connection with the address */
		xbee_conNew(xbee, &this->con, "Data", &this->address);

		/*?????*/
		//xbee_conDataSet(this->con, this->xbee, NULL);
		

		/* setup a callback to keep both the system load and response time low */
		xbee_conCallbackSet(this->con, myCB, NULL);

		/* kick off the chain reaction! */
		xbee_conTx(this->con, NULL, "Hello");
	}
	else{
		this->selectRadio(1);
	}
	
}

void WSNXbee::send(int numberOfXbee, string message){
	
	this->selectRadio(numberOfXbee);
	
	//convert string to char
	char * writable = new char[message.size() + 1];
	copy(message.begin(), message.end(), writable);
	writable[message.size()] = '\0';
	//send data
	xbee_conTx(con, NULL, writable);
}


string WSNXbee::receive(int numberOfXbee){
	
		this->selectRadio(numberOfXbee);

		void *p;
        xbee_conCallbackGet(this->con, (xbee_t_conCallback*)&p);

        usleep(100000);
        
        return data;        		

}
