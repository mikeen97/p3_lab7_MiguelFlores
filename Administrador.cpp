#include "Administrador.h"

Administrador::Administrador(int EmpleadosContratados,int EmpleadosDespedidos){
	this->EmpleadosContratados=EmpleadosContratados;
	this->EmpleadosDespedidos=EmpleadosDespedidos;
}
Administrador::Administrador(){

}void Administrador::setEmpleadosContratados(int EmpleadosContratados){
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
