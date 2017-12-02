#include "Meseros.h"

Meseros::Meseros(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->ListaPlatillos=ListaPlatillos;
}

Meseros::Meseros(){
}
void Meseros::setListaPlatillos(string m){
   this-> ListaPlatillos.push_back(m);
}
vector<string> Meseros::getListaPlatillos(){
   return ListaPlatillos;
}
