#include "Chef.h"

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
