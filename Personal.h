#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef PERSONAL_H
#define PERSONAL_H
class Personal : Usuario{
	protected:
		string AnoContratacion;
		double Sueldo;
	public:
		Personal(string,double);
		Personal();
		string getAnoContratacion();
		void setAnoContratacion(string);

		double getSueldo();
		void setSueldo(double);

};
#endif