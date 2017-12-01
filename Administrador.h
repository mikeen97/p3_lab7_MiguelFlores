#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador : Personal{
	protected:
		int EmpleadosContratados;
		int EmpleadosDespedidos;
	public:
		Administrador(int,int);
		Administrador();
		int getEmpleadosContratados();
		void setEmpleadosContratados(int);

		int getEmpleadosDespedidos();
		void setEmpleadosDespedidos(int);

};
#endif