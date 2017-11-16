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

	/* Aguarda as coordenadas xyz do spy */
	for(;;){
		std::string data;
		w->receive(1, data);
		if (!data.empty()) {
            std::cout << data << "\n";		
        }
		usleep(1000000);
	}
	/* Responde para o Spy que recebeu as coordenadas */
		w->send(1, "Coordenadas recebidas!!!");
		usleep(1000000);	
		
	/* Armar drone */
	std::cout << "Armed!\n";
		
	/* Configurar as velocidades de terra e ar */
	std::cout << "Speeds configured!\n";
		
	/* Subir o drone até a altura de 5 metros */
	
	/* Enviar a coordenada recebida para a Flight Controller {enviar a coordenada GPS} */
	std::ostringstream sx;
	std::ostringstream sy;
	std::ostringstream sz;
	sx << x;
	sy << y;
	sz << z;
	//c->sendData("{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}");
	std::cout << "{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}" << std::endl;
	
	/* Verificar coordenada atual com coordenada recebida */
	
	/* Quando chegar na coordenada recebida: Pousar o drone*/
	
	/* Dearmar o drone */
	
	/* Enviar a mensagem de missão cumprida para o spy */
	w->send(1, "Missão cumprida!!!");
	usleep(1000000);
	return 0;

}
