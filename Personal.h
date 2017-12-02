#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef PERSONAL_H
#define PERSONAL_H
class Personal : public Usuario{
	protected:
		string AnoContratacion;
		double Sueldo;
	public:
		Personal(string,string,string,int,string,int,string,double);//contructor sobrecargado.
		Personal(string,double);
		Personal();
		string getAnoContratacion();
		void setAnoContratacion(string);

		double getSueldo();
		void setSueldo(double);

};
#endif