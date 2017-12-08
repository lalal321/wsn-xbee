#include <iostream>
#include <fstream>
#include <unistd.h>
#include "client.hpp"
#include "wsn-xbee.h"
#include "json.hpp"

int main(){
    std::cout.setf(std::ios::unitbuf);
    std::string data;
    //results file id
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"../log/test_%d-%m-%Y_%H-%M-%S.txt",timeinfo);
    string resultsFileId(buffer);

    //results file
    ofstream resultsFile;
    resultsFile.open(resultsFileId);
	
	/* Setup Flight Controller connection */	
	TCPClient *c = new TCPClient();
	c->conn("localhost",7000);

	/* Setup Xbee radio connection */
	WSNXbee *w = new WSNXbee("/dev/serial0", 57600);
	
	resultsFile << "Initialized!\n";
    resultsFile.flush();
    
	/* Aguarda as coordenadas xyz do spy */
	for(;;){

		w->receive(1, data);
		if (!data.empty()) {
            resultsFile << data << "\n";
            resultsFile.flush();
            break;		
        }
		usleep(1000000);
	}
	/* Responde para o Spy que recebeu as coordenadas */
	//w->send(1, "Coordenadas recebidas!!!");
	resultsFile << "w->send(1, Coordenadas recebidas!!!)" << std::endl;
	resultsFile.flush();
	usleep(1000000);	
		
	/* Armar drone */
	//c->sendData("{\"command\":\"arm\",\"args\":{}}");
	resultsFile << "{\"command\":\"arm\",\"args\":{}}" << std::endl;
	resultsFile.flush();	
	resultsFile << "UAV Armed!\n";
    resultsFile.flush();
	usleep(1000000);
		
	/* Configurar as velocidades de terra e ar */
	//c->sendData("{\"command\":\"setSpeed\",\"args\":{\"airSpeed\": \"5\",\"groundSpeed\": \"5\"}}");
	resultsFile << "{\"command\":\"setSpeed\",\"args\":{\"airSpeed\": \"5\",\"groundSpeed\": \"5\"}}" << std::endl;	
    resultsFile.flush();
	resultsFile << "Speeds configured!\n";
    resultsFile.flush();
	usleep(1000000);
		
	/* Subir o drone até a altura de 10 metros */
	//c->sendData("{\"command\":\"takeOff\",\"args\":{\"z\": \"10\"}}");
	resultsFile << "{\"command\":\"tawkeOff\",\"args\":{\"z\": \"10\"}}" << std::endl;
    resultsFile.flush();
	usleep(60000000);
		
	/* Enviar a coordenada recebida para a Flight Controller {enviar a coordenada GPS} */
	std::ostringstream slat;
	std::ostringstream slon;
	std::ostringstream salt;
	
	// for convenience
	using json = nlohmann::json;
	// parse explicitly
	auto j = json::parse(data);
	
	slat << j["lat"];
	slon << j["lon"];
	salt << j["alt"];
	
	//c->sendData("{\"command\":\"setGEOPosition\",\"args\":{\"lat\":"+slat.str()+",\"lon\":"+slon.str()+",\"alt\":"+salt.str()+"}}");
	resultsFile << "{\"command\":\"setPosition\",\"args\":{\"lat\":"+slat.str()+",\"lon\":"+slon.str()+",\"alt\":"+salt.str()+"}}" << std::endl;
    resultsFile.flush();
	usleep(120000000);	
	
	/* Após receber a coordenada pousar 2 minutos*/
	//c->sendData("{\"command\":\"backToLand\",\"args\":{}}");
	resultsFile << "{\"command\":\"backToLand\",\"args\":{}}" << std::endl;
    resultsFile.flush();
    		
	/* Enviar a mensagem de missão cumprida para o spy */
	
	resultsFile << "Missão cumprida!!!";
    resultsFile.flush();
	
	//close the results file
    resultsFile.close();
	
	return 0;

}
