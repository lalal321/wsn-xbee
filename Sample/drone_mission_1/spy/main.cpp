#include <iostream>
#include <unistd.h>
#include "lib/Socket/client.hpp"
#include "wsn-xbee.h"

int main(){
    std::cout.setf(std::ios::unitbuf);
	float x=0, y=0, z=0;
	
	/* Setup Flight Controller connection */
	TCPClient *c = new TCPClient();
	c->conn("localhost",7000);

	/* Setup Xbee radio connection */
	WSNXbee *w = new WSNXbee("/dev/serial0", 57600);
		
	std::cout << "Initialized!\n";

	/* Armar drone */
	//c->sendData("{\"command\":\"arm\",\"args\":{}}");
	std::cout << "{\"command\":\"arm\",\"args\":{}}" << std::endl;	
	std::cout << "UAV Armed!\n";	
	
	/* Configurar as velocidades de terra e ar */
	//c->sendData("{\"command\":\"setSpeed\",\"args\":{\"airSpeed\": \"5\",\"groundSpeed\": \"5\"}}");
	std::cout << "{\"command\":\"setSpeed\",\"args\":{\"airSpeed\": \"5\",\"groundSpeed\": \"5\"}}" << std::endl;	
	std::cout << "Speeds configured!\n";
		
	/* Subir o drone até a altura de 5 metros */
	//c->sendData("{\"command\":\"takeOff\",\"args\":{\"z\": \"5\"}}");
	std::cout << "{\"command\":\"tawkeOff\",\"args\":{\"z\": \"5\"}}" << std::endl;
	
	/* Executar percurso dos waysponts */
	/* Colocar no modo automático, ao final do percurso retornar para home e desarmar. */
	
	/* Se encontrar alvo {Salvar a coordenada GPS get} */
	while(){
		if(objectRED == 1 || objectBlue == 1){ 
			std::ostringstream sx;
			std::ostringstream sy;
			std::ostringstream sz;
			sx << x;
			sy << y;
			sz << z;
			//c->getData("{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}");
			std::cout << "{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}" << std::endl;
			/* Enviar a coordenada para o drone attack */
			if(objectRed == 1){
				w->send(1, "coordenada xyz");
			    usleep(1000000);
			    w->receive(1, data);
			    if (!data.empty()) {
			    std::cout << data << "\n";
			    usleep(1000000);
			}else if(objectBlue == 1){
		
		}
	}
	


	return 0;
}
