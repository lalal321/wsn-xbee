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
	std::cout << "Armed!\n";	
	
	/* Configurar as velocidades de terra e ar */
	std::cout << "Speeds configured!\n";
		
	/* Subir o drone até a altura de 5 metros e procurar alvo */
	
	/* Se encontrar alvo {Salvar a coordenada GPS get} */
	std::ostringstream sx;
	std::ostringstream sy;
	std::ostringstream sz;
	sx << x;
	sy << y;
	sz << z;
	//c->getData("{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}");
	std::cout << "{\"command\":\"setPosition\",\"args\":{\"x\":"+sx.str()+",\"y\":"+sy.str()+",\"z\":"+sz.str()+"}}" << std::endl;
	
	/* Retornar para o ponto de partida */
	
	/* Dearmar o drone */
	
	/* Enviar a coordenada para o drone attack */
	w->send(1, "coordenada xyz");
	usleep(1000000);
	w->receive(1, data);
	if (!data.empty()) {
		std::cout << data << "\n";
    }
	usleep(1000000);

	return 0;
}
