#include "Cliente.h"
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
Cliente::Cliente(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string Direccion,int RatingRest):Usuario(UserName, Password, Nombre, Edad, Id, NumeroTelefonico){
	this->Edad=Edad;
	this->Direccion=Direccion;
	this->RatingRest=RatingRest;
}

Cliente::Cliente(){

}
void Cliente::setDireccion(string Direccion){
   this-> Direccion=Direccion;
}

string Cliente::getDireccion(){
   return Direccion;
}

void Cliente::setRatingRest(int RatingRest){
   this-> RatingRest=RatingRest;
}
int Cliente::getRatingRest(){
   return RatingRest;
}
Cliente::~Cliente(){
	
}

string Cliente::escritura(){
	std::stringstream sstm;
	string tipo="C";
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
    //Direccion 
    retVal+=Direccion+";";
    //CALIFICACION
    sstm<<RatingRest;
    sueldo1= sstm.str();
    retVal+=sueldo1+",";
    return retVal;
}