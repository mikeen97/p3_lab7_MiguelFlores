#include "Personal.h"

Personal::Personal(string AnoContratacion,double Sueldo){
	this->AnoContratacion=AnoContratacion;
	this->Sueldo=Sueldo;
}
Personal::Personal(){

}void Personal::setAnoContratacion(string AnoContratacion){
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
