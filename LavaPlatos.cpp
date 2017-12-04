#include "LavaPlatos.h"
#include <sstream>

LavaPlatos::LavaPlatos(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo,int NivelMotivacion):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->NivelMotivacion=NivelMotivacion;
}

LavaPlatos::LavaPlatos(){

}

void LavaPlatos::setNivelMotivacion(int NivelMotivacion){
   this-> NivelMotivacion+=NivelMotivacion;
   if (NivelMotivacion<0){
   	NivelMotivacion=0;
   }
}

int LavaPlatos::getNivelMotivacion(){
   return NivelMotivacion;
}
LavaPlatos::~LavaPlatos(){
	
}

string LavaPlatos::escritura(){
	std::stringstream sstm;
	string tipo="L";
	string edad1="",numeroTelefonico1="",sueldo1="",empleadosContratados1="";
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
    //NIVEL DE MOTIVACION
    sstm<<NivelMotivacion;
    empleadosContratados1= sstm.str();
    retVal+=empleadosContratados1+",";
    return retVal;
}

