#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Usuario.h"

using namespace std;

#ifndef MESEROS_H
#define MESEROS_H
class Meseros : public Personal{
	protected:
		vector<string> ListaPlatillos;
	public:
		Meseros(string,string,string,int,string,int,string,double);
		Meseros();
		vector<string> getListaPlatillos();
		void setListaPlatillos(string);
		void eliminarPlato(int);//elei
		void eliminarLista();

		virtual ~Meseros();
		virtual string escritura();

};
#endif
