#include "Usuario.h"

Usuario::Usuario(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico){
	this->UserName=UserName;
	this->Password=Password;
	this->Nombre=Nombre;
	this->Edad=Edad;
	this->Id=Id;
	this->NumeroTelefonico=NumeroTelefonico;
}
Usuario::Usuario(){

}void Usuario::setUserName(string UserName){
   this-> UserName=UserName;
}
string Usuario::getUserName(){
   return UserName;
}
void Usuario::setPassword(string Password){
   this-> Password=Password;
}
string Usuario::getPassword(){
   return Password;
}
void Usuario::setNombre(string Nombre){
   this-> Nombre=Nombre;
}
string Usuario::getNombre(){
   return Nombre;
}
void Usuario::setEdad(int Edad){
   this-> Edad=Edad;
}
int Usuario::getEdad(){
   return Edad;
}
void Usuario::setId(string Id){
   this-> Id=Id;
}
string Usuario::getId(){
   return Id;
}
void Usuario::setNumeroTelefonico(int NumeroTelefonico){
   this-> NumeroTelefonico=NumeroTelefonico;
}
int Usuario::getNumeroTelefonico(){
   return NumeroTelefonico;
}
