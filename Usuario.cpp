#include "Usuario.h"
#include <sstream>

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
Usuario::~Usuario(){
   
}
string Usuario::escritura(){
   std::stringstream sstm;
   string tipo="U";
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
    retVal+=numeroTelefonico1+",";
    return retVal;
}

