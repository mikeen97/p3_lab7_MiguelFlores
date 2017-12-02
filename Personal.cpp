#include "Personal.h"

Personal::Personal(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo):Usuario(UserName, Password, Nombre, Edad, Id, NumeroTelefonico){
	this->AnoContratacion=AnoContratacion;
	this->Sueldo=Sueldo;
}
Personal::Personal(){

}
void Personal::setAnoContratacion(string AnoContratacion){
   this-> AnoContratacion=AnoContratacion;
}
string Personal::getAnoContratacion(){
   return AnoContratacion;
}
void Personal::setSueldo(double Sueldo){
   this-> Sueldo=Sueldo;
}
double Personal::getSueldo(){
   return Sueldo;
}