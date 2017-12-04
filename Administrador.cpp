#include "Administrador.h"
#include <fstream>
#include <sstream>

Administrador::Administrador(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo,int EmpleadosContratados,int EmpleadosDespedidos):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->EmpleadosContratados=EmpleadosContratados;
	this->EmpleadosDespedidos=EmpleadosDespedidos;
}

Administrador::Administrador(){

}

void Administrador::setEmpleadosContratados(int EmpleadosContratados){
   this-> EmpleadosContratados+=EmpleadosContratados;
}


int Administrador::getEmpleadosContratados(){
   return EmpleadosContratados;
}


void Administrador::setEmpleadosDespedidos(int EmpleadosDespedidos){
   this-> EmpleadosDespedidos-=EmpleadosDespedidos;
}


int Administrador::getEmpleadosDespedidos(){ 
   return EmpleadosDespedidos;
}


string Administrador::escritura(){
	std::stringstream sstm;
	string tipo="L";
	string edad1="",numeroTelefonico1="",sueldo1="",empleadosContratados1="",empleadosDespedidos1="";
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
    retVal+=sueldo1+";";
    //empleados contratados
    sstm<<EmpleadosContratados;
    empleadosContratados1= sstm.str();
    retVal+=empleadosContratados1+";";
    //empleados despedidos
    sstm<<EmpleadosDespedidos;
    empleadosDespedidos1 =sstm.str();
    retVal+=empleadosDespedidos1+",";
    return retVal;
}
Administrador::~Administrador(){
	
}


