#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador : public Personal{
	public:
		int EmpleadosContratados;
		int EmpleadosDespedidos;
	public:
		Administrador(string,string,string,int,string,int,string,double,int,int);//contructor sobrecargado de Administrador
		Administrador(int,int);
		Administrador();
		int getEmpleadosContratados();
		void setEmpleadosContratados(int);

		int getEmpleadosDespedidos();
		void setEmpleadosDespedidos(int);

};
#endif