#include "Chef.h"
#include <sstream>

Chef::Chef(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo,string PlatilloFavorito):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->PlatilloFavorito=PlatilloFavorito;
}

Chef::Chef(){

}

void Chef::setPlatilloFavorito(string PlatilloFavorito){
   this-> PlatilloFavorito=PlatilloFavorito;
}

string Chef::getPlatilloFavorito(){
   return PlatilloFavorito;
}
Chef::~Chef(){
	
}

string Chef::escritura(){
	std::stringstream sstm;
	string tipo="H";
	string edad1="",numeroTelefonico1="",sueldo1="";
	string retVal="";
	//tipo
	retVal+=tipo+";";
	//username
	retVal+=UserName+";";
	//password
	retVal+=Password+";";
	//nombre
	retVal+=Nombre+";";
	//edad
    sstm<<Edad;
    edad1=sstm.str();
    retVal+=edad1+";";
    //id 
	retVal+=Id+";";
	//Numero telefonico
    sstm<<NumeroTelefonico;
    numeroTelefonico1= sstm.str();
    retVal+=numeroTelefonico1+";";
    //ano contratacion 
    retVal+=AnoContratacion+";";
    //sueldo
    sstm<<Sueldo;
    sueldo1= sstm.str();
    retVal+=sueldo1+";";
    //empleados contratados
    retVal+=PlatilloFavorito+",";
    return retVal;
}







