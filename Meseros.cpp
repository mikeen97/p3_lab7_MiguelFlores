#include "Meseros.h"
#include <sstream>

Meseros::Meseros(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->ListaPlatillos=ListaPlatillos;
}

Meseros::Meseros(){
}

void Meseros::setListaPlatillos(string m){
   this-> ListaPlatillos.push_back(m);
   vector<string> limpiar;
   if (m=="borrar123"){
		ListaPlatillos=limpiar;
   }
}

vector<string> Meseros::getListaPlatillos(){
   return ListaPlatillos;
}

void Meseros::eliminarPlato(int pos){
	for (int i = 0; i < ListaPlatillos.size(); ++i){
		if (pos==i){
			ListaPlatillos.erase(ListaPlatillos.begin()+i);
			break;
		}
	}
}
void Meseros::eliminarLista(){
	for (int i = 0; i < ListaPlatillos.size(); ++i){
		ListaPlatillos.erase(ListaPlatillos.begin()+i);
	}
}
Meseros::~Meseros(){
	
}

string Meseros::escritura(){
	std::stringstream sstm;
	string tipo="M";
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
    retVal+=sueldo1+",";
    return retVal;
}
