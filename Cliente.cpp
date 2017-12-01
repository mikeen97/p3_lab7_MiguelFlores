#include "Cliente.h"

Cliente::Cliente(string Direccion,int RatingRest){
	this->Direccion=Direccion;
	this->RatingRest=RatingRest;
}
Cliente::Cliente(){

}void Cliente::setDireccion(string Direccion){
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
