#include "Administrador.h"


Administrador::Administrador(string UserName,string Password,string Nombre,int Edad,string Id,int NumeroTelefonico,string AnoContratacion,double Sueldo,int EmpleadosContratados,int EmpleadosDespedidos):Personal(UserName, Password, Nombre, Edad, Id, NumeroTelefonico, AnoContratacion, Sueldo){
	this->EmpleadosContratados=EmpleadosContratados;
	this->EmpleadosDespedidos=EmpleadosDespedidos;
}

Administrador::Administrador(){

}

void Administrador::setEmpleadosContratados(int EmpleadosContratados){
   this-> EmpleadosContratados=EmpleadosContratados;
}


int Administrador::getEmpleadosContratados(){
   return EmpleadosContratados;
}


void Administrador::setEmpleadosDespedidos(int EmpleadosDespedidos){
   this-> EmpleadosDespedidos=EmpleadosDespedidos;
}


int Administrador::getEmpleadosDespedidos(){ 
   return EmpleadosDespedidos;
}


