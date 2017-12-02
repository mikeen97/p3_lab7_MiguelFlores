#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Usuario.h"

using namespace std;

#ifndef MESEROS_H
#define MESEROS_H
class Meseros : Personal{
	protected:
		vector<string> ListaPlatillos;
	public:
		Meseros(string,string,string,int,string,int,string,double);
		Meseros(vector<string>);
		Meseros();
		vector<string> getListaPlatillos();
		void setListaPlatillos(string);

};
#endif
