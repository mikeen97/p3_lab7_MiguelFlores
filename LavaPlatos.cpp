#include "LavaPlatos.h"

LavaPlatos::LavaPlatos(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo,int NivelMotivacion):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->NivelMotivacion=NivelMotivacion;
}

LavaPlatos::LavaPlatos(){

}

void LavaPlatos::setNivelMotivacion(int NivelMotivacion){
   this-> NivelMotivacion=NivelMotivacion;
}

int LavaPlatos::getNivelMotivacion(){
   return NivelMotivacion;
}
LavaPlatos::~LavaPlatos(){
	
}