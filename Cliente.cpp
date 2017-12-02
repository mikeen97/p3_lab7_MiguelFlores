#include "Cliente.h"

Cliente::Cliente(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string Direccion,int RatingRest):Usuario(UserName, Password, Nombre, Edad, Id, NumeroTelefonico){
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
