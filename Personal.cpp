#include "Personal.h"
#include <sstream>

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
Personal::~Personal(){
	
}
string Personal::escritura(){
	std::stringstream sstm;
	string tipo="P";
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